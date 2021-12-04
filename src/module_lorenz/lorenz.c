#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/lorenz.h"
#include "../../include/position.h"
#include "../../include/param.h"
#include "../../include/point.h"

Position * Creer_liste ( float T_max){
    float dt = 0.01;
    int N = T_max / dt;  //fréquence de calcul sur [0,T_max]
    Position * L = malloc( N * sizeof(Position) );   //liste de coordonnées en fontion du temps
    for (int i=0; i < N; i++){
        L[i]= malloc(sizeof(position_s));
    }
    return L;
}

Position * lorenz (Point M, Param param){
    float dt = 0.01;
    int N = param->T_max / dt;
    Position * L = Creer_liste( param->T_max );
    L[0]->point->x = M->x;
    L[0]->point->y = M->y;
    L[0]->point->z = M->z;
    L[0]->t = 0;
    for (int i=1; i<N; i++){
        L[i]->point->x = L[i-1]->point->x + Param->a * (L[i-1]->point->y - L[i-1]->point->x) * dt;
        L[i]->point->y = L[i-1]->point->y + (L[i-1]->point->x * (Param->b - L[i-1]->point->z) - L[i-1]->point->y) * dt;
        L[i]->point->z = L[i-1]->point->z + (L[i-1]->point->x * L[i-1]->point->y - Param->c * L[i-1]->point->z) * dt;
        L[i]->t = L[i-1]->t + dt;
    }
    return L;
}

void coord_Traj(Position * L, float T_max){
    int N = T_max / 0.01; //longueur de la liste = N
    for (int i=0; i<N; i++){
        printf("%f %f %f %f\n", L[i]->t, L[i]->point->x, L[i]->point->y, L[i]->point->z);
    }
}

int main (){
    Point M = malloc(sizeof(point_s));
    scanf("%f\n",&M->x);
    scanf("%f\n",&M->y);
    scanf("%f\n",&M->z);

    
    printf("[ x = %f , y = %f , z = %f ]  \n", M->x, M->y, M->z);

    Param p = malloc(sizeof(param_s));
    scanf("%f\n",&p->a);
    scanf("%f\n",&p->b);
    scanf("%f\n",&p->c);
    scanf("%f\n",&p->T_max);

    printf("[ a = %f , b = %f , c = %f , T_max=%f ]  \n", p->a, p->b, p->c, p->T_max);

    coord_Traj(lorenz (M, p), p->T_max);
    
    return 0;
}