#include <QDebug>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_im = new QStandardItemModel(5, 3);
    m_im->setData(m_im->index(0, 0), "Ali Serçe");
    m_im->setData(m_im->index(0, 1), "123");
    m_im->setData(m_im->index(0, 2), "12/01/1999");
    m_im->setHeaderData(0, Qt::Horizontal, "Adı Soyadı");
    m_im->setHeaderData(1, Qt::Horizontal, "No");
    m_im->setHeaderData(2, Qt::Horizontal, "Doğum Tarihi");
    ui->m_tableView->setModel(m_im);
    m_im->insertRow(0);
    m_im->setData(m_im->index(0, 0), "Ozkan Cicek");
    m_im->setData(m_im->index(0, 1), "1080");
    m_im->setData(m_im->index(0, 2), "06/11/1987");

    QFont font("Times New Roman", 12);
    font.setBold(true);
    ui->m_tableView->horizontalHeader()->setFont(font);
    ui->m_tableView->resizeColumnsToContents();
    ui->m_tableView->resizeRowsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_pushButton_clicked()
{
    qDebug() << m_im->data(ui->m_tableView->currentIndex()).toString();

}




