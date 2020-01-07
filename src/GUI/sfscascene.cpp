#include "sfscascene.h"
#include <QDebug>

SfscaScene::SfscaScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) :
    QGraphicsScene(x, y, width, height, parent),
    t1(150, 10, 100, 125),t2(450, 10, 100, 75),t3(750, 10, 100, 125),
    vt12(320, 35),vt23(620, 35),v12(320, 255),v13(620, 155),v23(620, 335),
    m1(180, 400),m2(480, 400),m3(780, 400),
    start(time(NULL))
{
    //Connect Item to Part
    Motor** mtab = syst.getMotors();
    Valve** vtab = syst.getValves();
    Tank** ttab = syst.getTanks();
    t1.connect(ttab[T1]); t2.connect(ttab[T2]); t3.connect(ttab[T3]);
    vt12.connect(vtab[VT12]); vt23.connect(vtab[VT23]); v12.connect(vtab[V12]); v13.connect(vtab[V13]); v23.connect(vtab[V23]);
    m1.connect(mtab[M1]); m2.connect(mtab[M2]); m3.connect(mtab[M3]);

    //Ajout des TankItems et MotorItems
    addItem(&t1);addItem(&t2);addItem(&t3);
    addItem(&m1);addItem(&m2);addItem(&m3);

    addLine(200, 135 , 200, 400);addLine(500, 85 , 500, 400);addLine(800, 135 , 800, 400);
    addLine(250, 50 , 450, 50);addLine(550, 50 , 750, 50);

    addLine(200, 170 , 800, 170);
    addLine(200, 270 , 500, 270);
    addLine(500, 350 , 800, 350);

    //Ajout des Valves
    addItem(&vt12);addItem(&vt23);addItem(&v12);addItem(&v13);addItem(&v23);

    //Ajout du Text
    msg_success = addText("", QFont("Ubuntu", 20));
    msg_success->setPos(width/2 - 30, height/2);
    msg_success->setVisible(false);

    connect(&t1, SIGNAL(pressed()), this, SLOT(myupdate()));
    connect(&t2, SIGNAL(pressed()), this, SLOT(myupdate()));
    connect(&t3, SIGNAL(pressed()), this, SLOT(myupdate()));

    myupdate();
}

SfscaScene::~SfscaScene()
{
    delete msg_success;
}

void SfscaScene::myupdate()
{
   bool s = syst.run();
   if(!alreadydone && s)
   {
       end = time(NULL);
       printSuccessMsg();
       alreadydone = true;
       emit completed();
   }
   update();
}

void SfscaScene::setDone(bool b)
{
    alreadydone = b;
}

void SfscaScene::runRandomConfig()
{
    syst.configRandom();
}

float SfscaScene::computeScore()
{
    const int POINT_LOST_PERSEC = 3;
    float s =  10.0 - (end-start)/POINT_LOST_PERSEC;
    return (s > 0 ? s : 0);
}

void SfscaScene::printSuccessMsg()
{
    QString msg = (QString)"Success / Time : " + QString::number((end-start)) + (QString)"s";
    msg_success->setPlainText(msg);
    msg_success->setVisible(true);
}

 void SfscaScene::hideMsg()
 {
    msg_success->setVisible(false);
 }

void SfscaScene::setV(e_valve ev)
{
    Valve* v = syst.getValves()[ev];
    v->isClosed() ? v->open() : v->close();
}

void SfscaScene::setPump2(e_tank et)
{
    Tank* t = syst.getTanks()[et];
    if(t->getP2() != BROKEN)
        t->setP2((e_pump)(1 - t->getP2()));
}

void SfscaScene::chronostart()
{
    start = time(NULL);
    end = 0;
}

void SfscaScene::chronoend()
{
    start = 0;
    end = 0;
}
