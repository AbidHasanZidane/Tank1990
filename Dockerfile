FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y build-essential wget

RUN wget https://download.qt.io/official_releases/qt/6.6/6.6.3/qt-opensource-linux-x64-6.6.3.run

RUN chmod +x qt-opensource-linux-x64-6.6.3.run

RUN ./qt-opensource-linux-x64-6.6.3.run --script /dev/null --platform minimal --verbose --no-ssl --no-gnome --no-webkit

RUN rm qt-opensource-linux-x64-6.6.3.run

ENV QTDIR /opt/Qt
ENV PATH $QTDIR/6.6.3/gcc_64/bin:$PATH

RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

CMD ["bash"]
