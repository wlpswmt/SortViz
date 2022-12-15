#include "visualization.h"
#include "ui_widget.h"
#include"timecompare.h"
#include <random>
#include <algorithm>
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //时间性能比较窗口
    time_comparison_scene =new TimeCompare;
    //time_comparison_scene->setWindowTitle("时间性能比较");
    //scene = new QGraphicsScene(time_comparison_scene);


    ui->on_time_comparison->setParent(this);
    ui->on_time_comparison->move(1150,30);
    ui->on_time_comparison->resize(200,30);
    connect(ui->on_time_comparison,&QPushButton::clicked,time_comparison_scene,[=](){
        QTimer::singleShot(500,this,[=](){
            //自身隐藏
            // this->hide();
           time_comparison_scene->show();
        });

      });


    //搭建可放置二维图形的QGraphicScene
    scene = new QGraphicsScene(this);
    ui->cellsToSortBackground->setScene(scene);
    ui->cellsToSortBackground->verticalScrollBar()->blockSignals(true);
    ui->cellsToSortBackground->horizontalScrollBar()->blockSignals(true);

    //配置变量
    appStates = -1; // (-1) - App started

    sceneHeight = ui->cellsToSortBackground->size().height();
    sceneWidth = ui->cellsToSortBackground->size().width();
    comparisions = 0;

    //自定义WidgetList 初始化QMap
    for(int i=0; i < ui->algorithmSelection->count(); i++)
    {
        QListWidgetItem * item = ui->algorithmSelection->item(i);
        item -> setSizeHint(QSize(item->sizeHint().width(), 50));
        AlgorithmList.insert(i, item->text());
        //TimeCompare::InsertNode(item->text());
       // TableWidgetItem->AlgorithmsName[i]=(item->text());
    }

    //不可按
    ui->amountChanger->setDisabled(true);
    ui->delayChanger->setDisabled(true);
    ui->sortButton->setDisabled(true);

    //延迟1ms,初始化100个。
    columnsSetUp(1, 100, 0);
}

void Widget::columnsSetUp(int ms, int n, int model)
{
    //configuring variables
    ui->LabelComparisions_var->setNum(0);
    ui->LabelArrayAccesses_var->setNum(0);
    sortDelay = ms;
    amountOfColumns = n;
    columnsWidth = sceneWidth / amountOfColumns;

    //setting up columns to sort
    columns.resize(static_cast<unsigned>(amountOfColumns));

    //setting up columns height
    double incrementBy = sceneHeight / amountOfColumns;
    for(auto i = incrementBy; i <= sceneHeight; i += incrementBy)
        columnsHeight.push_back(i);

    //randomize an array
    std::random_device m_random;
    std::mt19937 e_random(m_random());
    switch(model)
    {
    case 0: std::shuffle(columnsHeight.begin(), columnsHeight.end(), e_random); break;
    case 1: break;
    case 2: std::sort(columnsHeight.begin(), columnsHeight.end(),[](int a, int b){
            return b<a;
        });break;
    }



    //aplying columns to scene
    auto j = 0;
    auto k = 0.0;
    for(auto &p : columns)
    {
        p = new QGraphicsRectItem;
        p->setRect(k, (sceneHeight - columnsHeight[j]), columnsWidth , columnsHeight[j]);
        p->setBrush(QBrush(QColor(255, 0, 68, 255)));

        if(amountOfColumns <= 200)
            p->setPen(QPen(Qt::black, 2));
        else if(amountOfColumns > 200 && amountOfColumns <= 300)
            p->setPen(QPen(Qt::black, 1));
        else
            p->setPen(Qt::NoPen);

        scene->addItem(p);

        j++;
        k += columnsWidth;
    }
}

void Widget::resetColumns(int ms, int n, int model)
{
    for(auto &p : columns)
        scene->removeItem(p);

    columnsHeight.clear();
    columnsSetUp(ms, n, model);
    threadUpdate(sortDelay, algorithmKey);
}

void Widget::threadUpdate(int ms, int key)
{
    mThread = new Thread(ms, key, static_cast<int>(amountOfColumns), columnsHeight, this);

    connect(mThread, SIGNAL(comparision(int, int)), this, SLOT(on_comparision(int, int)));
    connect(mThread, SIGNAL(sortDone(int, int)), this, SLOT(sortDone(int, int)));
    connect(mThread, SIGNAL(arrayAccess(int)), ui->LabelArrayAccesses_var, SLOT(setNum(int)));     //SLOT(setNum(int))
    connect(mThread, SIGNAL(changeButtonStatus(int)), this, SLOT(sortButtonStatus(int)));
}

