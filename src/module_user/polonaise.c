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

/*CODE INTERNET
struct ma_pile{
	       char info;
	       struct ma_pile *suiv;
	      };


struct ma_pile *sommet;
char p1;
char ch[20],c;
int i=0,code=0;
char tempo[2]; 


struct ma_pile *Init(struct ma_pile **sommet){
    sommet=NULL;
    return *sommet;
}

int char_to_int(char c){
    if(c=='0'){
        return code==0;
    }else{
        code=c-48;
        return code;
    }
}

char int_to_char(int int_to_ch) {
    int_to_ch+=48;
    c=(char)int_to_ch;    // converti l'ascii int_to_char en caractere
    return c;
}

void EMP(char x,struct ma_pile **sommet){
    struct ma_pile *p;
    p=(struct ma_pile *)malloc(sizeof(struct ma_pile));
    p->info=x;
    p->suiv=*sommet;
    sommet=p;
}

int DEP(struct ma_pile **sommet){
    if(*sommet==NULL){
    printf("E R R E U R ! LA PILE EST VIDE");
    }else{
    struct ma_pile *p=*sommet;
    p1=p->info;  
    sommet=p->suiv;
    free(p);
    printf("\nOPERATION SUCCESS\n");
    printf("VALEUR DEPILEE :%d\n",char_to_int(p1));
    return p1;
   }
}

void saisie(char t[1]){
    char c;
    int j1=0;
    do{
    c=getch();
    if(((c>='0')&& (c<='9')) || ((c=='*')|| (c=='-')|| (c=='+')|| (c=='/'))){
        if((c>='0')&& (c<='9')){
	    j1++;     //comptabilise les caracteres entre '0' et '9'
	    if(j1>2)
	    printf("ACTION NON AUTORISEE\n");
        }else{
            t[i]=c;
            printf("%c\n",t[i]);
            i++;
        }
	}

    if((c=='*')|| (c=='-')|| (c=='+')|| (c=='/')){
	    j1=0;
	    t[i]=c;
	    printf("%c\n",t[i]);
	    i++;
	}
    }while(c!=13);
}

void VISU(struct ma_pile *sommet){
    if(sommet!=NULL){
        struct ma_pile *p=sommet;
        while(p) {
            printf("%c ->",p->info);
            p=p->suiv; 
        }
    }else{
    printf("E R R E U R ! VEUILLEZ D'ABORD REMPLIR LA PILE ");
}

void Traitement(char t[1]){
    int k,k1,code2=0,code1=0,resultat=0;
    char c;
    for(k=0;k<i;k++){
        if ((t[k]>='0') &&(t[k]<='9'))
        EMP(t[k],&sommet);
        if((t[k]=='*')|| (t[k]=='-')|| (t[k]=='+')|| (t[k]=='/')){
            k1=1;      //on commence ? d?piler
            while((sommet!=NULL) && (k1>=0)){  //ne depile que les 2 1ere valeurs
	            DEP(&sommet);
	            tempo[k1]=p1;
	            k1--;
	        }
	        code1=char_to_int(tempo[0]);
	        code2=char_to_int(tempo[1]);
            switch (t[k]){
	            case '+':resultat=code1+code2;printf("%d+%d=%d\n",code1,code2,resultat);
		            break;
	            case '-':resultat=code1-code2;printf("%d-%d=%d\n",code1,code2,resultat);
		            break;
	            case '*':resultat=code1*code2;printf("%d*%d=%d\n",code1,code2,resultat);
		            break;
	            case '/':resultat=code1/code2;printf("%d/%d=%d   il s'agit d'une division enti?re\n",code1,code2,resultat);
		            break;
	        }
            EMP(int_to_char(resultat),&sommet);
        }
    }
}
*/