#include <iostream>
#include <QFile>
#include <cstdlib>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("test.txt");

  if(!file.open(QIODevice::ReadOnly)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QTextStream ts(&file);

  QString str = ts.readAll();
  cout << str.toStdString() << endl;

  file.close();

  return 0;
}
