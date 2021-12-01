#include <stdio.h>
#include <stdlib.h>


struct point {
    float x;
    float y;
    float z;
    float T_max;
};

struct param {
    float sigma;
    float ro;
    float beta;
};



int main (){
    float dt = 0.01;

    struct point * M = malloc(sizeof(struct point));
    M->x=5;
    M->y=5;
    M->z=5;
    M->T_max=1;

    struct param * Param = malloc(sizeof(struct param));
    Param->sigma=3;
    Param->ro=5;
    Param->beta=4;

    int N = M->T_max / dt;  //fréquence de calcul sur [0,T_max]
    struct point** L = malloc(N*sizeof(struct point*));  //liste de coordonnées en fontion du temps
    for (int i=0; i< N; i++){
        L[i]= malloc(sizeof(struct point));
    }
    L[0]->x = M->x;
    L[0]->y = M->y;
    L[0]->z = M->z;
    L[0]->T_max = 0;
    printf("%f\n", L[0]->x);
    printf("%d\n", N);

    for (int i=1; i<N+1; i++){
        L[i]->x = L[i-1]->x + Param->sigma * (L[i-1]->y - L[i-1]->x) * dt;
        printf("%d:   %f\n", i, L[i]->x);
        L[i]->y = L[i-1]->y + (L[i-1]->x * (Param->ro - L[i-1]->z) - L[i-1]->y) * dt;
        printf("%f\n", L[i]->y);
        L[i]->z = L[i-1]->z + (L[i-1]->x * L[i-1]->y - Param->beta * L[i-1]->z) * dt;
        printf("%f\n", L[i]->z);
        L[i]->T_max = L[i-1]->T_max + dt;
        printf("%f\n", L[i]->T_max);
    }


    printf("[\n");
    for (int i=0; i< (int) N; i++){
        printf("h\n");
        printf("[ x = %f , y = %f , z = %f , temps = %f ]  \n", L[i]->x, L[i]->y, L[i]->z, L[i]->T_max);
    }
    printf("]");
    return 0;
};