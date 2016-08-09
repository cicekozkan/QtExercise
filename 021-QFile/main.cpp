#include <iostream>
#include <QFile>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("test.txt");

  if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  for(int i = 0; i < 100; i++)
    file.write(reinterpret_cast<const char*>(&i), sizeof(int));

  file.reset();

  int val;
  for(int i = 0; i < 100; i++){
    file.read(reinterpret_cast<char *>(&val), sizeof(int));
    cout << val << " ";
  }
  cout << endl;

  file.close();

  return 0;
}
