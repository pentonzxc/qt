#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPen>
#include <QPainter>

class Figure : public QObject , public QGraphicsItem
{
    Q_OBJECT

public:
    Figure(QPointF point, QObject *parent);



    QPointF getStartPoint() const;
    void setStartPoint(QPointF newStartPoint);

    QPointF getEndPoint() const;
    void setEndPoint(QPointF newEndPoint);

public slots:
    void updateRomb();

signals:
    void pointChanged();


protected:
    QColor color;
    QPen pen;
    QPointF startPoint;
    QPointF endPoint;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FIGURE_H
