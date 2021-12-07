#include <stdio.h>
#include <stdlib.h>
#include "../../include/param.h"



Param creer_param( float a, float b, float c, float T_max){
    Param p = malloc(sizeof(param_s));
    p->a = a;
    p->b = b;
    p->c = c;
    p->T_max = T_max;
    return p;
}

float getA( Param p ){
    return p->a;
}
float getB( Param p ){
    return p->b;
}
float getC( Param p ){
    return p->c;
}
float getT_MAX( Param p ){
    return p->T_max;
}

void setA (Param p, float n){
    p->a = n;
}
void setB (Param p, float n){
    p->b = n;
}
void setC (Param p, float n){
    p->c = n;
}
void setT_MAX (Param p, float n){
    p->T_max = n;
}

