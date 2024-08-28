/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Data;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeWidget *treeWidget;
    QTreeWidget *treeWidget_fields;
    QWidget *Hack;
    QMenuBar *menubar;
    QMenu *menuOpen;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1262, 667);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpen->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop));
        actionExit->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setCursor(QCursor(Qt::CursorShape::OpenHandCursor));
        centralwidget->setMouseTracking(true);
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        Data = new QWidget();
        Data->setObjectName("Data");
        gridLayout = new QGridLayout(Data);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        label = new QLabel(Data);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setMargin(2);

        verticalLayout->addWidget(label);

        treeWidget = new QTreeWidget(Data);
        QFont font;
        font.setBold(false);
        font.setUnderline(true);
        QFont font1;
        font1.setUnderline(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem->setFont(4, font1);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem->setFont(3, font1);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem->setFont(2, font1);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setAutoFillBackground(false);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setIndentation(0);
        treeWidget->setItemsExpandable(false);
        treeWidget->header()->setCascadingSectionResizes(false);

        verticalLayout->addWidget(treeWidget);

        treeWidget_fields = new QTreeWidget(Data);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignCenter);
        treeWidget_fields->setHeaderItem(__qtreewidgetitem1);
        new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(treeWidget_fields);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget_fields);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget_fields->setObjectName("treeWidget_fields");
        treeWidget_fields->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        treeWidget_fields->setAlternatingRowColors(true);
        treeWidget_fields->setIndentation(10);
        treeWidget_fields->setUniformRowHeights(false);

        verticalLayout->addWidget(treeWidget_fields);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(Data, QString());
        Hack = new QWidget();
        Hack->setObjectName("Hack");
        tabWidget->addTab(Hack, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1262, 23));
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addSeparator();
        menuOpen->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RFID Card Data", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("MainWindow", "Block 3", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "Block 2", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Block 1", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Block 0", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Sector ", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_fields->headerItem();
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "Field", nullptr));

        const bool __sortingEnabled = treeWidget_fields->isSortingEnabled();
        treeWidget_fields->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_fields->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "UID", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget_fields->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "BBC", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_fields->topLevelItem(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "Manufacturer Data", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget_fields->topLevelItem(3);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "Key A", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget_fields->topLevelItem(4);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "Key B", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_fields->topLevelItem(5);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("MainWindow", "Access Bit", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget_fields->topLevelItem(6);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("MainWindow", "Block Contents", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("MainWindow", "Block 0 content", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("MainWindow", "Block 1 content", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(2);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("MainWindow", "Block 2 content", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(3);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("MainWindow", "Block 3 content", nullptr));
        treeWidget_fields->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(Data), QCoreApplication::translate("MainWindow", "Data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Hack), QCoreApplication::translate("MainWindow", "Hack", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
