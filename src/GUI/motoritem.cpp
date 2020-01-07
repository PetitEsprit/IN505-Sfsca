#include "motoritem.h"
#include <QDebug>

MotorItem::MotorItem(qreal x, qreal y) : rec(x,y,40,80)
{}


void MotorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(!mptr) return ;
    std::vector<Part *> &supplier = mptr->getPn();
    QBrush grayb(Qt::gray); QPen blackp(Qt::black);
    painter->setBrush(grayb);
    painter->drawRect(rec);
    painter->setPen(blackp);
    painter->drawText(rec.x()+rec.width()/4, rec.y()+rec.height()/2, mptr->name);

    for(unsigned i=0; i < supplier.size(); i++)
    {
        painter->drawText(rec.x()+rec.width() + 10, 20 + rec.y()+i*20, supplier[i]->name);
    }

}

QRectF MotorItem::boundingRect() const
{
    return QRectF(rec.x(), rec.y(),  rec.width() + 10, rec.y() + rec.height());
}

void MotorItem::connect(Motor* m)
{
    mptr = m;
}
