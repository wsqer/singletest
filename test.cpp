#include "test.h"
#include "ui_test.h"
#include "QDebug"
#include "QFile"
#include <ctime>
#include <xdata.h>
#include "result.h"
#include <QMessageBox>
#include "QMouseEvent"
test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    nn=0;
    ui->setupUi(this);
    timer=new QTimer(this);
    timer->start(1000);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(timer, SIGNAL(timeout()), this, SLOT(set_timeout()));
    connect(ui->closed,&QPushButton::clicked,this,&test::closewindow);
    connect(ui->mins,&QPushButton::clicked,this,&test::minwindow);
}
void test::setinfo(int n,QString s) //根据用户选择题的数量生成对应的按钮
{
    num=n;
    names=s;
    times=num*60;
    for(int i=1;i<=num;i++)
    {
        QString s = QString::number(i, 10);
        QPushButton *p=new QPushButton(s);
        btn.push_back(p);
        p->setObjectName(s);
        connect(p,SIGNAL(clicked()),this,SLOT(delact()));
        if(i>15 && i<=30)
        {
            ui->gridLayout_2->addWidget(p);
        }
        else if(i>30)
        {
            ui->gridLayout_3->addWidget(p);
        }
        else
        {
            ui->gridLayout_4->addWidget(p);
        }

    }
    //对所有控件添加单击事件
    connect(ui->backT,&QPushButton::clicked,this,&test::setback);
    connect(ui->nextT,&QPushButton::clicked,this,&test::setnext);
    connect(ui->xu1,&QPushButton::clicked,this,&test::seta);
    connect(ui->xu2,&QPushButton::clicked,this,&test::setb);
    connect(ui->xu3,&QPushButton::clicked,this,&test::setc);
    connect(ui->xu4,&QPushButton::clicked,this,&test::setd);
    connect(ui->submit,&QPushButton::clicked,this,&test::tests);

 randvalue();//将题随机的取出来
 gonow();

}
void test::setradiofalse()
{
    ui->xu1->setCheckable(false);
    ui->xu2->setCheckable(false);
    ui->xu3->setCheckable(false);
    ui->xu4->setCheckable(false);
    ui->xu1->setCheckable(true);
    ui->xu2->setCheckable(true);
    ui->xu3->setCheckable(true);
    ui->xu4->setCheckable(true);
}
void test::tests()   //提交答案时调用
{
    int i,j;
    float v;
    for(i=0,j=0;i<num;i++)
    {
        if(alldata.res[randda[i]]==keys[i])
        {
            j++;
        }
    }
    v=(j*1.0)/(num*1.0)*100;
    result *goval=new result();
    goval->setres(v);
    goval->show();
    this->close();

}
void test::seta()
{

    keys[nn]=1;
    btn[nn]->setStyleSheet("background-color: rgb(255, 0, 0);");
}
void test::setb()
{

    keys[nn]=2;
    btn[nn]->setStyleSheet("background-color: rgb(255, 0, 0);");
}
void test::setc()
{

    keys[nn]=3;
    btn[nn]->setStyleSheet("background-color: rgb(255, 0, 0);");
}
void test::setd()
{

    keys[nn]=4;
    btn[nn]->setStyleSheet("background-color: rgb(255, 0, 0);");
}
void test::delact()
{
    QString x=QObject::sender()->objectName();  //区分按钮响应
    nn=x.toInt()-1;
    gonow();
    setradiofalse();
}
void test::setback()
{
    if(nn>0)
    {
        nn--;
        gonow();
        setradiofalse();
    }
}

void test::setnext()
{
    if(nn<randda.size()-1)
    {
        nn++;
        gonow();
        setradiofalse();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "|-_-|", "题已做完，请提交！",QMessageBox::Yes | QMessageBox::No);
        message.setIconPixmap(QPixmap("testcty.png"));

        if(message.exec()==QMessageBox::Yes)
        {
            tests();
        }
    }
}
void test::gonow()
{
    QString sss = QString::number(nn+1, 10);
    ui->title1->setText(sss+" ,"+alldata.tit[randda[nn]]);
    ui->xu1->setText("A,"+alldata.As[randda[nn]]);
    ui->xu2->setText("B,"+alldata.Bs[randda[nn]]);
    ui->xu3->setText("C,"+alldata.Cs[randda[nn]]);
    ui->xu4->setText("D,"+alldata.Ds[randda[nn]]);
}
void test::randvalue()     //从题库中随机选择用户指定数目的题
{

    srand( (unsigned)time(0));   //设置随机数种子
    int f;
    while(num>randda.size()) //当选择的题和指定的题目数相同时
    {
        int i;
        bool pd=true;
        f=rand() % alldata.tit.size();   //取随机数
        for(i=0;i<randda.size();i++)
        {
            if(randda[i]==f)   //如果已有相同的题，跳过
            {
                pd=false;
           }
        }
        if(pd)
       {
            randda.push_back(f);//将选择的题目号压入vertor中
       }

    }


}
test::~test()
{
     for(int f=0;f<btn.size();f++)
     {
         delete btn[f];
     }

    delete ui;
     delete timer;
}
void test::set_timeout()
{
    times--;

    ui->settime->setText("剩余时间"+QString("%1").arg(times)+"秒");
    if(times<0)
    {
        timer->stop();
        tests();
    }
}




void test::closewindow()
{
    this->close();
}
void test::minwindow()
{
    this->showMinimized();
}


void test::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       m_Drag = true;
       m_DragPosition = event->globalPos() - this->pos();
       event->accept();
    }
}

void test::mouseMoveEvent(QMouseEvent *event)
{
    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void test::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}

