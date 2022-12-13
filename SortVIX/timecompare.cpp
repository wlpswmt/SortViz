#include "timecompare.h"
#include"ui_form.h"
#include"QLabel"

TimeCompare::TimeCompare(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    //配置窗口场景
    this->setWindowTitle("时间性能比较");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //表格填充满
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    ui->tableWidget->setEditTriggers(QAbstractItemView:: NoEditTriggers) ;

    //传输数据


}



void TimeCompare::LinkMachine(_vector<PTABLE_NODE> *TableList)
{
    for(auto it=TableList->begin();it<(TableList->end());++it)
    {
        (*it)->Flink = new TABLE_ITEM;
    }
}






























