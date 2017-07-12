#include "insertdata.h"
#include "ui_insertdata.h"
#include "QDebug"
#include "QFile"
#include "xdata.h"
#include <QMessageBox>
#include "QMouseEvent"
using namespace std;
insertdata::insertdata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::insertdata)
{

    ui->setupUi(this);
    this->setWindowTitle("试题录入");
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //设置控件的点击事件
    connect(ui->closewindow,&QPushButton::clicked,this,&insertdata::closewindow);
    connect(ui->minwindow,&QPushButton::clicked,this,&insertdata::minwindow);
    connect(ui->submitdata,&QPushButton::clicked,this,&insertdata::writeFile);
    connect(ui->radioA,&QPushButton::clicked,this,&insertdata::geta);
    connect(ui->radioB,&QPushButton::clicked,this,&insertdata::getb);
    connect(ui->radioC,&QPushButton::clicked,this,&insertdata::getc);
    connect(ui->radioD,&QPushButton::clicked,this,&insertdata::getd);
}
void insertdata::writeFile()    //将用户输入的数据写入data.dat文件中
{

    int bvc=QMessageBox::question(NULL, "试题", "确定录入??", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);//需要用户确认是否写入
    if(bvc==QMessageBox::Yes)
    {
        QString title=ui->title->toPlainText();
        QString a=ui->puta->text();
        QString b=ui->putb->text();
        QString c=ui->putc->text();
        QString d=ui->putd->text();
        title.remove(QRegExp("\\s")); //去掉输入的空格，以便管理
        a.remove(QRegExp("\\s"));
        b.remove(QRegExp("\\s"));
        c.remove(QRegExp("\\s"));
        d.remove(QRegExp("\\s"));
        QFile fileout("data.dat");
          if(!fileout.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
          {
              qDebug() << "Open failed";
          }
          QTextStream txtOutput(&fileout);

              txtOutput<<" "<<title<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<values;

        ui->title->setText("");  //设置控件为空，方便下一题的录入
        ui->puta->setText("");
        ui->putb->setText("");
        ui->putc->setText("");
        ui->putd->setText("");
    }

}
void insertdata::geta()
{
    values=1;
}
void insertdata::getb()
{
    values=2;
}
void insertdata::getc()
{
    values=3;
}
void insertdata::getd()
{
    values=4;
}
insertdata::~insertdata()
{
    delete ui;
}
void insertdata::closewindow()
{
    this->close();
}
void insertdata::minwindow()
{
    this->showMinimized();
}


void insertdata::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       m_Drag = true;
       m_DragPosition = event->globalPos() - this->pos();
       event->accept();
    }
}

void insertdata::mouseMoveEvent(QMouseEvent *event)
{
    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void insertdata::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}

