#ifndef TEST_H
#define TEST_H
#include <QMainWindow>
#include <vector>
#include <xdata.h>
#include <QPushButton>
#include "QTimer"
using namespace std;
namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT
    int num;
    QString names;


    vector<int> randda;
    vector<QPushButton *> btn;
    Xdata alldata;
public:
    int nn;
    int keys[50];
    void randvalue();
    void setnext();
    void gonow();
    void seta();
    void setb();
    void setc();
    void setd();
    void tests();
    void closewindow();
    void minwindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void setradiofalse();
    void setinfo(int n,QString s);
        explicit test(QWidget *parent = 0);
    ~test();

private:
    int times;
    QTimer *timer;
    bool m_Drag;
    QPoint m_DragPosition;
    Ui::test *ui;
public slots:
 void set_timeout();
void delact();
void setback();
};


#endif // TEST_H
