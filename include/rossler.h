#ifndef __ROSSLER__
#define __ROSSLER__



Point lire_point();
Param lire_param();

Position * Creer_liste ( float T_max);
Position * rossler (Point M, Param param);
void coord_Traj(Position * L, float T_max);

#endif