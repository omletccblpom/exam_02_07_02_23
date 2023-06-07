#include <QtTest>
#include "heapsort.h"
#include <iostream>
// add necessary includes here

class echoserver : public QObject
{
    Q_OBJECT

public:
    echoserver();
    ~echoserver();

private slots:
    void test_case1();
    void test_case_step1();
    void test_case_negative();
};

echoserver::echoserver()
{

}

echoserver::~echoserver()
{

}

void echoserver::test_case_negative()
{
    int size = 6;
    int step = 100;
    int arr[] = { -6, -3, -5, -1, -2, -4 };
    int sorted_arr[] = { -6, -5, -4, -3, -2, -1 };

    heapSort(arr, size, step);

    for (int i = 0; i < size; i++) {
        QVERIFY(arr[i] == sorted_arr[i]);
    }
}

void echoserver::test_case_step1()
{
    int size = 6;
    int step = 1;
    int arr[] = { 12, 8, 14, 15, 3, 2 };
    int sorted_arr[] = { 2, 3, 8, 12, 14, 15 };

    heapSort(arr, size, step);

    for (int i = 0; i < size; i++) {
        QVERIFY(arr[i] == sorted_arr[i]);
    }
}

void echoserver::test_case1()
{
    int size = 6;
    int arr[] = { 8, 7, 3, 6, 4, 2};
    int sorted_arr[] = { 2, 3, 4, 6, 7, 8};

    heapSort(arr, size, 100);

    for (int i = 0; i < size; i++) {
        QVERIFY(arr[i] == sorted_arr[i]);
    }
}

QTEST_APPLESS_MAIN(echoserver)

#include "tst_echoserver.moc"
