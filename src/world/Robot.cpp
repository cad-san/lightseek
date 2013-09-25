#include "Robot.h"
#include "Geometry.h"

Robot::Robot(const WorldPtr& world_ptr) : world(world_ptr)
{
    this->x = World::INVALID_COORD;
    this->y = World::INVALID_COORD;
    this->angle = 0;
}

Robot::~Robot()
{
}

void Robot::init()
{
}

int Robot::getDistance() const
{
    lock lk(sync_mutex);
    return world->getDistance(x,y,angle);
}

void Robot::getPosition(int* x, int* y) const
{
    if(x == NULL || y == NULL)
        return;

    lock lk(sync_mutex);
    *x = this->x;
    *y = this->y;
}

void Robot::getAngle(int* angle) const
{
    if(angle == NULL)
        return;

    lock lk(sync_mutex);
    *angle = this->angle;
}

bool Robot::setPosition(const int& x, const int& y)
{
    lock lk(sync_mutex);

    this->x = x;
    this->y = y;

    return true;
}

bool Robot::setAngle(const int& angle)
{
    lock lk(sync_mutex);

    this->angle = angle;

    return true;
}

bool Robot::moveFront(const int distance)
{
    lock lk(sync_mutex);

    double radian = Geo::convert_radian(angle);
    Geo::Point curr(x, y);
    Geo::Point next = curr + Geo::polar(distance, radian);

    if(!world->isValidPosition(next.x(), next.y()))
        return false;

    this->x = static_cast<int>(next.x());
    this->y = static_cast<int>(next.y());

    return true;
}

bool Robot::rotate(const int angle)
{
    lock lk(sync_mutex);

    this->angle += angle;
    this->angle = (this->angle + 360) % 360;

    return true;
}
