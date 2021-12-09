#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/param.h"

typedef struct _param_s{
    float a;
    float b;
    float c;
    float T_max;
} param_s ;

Param allouer_param(){
    return malloc(sizeof(param_s));
}

void setParam( Param p, float a, float b, float c, float T_max ){
    p->a = a;
    p->b = b;
    p->c = c;
    p->T_max = T_max;

}

Param creer_param( float a, float b, float c, float T_max ){
    Param p = allouer_param(); //malloc(sizeof(param_s));
    setParam(p,a,b,c,T_max);
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

Param lire_param(){
    float a;
    float b;
    float c;
    float T_max;
    printf("a=");
    lireDecimal(&a);
    printf("b=");
    lireDecimal(&b);
    printf("c=");
    lireDecimal(&c);
    printf("Temps maximal=");
    lireDecimal(&T_max);
    Param param = creer_param(a,b,c,T_max);
    return param;
}

