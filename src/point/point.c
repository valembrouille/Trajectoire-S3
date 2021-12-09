#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/point.h"

typedef struct _point_s{
    float x;
    float y;
    float z;
} point_s ;


void setPoint( Point M, float x, float y, float z ){

    M->x = x;
    M->y = y;
    M->z = z;

}
Point allouer_point(){
    return malloc(sizeof(point_s));
}

Point creer_point( float x, float y, float z ){
    Point M = allouer_point(); //malloc(sizeof(point_s));
    setPoint(M,x,y,z);
    return M;
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

Point lire_point(){
    float x;
    float y;
    float z;
    printf("x=");
    lireDecimal(&x);
    printf("y=");
    lireDecimal(&y);
    printf("z=");
    lireDecimal(&z);
    Point M = creer_point(x,y,z);
    return M;
}