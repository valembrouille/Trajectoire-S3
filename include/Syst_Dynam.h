#ifndef SYST_DYNAM
#define SYST_DYNAM


struct point {
    float x;
    float y;
    float z;
    float T_max;
}

struct param {
    float sigma;
    float ro;
    float beta;
}

struct point ** Creer_liste ( float T_max);
struct point ** lorenz (struct point M, param Pram);
void aff_Traj(struct point ** L, float T_max);
#endif