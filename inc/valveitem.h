#ifndef VALVEITEM_H
#define VALVEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "Valve.hpp"

class ValveItem : public QGraphicsItem
{
    Valve* vptr;
    QRect circ;
    public:
        ValveItem(qreal x, qreal y);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = 0);
        QRectF boundingRect() const;
        void connect(Valve *);
};

#endif // VALVEITEM_H
