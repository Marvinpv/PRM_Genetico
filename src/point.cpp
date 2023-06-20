#include <point.hpp>
#include <algorithm>
#include <iostream>
#include <type_point.hpp>
#include <math.h>

using namespace std;

void Point::addGroup(unsigned g){

    groups.insert(g);
    

    if(groups.size() > 1){
        type = TypePoint::Connective;
    }
}

const Point & Point::operator=(const Point &otro){
    x = otro.x;
    y = otro.y;
    type = otro.type;
    groups = set<unsigned>(otro.groups);

    return *this;
}

bool Point::checkGroup(unsigned g){
    return groups.count(g) > 0;
}

const double Point::getDistance(Point &other){
    return sqrt((x - other.getX())*(x - other.getX()) + (y - other.getY())*(y - other.getY()));
}