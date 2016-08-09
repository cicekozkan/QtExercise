#include <iostream>
#include <QFile>
#include <QDataStream>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("test.dat");

  if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QDataStream ds(&file);

  for(int i = 0; i < 10; i++)
    ds << i;

  file.close();

  return 0;
}
