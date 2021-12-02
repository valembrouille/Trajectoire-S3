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
    M->a = x;
    M->b = y;
    M->c = z;
    return M;
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