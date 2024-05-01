/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QSplitter *splitter_8;
    QSplitter *splitter_5;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QSplitter *splitter_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSplitter *splitter_7;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QSplitter *splitter_9;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QWidget *tab_6;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_7;
    QTableWidget *tableWidget_3;
    QTableWidget *tableWidget_4;
    QLabel *label_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QComboBox *comboBox;
    QPushButton *pushButton_10;
    QWidget *tab_9;
    QPushButton *pushButton_13;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_12;
    QSplitter *splitter_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_11;
    QSplitter *splitter_3;
    QLabel *label_6;
    QListWidget *listWidget_5;
    QSplitter *splitter_4;
    QLabel *label_9;
    QListWidget *listWidget_6;
    QWidget *tab_10;
    QListWidget *listWidget_7;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QProgressBar *progressBar;
    QLabel *label_14;
    QProgressBar *progressBar_2;
    QLabel *label_15;
    QProgressBar *progressBar_3;
    QLabel *label_16;
    QProgressBar *progressBar_4;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(632, 453);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(8, 0, 631, 723));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMovable(true);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        splitter_8 = new QSplitter(tab_5);
        splitter_8->setObjectName("splitter_8");
        splitter_8->setGeometry(QRect(0, 10, 301, 291));
        splitter_8->setOrientation(Qt::Vertical);
        splitter_5 = new QSplitter(splitter_8);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setOrientation(Qt::Horizontal);
        nameLabel = new QLabel(splitter_5);
        nameLabel->setObjectName("nameLabel");
        splitter_5->addWidget(nameLabel);
        nameLineEdit = new QLineEdit(splitter_5);
        nameLineEdit->setObjectName("nameLineEdit");
        splitter_5->addWidget(nameLineEdit);
        pushButton = new QPushButton(splitter_5);
        pushButton->setObjectName("pushButton");
        splitter_5->addWidget(pushButton);
        splitter_8->addWidget(splitter_5);
        tableWidget = new QTableWidget(splitter_8);
        tableWidget->setObjectName("tableWidget");
        splitter_8->addWidget(tableWidget);
        splitter_6 = new QSplitter(splitter_8);
        splitter_6->setObjectName("splitter_6");
        splitter_6->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter_6);
        pushButton_2->setObjectName("pushButton_2");
        splitter_6->addWidget(pushButton_2);
        pushButton_3 = new QPushButton(splitter_6);
        pushButton_3->setObjectName("pushButton_3");
        splitter_6->addWidget(pushButton_3);
        splitter_8->addWidget(splitter_6);
        splitter_7 = new QSplitter(splitter_8);
        splitter_7->setObjectName("splitter_7");
        splitter_7->setOrientation(Qt::Horizontal);
        pushButton_20 = new QPushButton(splitter_7);
        pushButton_20->setObjectName("pushButton_20");
        splitter_7->addWidget(pushButton_20);
        pushButton_21 = new QPushButton(splitter_7);
        pushButton_21->setObjectName("pushButton_21");
        splitter_7->addWidget(pushButton_21);
        splitter_8->addWidget(splitter_7);
        splitter_9 = new QSplitter(tab_5);
        splitter_9->setObjectName("splitter_9");
        splitter_9->setGeometry(QRect(330, 10, 256, 408));
        splitter_9->setOrientation(Qt::Vertical);
        label = new QLabel(splitter_9);
        label->setObjectName("label");
        splitter_9->addWidget(label);
        listWidget = new QListWidget(splitter_9);
        listWidget->setObjectName("listWidget");
        splitter_9->addWidget(listWidget);
        label_2 = new QLabel(splitter_9);
        label_2->setObjectName("label_2");
        splitter_9->addWidget(label_2);
        listWidget_2 = new QListWidget(splitter_9);
        listWidget_2->setObjectName("listWidget_2");
        splitter_9->addWidget(listWidget_2);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        label_3 = new QLabel(tab_6);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 91, 16));
        lineEdit = new QLineEdit(tab_6);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 20, 71, 20));
        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(200, 20, 80, 18));
        tableWidget_3 = new QTableWidget(tab_6);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(20, 50, 256, 171));
        tableWidget_4 = new QTableWidget(tab_6);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(320, 50, 256, 171));
        label_4 = new QLabel(tab_6);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 20, 151, 16));
        pushButton_8 = new QPushButton(tab_6);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 260, 121, 21));
        pushButton_9 = new QPushButton(tab_6);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(150, 260, 121, 21));
        comboBox = new QComboBox(tab_6);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(90, 230, 111, 22));
        pushButton_10 = new QPushButton(tab_6);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(100, 290, 80, 18));
        tabWidget->addTab(tab_6, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        pushButton_13 = new QPushButton(tab_9);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(70, 100, 80, 18));
        splitter = new QSplitter(tab_9);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(10, 40, 205, 50));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_3);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_4);

        splitter->addWidget(layoutWidget);
        pushButton_12 = new QPushButton(splitter);
        pushButton_12->setObjectName("pushButton_12");
        splitter->addWidget(pushButton_12);
        splitter_2 = new QSplitter(tab_9);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setGeometry(QRect(12, 11, 202, 22));
        splitter_2->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_2);
        label_5->setObjectName("label_5");
        splitter_2->addWidget(label_5);
        lineEdit_2 = new QLineEdit(splitter_2);
        lineEdit_2->setObjectName("lineEdit_2");
        splitter_2->addWidget(lineEdit_2);
        pushButton_11 = new QPushButton(splitter_2);
        pushButton_11->setObjectName("pushButton_11");
        splitter_2->addWidget(pushButton_11);
        splitter_3 = new QSplitter(tab_9);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setGeometry(QRect(10, 170, 241, 204));
        splitter_3->setOrientation(Qt::Vertical);
        label_6 = new QLabel(splitter_3);
        label_6->setObjectName("label_6");
        splitter_3->addWidget(label_6);
        listWidget_5 = new QListWidget(splitter_3);
        listWidget_5->setObjectName("listWidget_5");
        splitter_3->addWidget(listWidget_5);
        splitter_4 = new QSplitter(tab_9);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setGeometry(QRect(270, 170, 256, 204));
        splitter_4->setOrientation(Qt::Vertical);
        label_9 = new QLabel(splitter_4);
        label_9->setObjectName("label_9");
        splitter_4->addWidget(label_9);
        listWidget_6 = new QListWidget(splitter_4);
        listWidget_6->setObjectName("listWidget_6");
        splitter_4->addWidget(listWidget_6);
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        listWidget_7 = new QListWidget(tab_10);
        listWidget_7->setObjectName("listWidget_7");
        listWidget_7->setGeometry(QRect(254, 10, 254, 71));
        pushButton_18 = new QPushButton(tab_10);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(150, 100, 101, 18));
        pushButton_19 = new QPushButton(tab_10);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(270, 100, 80, 18));
        layoutWidget1 = new QWidget(tab_10);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(120, 170, 311, 135));
        gridLayout_5 = new QGridLayout(layoutWidget1);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName("label_13");

        gridLayout_5->addWidget(label_13, 0, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout_5->addWidget(progressBar, 0, 1, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName("label_14");

        gridLayout_5->addWidget(label_14, 1, 0, 1, 1);

        progressBar_2 = new QProgressBar(layoutWidget1);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setValue(24);

        gridLayout_5->addWidget(progressBar_2, 1, 1, 1, 1);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName("label_15");

        gridLayout_5->addWidget(label_15, 2, 0, 1, 1);

        progressBar_3 = new QProgressBar(layoutWidget1);
        progressBar_3->setObjectName("progressBar_3");
        progressBar_3->setValue(24);

        gridLayout_5->addWidget(progressBar_3, 2, 1, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName("label_16");

        gridLayout_5->addWidget(label_16, 3, 0, 1, 1);

        progressBar_4 = new QProgressBar(layoutWidget1);
        progressBar_4->setObjectName("progressBar_4");
        progressBar_4->setValue(24);

        gridLayout_5->addWidget(progressBar_4, 3, 1, 1, 1);

        layoutWidget2 = new QWidget(tab_10);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(40, 10, 292, 100));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(layoutWidget2);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout_4->addWidget(lineEdit_5, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_14 = new QPushButton(layoutWidget2);
        pushButton_14->setObjectName("pushButton_14");

        gridLayout->addWidget(pushButton_14, 0, 0, 1, 1);

        pushButton_15 = new QPushButton(layoutWidget2);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout->addWidget(pushButton_15, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 2, 3, 1);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName("label_11");

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName("label_12");

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        lineEdit_7 = new QLineEdit(layoutWidget2);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout_4->addWidget(lineEdit_7, 2, 1, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget2);
        comboBox_2->setObjectName("comboBox_2");

        gridLayout_4->addWidget(comboBox_2, 1, 1, 1, 1);

        tabWidget->addTab(tab_10, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 632, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Number of people", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Load Previous Config", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Original balances", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Reduced balances", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Debt Simplifier", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Number of locations", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Shortest distance between each location", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Calculate Minimum Distance", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Calculate Minimum Path", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Travel Helper", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Item Name", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Max Budget", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Items", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Combinations", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Best Combination", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Load Previous Config", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Maintanence", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Grocieries", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Bills", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Miscellaneous", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Add Transaction", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Expense Tracker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
