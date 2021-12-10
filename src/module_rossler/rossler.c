#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/rossler.h"


Position * rossler (Point M, Param p, float dt){
  
    float a,b,c,T_max, t;
    a= getA(p );
    b= getB(p);
    c= getC(p);
    T_max = getT_MAX(p);
    int N = T_max / dt;

    Position * L = Creer_liste_position( getT_MAX(p),dt );
 
    setPOINT_Dans_Position(L[0],M );

    Point pointI;
    Point pointIMoin1;
    
    for (int i=1; i<N; i++){
        pointI = getPOINT_DE_POSITION(L[i]);
        pointIMoin1 = getPOINT_DE_POSITION(L[i-1]);
         
        setX (pointI, getX(pointIMoin1) + (- getY(pointIMoin1) - getZ(pointIMoin1)) * dt);
        setY(pointI,getY(pointIMoin1) + (getX(pointIMoin1) + a * getY(pointIMoin1)) * dt);
        setZ(pointI,getZ(pointIMoin1) + (b + getZ(pointIMoin1) * (getX(pointIMoin1) - c )) * dt);

        t = getT(L[i-1]);
        setT( L[i] , t+dt );
    }
    return L;
}
