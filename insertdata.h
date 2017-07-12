#ifndef INSERTDATA_H
#define INSERTDATA_H

#include <QMainWindow>

namespace Ui {
class insertdata;
}

class insertdata : public QMainWindow
{
    Q_OBJECT
    int values;
public:
    void geta();
    void getb();
    void getc();
    void getd();
    void closewindow();
    void minwindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void writeFile();
    explicit insertdata(QWidget *parent = 0);
    ~insertdata();

private:
    Ui::insertdata *ui;
    bool m_Drag;
    QPoint m_DragPosition;
};

#endif // INSERTDATA_H
