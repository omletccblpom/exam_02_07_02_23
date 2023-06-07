#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include "heapsort.h"
#include <iostream>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "server is not started";
    } else {
        server_status = 1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection() {
    if(server_status == 1) {
        mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead() {
    while (mTcpSocket->bytesAvailable() > 0)
    {
        QString result = "";
        QString data = mTcpSocket->readAll();
        QStringList params = data.split("&");
        if (params[0] == "sort" && params.size() == 3) {
            int step = params[1].toInt();
            QStringList digits = params[2].split(" ");
            int arr[digits.size()];

            for (int i = 0; i < digits.size(); i++) {
                arr[i] = digits[i].toInt();
            }

            heapSort(arr, digits.size(), step);
            for (int i = 0; i < digits.size(); i++) {
                result += QString::number(arr[i]) + " ";
            }
            result += "\r\n";
        }
        else {
            result = data;
        }

        mTcpSocket->write(result.toUtf8());
    }
}

void MyTcpServer::slotClientDisconnected() {
    mTcpSocket->close();
}
