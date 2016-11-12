#include <QtGui>
#include <QDebug>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pushButtonOk_clicked()
{
    QStringList sl;

    sl << "Ali" << "Veli" << "Selami" << "Ayşe" << "Fatma";
    QStringListModel *slm = new QStringListModel(sl);

    ui->m_listView->setModel(slm);
    ui->m_treeView->setModel(slm);

    QModelIndex index = slm->index(3);
    QVariant variant = slm->data(index, 0);
    qDebug() << "Before we change the data at index 3 its value = " << variant.toString();
    slm->setData(index, "Tacettin");

    slm->insertRow(1);
    index = slm->index(1);
    slm->setData(index, "Cumhur");

    //slm->sort(0, Qt::DescendingOrder);


}
