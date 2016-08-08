#include <iostream>
#include <QByteArray>

using namespace std;

int main(int argc, char *argv[])
{
  QByteArray qba;

  for(int i = 0; i < 100; i++)
    qba.push_back(i);

  QByteArray result = qba.mid(10, 5);

  for(unsigned char ch : result)
    cout << (int)ch << " ";
  cout << endl;

  return 0;
}
