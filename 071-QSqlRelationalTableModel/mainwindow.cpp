#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setUserName("root");
    m_db.setPassword("$Oz502024");
    m_db.setDatabaseName("world");
    m_db.open();

    m_rtm = new QSqlRelationalTableModel();
    m_rtm->setTable("city");
    m_rtm->setRelation(2, QSqlRelation("country", "Code", "Name"));

    m_rtm->setHeaderData(1, Qt::Horizontal, "Şehir");
    m_rtm->setHeaderData(2, Qt::Horizontal, "Ülke");
    m_rtm->setHeaderData(3, Qt::Horizontal, "Bölge");
    m_rtm->setHeaderData(4, Qt::Horizontal, "Nüfus");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_pushButtonSelect_clicked()
{
    ui->m_tableView->setModel(m_rtm);
    m_rtm->select();

}
