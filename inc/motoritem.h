#ifndef MOTORITEM_H
#define MOTORITEM_H

#include <QPainter>
#include <QGraphicsObject>
#include "Motor.hpp"

class MotorItem :  public QGraphicsObject
{
        Motor* mptr;
        QRect rec;
    public:
        MotorItem(qreal x, qreal y);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = 0);
        QRectF boundingRect() const;
        void connect(Motor *);


};

#endif // MOTORITEM_H
