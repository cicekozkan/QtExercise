#include <iostream>
#include <QFile>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("a.dat");

  if(!file.open(QIODevice::WriteOnly)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  cout << "File exists?: " << (file.exists()?"Yes":"No") << endl;
  cout << "Is file open?: " << (file.isOpen()?"Yes":"No") << endl;

  cout << "OK!\n";

  file.close();

  return 0;
}
