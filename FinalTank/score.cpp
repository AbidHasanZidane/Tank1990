#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent), score(0), totalScore(0) {
    readTotalScore();
    setPlainText(QString("Score: ") + QString::number(score) + "\nTotal Score: " + QString::number(totalScore));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increaseScore() {
    score += 10;
    totalScore += 10;
    setPlainText(QString("Score: ") + QString::number(score) + "\nTotal Score: " + QString::number(totalScore));
    updateScores(); // Update the scores in the files
}

int Score::getScore() const {
    return score;
}

void Score::updateScores() {
    writeScore();
    writeTotalScore();
}

void Score::readTotalScore() {
    QFile file("total_score.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return; // If the file can't be opened, assume the total score is 0
    }

    QTextStream in(&file);
    in >> totalScore;

    file.close();
}

void Score::writeScore() const {
    QFile file("score.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return; // If the file can't be opened, do nothing
    }

    QTextStream out(&file);
    out << score;

    file.close();
}

void Score::writeTotalScore() const {
    QFile file("total_score.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return; // If the file can't be opened, do nothing
    }

    QTextStream out(&file);
    out << totalScore;

    file.close();
}
