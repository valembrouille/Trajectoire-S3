#ifndef __POINT__
#define __POINT__


typedef struct _point_s * Point;

Point creer_point( float x, float y, float z );

void getX( Point M, float a );
void getY( Point M, float a );
void getZ( Point M, float a );

void setX( Point M, float n );
void setY( Point M, float n );
void setZ( Point M, float n );

#endif
