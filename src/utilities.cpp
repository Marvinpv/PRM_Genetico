#include <iostream>
#include <utilities.hpp>

using namespace std;

double normalize(double val, double min_val, double max_val){
    return (val-min_val)/(max_val - min_val);
}


