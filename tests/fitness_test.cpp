#include <iostream>
#include <bitmap.hpp>
#include <string>
#include <chromosome.hpp>
#include <vector>
#include <point.hpp>
#include <prm_utilities.hpp>

using namespace std;

int main(){

    string path = "../maps/room1_smoothed.pgm"; 
    BitMap mapa_prueba(path);
    mapa_prueba.inflateObstacles(10);

    vector<Point> points_1;
    points_1.push_back(Point(60,36));
    points_1.push_back(Point(55,250));
    points_1.push_back(Point(156,166));
    points_1.push_back(Point(203,72));
    points_1.push_back(Point(103,280));
    points_1.push_back(Point(263,115));
    points_1.push_back(Point(50,141));
    points_1.push_back(Point(25,278));
    points_1.push_back(Point(266,22));
    points_1.push_back(Point(270,272));

    vector<Point> points_2;
    points_2.push_back(Point(123,251));
    points_2.push_back(Point(65,276));
    points_2.push_back(Point(74,96));
    points_2.push_back(Point(248,167));
    points_2.push_back(Point(169,11));
    points_2.push_back(Point(41,99));
    points_2.push_back(Point(10,156));
    points_2.push_back(Point(198,257));
    points_2.push_back(Point(66,284));
    points_2.push_back(Point(106,58));

    Chromosome c(points_1,mapa_prueba);
    Chromosome d(points_2,mapa_prueba);

    Chromosome c1;
    Chromosome c2;

    blxAlphaCross(c,d,0.3,c1, c2, mapa_prueba);

    cout <<"size: " <<c1.getNumPoints()<<endl;
    string points_x = "";
    string points_y = "";
    
    
    vector<string> groups_str(c1.getNumGroups(),"");
    string connective_group = "";
    string connections = "";

    for(unsigned i = 0 ; i < c1.getNumGroups() ; i++){
        for(unsigned j = 0 ; j < c1.getNumPoints() ; j++){
            if(i == 0){
                points_x += to_string(c1.getPoint(j).getX()) + ",";
                points_y += to_string(c1.getPoint(j).getY()) + ",";
                if(c1.getPoint(j).getType() == TypePoint::Connective)
                    connective_group += to_string(j) + ",";
            }

            if(c1.getPoint(j).checkGroup(i) && c1.getPoint(j).getType() == TypePoint::Group){
                groups_str[i] += to_string(j) + ",";
            }
            
        }
    }

    double dist_threshold = 50;
    for(unsigned i = 0 ; i < c1.getNumPoints() ; i++){
        for(unsigned j = i ; j < c1.getNumPoints() ; j++){
            if(c1.checkConnection(i,j) /*&& c1.getPoint(i).getDistance(c1.getPoint(j)) < dist_threshold*/){
                connections += to_string(i) + "," + to_string(j) + ",";
            }
                 
        }
    }

    mutatePoint(c1,mapa_prueba);


    cout << "Points x: " << points_x << endl;
    cout << "Points y: " << points_y << endl;
    //cout << "Connections: " << connections << endl;
    cout << "Connected components in graph: " << c1.checkConnectedGroupComponentsNr() << endl;
    cout << "Fitness: " << c1.getFitness() << endl;

    string command = "python3 ../src/check_groups.py "
                    + points_x
                    + " "
                    + points_y
                    + " "
                    + to_string(c1.getNumGroups());
                    
    
    for(unsigned i = 0 ; i < c1.getNumGroups() ; i++){
        command += " " + groups_str[i];
        cout << "Group " << i << ": " << groups_str[i]<<endl;
    }

    if(connective_group == ""){
        command += " None";
    }else{
        command += " " + connective_group;  
    }
    
    if(connections == ""){
        command += " None";
    }else{
        command += " " + connections;  
    }
    
    
    //cout << "Comand: " << command <<endl;

    int ret = system(command.c_str());
}