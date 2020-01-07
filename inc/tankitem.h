#ifndef TANKITEM_H
#define TANKITEM_H

#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "Tank.hpp"

class TankItem : public QGraphicsObject
{
    Q_OBJECT
    Tank* tptr;
    QRect rec;
    QGraphicsEllipseItem itemP1;
    QGraphicsEllipseItem itemP2;

    public:
        TankItem(qreal x, qreal y, qreal w, qreal h);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = 0);
        QRectF boundingRect() const;
        void connect(Tank *);
        void setFreeMode(bool m);
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent * event);
    signals:
        void pressed();

};

#endif // TANKITEM_H
