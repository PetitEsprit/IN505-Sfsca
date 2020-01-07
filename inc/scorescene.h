#ifndef SCORESCENE_H
#define SCORESCENE_H

#include <QGraphicsScene>
#include "Login.hpp"

class ScoreScene : public QGraphicsScene
{
    private:
        list <Grade> scores;
    public:
        ScoreScene(list <Grade>	&history);
        void addScores();
        ~ScoreScene();
};

#endif // SCORESCENE_H
