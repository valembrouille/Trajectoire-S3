#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/rossler.h"

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

/*Position * Creer_liste ( float T_max){
    float dt = 0.01;
    int N = T_max / dt;  //fréquence de calcul sur [0,T_max]
    Position * L = malloc( N * sizeof(Position) );   //liste de coordonnées en fontion du temps
    for (int i=0; i < N; i++){
        L[i]= malloc(sizeof(position_s));
    }
    return L;
}*/
Position * rossler (Point M, Param p, float dt){
    //float dt = 0.01; 
    float a,b,c,T_max, t;
    a= getA(p );
    b= getB(p);
    c= getC(p);
    T_max = getT_MAX(p);
    int N = T_max / dt;
    //printf ("lorenz_1 \n");

    Position * L = Creer_liste_position( getT_MAX(p),dt );
    //printf ("lorenz_2 \n");
    setPOINT_Dans_Position(L[0],M );
    /*Point point0 = getPOINT_DE_POSITION(L[0]);
    setPoint(point0, getX(M), getY(M),getZ(M) );
    */
    /*
    L[0]->point->x = getX(M);
    L[0]->point->y = getY(M);
    L[0]->point->z = getZ(M);
    */
    //printf ("lorenz_3 \n");
    
    setT(L[0],0);
    //L[0]->t = 0;
    //printf ("lorenz_4 \n");
    Point pointI;
    Point pointIMoin1;

    for (int i=1; i<N; i++){
        //printf ("lorenz_5 \n");
        pointI = getPOINT_DE_POSITION(L[i]);
        pointIMoin1 = getPOINT_DE_POSITION(L[i-1]);
        setX (pointI, getX(pointIMoin1) + (- getY(pointIMoin1) - getZ(pointIMoin1)) * dt);
        setY(pointI,getY(pointIMoin1) + (getX(pointIMoin1) + a * getY(pointIMoin1)) * dt);
        setZ(pointI,getZ(pointIMoin1) + (b + getZ(pointIMoin1) * (getX(pointIMoin1) - c )) * dt);
        //setT(L[i], getT(L[i-1]) +dt);
        //L[i]->t = L[i-1]->t + dt;
        t = getT(L[i-1]);
        setT( L[i] , t+dt );
    }
    //printf ("lorenz_6 \n");

    return L;
}
