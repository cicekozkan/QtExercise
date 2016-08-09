#include <iostream>
#include <QFile>
#include <QTextStream>

using namespace std;

class Sample{
private:
  int m_a, m_b;
public:
  Sample(int a, int b):m_a{a}, m_b{b}{}
  int a(void) const {return m_a;}
  int b(void) const {return m_b;}
};

QTextStream& operator<< (QTextStream &ts, const Sample &s)
{
  ts << s.a() << ", " << s.b() << endl;
  return ts;
}

int main(int argc, char *argv[])
{
  QFile file("test.txt");

  if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QTextStream ts(&file);
  Sample s(10, 20);

  ts << s;

  file.close();

  return 0;
}
