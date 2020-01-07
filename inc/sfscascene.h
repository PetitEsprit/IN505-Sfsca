#ifndef SFSCASCENE_H
#define SFSCASCENE_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "tankitem.h"
#include "valveitem.h"
#include "motoritem.h"
#include "System.hpp"
#include <ctime>

class SfscaScene : public QGraphicsScene
{
    Q_OBJECT
    private:
        System syst;
        TankItem t1,t2,t3;
        ValveItem vt12,vt23,v12,v13,v23;
        MotorItem m1,m2,m3;
        QGraphicsTextItem *msg_success;
        time_t start, end;
        bool alreadydone;
    public:
        SfscaScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
        ~SfscaScene();
        void chronostart();
        void chronoend();
        float computeScore();
        void runRandomConfig();
        void printSuccessMsg();
        void hideMsg();
        void setDone(bool b);
    public slots:
        void setV(e_valve ev );
        void setPump2(e_tank et);
        void myupdate();
    signals:
        void completed();

};

#endif // SFSCASCENE_H
