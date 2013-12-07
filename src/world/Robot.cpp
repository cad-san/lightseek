#include "Robot.h"
#include "Geometry.h"

static const int DEFAULT_RADIUS = 15;

Robot::Robot(const WorldPtr& world_ptr)
    : position_(World::INVALID_COORD, World::INVALID_COORD)
    , world_(world_ptr)
{
    this->angle_ = 0;
    this->radius_ = DEFAULT_RADIUS;
}

Robot::Robot(const WorldPtr& world_ptr, int radius)
    : position_(World::INVALID_COORD, World::INVALID_COORD)
    , world_(world_ptr)
{
    this->angle_ = 0;
    this->radius_ = radius;
}

Robot::~Robot()
{
}

void Robot::init()
{
}

int Robot::getFrontDistance() const
{
    lock lk(sync_mutex_);
    return world_->getDistance(position_.x<int>(),
                               position_.y<int>(), angle_);
}

int Robot::getRightSideDistance() const
{
    lock lk(sync_mutex_);
    return world_->getDistance(position_.x<int>(),
                               position_.y<int>(), angle_ + 90);
}

int Robot::getLeftSideDistance() const
{
    lock lk(sync_mutex_);
    return world_->getDistance(position_.x<int>(),
                               position_.y<int>(), angle_ - 90);
}

void Robot::getPosition(int* x, int* y) const
{
    if(x == NULL || y == NULL)
        return;

    lock lk(sync_mutex_);
    *x = this->position_.x<int>();
    *y = this->position_.y<int>();
}

void Robot::getAngle(int* angle) const
{
    if(angle == NULL)
        return;

    lock lk(sync_mutex_);
    *angle = this->angle_;
}

void Robot::getSize(int* radius) const
{
    if(radius == NULL)
        return;
    *radius = this->radius_;
}

bool Robot::setPosition(const int& x, const int& y)
{
    lock lk(sync_mutex_);

    this->position_ = Geo::Point(x, y);

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
    Geo::Point next = position_ + Geo::polar(distance, radian);

    if(!world_->isValidPosition(next))
        return false;

    position_ = next;

    return true;
}

bool Robot::rotate(const int angle)
{
    lock lk(sync_mutex_);

    this->angle_ += angle;
    this->angle_ = (this->angle_ + 360) % 360;

    return true;
}
