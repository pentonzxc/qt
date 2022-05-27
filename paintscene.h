#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:

    enum Draw{
        RectangleMode,
        EllipseMode,
        LineMode,
        DrawMode,
        EditMode
    };

    explicit PaintScene(QObject *parent = nullptr);
    int getAction();
    void setAction(int type_);


    static int penWidth;
    static int penColor;
    static int currentAction;
private:
    Figure* figure;
    QPointF oldPos;


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
