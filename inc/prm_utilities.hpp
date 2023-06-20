
#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_
#include <chromosome.hpp>
#include <point.hpp>
#include <vector>

using namespace std;

double normalize(double val, double min_val, double max_val);

void blxAlphaCross(Chromosome& father1, Chromosome& father2, double alpha, Chromosome & son1, Chromosome & son2, BitMap bitmap);

unsigned nearestPoint(Point p, vector<Point> &other_points);

Point rescuePoint(int x1, int x2, BitMap bitmap);

void mutatePoint(Chromosome & c, BitMap bitmap);

#endif