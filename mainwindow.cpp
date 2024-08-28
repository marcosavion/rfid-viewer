#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QScreen>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QTreeWidget>
#include <QHeaderView>
#include "utils.h"
#include "tag.h"
#include "controller.h"
#include <iostream>
using namespace std;



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    Controller c;

    this->controller = c;

    ui->setupUi(this);

    move(screen()->geometry().center() - frameGeometry().center());

    QObject::connect(this->ui->treeWidget, &QTreeWidget::itemSelectionChanged, this, &MainWindow::handleSelectionChange);

    setup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief This method resizes header columns
 * treeWidget_fields: All header column have the same size
 * treeWidget: The first one is smaller than other ones
 */
void MainWindow::setup(){

    //treeWidget_fields: Resize all headers equally
    QHeaderView * header = this->ui->treeWidget_fields->header();
    header->setSectionResizeMode(QHeaderView::Stretch);

    //treeWidget
    //First column
    this->ui->treeWidget->setColumnWidth(0,75);

    header = this->ui->treeWidget->header();

    //Remaining columns: same size
    for (int i = 1; i < 5; ++i) {
        header->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

/**
 * @brief Creates a QFileDialog to open a file with .mct o .json extension
 * .json files are not supported yet
 */
void MainWindow::on_actionOpen_triggered()
{

    QString filter = "MIFARE Classic Tool (*.mct);;JSON (*.json)";

    QString fileNamePath = QFileDialog::getOpenFileName(this,"Open File","",filter);

    controller.openFile(fileNamePath.toStdString());

    this->showTagData();
}

/**
 * @brief Shows the Tag information organised
 */
void MainWindow::showTagData(){

    unsigned short cont;

    for(Sector sector: this->controller.getTagData()){

        QTreeWidgetItem *root = new QTreeWidgetItem(this->ui->treeWidget);
        cont = 1;

        root->setText(0, strToQString(sector.getIDStr()));

        root->setTextAlignment(0,Qt::AlignCenter);

        if(!sector.isValid()){
            for(int i=0; i<4;i++){
                root->setText(cont, strToQString(INVALID_STRING_SECTOR));
                root->setForeground(cont, Qt::red);
                root->setTextAlignment(cont,Qt::AlignCenter);
                cont++;
            }
        }
        else{
            for(Block block: sector.getBlocks()){
                root->setText(cont, strToQString(block.toString()));
                root->setTextAlignment(cont,Qt::AlignCenter);
                cont++;
            }
        }


        this->ui->treeWidget->addTopLevelItem(root);
    }

    insertValue(0,this->controller.getUID());
    insertValue(2,this->controller.getManufacturerData());

    //Adding Tag BCC
    QTreeWidgetItem *secondItem = this->ui->treeWidget_fields->topLevelItem(1);
    Qt::GlobalColor bbcColor;

    if(this->controller.checkBCC()){
        bbcColor = Qt::green;
    }else{
        bbcColor = Qt::red;
    }
    if(secondItem){
        secondItem->setText(1, strToQString(this->controller.getBCC()));
        secondItem->setForeground(1,bbcColor);
    }

}


/**
 * @brief Inserts different values in particular column.
 * This method is only for treeWidget_fields. To add information to different fields
 * @param columnNumber
 * @param data
 */
void MainWindow::insertValue(unsigned short columnNumber, string data, Qt::GlobalColor textColor){

    QTreeWidgetItem *item = this->ui->treeWidget_fields->topLevelItem(columnNumber);

    if(item){
        item->setText(1, QString::fromStdString(data).toUpper());
        item->setForeground(1,textColor);
    }
}

/**
 * @brief Changes sector information depending on user selected sector
 */
void MainWindow::handleSelectionChange(){
    QTreeWidgetItem* item = this->ui->treeWidget->currentItem();
    if (item) {
        QString itemText = item->text(0);

        unsigned short sectorNumber = stoi(itemText.toStdString());

        Sector sector = this->controller.getSector(sectorNumber);

        if(!sector.isValid()){
            insertValue(3,INVALID_STRING_SECTOR, Qt::red);
            insertValue(4,INVALID_STRING_SECTOR, Qt::red);
            insertValue(5,INVALID_STRING_SECTOR, Qt::red);

            QTreeWidgetItem *seventhItem = this->ui->treeWidget_fields->topLevelItem(6);

            if(seventhItem){
                seventhItem->setText(1, strToQString(sector.getIDStr()));
                unsigned short cont = 0;

                for(int i=0; i<4; i++){
                    seventhItem->child(cont)->setText(1,strToQString(INVALID_STRING_SECTOR));
                    seventhItem->child(cont)->setForeground(1,Qt::red);
                    cont++;
                }
                seventhItem->setExpanded(true);
            }
        }
        else{
            insertValue(3,this->controller.getPasswordA(sectorNumber));
            insertValue(4,this->controller.getPasswordB(sectorNumber));
            insertValue(5,this->controller.getAccessBits(sectorNumber));

            QTreeWidgetItem *seventhItem = this->ui->treeWidget_fields->topLevelItem(6);

            if(seventhItem){
                seventhItem->setText(1, strToQString(sector.getIDStr()));
                unsigned short cont = 0;

                for(Block block: sector.getBlocks()){
                    seventhItem->child(cont)->setText(1,strToQString(block.toString()));
                    seventhItem->child(cont)->setForeground(1, Qt::white);
                    cont++;
                }
                seventhItem->setExpanded(true);
            }
        }
    }
}


/**
 * @brief Converts a string into QString
 * @param data
 * @return A QString created from normal string
 */
QString MainWindow::strToQString(string data){
    return QString::fromStdString(data).toUpper();
}

