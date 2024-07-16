#include "score.h"
#include <QFont>  // 引入Qt字体类

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent), score(0), totalScore(0) {
    readTotalScore();  // 初始化时从文件中读取总分数
    setPlainText(QString("Score: ") + QString::number(score) + "\nTotal Score: " + QString::number(totalScore));  // 设置显示的初始文本内容，包括当前分数和总分数
    setDefaultTextColor(Qt::blue);  // 设置文本颜色为蓝色
    setFont(QFont("times", 16));    // 设置字体为Times New Roman，大小为16像素
}

void Score::increaseScore() {
    score += 10;          // 增加当前分数和总分数
    totalScore += 10;
    setPlainText(QString("Score: ") + QString::number(score) + "\nTotal Score: " + QString::number(totalScore));  // 更新显示的文本内容，包括当前分数和总分数
    updateScores();       // 更新分数到文件中
}

int Score::getScore() const {
    return score;  // 返回当前分数
}

void Score::updateScores() {
    writeScore();       // 将当前分数写入文件
    writeTotalScore();  // 将总分数写入文件
}

void Score::readTotalScore() {
    QFile file("total_score.txt");  // 打开总分数文件

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;  // 如果无法打开文件，假设总分数为0
    }

    QTextStream in(&file);
    in >> totalScore;  // 从文件中读取总分数

    file.close();  // 关闭文件
}

void Score::writeScore() const {
    QFile file("score.txt");  // 打开分数文件

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;  // 如果无法打开文件，不做任何操作
    }

    QTextStream out(&file);
    out << score;  // 将当前分数写入文件

    file.close();  // 关闭文件
}

void Score::writeTotalScore() const {
    QFile file("total_score.txt");  // 打开总分数文件

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;  // 如果无法打开文件，不做任何操作
    }

    QTextStream out(&file);
    out << totalScore;  // 将总分数写入文件

    file.close();  // 关闭文件
}
