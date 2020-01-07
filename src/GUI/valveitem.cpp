#include "valveitem.h"

ValveItem::ValveItem(qreal x, qreal y) : circ(x,y,30,30)
{}

void ValveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QBrush (Qt::black));
    painter->drawEllipse(circ);
    painter->setBrush(QBrush (Qt::white));
    if(!vptr) return ;
    if(!vptr->isClosed())
        painter->drawRect(circ.x()+circ.width()/2-2,circ.y(),4,circ.height());
    else {painter->drawRect(circ.x(),circ.y()+circ.height()/2,circ.width(),4);}
    painter->setPen(QPen (Qt::black));
    painter->drawText(circ.x(), circ.y(), vptr->name);
}

QRectF ValveItem::boundingRect() const
{
    return circ;
}

void ValveItem::connect(Valve* v)
{
    vptr = v;
}
