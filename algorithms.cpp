#include "algorithms.h"
#include"timecompare.h"

QTimer* Thread:: myTimer= NULL ;

Thread::Thread(int ms, int alg, int n, _vector<double> col, QObject *parent = nullptr) : QThread(parent)
{
    sortWith = alg;
    amount = n;
    columnsHeight = col;
    arrayAccessVariable = 0;
    sortDoneDelay = (amount >= 300 ? 1 : 5);
    sortDelay = ms;

}

void Thread::run()      //运行排序算法
{
    switch(sortWith)  //sortwith来自于键值对 中的key
    {
    case 0: BubbleSort(); break;
    case 1: RecursiveBubbleSort(amount); break;
    case 2: CocktailSort(); break;
    case 3: GnomeSort(); break;
    case 4: QuickSort(0, amount -1); break;
    case 5: HeapSort(); break;
    case 6: InsertSort(); break;
    case 7: SelectSort(); break;
    case 8: ShellSort(); break;
    case 9: mergeSort(0, amount-1); break;
    }
    Sorted();
}

void Thread::Sorted()
{
    for(auto i=0; i<amount; i++)
    {
        emit sortDone(i, sortWith);
        msleep(sortDoneDelay);
    }
    emit changeButtonStatus(2);
}

void Thread::swap(int n, int k)
{
    std::swap(columnsHeight[n], columnsHeight[k]);
    emit comparision(n, k);
}

void Thread::isAccessToArray()
{
    arrayAccessVariable++;  //数组访问次数++
    emit arrayAccess(arrayAccessVariable);
}

//--------- BUBBLE SORT -----------

void Thread::BubbleSort()
{
    for(auto i = 0; i < amount; i++)
        for(auto j = 0; j< amount-1; j++)
        {
            if(columnsHeight[j] > columnsHeight[j+1])
            {
                swap(j, j+1);
                msleep(sortDelay);
            }

            isAccessToArray();
        }
}

//--------- RECURSIVE BUBBLE SORT -

void Thread::RecursiveBubbleSort(int n)
{
    if (n == 1)
        return;

    for (int i=0; i<n-1; i++)
    {
        if (columnsHeight[i] > columnsHeight[i+1])
            swap(i, i+1);

        isAccessToArray();
        msleep(sortDelay);
    }
    RecursiveBubbleSort(n-1);
}

//--------- COCKTAIL SORT ---------

void Thread::CocktailSort()
{
    bool swapped = true;
    auto start = 0;
    auto end = amount-1;

    while(swapped)
    {
        swapped = false;
        for (auto i = start; i < end; i++)
        {
            if(columnsHeight[i] > columnsHeight[i + 1])
            {
                swap(i, i+1);
                swapped = true;
            }
            isAccessToArray();
            msleep(sortDelay);
        }

        if (!swapped)
            break;

        swapped = false;
        end--;

        for (auto i = end-1; i >= start; i--)
        {
            if (columnsHeight[i] > columnsHeight[i + 1])
            {
                swap(i, i+1);
                swapped = true;
            }
            isAccessToArray();
            msleep(sortDelay);
        }
        start++;
    }
}

//--------- GNOME SORT ------------

void Thread::GnomeSort()
{
    int index = 0;

    while (index < amount)
    {
        if (index == 0)
            index++;
        if (columnsHeight[index] >= columnsHeight[index-1])
            index++;
        else
        {
            swap(index, index-1);
            index--;
        }
        isAccessToArray();
        msleep(sortDelay);
    }
}

//--------- QUICK SORT ------------

int Thread::QuickSortPartition(int arrayBegin, int arrayEnd)
{
    auto pivot = columnsHeight[arrayEnd];
    auto i = (arrayBegin - 1);

    for (auto j = arrayBegin; j <= arrayEnd - 1; j++)
    {
        if (columnsHeight[j] <= pivot)
        {
            i++;
            swap(i, j);
            msleep(sortDelay);
        }

        isAccessToArray();
    }

    swap(i+1, arrayEnd);


    return(i + 1);
}

void Thread::QuickSort(int arrayBegin, int arrayEnd)
{
    if (arrayBegin < arrayEnd)
    {
        auto pi = QuickSortPartition(arrayBegin, arrayEnd);

        QuickSort(arrayBegin, pi - 1);
        QuickSort(pi + 1, arrayEnd);
    }
}

