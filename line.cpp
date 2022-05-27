#include "line.h"



Line::Line(QPointF point, QObject *parent):
    Figure(point, parent)
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black , 2));
    painter->drawLine(getStartPoint().x() , getStartPoint().y() , getEndPoint().x() ,getEndPoint().y() );
}
