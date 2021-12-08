#ifndef __POINT__
#define __POINT__


typedef struct _point_s * Point;

Point allouer_point();
void setPoint( Point M,float x, float y, float z );
Point creer_point( float x, float y, float z );

float getX( Point M );
float getY( Point M );
float getZ( Point M );

void setX( Point M, float n );
void setY( Point M, float n );
void setZ( Point M, float n );

#endif
