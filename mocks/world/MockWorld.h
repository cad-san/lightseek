#ifndef D_MOCK_WORLD_H
#define D_MOCK_WORLD_H

#include "World.h"
#include "CppUTestExt/MockSupport.h"

class MockWorld : public World
{
private:
    int dummy_dist_;

public:
    MockWorld() : World()
    {
        this->dummy_dist_ = INVALID_DISTANCE;
    }

    virtual ~MockWorld() {}

    void setDummyDistance(int dummy_dist)
    {
        this->dummy_dist_ = dummy_dist;
    }

    int getDistance(int x, int y, int angle) const
    {
        mock("MockWorld")
            .actualCall("getDistance")
            .withParameter("x", x)
            .withParameter("y", y)
            .withParameter("angle", angle);

        return this->dummy_dist_;
    }

    void setExpectionOfGetDistance(int x, int y, int angle)
    {
        mock("MockWorld")
            .expectOneCall("getDistance")
            .withParameter("x", x)
            .withParameter("y", y)
            .withParameter("angle", angle);
    }
};

typedef boost::shared_ptr<MockWorld> MockWorldPtr;

#endif
