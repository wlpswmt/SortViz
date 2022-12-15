#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include"timecompare.h"

#include "algorithms.h"

namespace Ui {
class SortVIX;
}

class Thread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    TimeCompare* time_comparison_scene = NULL;

    ~Widget();

private slots:
    void on_sortButton_clicked();
    void on_algorithmSelection_itemClicked(QListWidgetItem*);
    void on_amountChanger_valueChanged(int);
    void on_delayChanger_valueChanged(int);

    void on_RunTime();
    void on_comparision(int, int);
    void sortButtonStatus(int);
    void sortDone(int, int);
    void resetColumns(int, int, int);

    void on_change_num_disorder_clicked();

    void on_change_num_to_order_clicked();

    void on_change_num_to_re_order_clicked();

private:
    Ui::SortVIX *ui;
    Thread *mThread;  //子线程
    QTimer *timer1;
    QGraphicsScene *scene;
    int timer_i;
    //设置数组
    void columnsSetUp(int, int, int);
    // 更新线程
    void threadUpdate(int, int);

    _vector<QGraphicsRectItem*> columns;
    _vector<double> columnsHeight;

    QMap<int, QString> AlgorithmList;

    // 延迟
    int sortDelay;

    double columnsWidth;
    double sceneHeight;
    double sceneWidth;

    int amountOfColumns;
    int comparisions;

    // 算法键值
    int algorithmKey;

    // (-1) - App started, 0 - App ready to sort, (1) - App sorting, (2) - App sorted  程序运行状态
    int appStates;
};

#endif // WIDGET_H
