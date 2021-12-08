#ifndef __LORENZ__
#define __LORENZ__



Point lire_point();
Param lire_param();


//Position * Creer_liste ( float T_max);
Position * lorenz (Point M, Param param, float dt);
void coord_Traj(Position * L, float T_max, float dt);

#endif