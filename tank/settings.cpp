#include "settings.h"

void settings::modifySettings(QString location, QString content)
{
    QStringList text;
    QFile readFile("settings.dat");  // 打开设置文件
    readFile.open(QFile::ReadOnly | QIODevice::Text);  // 以只读文本模式打开文件
    QTextStream in(&readFile);  // 文本流读取文件
    text = in.readAll().split("\n");  // 将文件内容按行读取并存入字符串列表
    readFile.close();  // 关闭文件

    QFile writeFile("settings.dat");  // 打开设置文件进行写操作
    writeFile.open(QFile::WriteOnly | QIODevice::Text);  // 以只写文本模式打开文件
    QTextStream out(&writeFile);  // 文本流写入文件
    for (int i = 0; i < text.count(); i++)
    {
        if (text.at(i).contains(location))  // 如果找到包含目标位置的行
        {
            QString tempStr = text.at(i);  // 获取目标行内容
            tempStr.replace(0, tempStr.length(), location + content);  // 替换目标行内容
            out << tempStr << '\n';  // 写入更新后的行内容
        }
        else  // 如果不是目标行
        {
            if (i == text.count() - 1)
            {
                out << text.at(i);  // 如果是最后一行，直接写入内容
            }
            else
            {
                out << text.at(i) << '\n';  // 否则写入内容并换行
            }
        }
    }
    writeFile.close();  // 关闭文件
}

QString settings::readSettings(QString location)
{
    QStringList text;
    QFile readFile("settings.dat");  // 打开设置文件
    readFile.open(QFile::ReadOnly | QIODevice::Text);  // 以只读文本模式打开文件
    QTextStream in(&readFile);  // 文本流读取文件
    text = in.readAll().split("\n");  // 将文件内容按行读取并存入字符串列表
    readFile.close();  // 关闭文件

    for (int i = 0; i < text.count(); i++)
    {
        if (text.at(i).contains(location))  // 如果找到包含目标位置的行
        {
            return text.at(i).split(":").at(1);  // 返回该行冒号后的内容作为设置值
        }
    }
    return "";  // 如果未找到目标位置，返回空字符串
}
