#include <stdio.h>
#include <math.h>
#include "movement.h"

float computeDesiredAngle(struct coordinates_ point1, struct coordinates_ point2) {
    float desiredAngle;

    // Warning: we need to make a rotation because the given demo map is not made
    // with the North as reference
    // Just comment this if the map and the beacon geolocation are properly done
    struct coordinates_ rotatedPoint1 = computeRotation(point1, OFFSET);
    struct coordinates_ rotatedPoint2 = computeRotation(point2, OFFSET);
    float diffx = rotatedPoint2.x - rotatedPoint1.x;
    float diffy = rotatedPoint2.y - rotatedPoint1.y;

    //printf("Diff x = %.2f - Diff y = %.2f\n\n", diffx, diffy);

    if(diffy == 0.0)
        desiredAngle = 0.0;
    else
        desiredAngle = atanf(fabs(diffx)/fabs(diffy)); //calcul de l'angle

    //printf("Calcul angle desire (rad)   : %2.f\n", desiredAngle);
    desiredAngle = desiredAngle / (PI/2) * 180.0 / 2.0; //radians en dergrées
    //printf("Calcul angle desire (degree): %2.f\n", desiredAngle);

    if(diffx == 0.0 && diffy > 0.0)
        desiredAngle = 0.0;
    else if(diffx == 0.0 && diffy < 0.0)
        desiredAngle = 180.0;
    else if(diffy == 0.0 && diffx > 0.0)
        desiredAngle = 90.0;
    else if(diffy == 0.0 && diffx < 0.0)
        desiredAngle = -90.0;
    else if(diffx>0.0 && diffy>0.0) //si quadrant haut droite
        desiredAngle = desiredAngle;
    else if (diffx<0.0 && diffy>0.0) //si quadrant haut gauche
        desiredAngle = - desiredAngle;
    else if (diffx>0.0 && diffy<0.0) //Si quadrant bas à droite
        desiredAngle = 180.0 - desiredAngle;
    else if (diffx<0.0 && diffy<0.0) //Si quadrant bas gauche
        desiredAngle = -180.0 + desiredAngle;

    //printf("Calcul angle desire final v0.1 : %2.f\n", desiredAngle);

    return desiredAngle;
}

struct coordinates_ computeRotation(struct coordinates_ point, float angle) {

    struct coordinates_ rotatedCoordinates;
    //printf("Old x = %.2f - Old y = %.2f\n\n", point.x, point.y);
    rotatedCoordinates.x = point.x*cosf(angle) + point.y*sinf(angle);
    rotatedCoordinates.y = -point.x*sinf(angle) + point.y*cosf(angle);
    //printf("New x = %.2f - New y = %.2f\n\n", rotatedCoordinates.x, rotatedCoordinates.y);

    return rotatedCoordinates;
}

float computeDirection(float angle_actuel, float angle_desire, float power, direction* move)
{
	if(angle_actuel < 0 && angle_desire > 0){
      if((angle_desire - angle_actuel)>180)
        *move = LEFT;
      else
        *move = RIGHT;
    }
    else if(angle_actuel > 0 && angle_desire < 0){
      if((angle_actuel - angle_desire) > 180)
        *move = RIGHT;
      else
        *move = LEFT;
    }
    else if(angle_actuel > 0 && angle_desire > 0)
      *move = RIGHT;
    else if(angle_actuel < 0 && angle_desire < 0)
      *move = LEFT;
    
    return power;
}

void computeOffsetMag(float* angle_desire, float nav_prec, float nav_suiv)
{
    /*
  if(*angle_desire > nav_prec)// (180.0 + Main_Nav.magneto.heading_unwrapped)) 
  {
    *angle_desire = *angle_desire - 360.0;
  }
    else if(*angle_desire < nav_suiv) 
  {
    *angle_desire = *angle_desire + 360.0;
  }
  */
}
