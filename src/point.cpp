#include <point.hpp>
#include <algorithm>
#include <iostream>
#include <type_point.hpp>

using namespace std;

void Point::addGroup(unsigned g){
    if(!groups.count(g)){
        groups.insert(g);
    }else{
        //cout << " Group "<<g<<" already in point: ("<<x<<","<<y<<") "<<endl;
    }

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