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
    m_db.setPassword("csd1993");
    m_db.setDatabaseName("world");
    m_db.open();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pushButtonSelect_clicked()
{
    QSqlTableModel *tm = new QSqlTableModel();

    tm->setTable("city");
    tm->setFilter("Name LIKE 'K%'");
    // Eşdeğeri: SELECT * from city WHERE Name LIKE K%
    tm->select();
    ui->m_tableView->setModel(tm);
    ui->m_tableView->resizeRowsToContents();
    ui->m_tableView->hideColumn(0);
}
