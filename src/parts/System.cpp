#include "System.hpp"
#include <iostream>
#include <QDebug>
#include <cstdlib>
#include <ctime>

System::System()
{
	motor[M1] = new Motor("M1");
	motor[M2] = new Motor("M2");
	motor[M3] = new Motor("M3");

    tank[T1] = new Tank("TANK 1", false);
    tank[T2] = new Tank("TANK 2", false);
    tank[T3] = new Tank("TANK 3", false);

    valve[V12] = new Valve("V12", false);
    valve[V13] = new Valve("V13", false);
    valve[V23] = new Valve("V23", false);

    valve[VT12] = new Valve("VT12", false);
    valve[VT23] = new Valve("VT23", false);
	
	tank[T1]->addLink(motor[M1]);
	tank[T1]->addLink(valve[V12]);
	tank[T1]->addLink(valve[V13]);
	
	tank[T2]->addLink(motor[M2]);
	tank[T2]->addLink(valve[V12]);
	tank[T2]->addLink(valve[V23]);
	
	tank[T3]->addLink(motor[M3]);
	tank[T3]->addLink(valve[V13]);
	tank[T3]->addLink(valve[V23]);
	
	valve[V12]->addLink(motor[M1]);
	valve[V12]->addLink(motor[M2]);
	valve[V12]->addLink(valve[V13]);
	valve[V12]->addLink(valve[V23]);
	
	valve[V13]->addLink(motor[M1]);
	valve[V13]->addLink(motor[M3]);
	valve[V13]->addLink(valve[V12]);
	valve[V13]->addLink(valve[V23]);
	
	valve[V23]->addLink(motor[M2]);
	valve[V23]->addLink(motor[M3]);
	valve[V23]->addLink(valve[V12]);
	valve[V23]->addLink(valve[V13]);

    std::srand(std::time(nullptr));
}

System::~System()
{
	for (Motor *m : motor) delete m;
	for (Tank *t : tank) delete t;
	for (Valve *v : valve) delete v;
}

bool System::run()
{
	balanceFuel();

    //reset les tanks alimantant le moteur
    unmarkAll();
    motor[M1]->getPn().clear();
    motor[M2]->getPn().clear();
    motor[M3]->getPn().clear();

    //RUN

    std::vector<Part*> pn;

    if(!tank[T1]->isCurrEmpty() && tank[T1]->getP1() == ON) motor[M1]->addLink(tank[T1]);
    tank[T1]->supplyFuel();
    for(Motor *m : motor)
    {
        if(m->isMarked())
        {
            pn = m-> getPn();
            if(pn.empty() || pn.back() != tank[T1])
            { m->addLink(tank[T1]);break;}

        }
    }
    unmarkAll();

    if(!tank[T2]->isCurrEmpty() && tank[T2]->getP1() == ON) motor[M2]->addLink(tank[T2]);
    tank[T2]->supplyFuel();
    for(Motor *m : motor)
    {
        if(m->isMarked())
        {
            pn = m-> getPn();
            if(pn.empty() || pn.back() != tank[T2])
            { m->addLink(tank[T2]);break;}
        }
    }
	unmarkAll();

    if(!tank[T3]->isCurrEmpty() && tank[T3]->getP1() == ON) motor[M3]->addLink(tank[T3]);
    tank[T3]->supplyFuel();
    for(Motor *m : motor)
    {
        if(m->isMarked())
        {
            pn = m-> getPn();
            if(pn.empty() || pn.back() != tank[T3])
            { m->addLink(tank[T3]);break;}
        }
    }
	unmarkAll();

    bool completed = true;
    for(Motor* m : motor)
           if(m->getPn().empty()) completed = false;
    return completed;
}

void System::balanceFuel()
{
	bool emptyT1, emptyT2, emptyT3;
	bool closedVT12, closedVT23;

	emptyT1 = tank[T1]->isEmpty();
	emptyT2 = tank[T2]->isEmpty();
	emptyT3 = tank[T3]->isEmpty();

    emptyT1 ? tank[T1]->drainAfter() : tank[T1]->fillAfter();
    emptyT2 ? tank[T2]->drainAfter() : tank[T2]->fillAfter();
    emptyT3 ? tank[T3]->drainAfter() : tank[T3]->fillAfter();


	closedVT12 = valve[VT12]->isClosed();
	closedVT23 = valve[VT23]->isClosed();

    if(emptyT1 && !emptyT3 && closedVT12 && closedVT23) tank[T1]->fillAfter();

	if(emptyT2)
	{
		if( (!emptyT1 && closedVT12) || (!emptyT3 && closedVT23) ) tank[T2]->fillAfter();
	}
	
	if(emptyT3 && !emptyT1 && closedVT12 && closedVT23) tank[T3]->fillAfter();
}

void System::configRandom()
{
    int n = rand()%4;
    for(Valve *v : valve)
        (rand()%2) ? v->open() : v->close();
    if(n==1)
    {
        tank[T1]->fill();tank[T2]->drain();tank[T3]->drain();
        tank[T1]->setP1(ON);tank[T1]->setP1(ON);tank[T1]->setP1(ON);
        tank[T1]->setP2(OFF);tank[T2]->setP2(OFF);tank[T3]->setP2(OFF);
    }
    else if(n==2)
    {
        tank[T1]->drain();tank[T2]->drain();tank[T3]->fill();
        tank[T1]->setP1(ON);tank[T1]->setP1(BROKEN);tank[T1]->setP1(ON);
        tank[T1]->setP2(OFF);tank[T2]->setP2(OFF);tank[T3]->setP2(OFF);
    }
    else if(n==3)
    {
        tank[T1]->fill();tank[T2]->drain();tank[T3]->drain();
        tank[T1]->setP1(ON);tank[T1]->setP1(ON);tank[T1]->setP1(ON);
        tank[T1]->setP2(BROKEN);tank[T2]->setP2(OFF);tank[T3]->setP2(BROKEN);
    }
}

void System::unmarkAll()
{
	for (Motor *m : motor) m->unmark();
	for (Tank *t : tank) t->unmark();
	for (Valve *v : valve) v->unmark();
}

Motor** System::getMotors() {return motor;}
Tank** System::getTanks() {return tank;}
Valve** System::getValves() {return valve;}
