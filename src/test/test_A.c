#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

    int choix;
    float x;
    float y;
    float z;
    float tempsmax;
    float a;
    float b;
    float c;
    entree_choixsyst(&choix);
    entree_position(&x,&y,&z,&tempsmax);
    entree_parametres(&a,&b,&c);
    printf("%f %f %f %f \n",x,y,z,tempsmax);
    printf("%f %f %f \n",a,b,c);

    return 0;
}