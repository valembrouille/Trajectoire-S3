#include <stdio.h>
#include <stdlib.h>
#include "../../include/position.h"
#include "../../include/point.h"

typedef struct _position_s{
    Point point;
    float t;
} position_s ;

Position creer_position( float x, float y, float z, float t){
    Position pos = malloc(sizeof(position_s));
    pos->t = t;
    pos->point = creer_point(x, y, z);
    return pos;
}