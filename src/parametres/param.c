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



/*param * entree_parametres(float*a, float*b, float*c){
    printf("a=");
    lireDecimal(a);
    printf("b=");
    lireDecimal(b);
    printf("c=");
    lireDecimal(c);
    param * param;
    param->a=a;
    param->b=b;
    param->c=c;
    return param;
}*/