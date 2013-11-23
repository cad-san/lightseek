#include "WorldWidget.h"

#include <QPainter>

WorldWidget::WorldWidget(QWidget* parent) : QWidget(parent)
{
}

WorldWidget::~WorldWidget()
{
}

QSize WorldWidget::sizeHint() const
{
    int w = 500, h = 500;

    if(world_model_)
        world_model_->getDimension(&w, &h);

    return QSize(w, h);
}

void WorldWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    paintField(painter);
    paintObjects(painter);
}

void WorldWidget::paintField(QPainter& painter)
{
    if(!world_model_)
        return;

    /* フィールドの描画 */
    int w, h;
    world_model_->getDimension(&w, &h);

    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, w, h);
}

void WorldWidget::paintObjects(QPainter& painter)
{
    if(!world_model_)
        return;

    /* オブジェクトの描画 */
    std::vector<ObstaclePtr> obstacles = world_model_->getObstacleList();
    std::vector<ObstaclePtr>::iterator it = obstacles.begin();
    while( it != obstacles.end() )
    {
        int x, y, w, h;
        it->get()->getPosition(&x, &y);
        it->get()->getDimension(&w, &h);

        painter.drawRect(x, y, w, h);
        ++it;
    }
}

void WorldWidget::setWorldModel(const WorldPtr& world_ptr)
{
    this->world_model_ = world_ptr;
}

void WorldWidget::setRobotModel(const RobotPtr& robot_ptr)
{
    this->robot_model_ = robot_ptr;
}
