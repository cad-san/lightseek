#include "WorldWidget.h"

#include <QPainter>
#include <QTimer>

const QColor FLOOR_COLOR(51,51,51);
const QColor EDGE_COLOR(174,238,0);
const QColor ROBOT_COLOR(1,176,240);
const QColor ARROW_COLOR(255,53,139);
const QColor OBJECT_COLOR(174,238,0);

WorldWidget::WorldWidget(QWidget* parent) : QWidget(parent)
{
    timer_ = new QTimer();
    connect(timer_, SIGNAL(timeout()), this, SLOT(onTimer()));
}

WorldWidget::~WorldWidget()
{
    delete timer_;
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
    paintRobot(painter);
}

void WorldWidget::paintField(QPainter& painter)
{
    if(!world_model_)
        return;

    /* フィールドの描画 */
    int w, h;
    world_model_->getDimension(&w, &h);

    painter.setPen(QPen(EDGE_COLOR, 4));
    painter.setBrush(FLOOR_COLOR);
    painter.drawRect(0, 0, w, h);
}

void WorldWidget::paintObjects(QPainter& painter)
{
    if(!world_model_)
        return;

    painter.setPen(QPen(OBJECT_COLOR, 2));
    painter.setBrush(FLOOR_COLOR);

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

void WorldWidget::paintRobot(QPainter& painter)
{
    if(!robot_model_)
        return;

    int x, y, angle;
    robot_model_->getPosition(&x, &y);
    robot_model_->getAngle(&angle);

    int radius;
    robot_model_->getSize(&radius);

    //アンチエイリアスセット
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(ROBOT_COLOR, 4));
    painter.setBrush(FLOOR_COLOR);

    // 円を書く
    painter.drawEllipse(x - radius, y - radius, radius * 2, radius * 2);

    // Angleを示す矢印を書く
    Geo::Point anchor = Geo::Point(x, y) + Geo::polar(radius * 2, Geo::convert_radian(angle));
    const Geo::Point points[3] = {
        anchor,
        anchor + Geo::polar(10, Geo::convert_radian(angle + 30 + 180)),
        anchor + Geo::polar(10, Geo::convert_radian(angle - 30 + 180)),
    };

    QPoint qpoints[3];
    for(int i = 0; i < 3; i++)
    {
        qpoints[i] = QPoint(points[i].x(), points[i].y());
    }

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(ARROW_COLOR, 1));
    painter.setBrush(ARROW_COLOR);

    painter.drawPolygon(qpoints, 3, Qt::WindingFill);
}

void WorldWidget::onTimer()
{
    update();
}

void WorldWidget::init()
{
    if(timer_->isActive())
        timer_->stop();
}

void WorldWidget::start()
{
    if(!timer_->isActive())
        timer_->start(50);
}

void WorldWidget::stop()
{
    if(timer_->isActive())
        timer_->stop();
}

void WorldWidget::setWorldModel(const WorldPtr& world_ptr)
{
    this->world_model_ = world_ptr;
}

void WorldWidget::setRobotModel(const RobotPtr& robot_ptr)
{
    this->robot_model_ = robot_ptr;
}
