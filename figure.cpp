#include "figure.h"

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    connect(this , &Figure::pointChanged , this , &Figure::updateRomb);


    this->setFlags(QGraphicsItem::ItemIsSelectable|
                   QGraphicsItem::ItemIsMovable |  QGraphicsItem::ItemSendsGeometryChanges);


}

QPointF Figure::getStartPoint() const
{
    return startPoint;
}

void Figure::setStartPoint(QPointF newStartPoint)
{
    startPoint = mapFromScene(newStartPoint);
    emit pointChanged();
}

QPointF Figure::getEndPoint() const
{
    return endPoint;
}

void Figure::setEndPoint(QPointF newEndPoint)
{
    endPoint = mapFromScene(newEndPoint);
    emit pointChanged();

}

void Figure::updateRomb()
{
    this->update((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
                 (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
                 qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
                 qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}

QRectF Figure::boundingRect() const
{
    return QRectF((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
                      (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
                      qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
                  qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);

}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);

}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);

}
