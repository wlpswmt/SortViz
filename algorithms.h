#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QtWidgets>
#include"MyVector.h"
class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(int, int, int, _vector<double>, QObject*);

signals:
    void comparision(int, int);    //比较函数信号
    void sortDone(int, int);            //排序信号
    void arrayAccess(int);
    void changeButtonStatus(int);

protected:
    void run() override;

private:
    _vector<double> columnsHeight;
    int sortDoneDelay;
    int sortDelay;
    int amount;
    int sortWith;
    int arrayAccessVariable;

    void swap(int, int);
    void isAccessToArray();
    void Sorted();

    //sorting algorithms declaration
    void BubbleSort();
    void RecursiveBubbleSort(int);
    void CocktailSort();
    void GnomeSort();

    int QuickSortPartition(int, int);
    void QuickSort(int, int);

    void Heapify(int n, int i);
    void HeapSort();

    void InsertSort();
    void ShellSort();

    void SelectSort();

    void merge(int, int, int);
    void mergePass(int);
    void mergeSort(int, int);
};

#endif // THREAD_H
