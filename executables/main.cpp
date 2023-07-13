#include <iostream>
#include <bitmap.hpp>
#include <string>
#include <chromosome.hpp>
#include <age.hpp>
#include <agg.hpp>
#include <shade.hpp>
#include <fstream>
#include <chrono>


using namespace std;

const unsigned int NUM_ROOMS = 4;
const unsigned int points_for_room[] = {6,10,12,7};

enum class Alg{
    agg,
    age,
    shade,
    visibility_graph
};

const unsigned int NUM_ALGS = 4;
const unsigned int NUM_EXEC = 70;
const unsigned int POP_SIZE = 50;
const unsigned M = 400;

int main(int argc, char ** argv){

    typedef std::chrono::high_resolution_clock Clock;
    for(unsigned i = 0 ; i < NUM_ROOMS ; i++){
        string path = "../maps/room" + to_string(i+1) + "_smoothed.pgm"; 
        BitMap mapa_prueba(path);
        fstream f;
        for(unsigned j = 0 ; j < NUM_ALGS ; j++){
            string out_file = "../results/";
            switch (j)
            {
            case 0: // AGG
                cout << "AGG - ROOM NR " << i+1 << " - NUM POINTS " << points_for_room[i] << endl;
                out_file += "agg_"+to_string(i+1)+"_"+to_string(points_for_room[i])+".txt";
                f.open(out_file.c_str(),fstream::app | fstream::out);
                f << "Points,Fitness,Visibility,Time"<<endl;
                for(unsigned l = 0 ; l < NUM_EXEC ; l++){
                    AGG a(mapa_prueba,POP_SIZE,points_for_room[i]);
                    auto t1 = Clock::now();
                    Chromosome c(a.optimize());
                    auto t2 = Clock::now();
                    f << c.getNumPoints() << "," << c.getFitness() << "," << c.calculateVisibility(mapa_prueba) << "," << (t2 - t1).count() << endl;
                }
                f.close();
                break;
            
            case 1: // AGE
                cout << "AGE - ROOM NR " << i+1 << " - NUM POINTS " << points_for_room[i] << endl;
                out_file += "age_"+to_string(i+1)+"_"+to_string(points_for_room[i])+".txt";
                f.open(out_file.c_str(),fstream::app | fstream::out);
                f << "Points,Fitness,Visibility,Time"<<endl;
                for(unsigned l = 0 ; l < NUM_EXEC ; l++){
                    AGE a(mapa_prueba,POP_SIZE,points_for_room[i]);
                    auto t1 = Clock::now();
                    Chromosome c(a.optimize());
                    auto t2 = Clock::now();
                    f << c.getNumPoints() << "," << c.getFitness() << "," << c.calculateVisibility(mapa_prueba) << "," << (t2 - t1).count() << endl;
                }

                f.close();
                break;
            
            case 2: // SHADE
                cout << "SHADE - ROOM NR " << i+1 << " - NUM POINTS " << points_for_room[i] << endl;
                out_file += "shade_"+to_string(i+1)+"_"+to_string(points_for_room[i])+".txt";
                f.open(out_file.c_str(),fstream::app | fstream::out);
                f << "Points,Fitness,Visibility,Time"<<endl;
                for(unsigned l = 0 ; l < NUM_EXEC ; l++){
                    SHADE a(POP_SIZE,points_for_room[i], mapa_prueba);
                    auto t1 = Clock::now();
                    Chromosome c(a.optimize());
                    auto t2 = Clock::now();
                    f << c.getNumPoints() << "," << c.getFitness() << "," << c.calculateVisibility(mapa_prueba) << "," << (t2 - t1).count() << endl;
                }
                f.close();
                break;
            case 3: // VISIBILITY GRAPH
                cout << "VISIBILITY GRAPH - ROOM NR " << i+1 << " - M " << M << endl;
                out_file += "vis_"+to_string(i+1)+"_"+to_string(points_for_room[i])+".txt";
                f.open(out_file.c_str(),fstream::app | fstream::out);
                f << "Points,Fitness,Visibility,Time"<<endl;
                for(unsigned l = 0 ; l < NUM_EXEC ; l++){
                    Chromosome c;
                    auto t1 = Clock::now();
                    c.visibilityGraph(mapa_prueba,M);
                    auto t2 = Clock::now();
                    f << c.getNumPoints() << "," << c.getFitness() << "," << c.calculateVisibility(mapa_prueba) << "," << (t2 - t1).count() << endl;
                }
                f.close();
                break;
            default:
                break;
            }

        }
    }
    
}