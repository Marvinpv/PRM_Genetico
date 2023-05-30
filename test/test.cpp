#include <iostream>
#include <bitmap.hpp>
#include <string>
#include <chromosome.hpp>

using namespace std;

int main(void){
    string path = "./maps/room1.pgm";
    BitMap mapa_prueba(path);
    cout<<"Rows: " << mapa_prueba.getRows() << " Cols: " <<mapa_prueba.getCols() << endl;

    for(unsigned i = 0 ; i < mapa_prueba.getRows() ; i++){
        for(unsigned j = 0 ; j < mapa_prueba.getCols() ; j++){
            //cout <<int(mapa_prueba.getIndex(i,j))<<" ";
        }
        //cout << endl;
    }
    
    //mapa_prueba.inflateObstacles(10);


    if(mapa_prueba.checkCollision(Point(26,220),Point(265,288)))
        cout<<"HOla"<<endl;

    mapa_prueba.writeBitMap("./maps/room1_inflated.pgm");

    Chromosome c(50,mapa_prueba);
    string points_x = "";
    string points_y = "";
    cout <<"size: " <<c.points.size()<<endl;
    vector<string> groups_str(c.num_groups,"");
    for(unsigned i = 0 ; i < c.num_groups ; i++){
        for(unsigned j = 0 ; j < c.points.size() ; j++){
            if(i == 0){
                points_x += to_string(c.points[j].getX()) + ",";
                points_y += to_string(c.points[j].getY()) + ",";
                cout << "groups punto "<<j<<": ";
                /*for(set<unsigned>::iterator it = c.points[j].getGroups().begin(); it != c.points[j].getGroups().end() ; it++){
                    cout << *it << ", ";
                }*/
                cout << endl;
            }

            if(c.points[j].checkGroup(i)){
                groups_str[i] += to_string(j) + ",";
            }
            
        }
    }

    cout << "Points x: " << points_x << endl;
    cout << "Points y: " << points_y << endl;

    string command = "python3 src/check_groups.py "
                    + points_x
                    + " "
                    + points_y
                    + " "
                    + to_string(c.num_groups);
    
    for(unsigned i = 0 ; i < c.num_groups ; i++){
        command += " " + groups_str[i];
        cout << "Group " << i << ": " << groups_str[i]<<endl;
    }
    
    cout << "Comand: " << command <<endl;

    int ret = system(command.c_str());
    
}
