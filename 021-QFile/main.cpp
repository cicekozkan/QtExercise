#include <iostream>
#include <QByteArray>

using namespace std;

int main(int argc, char *argv[])
{
  QByteArray qba = QByteArray::number(12.34);

  for(QByteArray::iterator iter = qba.begin(); iter != qba.end(); iter++)
    cout << *iter << endl;

  return 0;
}
