#ifndef D_MOCK_ACTION_H
#define D_MOCK_ACTION_H

#include "Action.h"
#include "CppUTestExt/MockSupport.h"

class MockAction : public Action
{
public:
    MockAction() {}
    virtual ~MockAction() {}

    virtual bool moveFront(const int speed)
    {
        mock("MockAction")
            .actualCall("moveFront")
            .withParameter("speed", speed);

        return mock("MockAction").intReturnValue();
    }

    virtual bool rotate(const int angle)
    {
        mock("MockAction")
            .actualCall("rotate")
            .withParameter("angle", angle);

        return mock("MockAction").intReturnValue();
    }

    void setExpectionOfMoveFront(int speed, bool ret_value)
    {
        mock("MockAction")
            .expectOneCall("moveFront")
            .withParameter("speed", speed)
            .andReturnValue(ret_value);
    }

    void setExpectionOfRotate(int angle, bool ret_value)
    {
        mock("MockAction")
            .expectOneCall("rotate")
            .withParameter("angle", angle)
            .andReturnValue(ret_value);
    }
};

typedef boost::shared_ptr<MockAction> MockActionPtr;

#endif
