#include <iostream>
#include <QFile>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("a.dat");

  if(!QFile::rename("a.dat", "b.dat")){
    cerr << "cannot rename file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  cout << "File renamed!\n";

  return 0;
}
