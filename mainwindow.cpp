#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    fileName=QFileDialog::getOpenFileName(this, tr("Открыть текст"), "/home/text", tr("Text Files (*.txt)"));
    std::string file = fileName.toUtf8().constData();
    bool flag=false;
    textAnalyzer textAnal(file,&flag);
    if (flag){
        ui->Res->setRowCount(count+1);
        ui->Res->setItem(count,0,new QTableWidgetItem(QString::number(count+1)));
        ui->Res->setItem(count,1,new QTableWidgetItem(QString(fileName)));
        ui->Res->setItem(count,2,new QTableWidgetItem(QString::number(textAnal.strLenght())));
        ui->Res->setItem(count,3,new QTableWidgetItem(QString::number(textAnal.countSpace())));
        ui->Res->setItem(count,4,new QTableWidgetItem(QString::number(textAnal.countSentences())));
        ui->Res->setItem(count,5,new QTableWidgetItem(QString::number(textAnal.countPunctuation())));
        ui->Res->setItem(count,6,new QTableWidgetItem(QString::number(textAnal.countWords())));
        count++;
    }
    else{
        ui->statusbar->showMessage("Некоректное расположение файла");
    }

}

