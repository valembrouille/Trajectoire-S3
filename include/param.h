#ifndef __Param__
#define __Param__



typedef struct _param_s * Param;

Param creer_param( float a, float b, float c, float T_max);

void getA( Param p, float a );
void getB( Param p, float a );
void getC( Param p, float a );
void getT_MAX( Param p, float a );

void setA( Param p, float n );
void setB( Param p, float n );
void setT_MAX( Param p, float n );

#endif