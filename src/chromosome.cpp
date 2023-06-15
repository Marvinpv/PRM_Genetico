#include <chromosome.hpp>
#include <random.hpp>
#include <bitmap.hpp>
#include <constants.hpp>
#include <iostream>
#include <math.h>
#include <utilities.hpp>

using namespace std;
// get base random alias which is auto seeded and has static API and internal state
// it is not threads secure, you can also use ::random_thread_local
using Random = effolkronium::random_static;

bool Chromosome::checkConnection(unsigned i, unsigned j){
    if(i >=0 && i < num_points && j >= 0 && j < num_points)
        return (connections[i*num_points + j] || connections[j*num_points + i]);

    return false;
}

void Chromosome::createConnection(unsigned i, unsigned j){
    if(i >=0 && i < num_points && j >= 0 && j < num_points){
        connections[i*num_points + j] = true;
        connections[j*num_points + i] = true;
    }   
}

Chromosome::Chromosome(unsigned n_points, BitMap bitmap){
    num_points = n_points;
    points = vector<Point>();
    connections = vector<bool>(num_points*num_points,false);
    guards = vector<unsigned>();
    groups = vector<set<unsigned>>();
    fitness = 0;
    max_group_size = 0;
    vector<unsigned> group_components;
    vector<unsigned> adjacent_connective_points;
    Point p_xy;
        for( unsigned i = 0 ; i < num_points ; i++ ){
            unsigned x,y;
            do{
                x = Random::get<unsigned>(0,bitmap.getRows());
                y = Random::get<unsigned>(0,bitmap.getCols());
            }while(bitmap.getIndex(x,y) != FREE_SPACE_VAL);
            p_xy = Point(x,y);
            points.push_back(p_xy);
        }
    
    
    
    createGuards(bitmap);
    connections_groups = vector<bool>(guards.size()*guards.size(),false);
    num_groups = guards.size();

    
       
    initializePoints(bitmap);
    //cout << "Size points: " << points.size() << endl;
    initializeConnections(bitmap, 50);
    calculateFitness(bitmap);
}

Chromosome::Chromosome(vector<Point> p, BitMap bitmap){
    num_points = p.size();
    points = p;
    connections = vector<bool>(num_points*num_points,false);
    guards = vector<unsigned>();
    groups = vector<set<unsigned>>();
    fitness = 0;
    max_group_size = 0;
    vector<unsigned> group_components;
    vector<unsigned> adjacent_connective_points;
    
    createGuards(bitmap);
    connections_groups = vector<bool>(guards.size()*guards.size(),false);
    num_groups = guards.size();
 
    initializePoints(bitmap);
    //cout << "Size points: " << points.size() << endl;
    initializeConnections(bitmap, 50);
    calculateFitness(bitmap);
}

void Chromosome::initializePoints(BitMap bitmap){

    for( unsigned i = 0 ; i < num_points ; i++ ){
        unsigned j = 0;
        for(vector<unsigned>::iterator it_guards = guards.begin() ; it_guards != guards.end() ; it_guards++){
            unsigned dist;
            if(i != *it_guards && !bitmap.checkCollision(points[i],points[*it_guards],dist)){
                //createConnection(i,*it_guards);
                if(points[i].groups.empty()){ //If it only visits this, this will be a guard of a group 
                    points[i].addGroup(j);
                    groups[j].insert(i);
                    points[i].setType(TypePoint::Group);
                }else{ // It creates a connection between guards
                    points[i].addGroup(j);
                    groups[j].insert(i);
                    points[i].setType(TypePoint::Connective); 
                    connectGroupsFromConnective(points[i]);
                }

                if(groups[j].size() > max_group_size){
                    max_group_size = groups[j].size();
                }
            }

            j++;
        }
        //cout << endl;
    }

}




void Chromosome::initializeConnections(BitMap bitmap, unsigned dist_threshold){

    for(unsigned i = 0 ; i < points.size() ; i++){
        unsigned connections = 0;
        int closest_point = -1;
        unsigned min_dist = UINT32_MAX;
        for(unsigned j = 0 ; j < points.size() ; j++){
            if(i != j){
                unsigned dist;
                bool collision = bitmap.checkCollision(points[i],points[j],dist); 
                if(!collision /*&& dist < dist_threshold*/){
                    createConnection(i,j);
                    if(points[i].getType() == TypePoint::Group && points[j].getType() == TypePoint::Group && !points[i].checkGroup(*points[j].getGroups().begin()) && !checkGroupConnection(*points[i].getGroups().begin(),*points[j].getGroups().begin())){
                        unsigned g1 = *points[i].getGroups().begin(), g2 = *points[j].getGroups().begin(); 
                        setGroupConnection(g1,g2,true);
                        points[i].addGroup(g2);
                        points[j].addGroup(g1);
                    }
                    connections++;
                }/*else if(!collision && dist < min_dist){
                    closest_point = j;
                    min_dist = dist;
                }*/
    
            }
        }

        //if(connections == 0 && closest_point != -1)
        //    createConnection(i,closest_point);
        
    }
}

void Chromosome::createGuards(BitMap bitmap){

    for(unsigned i = 0 ; i < points.size() ; i++){
        unsigned j = 0;
        bool new_guard = true;
        for(vector<unsigned>::iterator it_guards = guards.begin() ; it_guards != guards.end() ; it_guards++){
            unsigned dist;
            if(!bitmap.checkCollision(points[i],points[*it_guards],dist)){
                new_guard = false;
            }
            j++;
        }

        if(new_guard){ //New guard
            guards.push_back(i);
            points[i].setType(TypePoint::Group);
            points[i].addGroup(guards.size() - 1);
            groups.push_back(set<unsigned>());
            groups[groups.size() - 1].insert(i);
        }
    }
}

