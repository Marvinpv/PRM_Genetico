#include <age.hpp>
#include <prm_utilities.hpp>
#include <random.hpp>

using Random = effolkronium::random_static;



AGE::AGE(BitMap bm, unsigned p_size, unsigned n_points){
    evals = 0;
    bitmap = bm;
    num_points = n_points;
    population = vector<Chromosome>();
    for(unsigned i = 0 ; i < p_size ; i++){
        Chromosome c(num_points, bitmap);
        population.push_back(c);
    }
}

void AGE::selection(){

    
        unsigned s1 = Random::get<unsigned>(0,num_points - 1);
        unsigned s2 = Random::get<unsigned>(0,num_points - 1);
        if(population[s1].getFitness() > population[s2].getFitness()){
            son1 = Chromosome(population[s1]);
        }else{
            son1 = Chromosome(population[s2]);    
        }

        s1 = Random::get<unsigned>(0,num_points - 1);
        s2 = Random::get<unsigned>(0,num_points - 1);
        if(population[s1].getFitness() > population[s2].getFitness()){
            son2 = Chromosome(population[s1]);
        }else{
            son2 = Chromosome(population[s2]);    
        }
    
}

void AGE::cross(){
    
    Chromosome father1(son1);
    Chromosome father2(son2);
    blxAlphaCross(father1, father2,ALPHA_BLX ,son1,son2,bitmap);

    evals += 2;
}


void AGE::mutation(){
    bool mut1 = Random::get<double>(0,1) < MUT_PROB;
    bool mut2 = Random::get<double>(0,1) < MUT_PROB;

    if (mut1){
        mutatePoint(son1, bitmap);
    }
    
    if (mut2){
        mutatePoint(son2, bitmap);
    }
}

void AGE::replacement(){

    unsigned worst_chrom = 0;
    double worst_fitness = population[0].getFitness();
    for(unsigned i = 1 ; i  < population.size() ; i++){
        if(population[i].getFitness() < worst_fitness){
            worst_chrom = i;
            worst_fitness = population[i].getFitness();
        }
    }

    unsigned second_worst_chrom = (worst_chrom + 1)%population.size();
    worst_fitness = population[second_worst_chrom].getFitness();
    for(unsigned i = 1 ; i  < population.size() ; i++){
        if(population[i].getFitness() < worst_fitness && i != worst_chrom){
            second_worst_chrom = i;
            worst_fitness = population[i].getFitness();
        }
    }


    vector<Chromosome> candidates = vector<Chromosome>();
    candidates.push_back(son1);
    candidates.push_back(son2);
    candidates.push_back(population[worst_chrom]);
    candidates.push_back(population[second_worst_chrom]);

    unsigned best_chrom = 0;
    double best_fitness = son1.getFitness();
    for(unsigned i = 1 ; i  < candidates.size() ; i++){
        if(candidates[i].getFitness() > best_fitness){
            best_chrom = i;
            best_fitness = candidates[i].getFitness();
        }
    }

    unsigned second_best_chrom = (best_chrom + 1)%candidates.size();
    best_fitness = candidates[second_best_chrom].getFitness();
    for(unsigned i = 1 ; i  < candidates.size() ; i++){
        if(candidates[i].getFitness() > best_fitness && i!= best_chrom){
            second_best_chrom = i;
            best_fitness = candidates[i].getFitness();
        }
    }

    population[worst_chrom] = Chromosome(candidates[second_best_chrom]);
    population[second_worst_chrom] = Chromosome(candidates[best_chrom]);

}

Chromosome AGE::optimize(){
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
