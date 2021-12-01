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

struct point ** Creer_liste ( float T_max ){
    float dt = 0.01;
    int N = T_max / dt;  //fréquence de calcul sur [0,T_max]
    struct point** L = malloc( N * sizeof(struct point*) );   //liste de coordonnées en fontion du temps
    for (int i=0; i < N; i++){
        L[i]= malloc(sizeof(struct point));
    }
    return L;
}

struct point ** lorenz (struct point * M, struct param * Param){
    float dt = 0.01;
    int N = M->T_max / dt;
    struct point ** L = Creer_liste( M->T_max );
    L[0]->x = M->x;
    L[0]->y = M->y;
    L[0]->z = M->z;
    L[0]->T_max = 0;
    for (int i=1; i<N; i++){
        L[i]->x = L[i-1]->x + Param->sigma * (L[i-1]->y - L[i-1]->x) * dt;
        L[i]->y = L[i-1]->y + (L[i-1]->x * (Param->ro - L[i-1]->z) - L[i-1]->y) * dt;
        L[i]->z = L[i-1]->z + (L[i-1]->x * L[i-1]->y - Param->beta * L[i-1]->z) * dt;
        L[i]->T_max = L[i-1]->T_max + dt;
    }
    return L;
};

void aff_Traj(struct point ** L, float T_max){
    int N = T_max / 0.01; //longueur de la liste = N
    for (int i=0; i<N; i++){
        printf("%f %f %f %f\n", L[i]->T_max, L[i]->x, L[i]->y, L[i]->z);
    }
};

int main (){
    struct point * M = malloc(sizeof(struct point));
    scanf("%f\n",&M->x);
    scanf("%f\n",&M->y);
    scanf("%f\n",&M->z);
    scanf("%f\n",&M->T_max);
    
    printf("[ x = %f , y = %f , z = %f , temps = %f ]  \n", M->x, M->y, M->z, M->T_max);

    struct param * p = malloc(sizeof(struct param));
    scanf("%f\n",&p->sigma);
    scanf("%f\n",&p->ro);
    scanf("%f\n",&p->beta);

    printf("[ sigma = %f , ro = %f , beta = %f]  \n", p->sigma, p->ro, p->beta);

    aff_Traj(lorenz (M, p), M->T_max);
    
    return 0;
};