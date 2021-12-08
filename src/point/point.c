#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"

typedef struct _point_s{
    float x;
    float y;
    float z;
} point_s ;


Point creer_point( float x, float y, float z ){
    Point M = allouer_point(); //malloc(sizeof(point_s));
    setPoint(M,x,y,z);
    return M;
}

void setPoint( Point M, float x, float y, float z ){

    M->x = x;
    M->y = y;
    M->z = z;

}
Point allouer_point(){
    return malloc(sizeof(point_s));
}

float getX( Point M ){
    return M->x;
}
float getY( Point M ){
    return M->y;
}
float getZ( Point M ){
    return M->z;
}

void setX (Point M, float n){
    M->x = n;
}
void setY (Point M, float n){
    M->y = n;
}
void setZ (Point M, float n){
    M->z = n;
}

/* Point * entree_Point(float x, float y, float z){
    printf("x=");
    lireDecimal(x);
    printf("y=");
    lireDecimal(y);
    printf("z=");
    lireDecimal(z);
    printf("temps max=");
    lireDecimal(tps);
    Point * point;
    point->x=x;
    point->y=y;
    point->z=z;
    point->tps=tps;
    return point;
}*/