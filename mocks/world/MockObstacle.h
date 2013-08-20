#ifndef D_MOCK_OBSTACLE_H
#define D_MOCK_OBSTACLE_H

#include "Obstacle.h"

class MockObstacle : public Obstacle
{
public:
    MockObstacle(int x, int y, int width, int height) : Obstacle(x, y, width, height)
    {
    }

    virtual ~MockObstacle() {};

    virtual bool isInArea(int x, int y) const
    {
        return ( this->x <= x && x < this->x + this->width  ) &&
               ( this->y <= y && y < this->y + this->height );
    }

};

typedef boost::shared_ptr<MockObstacle> MockObstaclePtr;

#endif
