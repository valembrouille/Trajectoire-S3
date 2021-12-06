#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"


typedef struct _point_s{
    float x;
    float y;
    float z;
} point_s ;

Point creer_point( float x, float y, float z ){
    Point M = malloc(sizeof(point_s));
    M->x = x;
    M->y = y;
    M->z = z;
    return M;
}

void getX( Point M, float a ){
    a = M->x;
}
void getY( Point M, float a ){
    a = M->y;
}
void getZ( Point M, float a ){
    a = M->z;
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