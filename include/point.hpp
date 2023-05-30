#ifndef POINT_HPP
#define POINT_HPP
#include <vector>
#include "type_point.hpp"
#include <set>

using namespace std;

class Point{
    private:
        unsigned x;
        unsigned y;
        set<unsigned> groups;
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
            type = TypePoint::Unknown;
        };

        Point(const Point &other){
            x = other.x;
            y = other.y;
            type = other.type;
            groups = set<unsigned>(other.groups);
        }

        inline unsigned getX(){
            return x;
        }

        inline unsigned getY(){
            return y;
        }

        inline TypePoint getType(){
            return type;
        }

        set<unsigned> getGroups(){
            return groups;
        }

        void setType(TypePoint t){
            type = t;
        }

        const Point & operator= (const Point &otro);

        void addGroup(unsigned g);

        bool checkGroup(unsigned g);
};

#endif