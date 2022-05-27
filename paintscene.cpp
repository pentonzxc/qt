#include "ellipse.h"
#include "line.h"
#include "paintscene.h"
#include "rectangle.h"



int PaintScene::penWidth  = 2;
int PaintScene::penColor  = Qt::black;
int PaintScene::currentAction = EditMode;

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

int PaintScene::getAction()
{
    return currentAction;
}

void PaintScene::setAction(int type_)
{
    currentAction = type_;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch(currentAction)
    {
      case RectangleMode:
      {
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        figure = item;
        this->addItem(figure);
      }

      case EllipseMode:
      {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        figure = item;
        this->addItem(figure);
      }

      case LineMode:
      {
        Line *item = new Line(event->scenePos());
        item->setPos(event->pos());
        figure = item;
        this->addItem(figure);
      }
      case DrawMode:
      {
        addEllipse(event->scenePos().x() - 5,
                     event->scenePos().y() - 5,
                     10,
                     10,
                     QPen(Qt::NoPen));
         oldPos = event->scenePos();
      }
      default:
      {
        QGraphicsScene::mousePressEvent(event);
      }

    }
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch(currentAction){
    case EditMode:
    {

            QGraphicsScene::mouseMoveEvent(event);
    }
    case DrawMode:{
        addLine(oldPos.x(),
                    oldPos.y(),
                    event->scenePos().x(),
                    event->scenePos().y(),
                    QPen(Qt::black,2,Qt::SolidLine,Qt::RoundCap));
            oldPos = event->scenePos();
            break;
    }
    default:{
        figure->setEndPoint(event->scenePos());
    }
}
    this->update(QRectF(0,0,this->width(), this->height()));
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}
