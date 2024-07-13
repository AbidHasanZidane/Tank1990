#include "settings.h"

void settings::modifySettings(QString location,QString content)
{
    QStringList text;
    QFile readFile("settings.dat");
    readFile.open(QFile::ReadOnly | QIODevice::Text);
    QTextStream in(&readFile);
    text=in.readAll().split("\n");
    readFile.close();
    QFile writeFile("settings.dat");
    writeFile.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&writeFile);
    for(int i=0;i<text.count();i++)
    {
        if(text.at(i).contains(location))
        {
            QString tempStr=text.at(i);
            tempStr.replace(0,tempStr.length(),location+content);
            out<<tempStr<<'\n';
        }
        else
        {
            if(i==text.count()-1)
            {
                out<<text.at(i);
            }
            else
            {
                out<<text.at(i)<<'\n';
            }
        }
    }
    writeFile.close();
}

QString settings::readSettings(QString location)
{
    QStringList text;
    QFile readFile("settings.dat");
    readFile.open(QFile::ReadOnly | QIODevice::Text);
    QTextStream in(&readFile);
    text=in.readAll().split("\n");
    readFile.close();
    for(int i=0;i<text.count();i++)
    {
        if(text.at(i).contains(location))
        {
            return text.at(i).split(":").at(1);
        }
    }
    return "";
}
