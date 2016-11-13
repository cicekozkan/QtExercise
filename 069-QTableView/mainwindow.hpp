#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QStandardItemModel>

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
    void on_m_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_im;
};

#endif // MAINWINDOW_HPP
