#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
void Score::increaseScore()
{
    score += 10;
    setPlainText(QString("Score: ") + QString::number(score));
}
int Score::getScore()
{

}
