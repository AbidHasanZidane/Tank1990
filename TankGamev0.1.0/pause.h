#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>

namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = nullptr);
    ~pause();
    bool runType;

private:
    void keyPressEvent(QKeyEvent *event) override;
    Ui::pause *ui;

protected:
};

#endif // PAUSE_H
