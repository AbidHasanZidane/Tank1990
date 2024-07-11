#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
class GameOver;
}

class GameOver : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0);
    ~GameOver();
signals:
    void retry();
private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
