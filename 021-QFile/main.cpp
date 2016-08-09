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

  char buf[100 + 1];
  qint64 n;

  n = file.read(buf, 100);
  buf[n] = '\0';

  cout << buf << endl;

  file.close();

  return 0;
}
