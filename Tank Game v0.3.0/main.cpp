#include "widget.h"
#include "settings.h"
#include <QApplication>
#include <QProcess>
#include <string>

int main(int argc,char *argv[])
{
    QFile fileOpen("settings.dat");
    fileOpen.open(QFile::ReadOnly | QIODevice::Text);
    QTextStream in(&fileOpen);
    std::string scale;
    while(!in.atEnd())
    {
        QStringList line=in.readLine().split(":");
        if(line.at(0)=="Resolution ratio")
            scale=line.at(1).toStdString();
    }
    fileOpen.close();
    settings::modifySettings("Resolution ratio:","1");
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
        settings::modifySettings("Resolution ratio:",QString::number(e/1280));
    }
    return e;
}
