#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv); // application
  MainWindow mainWindow;
  mainWindow.show();  // MainWindow class is inherited from Widget (window gadget)
                      // class. Widget class is used to create windows
                      // Window must be created before creating the message queue
                      // When a QWidget class object is instantiated a window is created
                      // QWidget::show member function shows this window
  a.exec(); // exec is a static member function of QApplication class (QApplication::exec)
            // call to this function creates the message loop

  return 0;
}
