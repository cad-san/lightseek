#include "Robot.h"

Robot::Robot(const WorldPtr& worldPtr) : worldPtr(worldPtr)
{
    this->x = World::INVALID_COORD;
    this->y = World::INVALID_COORD;
    this->angle = 0.0;
}

Robot::~Robot()
{
}

void Robot::init()
{
}

int Robot::getDistance() const
{
    return worldPtr->getDistance(x,y,angle);
}

void Robot::getPosition(int* x, int* y) const
{
    if(x == NULL || y == NULL)
        return;

    *x = this->x;
    *y = this->y;
}

void Robot::getAngle(double* angle) const
{
    if(angle == NULL)
        return;

    *angle = this->angle;
}

bool Robot::setPosition(const int& x, const int& y)
{
    this->x = x;
    this->y = y;

    return true;
}

bool Robot::setAngle(const double& angle)
{
    this->angle = angle;

    return true;
}
