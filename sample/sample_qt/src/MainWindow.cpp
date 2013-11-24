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

void MainWindow::init()
{
    if(env_)
        env_->init();
}

void MainWindow::start()
{
    if(env_)
        env_->start();
}

void MainWindow::stop()
{
    if(env_)
        env_->stop();
}

void MainWindow::setWorldModel(const WorldPtr& world_ptr)
{
    world_widget_->setWorldModel(world_ptr);
}

void MainWindow::setRobotModel(const RobotPtr& robot_ptr)
{
    world_widget_->setRobotModel(robot_ptr);
}

void MainWindow::setEnvironment(const EnvironmentPtr& env_ptr)
{
    env_ = env_ptr;
}
