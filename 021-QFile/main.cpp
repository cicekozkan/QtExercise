#include <iostream>
#include <QFile>
#include <cstdlib>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
  QFile file("Book1.csv");

  if(!file.open(QIODevice::ReadOnly)){
    cerr << "cannot open file!..\n";
    exit(EXIT_FAILURE);
  }//end if file open

  QTextStream ts(&file);

  for(;;){
    QString row = ts.readLine();
    if(row.isNull())
      break;
    QStringList sl = row.split(",");
    for(QString elem : sl)
      cout << elem.toStdString() << "|";
    cout << endl;
  }//end infinite for

  file.close();

  return 0;
}
