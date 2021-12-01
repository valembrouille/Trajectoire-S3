#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct position{
    float*x;
    float*y;
    float*z;
    float*tps;
};

struct parametres{
    float*a;
    float*b;
    float*c;
};

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

struct position * entree_position(float*x, float*y, float*z, float*tps){
    printf("x=");
    lireDecimal(x);
    printf("y=");
    lireDecimal(y);
    printf("z=");
    lireDecimal(z);
    printf("temps max=");
    lireDecimal(tps);
    struct position * point;
    point->x=x;
    point->y=y;
    point->z=z;
    point->tps=tps;
    return point;
}

struct parametres * entree_parametres(float*a, float*b, float*c){
    printf("a=");
    lireDecimal(a);
    printf("b=");
    lireDecimal(b);
    printf("c=");
    lireDecimal(c);
    struct parametres * param;
    param->a=a;
    param->b=b;
    param->c=c;
    return param;
}



int main(){
    float x;
    float y;
    float z;
    float tempsmax;
    float a;
    float b;
    float c;
    entree_position(&x,&y,&z,&tempsmax);
    entree_parametres(&a,&b,&c);
    printf("%f %f %f %f \n",x,y,z,tempsmax);
    printf("%f %f %f \n",a,b,c);
    return 0;
}