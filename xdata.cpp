#include "xdata.h"
#include "QFile"
#include "QDebug"
Xdata::Xdata()
{
    QFile file("data.dat");
      if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
          qDebug()<<"Can't open the file!"<<endl;
      }
      QTextStream in(&file);
      QString line;
      int i=0;
      while(!in.atEnd()){
          QString title;
          QString a;
          QString b;
          QString c;
          QString d;
          int r;
          in>>title>>a>>b>>c>>d>>r;
         tit.push_back(title);
          As.push_back(a);
          Bs.push_back(b);
          Cs.push_back(c);
          Ds.push_back(d);
          res.push_back(r);

          i++;

      }
      file.close();
}


