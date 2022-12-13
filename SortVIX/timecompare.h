#ifndef TIMECOMPARE_H
#define TIMECOMPARE_H

#include <QWidget>
#include <QtWidgets>
#include"MyVector.h"

typedef struct _TABLE_ITEM_{
    QString AlgorithmsName;
    int comparsions=0;
    int arrayAccess=0;
    int runtime=0;
}TABLE_ITEM,*PTABLE_ITEM;

typedef struct _TABLE_NODE_{
    PTABLE_ITEM Flink;
}TABLE_NODE,*PTABLE_NODE;

namespace Ui {
class Form;
}
class TimeCompare : public QWidget
{
    Q_OBJECT
public:
    explicit TimeCompare(QWidget *parent = nullptr);
    _vector<PTABLE_NODE> TableList;
    void LinkMachine(_vector<PTABLE_NODE>* TableList);

signals:
private:
    Ui::Form* ui;

};




#endif // TIMECOMPARE_H
