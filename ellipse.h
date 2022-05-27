#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

#include <QObject>

class Ellipse : public Figure
{
    Q_OBJECT
public:
    explicit Ellipse(QPointF point,QObject *parent = nullptr);
    ~Ellipse();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ELLIPSE_H
