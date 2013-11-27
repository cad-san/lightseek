#ifndef D_ROBOT_H
#define D_ROBOT_H

#include "World.h"
#include <boost/thread.hpp>

class Robot
{
private:
    typedef boost::mutex::scoped_lock lock;

    int x_;
    int y_;
    int angle_;

    int radius_;
    WorldPtr world_;
    mutable boost::mutex sync_mutex_;

public:

    Robot(const WorldPtr& world_ptr);
    Robot(const WorldPtr& world_ptr, int radius);
    virtual ~Robot();

    void init();

    int getDistance() const;

    bool setPosition(const int& x, const int& y);
    bool setAngle(const int& angle);

    void getPosition(int* x, int* y) const;
    void getAngle(int* angle) const;
    void getSize(int* radius) const;

    bool moveFront(const int distance);
    bool rotate(const int angle);
};

typedef boost::shared_ptr<Robot> RobotPtr;

#endif
