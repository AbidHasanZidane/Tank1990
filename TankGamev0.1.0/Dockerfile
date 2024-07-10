FROM ubuntu:latest

# 更新并安装依赖项

RUN apt-get update && apt-get install -y \
    build-essential \
    qt6-base-dev \
    qmake6 \
    qt6-charts-dev \
    libmysqlclient-dev \
    linguist-qt6 \
    libqt6sql6-mysql \
    qt6-l10n-tools \
    qtcreator \
    pulseaudio \
    qtbase5-dev \
    libqt5multimedia5-plugins \
    
    apt-get install qtmultimedia5-dev \
    libpulse-dev \
    qtbase5-dev \
    apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly \
    apt-get install qtmultimedia5-dev


# 检查是否安装成功
RUN qmake6 --version

# 设置工作目录
WORKDIR /TANKFIGHTER_EXAMPLE

# 将当前目录下的所有内容复制到工作目录中
COPY . /TANKFIGHTER_EXAMPLE

# 使用 qmake 构建项目
RUN qmake -o Makefile tank.pro

# 使用 make 编译项目
RUN make

# 进入运行
RUN ./tank