bool Chromosome::checkGroupConnection(unsigned i ,unsigned j){
    if(i >=0 && i < num_groups && j >= 0 && j < num_groups){
        return connections_groups[i*num_groups + j] || connections_groups[j*num_groups + i] ;
    }  

    return false;
}


void Chromosome::setGroupConnection(unsigned i, unsigned j, bool val){
    if(i >=0 && i < num_groups && j >= 0 && j < num_groups){
        connections_groups[i*num_groups + j] = val;
        connections_groups[j*num_groups + i] = val;
    }  
}

void Chromosome::connectGroupsFromConnective(Point p){
    for(set<unsigned>::iterator it = p.getGroups().begin() ; it != p.getGroups().end() ; it++){
        for(set<unsigned>::iterator it_j = p.getGroups().begin() ; it_j != p.getGroups().end() ; it_j++){
            if(*it != *it_j){
                setGroupConnection(*it,*it_j,true);
            }
        }
    }
}

double Chromosome::checkGraphConnectivity(){

    if(groups.size() == 0)
        return 0;

    unsigned connectedGroupComps = checkConnectedGroupComponentsNr();

    return 1.0/connectedGroupComps;
}


unsigned Chromosome::checkConnectedGroupComponentsNr(){
    vector<bool> visited(num_groups,false);
    unsigned nr = 0;
    
    /*cout << endl;
    for(int i = 0 ; i < num_groups ; i++){
        for(int j = 0 ; j < num_groups ; j++){
            cout << checkGroupConnection(i,j) <<" ";
        }
        cout << endl;
    }*/


    for(unsigned i = 0 ; i < num_groups ; i++){
        if(!visited[i]){
            nr++;
            connectedGroupComponentsRec(i,visited);
        }
    }

    return nr;
}



void Chromosome::connectedGroupComponentsRec(unsigned group,vector<bool> &visited){
    visited[group] = true;

    for(unsigned i = 0 ; i < num_groups ; i++){
        if(i != group && checkGroupConnection(group,i) && !visited[i]){
            connectedGroupComponentsRec(i,visited);
        }
    }
}

unsigned Chromosome::connectivePointsInGroup(unsigned group){
    unsigned count = 0;
    set<unsigned> g = groups[group];

    for(set<unsigned>::iterator it = g.begin() ; it != g.end() ; it++){
        if(points[*it].getType() == TypePoint::Connective)
            count++;
    }
    if(count == 0)
        count = 1;

    return count;
}

double Chromosome::avgDistanceBetweenGroup(unsigned group, BitMap bitmap){
    double avg = 0.;
    set<unsigned> g = groups[group];

    for(set<unsigned>::iterator it = g.begin() ; it != g.end() ; it++){
        for(set<unsigned>::iterator it_j = it ; it_j != g.end() ; it_j++){
            avg += points[*it].getDistance(points[*it_j]);
        }
    }
    if(avg == 0){
        avg = 1;
    }

    return avg/(double)g.size();
}

double Chromosome::varianceDistanceBetweenGroup(unsigned group, double avg){
    double variance = 0;

    set<unsigned> g = groups[group];

    for(set<unsigned>::iterator it = g.begin() ; it != g.end() ; it++){
        for(set<unsigned>::iterator it_j = it ; it_j != g.end() ; it_j++){
            variance += (points[*it].getDistance(points[*it_j]) - avg)*(points[*it].getDistance(points[*it_j]) - avg);
        }
    }

    if(variance == 0)
        variance = 1;

    return sqrt(variance/(double)g.size());
}



void Chromosome::calculateFitness(BitMap bitmap){
    fitness = 0.;
    for(unsigned i = 0 ; i < num_groups ; i++){
        double avg = avgDistanceBetweenGroup(i, bitmap); 
        double variance = varianceDistanceBetweenGroup(i,avg);
        unsigned connective = connectivePointsInGroup(i);
        double component_points = normalize((double)connective,0.0,(double)num_points/2.0);
        double groups_connected = (double)groupsConnected(i);

        double component = (avg)/(variance)+1.0/((component_points));
        component *= groups_connected*groups_connected;
        cout << "avg: " << avg <<", var: " << variance << ", group size: " << groups[i].size() << ", connective: " << connective <<",groups connected: "<< groups_connected <<", component: "<< component<< endl;
        /*if(connective > groups[i].size()/2.0)
            fitness -= (groups[i].size()*avg)/(variance*((connective+1)*10));
        else*/
            fitness += component;
        
    }
    unsigned connectedComponents = checkConnectedGroupComponentsNr();
    //if(connectedComponents > 1)
    //    fitness/=(double)(connectedComponents);
}

unsigned Chromosome::groupsConnected(unsigned group){
    unsigned count = 1;
    for(unsigned i = 0 ; i < num_groups ; i++){
        if(i != group && checkGroupConnection(i,group))
            count++;
    }

    return count;
}

void Chromosome::resetChromosome(BitMap bitmap){
    fitness = 0;
    max_group_size = 0;

    createGuards(bitmap);
    connections_groups = vector<bool>(guards.size()*guards.size(),false);
    num_groups = guards.size();
 
    initializePoints(bitmap);
    //cout << "Size points: " << points.size() << endl;
    initializeConnections(bitmap, 50);
    calculateFitness(bitmap);
}
