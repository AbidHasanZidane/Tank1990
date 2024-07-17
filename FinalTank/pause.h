#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
#include "settings.h"

namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = nullptr);
    ~pause();

signals:
    void retw1();
    void retmain();
    void retsettings();

private:
    void keyPressEvent(QKeyEvent *event) override;
    Ui::pause *ui;

protected:
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // PAUSE_H
