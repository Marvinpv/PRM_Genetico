#ifndef POINT_HPP
#define POINT_HPP
#include <vector>
#include "type_point.hpp"

using namespace std;

class Point{
    private:
        unsigned x;
        unsigned y;
        vector<unsigned> groups;
        TypePoint type;
    public:
        Point(){
            x = 0;
            y = 0;
            type = TypePoint::Group;
        }

        Point(unsigned x_0, unsigned y_0){
            x = x_0;
            y = y_0;
            type = TypePoint::Group;
        };

        Point(const Point &other){
            x = other.x;
            y = other.y;
            type = other.type;
            groups = vector<unsigned>(other.groups);
        }

        const Point & operator= (const Point &otro);

        void addGroup(unsigned g);
};

#endif