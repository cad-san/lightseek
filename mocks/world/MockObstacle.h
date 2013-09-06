#ifndef D_MOCK_OBSTACLE_H
#define D_MOCK_OBSTACLE_H

#include "SquareObstacle.h"
#include "CppUTestExt/MockSupport.h"

class MockObstacle : public SquareObstacle
{
private:
    int dummy_dist;

public:
    MockObstacle(int x, int y, int width, int height)
        : SquareObstacle(x, y, width, height)
    {
        this->dummy_dist = World::INVALID_DISTANCE;
    }

    virtual ~MockObstacle() {};

    virtual int getDistance(int x, int y, int angle) const
    {
        mock("MockObstacle")
            .actualCall("getDistance")
            .withParameter("x", x)
            .withParameter("y", y)
            .withParameter("angle", angle);

        return this->dummy_dist;
    }

    void setExpectionOfGetDistance(int x, int y, int angle)
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
