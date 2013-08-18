#ifndef D_ROBOT_H
#define D_ROBOT_H

#include "World.h"

class Robot
{
private:
    int x;
    int y;
    double angle;

    WorldPtr worldPtr;

public:

    Robot(const WorldPtr& worldPtr);
    virtual ~Robot();

    void init();

    int getDistance() const;

    bool setPosition(const int& x, const int& y);
    bool setAngle(const double& angle);

    void getPosition(int* x, int* y) const;
    void getAngle(double* angle) const;
};

#endif
