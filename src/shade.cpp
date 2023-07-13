#include <shade.hpp>
#include <random.hpp>
#include <prm_utilities.hpp>
#include <iostream>

using Random = effolkronium::random_static;

using namespace std;

SHADE::SHADE(unsigned p_size,unsigned n_points, BitMap bm){
    pop_size = p_size;
    num_points = n_points;
    evals = 0;
    bitmap = bm;

    population = vector<Chromosome>();
    archive = vector<Chromosome>();
    trials = vector<Chromosome>();
    
    for(unsigned i = 0 ; i < pop_size ; i++){
        Chromosome c(num_points, bitmap);
        population.push_back(c);
    }

    H_Mcr = vector<double>(H, 0.5);
    H_Mf = vector<double>(H, 0.5);
    
    Sf = vector<double>();
    Scr = vector<double>();
    delta_fk = vector<double>();
    sum_delta = 0.;


}

Chromosome SHADE::getPBest(double p){
    unsigned iters = Random::get<unsigned>(0,(unsigned)(p*(double)pop_size));
    set<unsigned> visited = set<unsigned>();
    double bestFitness = 0.0;
    int bestChrom = -1;
    for(unsigned i = 0 ; i < iters+1 ; i++){
        bestFitness = 0.0;
        bestChrom = -1;
        for(unsigned j = 0 ; j < pop_size ; j++){
            if(population[j].getFitness() > bestFitness && !visited.count(j)){
                bestFitness = population[j].getFitness();
                bestChrom = j;
            }
        }
    }

    return Chromosome(population[bestChrom]);
}

Chromosome SHADE::currentToPBestTrial(double p, unsigned a, double f){

    //We generate the necessary chromosomes for the new v_i
    //vector<Chromosome> sortedCopy(population);
    //sort(sortedCopy.begin(),sortedCopy.end());
    

    //unsigned p_best = Random::get<unsigned>(0,(unsigned)(p*pop_size));
    Chromosome x_pbest(getPBest(p));
    
    unsigned r1 = Random::get<unsigned>(0,pop_size - 1);
    Chromosome x_r1(population[r1]);
    unsigned r2 = Random::get<unsigned>(0, pop_size + archive.size() - 1);
    Chromosome x_r2;
    if(r2 >= pop_size){
        x_r2 = Chromosome(archive[r2%pop_size]);
    }else{
        x_r2 = Chromosome(population[r2]);
    }

    //cout << "Archive size: " << archive.size() << endl;
    Chromosome x_a(population[a]);

    vector<Point> ret;

    for(unsigned i = 0 ; i < num_points ; i++){
        Point comp1(x_a.getPoint(i));

        double x_comp2 = (f*((double)x_pbest.getPoint(i).getX() - (double)x_a.getPoint(i).getX()));
        double y_comp2 = (f*((double)x_pbest.getPoint(i).getY() - (double)x_a.getPoint(i).getY())); 

        double x_comp3 = (f*((double)x_r1.getPoint(i).getX() - (double)x_r2.getPoint(i).getX()));
        double y_comp3 = (f*((double)x_r1.getPoint(i).getY() - (double)x_r2.getPoint(i).getY())); 
        
        int x_final_point = (int)((double)comp1.getX() + x_comp2 + x_comp3);
        int y_final_point = (int)((double)comp1.getY() + y_comp2 + y_comp3);
        

        if(x_final_point > bitmap.getRows() ){
            x_final_point = bitmap.getRows() - 1;
        }else if(x_final_point < 0){
            x_final_point = 0;
        }
        
        if(y_final_point > bitmap.getCols() ){
            y_final_point = bitmap.getCols() - 1;
        }else if(y_final_point < 0){
            y_final_point = 0;
        }

        ret.push_back(rescuePoint(x_final_point,y_final_point,bitmap));

    }

    return Chromosome(ret,bitmap);

}

vector<unsigned> SHADE::createTrials(){

    vector<unsigned> r;
    trials.clear();

    for(unsigned i = 0 ; i < pop_size ; i++){
        unsigned r_i = Random::get<unsigned>(0,H-1);
        r.push_back(r_i);
        double CRi = H_Mcr[r_i];
        double Fi  = H_Mf[r_i];
        double p_i = Random::get<double>(P_MIN,0.2);
        
        Chromosome v_i(currentToPBestTrial(p_i,i,Fi));
        vector<Point> points_u_i;
        unsigned j_rand = Random::get<unsigned>(0,num_points - 1);
        for(unsigned j = 0 ; j < num_points ; j++){
            double cr = Random::get<double>(0,1);
            if(cr < CRi || j == j_rand){
                points_u_i.push_back(v_i.getPoint(j));
            }else{
                points_u_i.push_back(population[i].getPoint(j));
            }
            points_u_i[points_u_i.size() - 1].clearGroups();
        }

        trials.push_back(Chromosome(points_u_i,bitmap));
        evals++;
    }

    return r;
}

bool SHADE::replaceWithTrials(vector<unsigned> r){

    bool improved = false;
    for(unsigned i = 0 ; i < pop_size ; i++){
        if(population[i].getFitness() < trials[i].getFitness()){
            improved = true;
            if(archive.size() == population.size()){
                unsigned r = Random::get<unsigned>(0,population.size() - 1);
                population[r] = Chromosome(trials[i]);
            }else{
                archive.push_back(trials[i]);
            }

            Scr.push_back(H_Mcr[r[i]]);
            Sf.push_back(H_Mf[r[i]]);
            delta_fk.push_back(trials[i].getFitness() - population[i].getFitness());
            sum_delta += delta_fk[delta_fk.size() - 1];
            
            //cout << "Size Scr: " << Scr.size() << endl; 

            population[i] = Chromosome(trials[i]);
        }
    }

    return improved;
}

double SHADE::wk(unsigned k){
    return delta_fk[k]/sum_delta;
}

double SHADE::meanWA(){
    double sum_mean=0;
    for(unsigned i = 0 ; i < Scr.size() ; i++){
        sum_mean += wk(i) * Scr[i];
    }

    return sum_mean;
}

double SHADE::meanWL(){
    double sum_mean_sq = 0 , sum_mean = 0;

    for(unsigned i = 0 ; i < Scr.size() ; i++){
        sum_mean += wk(i) * Sf[i];
        sum_mean_sq += wk(i) * (Sf[i]*Sf[i]);
    }

    return sum_mean_sq/sum_mean;
}

Chromosome SHADE::optimize(){
    unsigned k = 0;
    bool improved = true;
    float progress = 0.0;
    while(evals < MAX_EVALS /*&& improved*/){
        vector<unsigned> r = createTrials();
        improved = replaceWithTrials(r);

        if(!Scr.empty() && !Sf.empty()){
            H_Mcr[k] = meanWA();
            H_Mf[k]  = meanWL();
            k = (k+1)%H;
        }

        //cout << "Evals: "<<progress <<endl;
        showProgressBar(progress);
        progress = (double)evals/(double)MAX_EVALS; // for demonstration only
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