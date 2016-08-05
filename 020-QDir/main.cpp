#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  QDir dir("C:\\windows");

  for(QFileInfo qf : dir.entryInfoList(QDir::Files | QDir::Executable))
    cout << qf.fileName().toStdString() << ", " << qf.size() << endl;

  return 0;
}
