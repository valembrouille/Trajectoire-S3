#include <stdio.h>
#include <stdlib.h>
#include "../../include/param.h"

typedef struct _param_s{
    float a;
    float b;
    float c;
    float T_max;
} param_s ; 

Param creer_param( float a, float b, float c, float T_max){
    Param p = malloc(sizeof(param_s));
    p->a = a;
    p->b = b;
    p->c = c;
    p->T_max = T_max;
    return p;
}

void getA( Param p, float a ){
    a = p->a;
}
void getB( Param p, float a ){
    a = p->b;
}
void getC( Param p, float a ){
    a = p->c;
}
void getT_MAX( Param p, float a ){
    a = p->T_max;
}

void setA (Param p, float n){
    P->a = n;
}
void setB (Param p, float n){
    P->b = n;
}
void setC (Param p, float n){
    P->c = n;
}
void setT_MAX (Param p, float n){
    P->T_max = n;
}

