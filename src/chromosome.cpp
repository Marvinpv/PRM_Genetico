#include <chromosome.hpp>
#include <random.hpp>
#include <bitmap.hpp>
#include <constants.hpp>

using namespace std;
// get base random alias which is auto seeded and has static API and internal state
// it is not threads secure, you can also use ::random_thread_local
using Random = effolkronium::random_static;

bool Chromosome::checkConnection(unsigned i, unsigned j){
    if(i >=0 && i < num_points && j > 0 && j < num_points)
        return (connections[i*num_points + j] || connections[j*num_points + i]);

    return false;
}

void Chromosome::createConnection(unsigned i, unsigned j){
    if(i >=0 && i < num_points && j > 0 && j < num_points){
        connections[i*num_points + j] = true;
        connections[j*num_points + i] = true;
    }   
}

Chromosome::Chromosome(unsigned n_points, BitMap bitmap){
    num_points = n_points;
    points = vector<Point>();
    connections = vector<bool>(num_points*num_points,false);
    fitness = 0;
    unsigned last_group_assigned = 0;
    vector<unsigned> group_components;
    vector<unsigned> adjacent_connective_points;

    for( unsigned i = 0 ; i < num_points ; i++ ){
        unsigned x,y;
        do{
            x = Random::get<unsigned>(0,bitmap.getCols());
            y = Random::get<unsigned>(0,bitmap.getRows());
        }while(bitmap.getIndex(x,y) != FREE_SPACE_VAL);

        Point p_xy(x,y);
        unsigned j = 0;
        vector<unsigned> adjacent_groups(last_group_assigned,0);
        
        for(vector<Point>::iterator it= points.begin() ; it != points.end() ; it++){
            if(!bitmap.checkCollision(p_xy,*it)){

                createConnection(i,j);
                if((*it).getType() == TypePoint::Group){
                    unsigned group = *(it->getGroups().begin());
                    //p_xy.addGroup(group);
                    adjacent_groups[group]++;
                }


                /*unsigned group = *(it->getGroups().begin());
                if(!p_xy.checkGroup(group)){
                    if(!p_xy.getGroups().empty()){
                        p_xy.setType(TypePoint::Connective);
                        p_xy.addGroup(group);
                    }else{
                        p_xy.setType(TypePoint::Group);
                        p_xy.addGroup(group);
                    }
                }*/
            }
            j++;
        }

        bool con = false;
        unsigned groups_connected = 0;
        for(int a = 0 ; a < last_group_assigned ; a++){
            if(adjacent_groups[i] == group_components[i]){
                p_xy.addGroup(i);
                p_xy.setType(TypePoint::Group);
            }else if(adjacent_groups[i] > 0){
                con = true;
                groups_connected++;
            }
        } 

        if(con){
            
            //p_xy.addGroup(last_group_assigned);
            p_xy.setType(TypePoint::Connective);
            if(groups_connected == 1){
                p_xy.addGroup(last_group_assigned);
                last_group_assigned++;
                group_components.push_back(1);
            }else{
                //last_group_assigned++;
                
                j = 0;
                for(vector<Point>::iterator it= points.begin() ; it != points.end() ; it++){
                    if(checkConnection(i,j))
                        p_xy.addGroup(j);
                    j++;
                }
            }    
        }       

        if(p_xy.getGroups().empty()){
            p_xy.addGroup(last_group_assigned);
            p_xy.setType(TypePoint::Group);
            group_components.push_back(1);
            last_group_assigned++;
        }

        points.push_back(p_xy);

    }

    num_groups = last_group_assigned;
}