#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

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

void lireEntier(int *n){
    int lu;
    int nbEff;
    do {
        lu=scanf("%d",n);
        nbEff=lireFinDeLigne();
    } while((lu!=1)&&(nbEff>0));
}

void entree_choixsyst(int * a){
    printf("\nQuel systeme voulez vous utiliser?\n-Tapez 1: Les forces de Lorenz\n-Tapez 2: \n-Tapez 4: Je veux rentrer mes propres parametres et variations de vitesse\n");
    lireEntier(a);
    if (*a==1){
        printf("Le systeme choisi est celui des Forces de Lorenz");
    }else if(*a==4){
        printf("Vous rentrez vous meme les coordonnees");
    }else{
        printf("Ce numero n'est attribue a aucun systeme");
    }
}

void choix_syst(){
    
}

int main(){
    int a;
    entree_choixsyst(&a);

    return 0;
}