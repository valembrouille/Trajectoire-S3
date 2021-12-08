#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void entree_choixsyst(int a){
    printf("\nQuel systeme voulez vous utiliser?\n-Tapez 1: Lorenz\n-Tapez 2: Rossler\n-Tapez 4: Je veux rentrer mes propres parametres et variations de vitesse\n");
    //lireEntier(a);
    if (a==1){
        printf("Le systeme choisi est celui des Forces de Lorenz");
        //coord_Traj(lorenz (M, p), p->T_max);
        //splot(file)
    }else if(a==4){
        printf("Vous rentrez vous meme les coordonnees");
        //coord_Traj(polonaise (M, p), p->T_max);
    }else{
        printf("Ce numero n'est attribue a aucun systeme");
    }
}

void choix_syst(){
    
}
