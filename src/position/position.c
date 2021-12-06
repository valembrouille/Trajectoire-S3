#include <stdio.h>
#include <stdlib.h>
#include "../../include/position.h"
#include "../../include/point.h"

typedef struct _position_s{
    Point point;
    float t;
} position_s ;

Position creer_position( float x, float y, float z, float t){
    Position pos = malloc(sizeof(position_s));
    pos->t = t;
    pos->point = creer_point(x, y, z);
    return pos;
}

void getPOINT( Position pos, Point a ){
    a = pos->point;
}
void getT( Position pos, float a ){
    a = pos->point;
}

void setPOINT( Position pos, Point M ){
    getX(M, float x);
    setX(pos->point->x = x);

    getY(M, float y);
    setY(pos->point->y = y);

    getZ(M, float z);
    setZ(pos->point->z = z);    

}
void setT( Position pos, float n ){
    pos->t = n;
}