#ifndef D_MOCK_OBSTACLE_H
#define D_MOCK_OBSTACLE_H

#include "Obstacle.h"
#include "CppUTestExt/MockSupport.h"

class MockObstacle : public Obstacle
{
private:
    int dummy_dist;

public:
    MockObstacle(int x, int y, int width, int height)
        : Obstacle(x, y, width, height)
    {
        this->dummy_dist = World::INVALID_DISTANCE;
    }

    virtual ~MockObstacle() {};

    virtual bool isInArea(int x, int y) const
    {
        return ( this->x <= x && x < this->x + this->width  ) &&
               ( this->y <= y && y < this->y + this->height );
    }

    virtual bool isInArea(const Obstacle& obstacle) const
    {
        Geo::Point min = getMinPoint();
        Geo::Point max = getMaxPoint();

        return ( obstacle.isInArea(min.x(), min.y()) || obstacle.isInArea(min.x(), max.y()) ||
                 obstacle.isInArea(max.x(), min.y()) || obstacle.isInArea(max.x(), max.y()) );
    }

    virtual int getDistance(int x, int y, double angle) const
    {
        mock("MockObstacle")
            .actualCall("getDistance")
            .withParameter("x", x)
            .withParameter("y", y)
            .withParameter("angle", angle);

        return this->dummy_dist;
    }

    void setExpectionOfGetDistance(int x, int y, double angle)
    {
        mock("MockObstacle")
            .expectOneCall("getDistance")
            .withParameter("x", x)
            .withParameter("y", y)
            .withParameter("angle", angle);
    }

    void setDummyDistance(int dummy_dist)
    {
        this->dummy_dist = dummy_dist;
    }
};

typedef boost::shared_ptr<MockObstacle> MockObstaclePtr;

#endif
