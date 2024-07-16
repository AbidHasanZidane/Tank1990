#include "widget.h"  // 包含游戏界面的头文件
#include "settings.h"  // 包含设置管理的头文件
#include <QApplication>  // 包含Qt应用程序类的头文件
#include <QProcess>  // 包含Qt进程控制类的头文件
#include <QFile>  // 包含文件操作类的头文件
#include <QTextStream>  // 包含文本流操作类的头文件
#include <string>  // 包含C++标准字符串类的头文件

int main(int argc, char *argv[])
{
    QFile fileOpen("settings.dat");  // 打开设置文件
    fileOpen.open(QFile::ReadOnly | QIODevice::Text);  // 以只读文本方式打开文件
    QTextStream in(&fileOpen);  // 创建文本流对象，并与文件关联
    std::string scale;  // 存储分辨率比例的字符串变量

    // 读取文件中的设置信息
    while (!in.atEnd()) {
        QStringList line = in.readLine().split(":");  // 按冒号分割每行字符串
        if (line.at(0) == "Resolution ratio")  // 如果是分辨率比例的设置项
            scale = line.at(1).toStdString();  // 将比例值转换为标准字符串存储
    }
    fileOpen.close();  // 关闭文件

    settings::modifySettings("Resolution ratio:", "1");  // 修改设置文件中的分辨率比例为默认值"1"

    qputenv("QT_SCALE_FACTOR", scale.c_str());  // 设置Qt应用程序的缩放因子

    QApplication a(argc, argv);  // 创建Qt应用程序对象
    Widget w;  // 创建游戏界面对象
    w.setFixedSize(1280, 720);  // 设置游戏界面固定大小为1280x720
    w.show();  // 显示游戏界面
    w.scale = scale;  // 将分辨率比例传递给游戏界面对象

    double e = a.exec();  // 执行应用程序，等待退出信号返回

    if (e != 0) {  // 如果退出代码不为0（异常退出）
        QProcess::startDetached(qApp->applicationFilePath());  // 以独立进程重新启动应用程序
        settings::modifySettings("Resolution ratio:", QString::number(e / 1280));  // 修改设置文件中的分辨率比例为当前实际比例
    }

    return e;  // 返回应用程序退出代码
}