void Widget::on_algorithmSelection_itemClicked(QListWidgetItem *item)
{
    if(appStates == -1)
    {
        ui->sortButton->setEnabled(true);
        ui->amountChanger->setEnabled(true);
        ui->delayChanger->setEnabled(true);

        appStates = 0;
        sortButtonStatus(appStates);
    }

    if(appStates == 0)
    {
        algorithmKey = AlgorithmList.key(item->text());
        ui->LabelSortingWith_var->setText(item->text());
    }
}

void Widget::on_amountChanger_valueChanged(int n)
{
    if(appStates == 0)
        resetColumns(sortDelay, n, 0);
}

void Widget::on_delayChanger_valueChanged(int ms)
{
    if(appStates == 0)
        resetColumns(ms, static_cast<int>(amountOfColumns), 0);
}


void Widget::on_sortButton_clicked()
{
    switch(appStates)
    {
        case 0:
            sortButtonStatus(1);
            comparisions = 0;
            threadUpdate(sortDelay, algorithmKey);
            mThread->start();
            break;

        case 1:
            mThread->terminate();
            sortButtonStatus(2);
            break;

        case 2:
            for(auto &p : columns)
                scene->removeItem(p);

            columnsHeight.clear();
            columnsSetUp(sortDelay, static_cast<int>(amountOfColumns), 0);
            sortButtonStatus(0);
            break;

        default:
            break;
    }
}

void Widget::sortButtonStatus(int state)
{
    QString buttonText;
    QString style;

    switch(state)
    {
    case 0:
        buttonText = "sort";
        ui->amountChanger->setEnabled(true);
        ui->delayChanger->setEnabled(true);
        ui->algorithmSelection->setEnabled(true);
        style = "background-color: rgba(255, 0, 68, 255); color: #fff";
        break;

    case 1:
        buttonText = "cancel";
        ui->amountChanger->setDisabled(true);
        ui->delayChanger->setDisabled(true);
        ui->algorithmSelection->setDisabled(true);
        style = "background-color: #000; color: #fff";
        break;

    case 2:
        buttonText = "new sort";
        ui->sortButton->setEnabled(true);
        style = "background-color: rgb(85, 0, 255); color: #fff";
        break;
    }

    appStates = state;
    ui->sortButton->setText(buttonText);
    ui->sortButton->setStyleSheet(style);
}

void Widget::on_comparision(int n, int k)
{
    auto nRect = columns[n]->rect();
    auto kRect = columns[k]->rect();
    auto nColumnPos = nRect.left();
    auto kColumnPos = kRect.left();

    nRect.moveLeft(kColumnPos);
    kRect.moveLeft(nColumnPos);

    columns[n]->setRect(nRect);
    columns[k]->setRect(kRect);

    std::swap(columns[n], columns[k]);

    comparisions++;
    ui->LabelComparisions_var->setNum(comparisions);
}

void Widget::sortDone(int n, int sortWith)
{
    columns[n]->setBrush(QBrush(QColor(0,200,0)));
    time_comparison_scene->SetData(sortWith, 0, new QTableWidgetItem(ui->LabelArrayAccesses_var->text()));
    time_comparison_scene->SetData(sortWith, 1, new QTableWidgetItem(ui->LabelComparisions_var->text()));
    // time_comparison_scene->SetData(sortWith, 3, new QTableWidgetItem(ui->LabelArrayAccesses->text()));
}

Widget::~Widget()
{
    mThread->terminate();
    delete ui;
}


void Widget::on_change_num_disorder_clicked()
{
    for(auto &p : columns)
        scene->removeItem(p);

    columnsHeight.clear();
    columnsSetUp(1, columns.size(), 0);
    threadUpdate(sortDelay, algorithmKey);
}

void Widget::on_change_num_to_order_clicked()
{
    for(auto &p : columns)
        scene->removeItem(p);

    columnsHeight.clear();
    columnsSetUp(1, columns.size(), 1);
    threadUpdate(sortDelay, algorithmKey);
}

void Widget::on_change_num_to_re_order_clicked()
{
    for(auto &p : columns)
        scene->removeItem(p);

    columnsHeight.clear();
    columnsSetUp(1, columns.size(), 2);
    threadUpdate(sortDelay, algorithmKey);
}
