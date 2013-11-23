#include <QtGui>
#include <QApplication>
#include <boost/make_shared.hpp>

#include "MainWindow.h"
#include "SquareObstacle.h"

static WorldPtr createWorld()
{
    WorldPtr world = boost::make_shared<World>(500,500);

    world->addObstacle( boost::make_shared<SquareObstacle>(100, 100, 100, 50) );
    world->addObstacle( boost::make_shared<SquareObstacle>(200, 400, 100, 50) );

    return world;
}

static RobotPtr createRobot(WorldPtr world)
{
    return boost::make_shared<Robot>(world);
}

int main(int argc, char* argv[])
{
    WorldPtr world = createWorld();
    RobotPtr robot = createRobot(world);

    QApplication app(argc, argv);
    MainWindow window;
    window.setWorldModel(world);
    window.setRobotModel(robot);

    window.show();
    return app.exec();
}
