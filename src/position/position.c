#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"


Position creer_position( float x, float y, float z, float t){
    Position pos = malloc(sizeof(position_s));
    pos->t = t;
    pos->point = creer_point(x, y, z);
    return pos;
}

Point getPOINT( Position pos ){
   return pos->point;
}
float getT( Position pos ){
    return pos->t;
}

void setPOINT( Position pos, Point M ){
 
    setX(pos->point , getX(M));

    setY(pos->point , getY(M));

    setZ(pos->point,  getZ(M));    

}
void setT( Position pos, float n ){
    pos->t = n;
}