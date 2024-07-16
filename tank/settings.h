#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QFile>
#include <QTextStream>

class settings
{
public:
    settings();  // 默认构造函数
    static void modifySettings(QString location, QString content);  // 修改设置项
    static QString readSettings(QString location);  // 读取设置项
};

#endif // SETTINGS_H
