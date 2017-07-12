#include "result.h"
#include "ui_result.h"
#include "QDebug"
#include "mainwindow.h"
#include "QMouseEvent"
result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
     connect(ui->tryagain,&QPushButton::clicked,this,&result::goindex);  //再次答题按钮事件
     connect(ui->closed,&QPushButton::clicked,this,&result::closewindow);

}
void result::goindex()
{
    MainWindow *p=new MainWindow();
    this->close();
    p->show();
}
void result::setres(float s)
{

    if(s>90)
    {
         ui->imgui->setStyleSheet("border-image: url(:/new/bgrand/img/q10.png);");
        ui->dianping->setText("优秀");

    }
    else if(s>80)
    {
        ui->imgui->setStyleSheet("border-image: url(:/new/bgrand/img/q4.png);");
        ui->dianping->setText("良好");
    }
    else if(s>70)
    {
        ui->imgui->setStyleSheet("border-image: url(:/new/bgrand/img/q11.png);");
        ui->dianping->setText("中等");
    }
    else if(s>60)
    {
        ui->imgui->setStyleSheet("border-image: url(:/new/bgrand/img/q12.png);");
        ui->dianping->setText("合格");
    }
    else
    {
        ui->imgui->setStyleSheet("border-image: url(:/new/bgrand/img/q3.png);");
        ui->dianping->setText("不合格  -_-");
    }
    QString data = QString("%1").arg((int)s);
    qDebug()<<s<<endl;
    ui->resultval->setText("最后得分为:"+data);
}

result::~result()
{
    delete ui;
}
void result::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       m_Drag = true;
       m_DragPosition = event->globalPos() - this->pos();
       event->accept();
    }
}

void result::mouseMoveEvent(QMouseEvent *event)
{
    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void result::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}
void result::closewindow()
{
    this->close();
}
