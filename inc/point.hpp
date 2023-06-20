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
            groups = set<unsigned>();
        }

        Point(unsigned x_0, unsigned y_0){
            x = x_0;
            y = y_0;
            type = TypePoint::Group;
            groups = set<unsigned>();
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

        inline void setX(unsigned new_x){
            x = new_x;
        }

        inline void setY(unsigned new_y){
            y = new_y;
        }

        inline TypePoint getType(){
            return type;
        }

        set<unsigned> & getGroups(){
            return groups;
        }

        void setType(TypePoint t){
            type = t;
        }

        void clearGroups(){
            groups.clear();
        }

        const Point & operator= (const Point &otro);

        void addGroup(unsigned g);

        bool checkGroup(unsigned g);

        const double getDistance(Point &other);
};

#endif