//--------- HEAP SORT -------------

void Thread::Heapify(int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && columnsHeight[l] > columnsHeight[largest])
        largest = l;

    isAccessToArray();

    if (r < n && columnsHeight[r] > columnsHeight[largest])
        largest = r;

    isAccessToArray();

    if (largest != i)
    {
        swap(i, largest);
        Heapify(n, largest);

        msleep(sortDelay);
    }
}

void Thread::HeapSort()
{
    auto n = amount;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(n, i);
    }

    for (int i=n-1; i>=0; i--)
    {
        swap(0, i);
        msleep(sortDelay);
        Heapify(i, 0);
    }
}

//-------INSERT SORT--------

void Thread::InsertSort()
{
    for(int i = 2; i < amount; i++) {
        columnsHeight[0] = columnsHeight[i];
        emit comparision(0, i);
        auto j = i - 1;
        while(columnsHeight[0]<columnsHeight[j]) {
            columnsHeight[j+1] = columnsHeight[j];
            emit comparision(j+1, j);
            j--;
            msleep(sortDelay);
        }
        isAccessToArray();
        columnsHeight[j+1] = columnsHeight[0];
        emit comparision(j+1, 0);
    }
}

//------SHELL SORT--------

void Thread::ShellSort()
{
    int i=0,j=0,gap=0;
    for(gap=amount/2; gap>=1; gap/=2)
    {
        for(i=gap;i<amount;i++)
        {
            columnsHeight[0]=columnsHeight[i];
            emit comparision(0, i);
            j=i-gap;
            while(j>0&&columnsHeight[0]<columnsHeight[j])
            {
                isAccessToArray();
                columnsHeight[j+gap]=columnsHeight[j];
                emit comparision(j+gap, j);
                j-=gap;
                msleep(sortDelay);
            }
            columnsHeight[j+gap]=columnsHeight[0];
            emit comparision(j+gap, 0);

        }
    }
}

//-----SELECT SORT---------

void Thread::SelectSort()
{
    for(int i=0;i<amount;i++)
    {
        int index=i;
        for(int j=i+1;j<amount;j++)
        {
            if(columnsHeight[index]>columnsHeight[j]) index=j;
            isAccessToArray();

        }
        swap(i,index);
        msleep(sortDelay);
    }
}

//------MERGE SORT---------
void Thread::merge(int arrayBegin, int arrayMid, int arrayEnd)
{
    _vector<double> temp = columnsHeight;
    int i=arrayBegin;
    int j=arrayMid+1;
    int k=arrayBegin;
    while(i<=arrayMid&&j<=arrayEnd)
    {
        if(columnsHeight[i]<=columnsHeight[j])
        {
            emit comparision(k, i);
            temp[k++]=columnsHeight[i++];
            msleep(sortDelay);
        }
        else
        {
            emit comparision(k, j);
            temp[k++]=columnsHeight[j++];
            msleep(sortDelay);
        }
    }
    while(i<=arrayMid)
    {
        emit comparision(k, i);
        temp[k++]=columnsHeight[i++];
        msleep(sortDelay);
    }
    while(j<=arrayEnd)
    {  
        emit comparision(k, j);
        temp[k++]=columnsHeight[j++];
        msleep(sortDelay);
    }
    isAccessToArray();
    for(int i=arrayBegin;i<=arrayEnd;i++)
    {
        columnsHeight[i]=temp[i];
    }
}

//void Thread::mergePass(int h)
//{
//    int start=1;
//    int mid=start+h-1;
//    int end=start+2*h-1;
//    while(end<=amount)
//    {
//        merge(start, mid, end);
//        start+=2*h;
//        mid=start+h-1;
//        end=start+2*h-1;
//    }
//    if(mid<amount)
//        merge(start, mid, amount);
//}

void Thread::mergeSort(int arrayBegin, int arrayEnd)
{
    if(arrayBegin<arrayEnd)
    {
        int mid=(arrayBegin+arrayEnd)/2;
        mergeSort(arrayBegin, mid);
        mergeSort(mid+1,arrayEnd);
        merge(arrayBegin, mid, arrayEnd);
    }
}
