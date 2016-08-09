#include <iostream>
#include <QFile>
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
  int num;

  for(;;){
    ts >> num;
    cout << num << endl;
    if(ts.atEnd())
      break;
  }//end infinite for

  file.close();

  return 0;
}
