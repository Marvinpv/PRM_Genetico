#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP
#include <vector>
#include <point.hpp>
#include <bitmap.hpp>

using namespace std;

class Chromosome{
    private:
        unsigned num_points;
         
        unsigned fitness;
        vector<bool> connections;
        vector<unsigned> guards;
    public:
        unsigned num_groups;
        vector<Point> points;
    
        Chromosome(){
            num_points = 0;
            points = vector<Point>();
            fitness = 0;
            connections = vector<bool>();
        }

        Chromosome(unsigned n_points){
            num_points = n_points;
            points = vector<Point>(n_points);
            connections = vector<bool>(n_points * n_points,false);
            guards = vector<unsigned>();
            fitness = 0;
        }

        Chromosome(Chromosome & other){
            num_points = other.num_points;
            points = vector<Point>(other.points);
            connections = vector<bool>(other.connections);
            fitness = other.fitness;
        }

        Chromosome(vector<Point> other_points, vector<bool> &connects, vector<unsigned> &other_guards){
            num_points = other_points.size();
            points = vector<Point>(other_points);
            connections = vector<bool>(connects);
            guards = vector<unsigned>(other_guards);
            fitness = 0;
        }

        Chromosome(unsigned n_points, BitMap bitmap);

        bool checkConnection(unsigned i, unsigned j);

        void createConnection(unsigned i, unsigned j);        

        void calculate_fitness(BitMap bitmap);
};

#endif