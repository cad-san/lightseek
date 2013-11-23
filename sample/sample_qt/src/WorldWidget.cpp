#include "WorldWidget.h"

WorldWidget::WorldWidget(QWidget* parent) : QWidget(parent)
{
}

WorldWidget::~WorldWidget()
{
}

void WorldWidget::setWorldModel(const WorldPtr& world_ptr)
{
    this->world_model_ = world_ptr;
}

void WorldWidget::setRobotModel(const RobotPtr& robot_ptr)
{
    this->robot_model_ = robot_ptr;
}
