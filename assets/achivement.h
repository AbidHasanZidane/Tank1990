#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H

#include <QWidget>

namespace Ui {
class achivement;
}

class achivement : public QWidget
{
    Q_OBJECT

public:
    explicit achivement(QWidget *parent = nullptr);
    ~achivement();
    Ui::achivement *ui;

signals:
    void switch2w();

private:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // ACHIVEMENT_H
