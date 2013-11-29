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
    int front_dist_;
    int right_dist_;
    int left_dist_;

    mutable boost::mutex sync_mutex_;

public:
    VirtualDistSensor(const RobotPtr& robot);
    virtual ~VirtualDistSensor();

    void init();
    void step();

    int getFrontDistance() const;
    int getLeftSideDistance() const;
    int getRightSideDistance() const;

};

#endif

