#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QFile>
#include <QTextStream>

class settings
{
public:
    settings();
    static void modifySettings(QString location,QString content);
    static QString readSettings(QString location);
};

#endif // SETTINGS_H
