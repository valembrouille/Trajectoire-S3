#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/point.h"
#include "../../include/position.h"
#include "../../include/entrees.h"
#include "../../include/param.h"
#include "../../include/user.h"


int lireFinDeLigne(){
    int count =0;
    char s;
    s= getchar();
    while ((s!=EOF) && (s!='\n')){
        if(!isspace(s)){
            count ++;
        }
        s=getchar();
    }
    return count;
}

void  lire_carac ( char *v){
    int lu;
    int nbEff;
    do{
        lu= scanf ( "%c" ,v);
        nbEff= lireFinDeLigne ();
    } while ((lu!= 1 )&&(nbEff> 0 ));
}


void entree_polo(char*dx,char*dy,char*dz){
    printf("Entrez vos formules en notation polonaise inversee.\n Ex: (b x y - *) = ((y-x)*b)\n");
    printf("pour calculer la variation de vitesse selon x:\n");
    lire_carac(dx);
    printf("pour calculer la variation de vitesse selon y:\n");
    lire_carac(dy);
    printf("pour calculer la variation de vitesse selon z:\n");
    lire_carac(dz);
} 
/* On rentre les chaines de caractères*/


/*
int param_chaine_ok(char*c){
    int i=0;
    while (c[i]!=0){
        if (c[i]!='a'&& c[i]!='b'&& c[i]!='c'&& c[i]!='x'&& c[i]!='y'&& c[i]!='z'&& c[i]!='+'&& c[i]!='-'&& c[i]!='*'&& c[i]!='/'){
            return 1;
        }
    }
    return 0;
}*/

int forme_chaine_ok(char*c,int i){
    if (c[i]==0){
        return 0;
    }else if(c[i]=='a'|| c[i]=='b'|| c[i]=='c'|| c[i]=='x'|| c[i]=='y'|| c[i]=='z'){
        if(c[i-1]=='a'|| c[i-1]=='b'|| c[i-1]=='c'|| c[i-1]=='x'|| c[i-1]=='y'|| c[i-1]=='z'|| i==0){
            forme_chaine_ok(c,i+1);
        }else{
            return 1;
        }
    }else if(c[i]=='+'|| c[i]=='-'|| c[i]=='*'|| c[i]=='/'){
        if (c[i+1]=='+'|| c[i+1]=='-'|| c[i+1]=='*'|| c[i+1]=='/'){
            forme_chaine_ok(c,i+1);
        }else{
            return 1;
        }
    }
}
/* on teste les chaines*/


/*Il faut utiliser les piles*/


/* TEST DE CODE
char polonaise_inv(char*c){
    char res= 0;
    if (param_chaine_ok(c)==1 && forme_chaine_ok(c,0)==1){
        return 'error';
    }else{
        int j =0;
        for (int i=0;(c[i]!='+'|| c[i]!='-'|| c[i]!='*'|| c[i]!='/');i++){
            j =i;
        } 
        int i=0;
        while (c[i]!=0){
            if (c[i]=='x'){
                
            }else if(c[i]=='y'){
                res='y';
            }
        }
    }
}
*/

