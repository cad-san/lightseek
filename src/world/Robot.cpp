#include "Robot.h"
#include "Geometry.h"

Robot::Robot(const WorldPtr& world_ptr) : world_(world_ptr)
{
    this->x_ = World::INVALID_COORD;
    this->y_ = World::INVALID_COORD;
    this->angle_ = 0;
}

Robot::~Robot()
{
}

void Robot::init()
{
}

int Robot::getDistance() const
{
    lock lk(sync_mutex_);
    return world_->getDistance(x_, y_, angle_);
}

void Robot::getPosition(int* x, int* y) const
{
    if(x == NULL || y == NULL)
        return;

    lock lk(sync_mutex_);
    *x = this->x_;
    *y = this->y_;
}

void Robot::getAngle(int* angle) const
{
    if(angle == NULL)
        return;

    lock lk(sync_mutex_);
    *angle = this->angle_;
}

bool Robot::setPosition(const int& x, const int& y)
{
    lock lk(sync_mutex_);

    this->x_ = x;
    this->y_ = y;

    return true;
}

bool Robot::setAngle(const int& angle)
{
    lock lk(sync_mutex_);

    this->angle_ = angle;

    return true;
}

bool Robot::moveFront(const int distance)
{
    lock lk(sync_mutex_);

    double radian = Geo::convert_radian(angle_);
    Geo::Point curr(x_, y_);
    Geo::Point next = curr + Geo::polar(distance, radian);

    if(!world_->isValidPosition(next))
        return false;

    this->x_ = static_cast<int>(next.x());
    this->y_ = static_cast<int>(next.y());

    return true;
}

bool Robot::rotate(const int angle)
{
    lock lk(sync_mutex_);

    this->angle_ += angle;
    this->angle_ = (this->angle_ + 360) % 360;

    return true;
}
