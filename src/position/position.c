#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"

typedef struct _position_s{
    Point point;
    float t;
} position_s ;

Position creer_position( float x, float y, float z, float t){
    Position pos = malloc(sizeof(position_s));
    pos->t = t;
    pos->point = creer_point(x, y, z);
    return pos;
}

Point getPOINT_DE_POSITION( Position pos ){
   return pos->point;
}
float getT( Position pos ){
    return pos->t;
}

void setPOINT_Dans_Position( Position pos, Point M ){
 
    setX(pos->point , getX(M));

    setY(pos->point , getY(M));

    setZ(pos->point,  getZ(M));    

}
void setT( Position pos, float n ){
    pos->t = n;
}

Position * Creer_liste_position ( float T_max, float dt){
    //float dt = 0.01;
    int N = T_max / dt;  //fréquence de calcul sur [0,T_max]
    Position * L = malloc( (N + 1) * sizeof(Position) );   //liste de coordonnées en fontion du temps
   // printf (" N= %d N * sizeof(Position) = %ld \n",N,  (N+1) * sizeof(Position)  );
    for (int i=0; i < N + 1; i++){
  //printf ("creer_liste_9 \n");
        L[i]= malloc(sizeof(position_s));
        L[i]->point = allouer_point();
    }
  //printf ("creer_liste_10 \n");
    return L;
}
