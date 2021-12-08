#ifndef __Param__
#define __Param__
 

typedef struct _param_s * Param;

Param allouer_param();
void setParam( Param p ,float a, float b, float c, float T_max );
Param creer_param( float a, float b, float c, float T_max);

float getA( Param p );
float getB( Param p );
float getC( Param p );
float getT_MAX( Param p );

void setA( Param p, float n );
void setB( Param p, float n );
void setT_MAX( Param p, float n );

#endif