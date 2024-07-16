#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include "settings.h"

namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();
    Ui::shop *ui;
    QSoundEffect *butEffect=new QSoundEffect;
    void refresh();

signals:
    void switch2w();

private slots:
    void on_pushButton_clicked();
    void spawned(double vol);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // SHOP_H
