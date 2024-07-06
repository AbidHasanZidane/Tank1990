#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QMainWindow>
#include"choosemodelscene.h"
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();
    ChooseModelScene*choosemodelscene=nullptr;
    void paintEvent(QPaintEvent *event);
private slots:

private:
    Ui::MainScene *ui;

};

#endif // MAINSCENE_H
