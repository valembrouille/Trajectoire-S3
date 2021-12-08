#ifndef __POSITION__
#define __POSITION__


typedef struct _position_s *Position;

Position * Creer_liste_position ( float T_max, float dt);
Position creer_position( float x, float y, float z, float t);

Point getPOINT_DE_POSITION( Position M );
float getT( Position pos);

void setPOINT_Dans_Position( Position pos, Point M );
void setT( Position pos, float n );


#endif