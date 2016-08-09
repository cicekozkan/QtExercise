#include <iostream>
#include <QFile>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("test.txt");

  if(!file.open(QIODevice::ReadOnly)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QByteArray qba = file.read(100);

  cout << qba.toStdString() << endl;

  file.close();

  return 0;
}
