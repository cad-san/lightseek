#ifndef D_VIRTUAL_DIST_SENSOR_H
#define D_VIRTUAL_DIST_SENSOR_H

#include "DistSensor.h"
#include "Robot.h"

#include <boost/thread.hpp>

class VirtualDistSensor : public DistSensor
{
private:
    typedef boost::mutex::scoped_lock lock;

    RobotPtr robot_;
    int distance_;

    mutable boost::mutex sync_mutex_;

public:
    VirtualDistSensor(const RobotPtr& robot);
    virtual ~VirtualDistSensor();

    void init();
    void step();

    int getDistance() const;
};

#endif

