#include "widget.h"
#include <QApplication>
#include <QProcess>
#include <string>

int main(int argc,char* argv[])
{
    QFile fileOpen("settings.txt");
    fileOpen.open(QFile::ReadOnly | QIODevice::Text);
    QTextStream in(&fileOpen);
    std::string scale = in.readAll().toStdString();
    fileOpen.close();
    fileOpen.open(QFile::WriteOnly | QIODevice::Text | QFile::Truncate);
    in<<1;
    fileOpen.close();
    qDebug()<<scale;
    qputenv("QT_SCALE_FACTOR",scale);
    QApplication a(argc,argv);
    Widget w;
    w.setFixedSize(1280,720);
    w.show();
    w.scale=scale;
    double e=a.exec();
    if(e!=0)
    {
        QProcess::startDetached(qApp->applicationFilePath());
        QFile file("settings.txt");
        file.open(QFile::WriteOnly | QFile::Truncate);
        QTextStream out(&file);
        out <<QString::number(e/1280);
        file.close();
        return 0;
    }
    return e;
}
