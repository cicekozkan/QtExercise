#include <iostream>
#include <QByteArray>

using namespace std;

int main(int argc, char *argv[])
{
  QByteArray qba;
  int a = 1234;

  qba.setNum(a);

  cout << qba.size() << endl;

  int b = qba.toInt();

  cout << b << endl;

  return 0;
}
