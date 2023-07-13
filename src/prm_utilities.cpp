#include <iostream>
#include <prm_utilities.hpp>
#include <point.hpp>
#include <vector>
#include <random.hpp>
#include <bitmap.hpp>
#include <constants.hpp>

using namespace std;

using Random = effolkronium::random_static;

const double SIGMA = 0.3;

std::normal_distribution<double> distribution(0.0, SIGMA);

double normalize(double val, double min_val, double max_val){
    return (val-min_val)/(max_val - min_val);
}


void blxAlphaCross(Chromosome& father1, Chromosome& father2, double alpha, Chromosome & son1, Chromosome & son2, BitMap bitmap){
    vector<Point> points_father1 = father1.getPointsCopy();
    vector<Point> points_father2 = father2.getPointsCopy();
    vector<Point> points_son1 = vector<Point>();
    vector<Point> points_son2 = vector<Point>();
    
    for(vector<Point>::iterator it = points_father1.begin() ; it != points_father1.end() ; it++){

        unsigned it2 = nearestPoint(*it, points_father2);
        double x_max = max(it->getX(), points_father2[it2].getX());
        double x_min = min(it->getX(), points_father2[it2].getX());
        double y_max = max(it->getY(), points_father2[it2].getY());
        double y_min = min(it->getY(), points_father2[it2].getY());
        
        points_father2.erase(points_father2.begin() + it2);
        double i_x = x_max - x_min;
        double i_y = y_max - y_min;

        int x1 = (int)Random::get<double>(x_min - i_x*alpha, x_max + i_x*alpha);
        int x2 = (int)Random::get<double>(x_min - i_x*alpha, x_max + i_x*alpha);
        int y1 = (int)Random::get<double>(y_min - i_y*alpha, y_max + i_y*alpha);
        int y2 = (int)Random::get<double>(y_min - i_y*alpha, y_max + i_y*alpha);

        Point p1 = rescuePoint(x1,y1,bitmap);
        Point p2 = rescuePoint(x2,y2,bitmap);

        points_son1.push_back(p1);
        points_son2.push_back(p2);
    }

    son1 = Chromosome(points_son1, bitmap);
    son2 = Chromosome(points_son2, bitmap);
}

Point rescuePoint(int x1, int y1, BitMap bitmap){
    int range_x = 15;
    int range_y = 15;
    int x_new = x1;
    int y_new = y1;
    while(bitmap.getIndex(x_new,y_new) != FREE_SPACE_VAL){
        if(x_new > range_x && x_new < bitmap.getRows() - range_x && y_new > range_y && y_new < bitmap.getCols() -range_y){
            x_new = x_new + Random::get<int>(-range_x, range_x);
            y_new = y_new + Random::get<int>(-range_y, range_y);
            
        }else{
            //cout << "Rows: " << bitmap.getRows() << endl;
            if(x_new > int(bitmap.getRows() - range_x)){
                x_new = x_new - Random::get<int>(0,range_x);
                //cout << "Entra x" << endl;
            }
               
            else if (x_new < range_x)
                x_new = x_new + Random::get<int>(0,range_x);
            else
                x_new = x_new + Random::get<int>(-range_x, range_x);
            

            if(y_new > int(bitmap.getCols() - range_y)){
                y_new = y_new - Random::get<int>(0, range_y);
                //cout << "Entra" << endl;
            }
                
            else if (y_new < range_y)
                y_new = y_new + Random::get<int>(0,range_y);
            else
                y_new = y_new + Random::get<int>(-range_y, range_y);
        }
        //cout << "x: "  << x_new << "y: " <<y_new << endl;

    }

    return Point(x_new, y_new);
}


unsigned nearestPoint(Point p, vector<Point> &other_points){
    
    double min_dist = p.getDistance(other_points[0]);
    unsigned it_min = 0;
    
    for(unsigned i = 0 ; i < other_points.size() ; i++){
        
        if(p.getDistance(other_points[i]) < min_dist){
            min_dist = p.getDistance(other_points[i]);
            it_min = i;
        }
    }
    
    return it_min;
}


void mutatePoint(Chromosome & c, BitMap bitmap){
    unsigned point = Random::get<unsigned>(0,c.getNumPoints() - 1);
    if(c.isGuard(point) != c.getGuards().end()){ //If the point is a guard, we change the guard to other point
        unsigned new_guard = Random::get<unsigned>(0,c.getNumPoints() - 1);
        while(c.isGuard(new_guard) != c.getGuards().end()){
            new_guard = Random::get<unsigned>(0,c.getNumPoints() - 1);
        }
            
        
        c.changeGuard(new_guard,bitmap);
    }else{
        
        auto mut_x = Random::get(distribution);
        auto mut_y = Random::get(distribution);

        //c.getPoint(point).setX((unsigned)(c.getPoint(point).getX() + mut_x + 0.5));
        //c.getPoint(point).setY((unsigned)(c.getPoint(point).getY() + mut_y + 0.5));

        //rescuePoint(c.getPoint(point).getX(),c.getPoint(point).getY(),bitmap);
        
        c.resetChromosome(bitmap);
    }
}


void showProgressBar(double progress){
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}