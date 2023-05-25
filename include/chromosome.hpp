#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP
#include <vector>
#include <point.hpp>
#include <bitmap.hpp>

using namespace std;

class Chromosome{
    private:
        unsigned num_points;
        vector<Point> points; 
        unsigned fitness;
        vector<bool> connections;
    public:
        Chromosome(){
            num_points = 0;
            points = vector<Point>();
            fitness = 0;
            connections = vector<bool>();
        }

        Chromosome(unsigned n_points){
            num_points = n_points;
            points = vector<Point>(n_points);
            connections = vector<bool>(n_points * n_points);
            fitness = 0;
        }

        Chromosome(Chromosome & other){
            num_points = other.num_points;
            points = vector<Point>(other.points);
            connections = vector<bool>(other.connections);
            fitness = other.fitness;
        }

        Chromosome(vector<Point> other_points, vector<bool> &connects){
            num_points = other_points.size();
            points = vector<Point>(other_points);
            connections = vector<bool>(connects);
            fitness = 0;
        }

        Chromosome(unsigned size_x, unsigned size_y, BitMap bitmap);

        bool checkConnection(unsigned i, unsigned j);        

        void calculate_fitness(BitMap bitmap);
};

#endif