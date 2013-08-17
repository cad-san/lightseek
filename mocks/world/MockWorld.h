#ifndef D_MOCK_WORLD_H
#define D_MOCK_WORLD_H

#include "World.h"

class MockWorld : public World
{
public:
    MockWorld() {};
    virtual ~MockWorld() {};

    int getDistance(int x, int y, double angle) const
    {
        return INVALID_DISTANCE;
    }
};

typedef boost::shared_ptr<MockWorld> MockWorldPtr;

#endif
