#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  QDir dir("C:\\Data\\QtExercise");
  qDebug() << (dir.exists() ? "Var": "Yok");
  qDebug() << "dirName = " << dir.dirName();
  qDebug() << "path = " << dir.path();

  if(!dir.mkdir("test"))
    cerr << "cannot create test directory!...\n";
  else
    cout << "test directory created\n";

  if(!dir.rmdir("test"))
    cerr << "cannot delete test directory!...\n";
  else
    cout << "test directory deleted\n";

  return 0;
}
