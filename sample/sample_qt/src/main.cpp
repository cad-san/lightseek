#include <QtGui>
#include <QApplication>
#include <boost/make_shared.hpp>

#include "MainWindow.h"
#include "SquareObstacle.h"

#include "Action.h"
#include "VirtualAction.h"
#include "VirtualDistSensor.h"

#include "Agent.h"
#include "Behavior.h"
#include "CrashAvoidBehavior.h"
#include "GoStraightBehavior.h"

#include "Environment.h"
#include "ThreadedSensor.h"

static WorldPtr createWorld()
{
    WorldPtr world = boost::make_shared<World>(500,500);

    world->addObstacle( boost::make_shared<SquareObstacle>(100, 100, 100, 50) );
    world->addObstacle( boost::make_shared<SquareObstacle>(200, 400, 100, 50) );

    return world;
}

static RobotPtr createRobot(WorldPtr world)
{
    RobotPtr robot = boost::make_shared<Robot>(world);
    robot->setInitPosition(250,250);
    robot->setInitAngle(0);
    return robot;
}

static ActionPtr createAction(RobotPtr robot)
{
    return boost::make_shared<VirtualAction>(robot);
}

static DistSensorPtr createDistSensor(RobotPtr robot)
{
    return boost::make_shared<VirtualDistSensor>(robot);
}

static AgentPtr createAgent(DistSensorPtr dist, ActionPtr action)
{
    boost::shared_ptr<Agent> agent = boost::make_shared<Agent>();

    agent->addBehavior(boost::make_shared<GoStraightBehavior>(0x01, dist, action));
    agent->addBehavior(boost::make_shared<CrashAvoidBehavior>(0x02, dist, action));

    return boost::make_shared<Thread>(agent);
}

static EnvironmentPtr createEnvironment(DistSensorPtr sensor)
{
    EnvironmentPtr env = boost::make_shared<Environment>();
    env->addSensor("distance", boost::make_shared<ThreadedSensor>("distance", sensor));
    return env;
}

int main(int argc, char* argv[])
{
    // Virtual Worldの作成
    WorldPtr world = createWorld();
    RobotPtr robot = createRobot(world);

    // Agentの作成
    ActionPtr     action = createAction(robot);
    DistSensorPtr sensor = createDistSensor(robot);
    EnvironmentPtr env   = createEnvironment(sensor);
    AgentPtr       agent = createAgent(sensor, action);

    // 初期化
    env->init();
    agent->init();
    robot->init();

    QApplication app(argc, argv);
    MainWindow window;
    window.setWorldModel(world);
    window.setRobotModel(robot);
    window.setEnvironment(env);
    window.setAgent(agent);

    window.show();
    return app.exec();
}
