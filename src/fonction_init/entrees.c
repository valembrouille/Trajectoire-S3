#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "../../include/entrees.h"

#include <string.h> // Penser à inclure string.h pour strchr()
 

int lireEntier(){
    return 1
}


int lireFinDeLigne(){
    int count =0;
    char s;
    s= getchar(); //consomme un caractère du buffer=file
    while ((s!=EOF) && (s!='\n')){
        if(!isspace(s)){
            count ++; //pas un espace
        }
        s=getchar();
    }
    return count;
}

void  lireDecimal ( float *v){
    float lu;
    int nbEff;
    do{
        lu= scanf ( "%f" ,v);
        nbEff= lireFinDeLigne ();
    } while ((lu!= 1 )&&(nbEff> 0 ));
}
