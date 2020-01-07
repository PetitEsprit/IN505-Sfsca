#include "tankitem.h"
#include <QDebug>

TankItem::TankItem(qreal x, qreal y, qreal w, qreal h) : rec(x,y, w, h), itemP1(x+10, y+h-40, 30, 30, this), itemP2(x+60, y+h-40, 30, 30,this)
{}

QRectF TankItem::boundingRect() const { return QRectF(rec.x(), rec.y(), rec.width(), rec.height());}

void TankItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/)
{
    QBrush whiteb(Qt::white),blackb(Qt::black), grayb(Qt::gray);
    QPen whitep(Qt::white),blackp(Qt::black);

    bool iscurrempty;
    e_pump p1, p2;
    if(tptr)
    {
        iscurrempty = tptr->isCurrEmpty();
        p1 = tptr->getP1();
        p2 = tptr->getP2();
    }

    if(iscurrempty)painter->setPen(QPen (Qt::green));
    else{ painter->setBrush(QBrush (Qt::green)); }
    painter->drawRoundedRect(rec,10,10);

    QRectF itemP1rec = itemP1.rect();
    QRectF itemP2rec = itemP2.rect();
    if(p1 == OFF) //si éteint ..
    {

        painter->setBrush(whiteb);
        painter->drawEllipse(itemP1rec);
        painter->setPen(blackp);
    }
    else if(p1 == ON) //si allumé ..
    {
        painter->setBrush(blackb);
        painter->drawEllipse(itemP1rec);
        painter->setPen(whitep);
    }
    else if(p1 == BROKEN)//si broken ..
    {
        painter->setBrush(grayb);
        painter->drawEllipse(itemP1rec);
        painter->setPen(whitep);
    }
    painter->drawText(itemP1rec.x()+7, itemP1rec.y()+20, "P1");

    if(p2 == OFF)
    {
        painter->setBrush(whiteb);
        painter->drawEllipse(itemP2rec);
        painter->setPen(blackp);
    }
    else if(p2 == ON)
    {
        painter->setBrush(blackb);
        painter->drawEllipse(itemP2rec);
        painter->setPen(whitep);
    }
    else if(p2 == BROKEN)
    {
        painter->setBrush(grayb);
        painter->drawEllipse(itemP2rec);
        painter->setPen(whitep);
    }
    painter->drawText(itemP2rec.x()+7, itemP2rec.y()+20, "P2");

    painter->setPen(blackp);
    painter->drawText(itemP1rec.x()+20, itemP1rec.y()-20, tptr->name);

    //qDebug() << tptr->name << '\n';
}

void TankItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    bool isempty;
    e_pump p1, p2;
    if(tptr)
    {
        isempty = tptr->isEmpty();
        p1 = tptr->getP1();
        p2 = tptr->getP2();
    }

    QPointF mousep = event->lastScenePos();
    if(itemP1.contains(mousep))
    {
       tptr->setP1((e_pump) ((p1+1) % 3));
    }

    else if(itemP2.contains(mousep))
    {
       tptr->setP2((e_pump) ((p2+1) % 3));
    }
    else
    {
        isempty ? tptr->fill() : tptr->drain();
    }
    emit pressed();
}

void TankItem::connect(Tank* t)
{
    tptr = t;
}
