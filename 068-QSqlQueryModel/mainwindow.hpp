#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_m_pushButtonOk_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase m_db;
};

#endif // MAINWINDOW_HPP
