#ifndef __POSITION__
#define __POSITION__
typedef struct _position_s{
    Point point;
    float t;
} position_s ;

typedef struct _position_s *Position;

Position creer_position( float x, float y, float z, float t);

Point getPOINT( Position M );
float getT( Position pos);

void setPOINT( Position pos, Point M );
void setT( Position pos, float n );


#endif