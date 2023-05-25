#include <chromosome.hpp>

using namespace std;

bool Chromosome::checkConnection(unsigned i, unsigned j){
    return (connections[i*num_points + j] || connections[j*num_points + i]);
}