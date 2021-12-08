#include <stdio.h>
#include <stdlib.h>
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/interface.h"
#include "../../include/lorenz.h"
//#include "../../include/rossler.h"

int main (){
    printf("\nQuel systeme voulez vous utiliser?\n-Tapez 1: Lorenz\n-Tapez 2: Rossler\n-Tapez 3: Je veux rentrer mes propres parametres et variations de vitesse\n");
    int a;
    float dt = 0.01;
    Position *pos;
    Point M;
    Param param ;
    a= lireEntier();
    printf("Le système choisi est %d", a);
    while ( a != 1 && a != 2 && a!=3){
        printf("Veuillez choisir un système de la LISTE\n");
        a = lireEntier();
        
    }
   // printf("Le système choisi est %d", a);


    if (a==1){
        printf("Le systeme choisi est celui des Forces de Lorenz\n");
        M = lire_point();
        param = lire_param();
        pos =  lorenz ( M,  param, dt);
        
        coord_Traj(pos , getT_MAX(param),dt);
    
    }else if (a==2){
        printf("Le systeme choisi est celui des Forces de Rossler");
        Point M = lire_point();
        Param param = lire_param();
        //rossler ( M, param ) ;
        //coord_Traj(rossler (M, param), getT(param));

    }else {
        printf("Vous rentrez vous même les coordonnées");
        //coord_Traj(polonaise (M, p), p->T_max);
    }
    //il manque la librairie d'interfaçage entre le programme et le gnuplot pour le moment
    //à ce stade le programme:
    // 1.  demande à l'utilisateur de choisir un système de la liste affichié, 
    // 2.  demande à l'utilisateur d'initialiser les paramètres et le point initial 
    // 3.  calcule les coordonnées en fonction du temps selon le système choisi
    // 4.  les affiche selon le format demandé par gnuplot sur l'écran (sortie pas encore dirigée dans un fichier) 
    return 0;
}

