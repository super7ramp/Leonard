#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../state_machine/var_coord.h"
#include "../com/message_drone.h"

#define PI (float)3.141592653589793

// Offset angle, our map doesn't use an absolute reference (North)
#define OFFSET (float)PI/4.0

/**
  * \brief Compute the desired cap
  * \param point1 Start point
  * \param point2 Arrival point
  */
float computeDesiredAngle(struct coordinates_ point1, struct coordinates_ point2);

/**
  * \brief Auxiliary
  * \param point Point whose coordinates will be rotated
  * \param angle Rotation angle 
  */
struct coordinates_ computeRotation(struct coordinates_ point, float angle);

/**
  * \briel compute the sens of rotation for found desired cap
  * \param angle now
  * \param angle new
  */
float computeDirection(float angle_actuel, float angle_desire, float power, direction* move);

void computeOffsetMag(float* angle_desire, float nav_prec, float nav_suiv);

#endif // MOVEMENT_H
