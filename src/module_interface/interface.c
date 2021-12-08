#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/interface.h"


void coord_Traj(Position * L, float T_max, float dt){
    int N = T_max / dt; //longueur de la liste = N
    Point pointI;
    for (int i=0; i<N; i++){
        pointI = getPOINT_DE_POSITION(L[i]);
        printf("%f %f %f %f\n", getT(L[i]), getX(pointI),getY(pointI),getZ( pointI));
    }
}
