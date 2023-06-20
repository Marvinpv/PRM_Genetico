#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP
#include <vector>
#include <point.hpp>
#include <bitmap.hpp>

using namespace std;

class Chromosome{
    private:
        unsigned num_points;
        vector<bool> connections;
        vector<unsigned> guards;
        vector<set<unsigned>> groups;
        unsigned num_groups;
        vector<Point> points;
        vector<bool> connections_groups;
        double fitness;
        unsigned max_group_size;

        void connectedGroupComponentsRec(unsigned group,vector<bool> &visited);

    public:
        
    
        Chromosome(){
            num_points = 0;
            points = vector<Point>();
            fitness = 0;
            connections = vector<bool>();
            //groups = vector<set<unsigned>>();
        }

        Chromosome(unsigned n_points){
            num_points = n_points;
            points = vector<Point>(n_points);
            connections = vector<bool>(n_points * n_points,false);
            //connections_groups = vector<bool>();
            guards = vector<unsigned>();
            groups = vector<set<unsigned>>();
            fitness = 0;
        }

        Chromosome(const Chromosome & other){
            num_points = other.num_points;
            points = vector<Point>(other.points);
            connections = vector<bool>(other.connections);
            guards = vector<unsigned>(other.guards);
            groups = vector<set<unsigned>>(other.groups);
            num_groups = other.num_groups;
            connections_groups = vector<bool>(other.connections_groups);
            //connections_groups = vector<bool>(other.connections_groups);
            fitness = other.fitness;
        }

        /*Chromosome(vector<Point> other_points, vector<bool> &connects, vector<unsigned> &other_guards){
            num_points = other_points.size();
            points = vector<Point>(other_points);
            connections = vector<bool>(connects);
            guards = vector<unsigned>(other_guards);
            fitness = 0;
        }*/

        unsigned getNumPoints(){
            return num_points;
        }

        Point &getPoint(unsigned i){
            if (i >= 0 && i < points.size())
                return points[i];
        }

        unsigned getNumGroups(){
            return num_groups;
        }

        double getFitness(){
            return fitness;
        }

        vector<Point> getPointsCopy(){
            return vector<Point>(points);
        }

        vector<unsigned> &getGuards(){
            return guards;
        }

        void deleteGuard(vector<unsigned>::iterator &g){
            guards.erase(g);
        }

        vector<unsigned>::iterator isGuard(unsigned i){
            for (auto it = guards.begin(); it != guards.end(); it++) {
                if (*it == i) {
                    return it;
                }
            }
            return guards.end();
        }

        void changeGuard(unsigned new_guard, BitMap bitmap);
        
        void initializeNewPoint(unsigned newPoint, BitMap bitmap);

        Chromosome(unsigned n_points, BitMap bitmap);

        Chromosome(vector<Point> p, BitMap bitmap);

        void initializePoints(BitMap bitmap);

        double groupArea(unsigned g);

        bool checkConnection(unsigned i, unsigned j);

        void createConnection(unsigned i, unsigned j);   

        void setConnection(unsigned i, unsigned j, bool val);     

        void calculateFitness(BitMap bitmap, bool debug=false);

        void initializeConnections(BitMap bitmap, unsigned dist_threshold);

        void createGuards(BitMap bitmap);

        void setGroupConnection(unsigned i, unsigned j, bool val);

        bool checkGroupConnection(unsigned i, unsigned j);

        void connectGroupsFromConnective(Point p);

        double checkGraphConnectivity();

        unsigned checkConnectedGroupComponentsNr();

        unsigned connectivePointsInGroup(unsigned group);

        double avgDistanceBetweenGroup(unsigned group, BitMap bitmap);

        double varianceDistanceBetweenGroup(unsigned group, double avg);

        unsigned groupsConnected(unsigned group);

        void resetChromosome(BitMap bitmap);

};

#endif