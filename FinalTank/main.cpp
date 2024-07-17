#include "widget.h"  // 包含主窗口的头文件
#include "settings.h"  // 包含设置类的头文件
#include <QApplication>  // Qt 应用程序类
#include <QProcess>  // Qt 进程类
#include <QFile>  // 文件操作类
#include <QTextStream>  // 文本流操作类
#include <string>  // C++ 标准库中的字符串类

int main(int argc, char *argv[])
{
    QFile fileOpen("settings.dat");  // 打开设置文件
    fileOpen.open(QFile::ReadOnly | QIODevice::Text);  // 以只读文本模式打开文件
    QTextStream in(&fileOpen);  // 创建文本流并关联到文件
    std::string scale;  // 用于存储分辨率比例的字符串变量

    // 从文件中读取设置信息
    while (!in.atEnd())
    {
        QStringList line = in.readLine().split(":");  // 读取一行并根据冒号分割成字符串列表
        if (line.at(0) == "Resolution ratio")
            scale = line.at(1).toStdString();  // 如果是分辨率比例的设置项，将其保存到 scale 变量中
    }
    fileOpen.close();  // 关闭文件

    // 修改设置文件中的分辨率比例为 "1"
    settings::modifySettings("Resolution ratio:", "1");

    // 设置 Qt 应用程序的缩放因子
    qputenv("QT_SCALE_FACTOR", scale.c_str());

    QApplication a(argc, argv);  // 创建 Qt 应用程序对象
    Widget w;  // 创建主窗口对象
    w.setFixedSize(1280, 720);  // 设置主窗口固定大小为 1280x720 像素
    w.show();  // 显示主窗口
    w.scale = scale;  // 将分辨率比例传递给主窗口对象的成员变量

    double e = a.exec();  // 运行应用程序并获取退出码

    // 如果退出码不为 0，则重新启动应用程序
    if (e != 0)
    {
        QProcess::startDetached(qApp->applicationFilePath());  // 启动一个新的进程以重新启动应用程序
        settings::modifySettings("Resolution ratio:", QString::number(e / 1280));  // 修改设置文件中的分辨率比例为当前 e 的比例
    }

    return e;  // 返回应用程序的退出码
}
