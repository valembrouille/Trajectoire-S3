#include <stdio.h>
#include <stdlib.h>
#include <Syst_Dynam.h>

int main (){
    point * M = malloc(sizeof(point));
    scanf("%f\n",M->x);
    scanf("%f\n",M->y);
    scanf("%f\n",M->z);
    scanf("%f\n",M->T_max);
    
    param * p = malloc(sizeof(param));
    scanf("%f\n",p->sigma);
    scanf("%f\n",p->ro);
    scanf("%f\n",p->beta);

    struct ** L = struct point ** lorentz (M, p);
    aff_Traj(L, M->T_max);

    }
    return 0;
}