#include "MainWindow.h"

MainWindow::MainWindow()
{
    createWidgets();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createWidgets()
{
    world_widget_ = new WorldWidget(this);
    setCentralWidget(world_widget_);
}

void MainWindow::setWorldModel(const WorldPtr& world_ptr)
{
    world_widget_->setWorldModel(world_ptr);
}

void MainWindow::setRobotModel(const RobotPtr& robot_ptr)
{
    world_widget_->setRobotModel(robot_ptr);
}
