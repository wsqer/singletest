#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <test.h>
#include<QtDebug>
#include <insertdata.h>
#include "xdata.h"
#include "QMessageBox"
#include "QMouseEvent"
#include "QInputDialog"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString m=QString::number(dda.tit.size(), 10);
    ui->allti->setText("共有："+m+"道题");
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    connect(ui->gotest,&QPushButton::clicked,this,&MainWindow::gotestfun);  //开始答题按钮事件
    connect(ui->insertdata,&QPushButton::clicked,this,&MainWindow::insertdat);  //录入试题按钮事件
    connect(ui->closed,&QPushButton::clicked,this,&MainWindow::closewindow);  //关闭按钮
}
void MainWindow::insertdat() //响应录入按钮事件函数
{
    bool isOK;
    QString text = QInputDialog::getText(NULL, "试题录入","请输入管理密码！！！",QLineEdit::Normal,"",&isOK);
    if(isOK)
    {
        if(text=="admin")
        {
            ins=new insertdata();
            ins->show();
        }
        else
        {
            QMessageBox::information(NULL, "口令错误", "请输入正确的口令！！！");
        }

    }


}
void MainWindow::closewindow()
{
    this->close();
}
void MainWindow::gotestfun(){

    int g=((ui->number->text()).toInt());
    if(g>0 && g<=dda.tit.size() && g<=45)
    {
        test *df=new test();
        df->setinfo(g,"小明");
        df->show();
        this->close();
    }
    else{
        QMessageBox::information(NULL, "错误", "请输入正确的题目数量！！");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   if (event->button() == Qt::LeftButton) {
       m_Drag = true;
       m_DragPosition = event->globalPos() - this->pos();
       event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos() - m_DragPosition);
        event->accept();
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    m_Drag = false;
}
