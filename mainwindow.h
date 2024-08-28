#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTreeWidget>
#include "tag.h"
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void insertValue(unsigned short columnNumber, string data, Qt::GlobalColor textColor = Qt::white);
    void handleSelectionChange();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void showTagData();

    void setup();

    QString strToQString(string data);

private:
    Ui::MainWindow *ui;
    Controller controller;
};
#endif // MAINWINDOW_H
