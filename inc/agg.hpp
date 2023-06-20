#ifndef AGG_HPP_
#define AGG_HPP_
#include <iostream>
#include <vector>
#include "point.hpp"
#include "chromosome.hpp"
#include "bitmap.hpp"

using namespace std;

class AGG{
    private:
        vector<Chromosome> population;
        vector<Chromosome> newPop;
        BitMap bitmap;
        unsigned population_size;
        unsigned num_points;
        const unsigned NUM_EVALS = 50000;
        const double CROSS_PROB = 0.7;
        const double MUT_PROB = 0.2;
        const double ALPHA_BLX = 0.3;
        unsigned evals;
    public:
        AGG(BitMap bm, unsigned p_size, unsigned n_points);   

        void selection();

        void cross();

        void mutation();

        void replacement();

        Chromosome optimize();
};



#endif