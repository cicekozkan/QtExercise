#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFont>
#include "mainwidget.hpp"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ui->m_tableWidget->setColumnCount(3);

    ui->m_tableWidget->setHorizontalHeaderLabels(QString("Adı Soyadı;No;Doğum Tarihi").split(';'));

    QFont font("Times New Roman", 12);
    font.setBold(true);

    ui->m_tableWidget->horizontalHeaderItem(0)->setFont(font);
    ui->m_tableWidget->horizontalHeaderItem(1)->setFont(font);
    ui->m_tableWidget->horizontalHeaderItem(2)->setFont(font);

    QFile file("C:/Data/Qt/src/065-QTableWidget/info.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "cannot open file!..\n";
        close();
        return;
    }
    QTextStream ts(&file);
    QString line;

    for (int i = 0; !(line = ts.readLine()).isNull(); ++i) {
        ui->m_tableWidget->insertRow(i);
        QStringList sl = line.split(',');

        QTableWidgetItem *qtwi = new QTableWidgetItem();
        qtwi->setText(sl[0]);
        qtwi->setTextColor(Qt::red);
        qtwi->setBackgroundColor(Qt::yellow);
        ui->m_tableWidget->setItem(i, 0, qtwi);

        qtwi = new QTableWidgetItem();
        qtwi->setText(sl[1]);
        qtwi->setTextColor(Qt::red);
        qtwi->setBackgroundColor(Qt::yellow);
        ui->m_tableWidget->setItem(i, 1, qtwi);

        qtwi = new QTableWidgetItem();
        qtwi->setText(sl[2]);
        qtwi->setTextColor(Qt::red);
        qtwi->setBackgroundColor(Qt::yellow);
        ui->m_tableWidget->setItem(i, 2, qtwi);
     }
}

MainWidget::~MainWidget()
{
    delete ui;
}
