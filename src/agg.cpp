#include <agg.hpp>
#include <prm_utilities.hpp>
#include <random.hpp>

using Random = effolkronium::random_static;



AGG::AGG(BitMap bm, unsigned p_size, unsigned n_points){
    evals = 0;
    bitmap = bm;
    num_points = n_points;
    population = vector<Chromosome>();
    newPop = vector<Chromosome>();
    population_size = p_size;
    for(unsigned i = 0 ; i < p_size ; i++){
        Chromosome c(num_points, bitmap);
        population.push_back(c);
    }
}

void AGG::selection(){
    newPop.clear();
    for(unsigned i = 0 ; i < population_size ; i++){
        unsigned s1 = Random::get<unsigned>(0,num_points - 1);
        unsigned s2 = Random::get<unsigned>(0,num_points - 1);
        if(population[s1].getFitness() > population[s2].getFitness()){
            newPop.push_back(population[s1]);
        }else{
            newPop.push_back(population[s2]);    
        }
    }
}

void AGG::cross(){
    unsigned expected_crosses = (unsigned)(CROSS_PROB * (population.size()/2));
    for(unsigned i = 0 ; i < expected_crosses*2 ; i+=2 ){
        Chromosome father1(newPop[i]);
        Chromosome father2(newPop[i + 1]);
        blxAlphaCross(father1, father2,ALPHA_BLX ,newPop[i],newPop[i+1],bitmap);
    }

    evals += expected_crosses*2;
}

void AGG::mutation(){
    unsigned expected_mutations = (unsigned)(MUT_PROB*newPop.size());

    for(unsigned i = 0 ; i < expected_mutations ; i++){
        unsigned chrom = Random::get<unsigned>(0,newPop.size() - 1);
        mutatePoint(newPop[chrom], bitmap);
    }
}

void AGG::replacement(){

    unsigned worst_chrom = 0;
    double worst_fitness = newPop[0].getFitness();
    for(unsigned i = 1 ; i  < newPop.size() ; i++){
        if(newPop[i].getFitness() < worst_fitness){
            worst_chrom = i;
            worst_fitness = newPop[i].getFitness();
        }
    }

    unsigned best_chrom = 0;
    double best_fitness = population[0].getFitness();
    for(unsigned i = 1 ; i < population.size() ; i++){
        if(population[i].getFitness() > best_fitness){
            best_chrom = i;
            best_fitness = population[i].getFitness();
        }
    }

    if(best_fitness > worst_fitness){
        newPop[worst_chrom] = Chromosome(population[best_chrom]);
    }

    population = newPop;

}

Chromosome AGG::optimize(){
    double progress = 0.;
    while(evals < NUM_EVALS){
        selection();
        cross();
        mutation();
        replacement();
        //cout << "Evals: " << evals << endl;
        showProgressBar(progress);
        progress = (double)evals/(double)NUM_EVALS;

    }

    unsigned best_chrom = 0;
    double best_fitness = population[0].getFitness();
    for(unsigned i = 1 ; i < population.size() ; i++){
        if(population[i].getFitness() > best_fitness){
            best_chrom = i;
            best_fitness = population[i].getFitness();
        }
    }

    return population[best_chrom];

}
