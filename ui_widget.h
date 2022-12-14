/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortVIX
{
public:
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *cellsToSortBackground;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *on_time_comparison;
    QPushButton *change_num_disorder;
    QPushButton *change_num_to_order;
    QPushButton *change_num_to_re_order;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelArrayAccesses;
    QLabel *LabelArrayAccesses_var;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LabelComparisions;
    QLabel *LabelComparisions_var;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelSortingWith;
    QLabel *LabelSortingWith_var;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *RunTime;
    QLabel *LabelRunTime_var;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *LabelAmountChanger;
    QSpinBox *amountChanger;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LabelDelayChanger;
    QSpinBox *delayChanger;
    QListWidget *algorithmSelection;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *sortButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *SortVIX)
    {
        if (SortVIX->objectName().isEmpty())
            SortVIX->setObjectName(QString::fromUtf8("SortVIX"));
        SortVIX->resize(1374, 720);
        SortVIX->setStyleSheet(QString::fromUtf8("QWidget {\n"
"  background-color: #fff;\n"
"	font: 25 11pt \"Roboto Light\";\n"
"	color: rgba(0, 0, 0, 100);\n"
"}\n"
"\n"
"#sortButton {\n"
"	border:none;\n"
"	background-color:  rgba(255, 0, 68,100);\n"
"	border-radius: 15%;\n"
"	font: 11pt \"Roboto\";\n"
"	color: #fff;\n"
"}\n"
"\n"
"#amountChanger, #delayChanger {\n"
"  padding-right: 10px;\n"
"	padding-left: 10px;\n"
"	border: 1px solid  rgba(255, 0, 68, 150);\n"
"	border-radius: 3%;\n"
"	background-color: #f5f5f5;\n"
"	font: 11pt \"Roboto\";\n"
"	color: rgb(255, 0, 68);\n"
"}\n"
"\n"
"#amountChanger::up-button:pressed, #amountChanger::down-button:pressed,\n"
"#delayChanger ::up-button:pressed, #delayChanger::down-button:pressed{\n"
" background-color: rgab(220, 0, 58, 255);\n"
"}\n"
"\n"
"#amountChanger::up-button, #amountChanger::down-button,\n"
"#delayChanger::up-button, #delayChanger::down-button {\n"
"  width: 16px;\n"
"  background-color: rgba(255, 0, 68, 150);\n"
"}\n"
"#amountChanger::down-button,\n"
"#delayChanger::down-button  {\n"
"	border-top:"
                        " 1px solid rgba(255, 0, 68, 180);\n"
"}\n"
"\n"
"#amountChanger::down-button:hover, #amountChanger::up-button:hover,\n"
"#delayChanger::down-button:hover, #delayChanger::up-button:hover {\n"
" background-color:rgba(255, 0, 68, 255);\n"
"}\n"
"\n"
"#amountChanger::up-button:disabled,#amountChanger::up-button:off,\n"
"#amountChanger::down-button:disabled,#amountChanger::down-button:off,\n"
"#delayChanger::up-button:disabled,#delayChanger::up-button:off,\n"
"#delayChanger::down-button:disabled,#delayChanger::down-button:off{\n"
"  background-color: rgba(0, 0, 0, 20)\n"
"}\n"
"\n"
"#amountChanger::down-button:disabled,#amountChanger::down-button:off,\n"
"#delayChanger::down-button:disabled,#delayChanger::down-button:off{\n"
"  border-top: 1px solid rgba(0, 0, 0, 20);\n"
"}\n"
"#amountChanger:disabled, #amountChanger:off,\n"
"#delayChanger:disabled, #delayChanger:off{\n"
"  border: 1px solid rgba(0, 0, 0, 20);\n"
"  color:  rgba(0, 0, 0, 50);\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(SortVIX);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cellsToSortBackground = new QGraphicsView(SortVIX);
        cellsToSortBackground->setObjectName(QString::fromUtf8("cellsToSortBackground"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cellsToSortBackground->sizePolicy().hasHeightForWidth());
        cellsToSortBackground->setSizePolicy(sizePolicy);
        cellsToSortBackground->setMinimumSize(QSize(1000, 700));
        cellsToSortBackground->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(31, 31, 31)"));
        cellsToSortBackground->setFrameShape(QFrame::NoFrame);
        cellsToSortBackground->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cellsToSortBackground->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        cellsToSortBackground->setAlignment(Qt::AlignCenter);
        cellsToSortBackground->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        horizontalLayout->addWidget(cellsToSortBackground);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        frame = new QFrame(SortVIX);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        on_time_comparison = new QPushButton(frame);
        on_time_comparison->setObjectName(QString::fromUtf8("on_time_comparison"));

        verticalLayout->addWidget(on_time_comparison);

        change_num_disorder = new QPushButton(frame);
        change_num_disorder->setObjectName(QString::fromUtf8("change_num_disorder"));

        verticalLayout->addWidget(change_num_disorder);

        change_num_to_order = new QPushButton(frame);
        change_num_to_order->setObjectName(QString::fromUtf8("change_num_to_order"));

        verticalLayout->addWidget(change_num_to_order);

        change_num_to_re_order = new QPushButton(frame);
        change_num_to_re_order->setObjectName(QString::fromUtf8("change_num_to_re_order"));

        verticalLayout->addWidget(change_num_to_re_order);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMinimumSize);
        LabelArrayAccesses = new QLabel(frame);
        LabelArrayAccesses->setObjectName(QString::fromUtf8("LabelArrayAccesses"));
        LabelArrayAccesses->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(LabelArrayAccesses);

        LabelArrayAccesses_var = new QLabel(frame);
        LabelArrayAccesses_var->setObjectName(QString::fromUtf8("LabelArrayAccesses_var"));
        LabelArrayAccesses_var->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 150);"));

        horizontalLayout_5->addWidget(LabelArrayAccesses_var);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        LabelComparisions = new QLabel(frame);
        LabelComparisions->setObjectName(QString::fromUtf8("LabelComparisions"));
        LabelComparisions->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(LabelComparisions);

        LabelComparisions_var = new QLabel(frame);
        LabelComparisions_var->setObjectName(QString::fromUtf8("LabelComparisions_var"));
        LabelComparisions_var->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 150);"));

        horizontalLayout_3->addWidget(LabelComparisions_var);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        LabelSortingWith = new QLabel(frame);
        LabelSortingWith->setObjectName(QString::fromUtf8("LabelSortingWith"));
        LabelSortingWith->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(LabelSortingWith);

        LabelSortingWith_var = new QLabel(frame);
        LabelSortingWith_var->setObjectName(QString::fromUtf8("LabelSortingWith_var"));
        LabelSortingWith_var->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 150);"));

        horizontalLayout_2->addWidget(LabelSortingWith_var);


        verticalLayout->addLayout(horizontalLayout_2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        RunTime = new QLabel(widget);
        RunTime->setObjectName(QString::fromUtf8("RunTime"));

        horizontalLayout_9->addWidget(RunTime);

        LabelRunTime_var = new QLabel(widget);
        LabelRunTime_var->setObjectName(QString::fromUtf8("LabelRunTime_var"));

        horizontalLayout_9->addWidget(LabelRunTime_var);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        LabelAmountChanger = new QLabel(frame);
        LabelAmountChanger->setObjectName(QString::fromUtf8("LabelAmountChanger"));
        LabelAmountChanger->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_6->addWidget(LabelAmountChanger);

        amountChanger = new QSpinBox(frame);
        amountChanger->setObjectName(QString::fromUtf8("amountChanger"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(amountChanger->sizePolicy().hasHeightForWidth());
        amountChanger->setSizePolicy(sizePolicy2);
        amountChanger->setMinimumSize(QSize(0, 0));
        amountChanger->setCursor(QCursor(Qt::PointingHandCursor));
        amountChanger->setStyleSheet(QString::fromUtf8(""));
        amountChanger->setReadOnly(false);
        amountChanger->setMinimum(5);
        amountChanger->setMaximum(999999999);
        amountChanger->setSingleStep(50);
        amountChanger->setValue(500);
        amountChanger->setDisplayIntegerBase(10);

        horizontalLayout_6->addWidget(amountChanger);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LabelDelayChanger = new QLabel(frame);
        LabelDelayChanger->setObjectName(QString::fromUtf8("LabelDelayChanger"));
        LabelDelayChanger->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(LabelDelayChanger);

        delayChanger = new QSpinBox(frame);
        delayChanger->setObjectName(QString::fromUtf8("delayChanger"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(delayChanger->sizePolicy().hasHeightForWidth());
        delayChanger->setSizePolicy(sizePolicy3);
        delayChanger->setMinimumSize(QSize(68, 0));
        delayChanger->setCursor(QCursor(Qt::PointingHandCursor));
        delayChanger->setStyleSheet(QString::fromUtf8(""));
        delayChanger->setMinimum(1);
        delayChanger->setMaximum(20);
        delayChanger->setSingleStep(1);
        delayChanger->setValue(1);
        delayChanger->setDisplayIntegerBase(10);

        horizontalLayout_7->addWidget(delayChanger);


        verticalLayout->addLayout(horizontalLayout_7);

        algorithmSelection = new QListWidget(frame);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(algorithmSelection);
        __qlistwidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        new QListWidgetItem(algorithmSelection);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(algorithmSelection);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        new QListWidgetItem(algorithmSelection);
        algorithmSelection->setObjectName(QString::fromUtf8("algorithmSelection"));
        algorithmSelection->setStyleSheet(QString::fromUtf8("border: 1px solid rgba(0,0,0,30);\n"
"padding-top: 20px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"color: rgba(0,0,0,120);\n"
"font: 87 14pt \"Roboto Light\";"));
        algorithmSelection->setFrameShape(QFrame::StyledPanel);
        algorithmSelection->setFrameShadow(QFrame::Sunken);
        algorithmSelection->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        algorithmSelection->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        algorithmSelection->setDragDropMode(QAbstractItemView::InternalMove);
        algorithmSelection->setSelectionMode(QAbstractItemView::SingleSelection);
        algorithmSelection->setSelectionBehavior(QAbstractItemView::SelectRows);
        algorithmSelection->setTextElideMode(Qt::ElideLeft);
        algorithmSelection->setLayoutMode(QListView::Batched);

        verticalLayout->addWidget(algorithmSelection);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        sortButton = new QPushButton(frame);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sizePolicy2.setHeightForWidth(sortButton->sizePolicy().hasHeightForWidth());
        sortButton->setSizePolicy(sizePolicy2);
        sortButton->setMinimumSize(QSize(176, 30));
        sortButton->setCursor(QCursor(Qt::PointingHandCursor));
        sortButton->setStyleSheet(QString::fromUtf8(""));
        sortButton->setFlat(false);

        horizontalLayout_4->addWidget(sortButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(frame);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        retranslateUi(SortVIX);

        QMetaObject::connectSlotsByName(SortVIX);
    } // setupUi

    void retranslateUi(QWidget *SortVIX)
    {
        SortVIX->setWindowTitle(QCoreApplication::translate("SortVIX", "SortVIX", nullptr));
        on_time_comparison->setText(QCoreApplication::translate("SortVIX", "\346\200\247\350\203\275\346\257\224\350\276\203", nullptr));
        change_num_disorder->setText(QCoreApplication::translate("SortVIX", "\344\271\261\345\272\217\346\225\260", nullptr));
        change_num_to_order->setText(QCoreApplication::translate("SortVIX", "\346\255\243\345\272\217\346\225\260", nullptr));
        change_num_to_re_order->setText(QCoreApplication::translate("SortVIX", "\351\200\206\345\272\217\346\225\260", nullptr));
        LabelArrayAccesses->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Array Accesses:</p></body></html>", nullptr));
        LabelArrayAccesses_var->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>0</p></body></html>", nullptr));
        LabelComparisions->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Comparisions:</p></body></html>", nullptr));
        LabelComparisions_var->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>0</p></body></html>", nullptr));
        LabelSortingWith->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Sorting with:</p></body></html>", nullptr));
        LabelSortingWith_var->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Select an algorithm..</p></body></html>", nullptr));
        RunTime->setText(QCoreApplication::translate("SortVIX", "RunTime:", nullptr));
        LabelRunTime_var->setText(QCoreApplication::translate("SortVIX", "0", nullptr));
        LabelAmountChanger->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Amount of columns</p></body></html>", nullptr));
        LabelDelayChanger->setText(QCoreApplication::translate("SortVIX", "<html><head/><body><p>Delay</p></body></html>", nullptr));

        const bool __sortingEnabled = algorithmSelection->isSortingEnabled();
        algorithmSelection->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = algorithmSelection->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("SortVIX", "Bubble Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = algorithmSelection->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("SortVIX", "Recursive Bubble Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = algorithmSelection->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("SortVIX", "Cocktail Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = algorithmSelection->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("SortVIX", "Gnome Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = algorithmSelection->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("SortVIX", "Quick Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = algorithmSelection->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("SortVIX", "Heap Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = algorithmSelection->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("SortVIX", "Insert Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = algorithmSelection->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("SortVIX", "select Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = algorithmSelection->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("SortVIX", "Shell Sort", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = algorithmSelection->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("SortVIX", "Merge Sort", nullptr));
        algorithmSelection->setSortingEnabled(__sortingEnabled);

        sortButton->setText(QCoreApplication::translate("SortVIX", "sort", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortVIX: public Ui_SortVIX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
