#include <QFileSystemModel>
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
    QFileSystemModel *fsm = new QFileSystemModel();
    fsm->setRootPath("D:/Movies");
    //fsm->setNameFilters(QString("A*,B*").split(','));

    //ui->m_listView->setCurrentIndex(fsm->index("c:/windows"));
    //ui->m_listView->setModel(fsm);
    ui->m_treeView->setModel(fsm);
}
