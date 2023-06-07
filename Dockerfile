FROM ubuntu:20.04

LABEL maintainer="Ledyaev_Timofey_221_353"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

EXPOSE 33333

WORKDIR /Ledyaev_353
COPY *.cpp /Ledyaev_353/
COPY *.h /Ledyaev_353/
COPY *.pro /Ledyaev_353/
COPY . /Ledyaev_353

RUN qmake echoServer.pro "TARGET=hallServer"
RUN make

ENTRYPOINT ["./hallServer"]
