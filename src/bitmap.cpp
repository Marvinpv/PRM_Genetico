#include <bitmap.hpp>
#include <imageES.hpp>
#include <iostream>
#include <constants.hpp>


using namespace std;

BitMap::BitMap(string path_file){
    map = LeerImagenPGM(path_file.c_str(), rows, cols);
}

unsigned char BitMap::getIndex(unsigned i, unsigned j){
    return map[i*cols + j];
}

unsigned BitMap::getRows(){
    return rows;
}

unsigned BitMap::getCols(){
    return cols;
}

void BitMap::writeBitMap(string path){
    string s(map.begin(),map.end());
    EscribirImagenPGM(path.c_str(), reinterpret_cast<const unsigned char *>(s.c_str()),rows, cols);
}

void BitMap::setIndex(unsigned i, unsigned j, unsigned char value){
    if(i >= 0 && i < rows && j >= 0 && j < cols)
        map[i*cols +j] = value;
}

void BitMap::inflateBorders(unsigned radius){

    for(int i=0; i < cols ; i++){
        for(int l = 0 ; l < int(radius/2) ; l++){
            for(int m =  i - int(radius/2) ; m < i + int(radius/2) ; m++){
                setIndex(l,m,char(0));
            }
        }

        for(int l = rows - 1 ; l > rows - int(radius/2) ; l--){
            for(int m =  i - int(radius/2) ; m < i + int(radius/2) ; m++){
                setIndex(l,m,char(0));
            }
        }
    }

    for(int i=0; i < rows ; i++){
        for(int l = 0 ; l < int(radius/2) ; l++){
            for(int m =  i - int(radius/2) ; m < i + int(radius/2) ; m++){
                setIndex(m,l,char(0));
            }
        }

        for(int l = cols - 1 ; l > cols - int(radius/2) ; l--){
            for(int m =  i - int(radius/2) ; m < i + int(radius/2) ; m++){
                setIndex(m,l,char(0));
            }
        }
    }
}



void BitMap::inflateObstacles(unsigned radius){
    inflateBorders(radius);

    for(unsigned i = 0; i < rows ; i++){
        for(unsigned j = 0 ; j < cols ; j++){
            if(getIndex(i,j) == UNKNOWN_SPACE_VAL){
                for(unsigned l = i - int(radius/2) ; l < i+ int(radius/2) ; l++){
                    for(unsigned m = j - int(radius/2) ; m < j+ int(radius/2) ; m++){
                        if(getIndex(l,m) == FREE_SPACE_VAL)
                            setIndex(l,m,OBSTACLE_VAL);
                    }
                }
                setIndex(i,j,OBSTACLE_VAL);                
            }
        }
    }

}

bool BitMap::checkCollision(Point p1, Point p2)
{
    int dx, dy;
    int sx, sy;
    int x1 = p1.getX(), x2 = p2.getX(), y1 = p1.getY(), y2 = p2.getY();
    int accum;//accumilato
    dx = x2 - x1;//Start X subtracted from End X
    dy = y2 - y1;

    sx = ((dx) < 0 ? -1 : ((dx) > 0 ? 1 : 0));//if dx is less than 0, sx = -1; otherwise if dx is greater than 0, sx = 1; otherwise sx = 0
    sy = ((dy) < 0 ? -1 : ((dy) > 0 ? 1 : 0));
    //dx = (dx < 0 ? -dx : dx);//if dx is less than 0, dx = -dx (becomes positive), otherwise nothing changes
    dx = abs(dx);//Absolute value
    //dy = (dy < 0 ? -dy : dy);
    dy = abs(dy);
    x2 += sx;//Add sx to End X
    y2 += sy;
    
    if (dx > dy)//if dx is greater than dy
    {
        accum = dx >> 1;//Accumilator = dx / 2
        do
        {
            //Plot point
            //Subtract dy from accumilator
            accum -= dy;
            //if accumilator is less than 0
            if (accum < 0)
            {
                //Add dx to accumilator
                accum += dx;
                //Add sy to Start Y
                y1 += sy;
            }
            //Add sx to Start X
            x1 += sx;
            //setIndex(x1,y1,OBSTACLE_VAL);
            if(getIndex(x1, y1) == OBSTACLE_VAL)
                return true;
        } while (x1 != x2);
    }
    else
    {
        accum = dy >> 1;
        do
        {
            accum -= dx;
            if (accum < 0)
            {
                accum += dy;
                x1 += sx;
            }
            y1 += sy;
            //setIndex(x1,y1,OBSTACLE_VAL);
            //cout << x1<< ","<<y1<<endl;
            if(getIndex(x1, y1) == OBSTACLE_VAL)
                return true;
        } while (y1 != y2);
    }
    
    return false;
}
