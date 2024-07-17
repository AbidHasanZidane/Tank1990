#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <QWidget>
#include <QSoundEffect>
#include "settings.h"

namespace Ui {
class achievement;
}

class achievement : public QWidget
{
    Q_OBJECT

public:
    explicit achievement(QWidget *parent = nullptr);
    ~achievement();
    QSoundEffect *butEffect=new QSoundEffect;
    Ui::achievement *ui;

signals:
    void switch2w();

private slots:
    void on_pushButton_clicked();

private:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // ACHIEVEMENT_H
