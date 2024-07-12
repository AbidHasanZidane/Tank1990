#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

class WorkerThread : public QThread {
    Q_OBJECT

public:
    WorkerThread(QObject *parent = nullptr) : QThread(parent), paused(false) {}

    void run() override {
        while (true) {
            mutex.lock();
            if (paused) {
                condition.wait(&mutex);
            }
            mutex.unlock();
            qDebug()<<"running";
            this->exec();
            //emit updateStatus();
        }
    }

    void pause() {
        QMutexLocker locker(&mutex);
        paused = true;
    }

    void resume() {
        QMutexLocker locker(&mutex);
        paused = false;
        condition.wakeAll();
    }
signals:
    void updateStatus();

private:
    bool paused;
    QMutex mutex;
    QWaitCondition condition;
};
