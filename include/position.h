#ifndef __POSITION__
#define __POSITION__

typedef struct _position_s * Position;

Position creer_position( float x, float y, float z, float t);

void getPOINT( Position pos, Point a );
void getT( Position pos, float a );

void setPOINT( Position pos, Point M );
void setT( Position pos, float n );


#endif