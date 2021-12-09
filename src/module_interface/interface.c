#include <stdio.h>
#include <stdlib.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/interface.h"


void coord_Traj(Position * L, float T_max, float dt, char* fileName){
const float inf = 1.0/0.0;
const float nan = 0.0/0.0;
    FILE *file;
    float t,x,y,z;
    file = fopen(fileName,"w");
    if (file == NULL){
         printf("Ereur ouverture fichier output \n");
    }
    
    int N = T_max / dt; //longueur de la liste = N
    Point pointI;
    for (int i=0; i<N; i++){
        t =  getT(L[i]);
        x=   getX(pointI);
        y =  getY(pointI);
        z =  getZ( pointI);
        if (t == inf || t == -inf || x == inf || x == -inf || y == inf || y == -inf || z == inf  || z == -inf ||
            t == nan || t == -nan || x == nan || x == -nan || y == nan || y == -nan || z == nan  || z == -nan  )
        {
            printf ("\n-----------------------------------------------------------------------\n");
            printf ("\n-------Valeurs tendent vers linfini . Points restants ignorés----------\n");
            printf ("\n-----------------------------------------------------------------------\n");
            break;    
        }
        pointI = getPOINT_DE_POSITION(L[i]);
        printf("%f %f %f %f\n", t, x,y,z);

        if (file != NULL){
            fprintf(file,"%lf %lf %lf %f\n", t,x,y,z);
        }
    }
    if (file != NULL){
        fclose(file);
    }
}
