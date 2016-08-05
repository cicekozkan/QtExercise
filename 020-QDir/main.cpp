#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << QDir::currentPath().toStdString() << endl;

  QDir::setCurrent("C:\\windows");

  QDir dir(".");

  for(QFileInfo qf : dir.entryInfoList(QDir::Files | QDir::Executable))
    cout << qf.fileName().toStdString() << ", " << qf.size() << endl;

  return 0;
}
