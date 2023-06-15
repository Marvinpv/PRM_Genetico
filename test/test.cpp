#include <iostream>
#include <bitmap.hpp>
#include <string>
#include <chromosome.hpp>

using namespace std;

int main(void){
    string path = "./maps/room1_smoothed.pgm"; 
    BitMap mapa_prueba(path);
    cout<<"Rows: " << mapa_prueba.getRows() << " Cols: " <<mapa_prueba.getCols() << endl;

    for(unsigned i = 0 ; i < mapa_prueba.getRows() ; i++){
        for(unsigned j = 0 ; j < mapa_prueba.getCols() ; j++){
            //cout <<int(mapa_prueba.getIndex(i,j))<<" ";
        }
        //cout << endl;
    }
    
    mapa_prueba.inflateObstacles(10);
    unsigned dist;
    mapa_prueba.checkCollision(Point(100,100),Point(7,280),dist);
    mapa_prueba.writeBitMap("./maps/room1_inflated.pgm");
    

    Chromosome c(10,mapa_prueba);
    cout <<"size: " <<c.getNumPoints()<<endl;
    string points_x = "";
    string points_y = "";
    
    
    vector<string> groups_str(c.getNumGroups(),"");
    string connective_group = "";
    string connections = "";

    for(unsigned i = 0 ; i < c.getNumGroups() ; i++){
        for(unsigned j = 0 ; j < c.getNumPoints() ; j++){
            if(i == 0){
                points_x += to_string(c.getPoint(j).getX()) + ",";
                points_y += to_string(c.getPoint(j).getY()) + ",";
                if(c.getPoint(j).getType() == TypePoint::Connective)
                    connective_group += to_string(j) + ",";
            }

            if(c.getPoint(j).checkGroup(i) && c.getPoint(j).getType() == TypePoint::Group){
                groups_str[i] += to_string(j) + ",";
            }
            
        }
    }

    double dist_threshold = 50;
    for(unsigned i = 0 ; i < c.getNumPoints() ; i++){
        for(unsigned j = i ; j < c.getNumPoints() ; j++){
            if(c.checkConnection(i,j) /*&& c.getPoint(i).getDistance(c.getPoint(j)) < dist_threshold*/){
                connections += to_string(i) + "," + to_string(j) + ",";
            }
                 
        }
    }



    cout << "Points x: " << points_x << endl;
    cout << "Points y: " << points_y << endl;
    //cout << "Connections: " << connections << endl;
    cout << "Connected components in graph: " << c.checkConnectedGroupComponentsNr() << endl;
    cout << "Fitness: " << c.getFitness() << endl;

    string command = "python3 src/check_groups.py "
                    + points_x
                    + " "
                    + points_y
                    + " "
                    + to_string(c.getNumGroups());
                    
    
    for(unsigned i = 0 ; i < c.getNumGroups() ; i++){
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


