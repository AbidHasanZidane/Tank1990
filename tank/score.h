#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>  // 引入Qt图形文本项类
#include <QFile>              // 引入Qt文件操作类
#include <QTextStream>        // 引入Qt文本流类

class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent=0);  // 构造函数，初始化分数和界面显示
    void increaseScore();             // 增加分数的方法
    int getScore() const;             // 获取当前分数的方法

private:
    int score;                        // 当前分数
    int totalScore;                   // 总分数
    void updateScores();              // 更新分数到文件的方法
    void readTotalScore();            // 从文件中读取总分数的方法
    void writeScore() const;          // 将当前分数写入文件的方法
    void writeTotalScore() const;     // 将总分数写入文件的方法
};

#endif // SCORE_H
