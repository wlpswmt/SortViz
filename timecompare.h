#ifndef TIMECOMPARE_H
#define TIMECOMPARE_H

#include <QWidget>
#include <QtWidgets>
#include"MyVector.h"

namespace Ui {
class Form;
}
class TimeCompare : public QWidget
{
    Q_OBJECT
public:
    explicit TimeCompare(QWidget *parent = nullptr);
    void SetData(int, int, QTableWidgetItem*);

signals:
private:
    Ui::Form* ui;

};




#endif // TIMECOMPARE_H
