#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>
#include <QStringList>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
  QDir dir("C:\\Data\\QtExercise");

  QStringList sl = dir.entryList(QDir::Files | QDir::Executable | QDir::Hidden);

  for(QString name : sl)
    qDebug() << name;

  return 0;
}
