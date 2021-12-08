#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/lorenz.h"

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


Position * Creer_liste ( float T_max){
    float dt = 0.01;
    int N = T_max / dt;  //fréquence de calcul sur [0,T_max]
    Position * L = malloc( N * sizeof(Position) );   //liste de coordonnées en fontion du temps
    for (int i=0; i < N; i++){
        L[i]= malloc(sizeof(position_s));
    }
    return L;
}

Position * lorenz (Point M, Param p){
    float dt = 0.01;
<<<<<<< HEAD

    getA(p, float a);
    getB(p, float b);
    getC(p, float c);
    getT_MAX(p, float T_max);
=======
    float a,b,c,T_max, t;
    a= getA(p );
    b= getB(p);
    c= getC(p);
    T_max = getT_MAX(p);
>>>>>>> d5ccc99e8fe6d68af04495d9830630b1fb8d48c6
    int N = T_max / dt;

    Position * L = Creer_liste( p->T_max );
    L[0]->point->x = getX(M);
    L[0]->point->y = getY(M);
    L[0]->point->z = getZ(M);
    L[0]->t = 0;

    for (int i=1; i<N; i++){
        L[i]->point->x = L[i-1]->point->x + a * (L[i-1]->point->y - L[i-1]->point->x) * dt;
        L[i]->point->y = L[i-1]->point->y + (L[i-1]->point->x * (b - L[i-1]->point->z) - L[i-1]->point->y) * dt;
        L[i]->point->z = L[i-1]->point->z + (L[i-1]->point->x * L[i-1]->point->y - c * L[i-1]->point->z) * dt;
        L[i]->t = L[i-1]->t + dt;
        t= getT(L[i-1]);
        setT( L[i] , t+dt );
    }
    return L;
}

void coord_Traj(Position * L, float T_max){
    int N = T_max / 0.01; //longueur de la liste = N
    for (int i=0; i<N; i++){
        printf("%f %f %f %f\n", L[i]->t, L[i]->point->x, L[i]->point->y, L[i]->point->z);
    }
}
