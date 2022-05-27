#include "rectangle.h"


Rectangle::Rectangle(QPointF point, QObject *parent):
    Figure(point , parent)
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black , 2));


    QRectF rect(getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x(),
                getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y(),
                qAbs(getEndPoint().x() - getStartPoint().x()),
                qAbs(getEndPoint().y() - getStartPoint().y()));

    painter->drawRect(rect);
}
