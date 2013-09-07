#ifndef D_ROBOT_H
#define D_ROBOT_H

#include "World.h"

class Robot
{
private:
    int x;
    int y;
    int angle;

    WorldPtr world;

public:

    Robot(const WorldPtr& world_ptr);
    virtual ~Robot();

    void init();

    int getDistance() const;

    bool setPosition(const int& x, const int& y);
    bool setAngle(const int& angle);

    void getPosition(int* x, int* y) const;
    void getAngle(int* angle) const;

    bool moveFront(const int distance);
    bool rotate(const int angle);
};

typedef boost::shared_ptr<Robot> RobotPtr;

#endif
