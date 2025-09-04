/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QCalendarWidget *calendarWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableView *financeItemsTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *incomeGroupBox;
    QVBoxLayout *verticalLayout_6;
    QTableView *monthIncomeTableView;
    QGroupBox *expenseGroupBox;
    QVBoxLayout *verticalLayout_5;
    QTableView *monthExpenseTableView;
    QLabel *totalMonthly;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *buttonNewFinanceItem;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setGridVisible(true);

        horizontalLayout->addWidget(calendarWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        financeItemsTableView = new QTableView(tab);
        financeItemsTableView->setObjectName("financeItemsTableView");
        financeItemsTableView->setSortingEnabled(true);

        verticalLayout_3->addWidget(financeItemsTableView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        incomeGroupBox = new QGroupBox(tab_2);
        incomeGroupBox->setObjectName("incomeGroupBox");
        verticalLayout_6 = new QVBoxLayout(incomeGroupBox);
        verticalLayout_6->setObjectName("verticalLayout_6");
        monthIncomeTableView = new QTableView(incomeGroupBox);
        monthIncomeTableView->setObjectName("monthIncomeTableView");

        verticalLayout_6->addWidget(monthIncomeTableView);


        verticalLayout_4->addWidget(incomeGroupBox);

        expenseGroupBox = new QGroupBox(tab_2);
        expenseGroupBox->setObjectName("expenseGroupBox");
        verticalLayout_5 = new QVBoxLayout(expenseGroupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        monthExpenseTableView = new QTableView(expenseGroupBox);
        monthExpenseTableView->setObjectName("monthExpenseTableView");

        verticalLayout_5->addWidget(monthExpenseTableView);


        verticalLayout_4->addWidget(expenseGroupBox);

        totalMonthly = new QLabel(tab_2);
        totalMonthly->setObjectName("totalMonthly");

        verticalLayout_4->addWidget(totalMonthly);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        buttonNewFinanceItem = new QPushButton(centralwidget);
        buttonNewFinanceItem->setObjectName("buttonNewFinanceItem");

        horizontalLayout_2->addWidget(buttonNewFinanceItem);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "excel file", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Daily view", nullptr));
        incomeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Income", nullptr));
        expenseGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Expense", nullptr));
        totalMonthly->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Monthly view", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "search", nullptr));
        buttonNewFinanceItem->setText(QCoreApplication::translate("MainWindow", "Add entry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
