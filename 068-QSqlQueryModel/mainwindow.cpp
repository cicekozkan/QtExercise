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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pushButtonOk_clicked()
{
    qDebug() << m_db.open();

    QSqlQueryModel *qm = new QSqlQueryModel();
    qm->setQuery("SELECT Name, CountryCode FROM city ORDER BY Name");
    ui->m_tableView->setModel(qm);
    ui->m_tableView->verticalHeader()->setVisible(false);
    QFont font("Times New Roman", 12);
    font.setBold(true);

    ui->m_tableView->horizontalHeader()->setFont(font);

}
