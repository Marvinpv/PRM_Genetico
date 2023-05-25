#include <point.hpp>
#include <algorithm>
#include <iostream>
#include <type_point.hpp>

using namespace std;

void Point::addGroup(unsigned g){
    if(!count(groups.begin(),groups.end(),g)){
        groups.push_back(g);
    }else{
        cout << " Group already in point: ("<<x<<","<<y<<") "<<endl;
    }

    if(groups.size() > 1){
        type = TypePoint::Connective;
    }
}

const Point & Point::operator=(const Point &otro){
    x = otro.x;
    y = otro.y;
    type = otro.type;
    groups = vector<unsigned>(otro.groups);

    return *this;
}