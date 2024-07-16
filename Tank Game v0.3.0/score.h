#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFile>
#include <QTextStream>

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent=0);
    void increaseScore();
    int getScore() const;

private:
    int score;
    int totalScore;
    void updateScores(); // Method to update the scores in the files
    void readTotalScore(); // Method to read the total score from the file
    void writeScore() const; // Method to write the current score to the file
    void writeTotalScore() const; // Method to write the total score to the file
};

#endif // SCORE_H
