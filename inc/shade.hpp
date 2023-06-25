#ifndef SHADE_HPP_
#define SHADE_HPP_
#include <vector>
#include <chromosome.hpp>
#include <bitmap.hpp>

using namespace std;

class SHADE{
    private:
        const unsigned H = 20;
        vector<double> H_Mcr;
        vector<double> H_Mf;
        vector<Chromosome> population;     
        vector<Chromosome> archive;
        vector<Chromosome> trials;
        vector<double> Sf;
        vector<double> Scr;
        vector<double> delta_fk;
        unsigned pop_size;
        unsigned num_points;
        BitMap bitmap;
        unsigned evals = 0;
        const unsigned MAX_EVALS = 50000;
        const double P_MIN = 0.05;
    public:
        SHADE(unsigned p_size,unsigned n_points, BitMap bm);

        vector<unsigned> createTrials();

        Chromosome currentToPBestTrial(double p, unsigned i, double f);

        bool replaceWithTrials(vector<unsigned> r);

        double wk(unsigned k);

        double meanWA();

        double meanWL();

        Chromosome optimize();
};

#endif