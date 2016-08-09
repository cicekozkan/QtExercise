#include <iostream>
#include <QFile>
#include <QDataStream>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("test.dat");

  if(!file.open(QIODevice::ReadOnly)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QDataStream ds(&file);
  int i;

  for(;;){
    ds >> i;
    cout << i << endl;
    if(ds.atEnd())
      break;
  }

  file.close();

  return 0;
}
