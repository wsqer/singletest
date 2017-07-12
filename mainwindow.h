#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xdata.h"
#include "insertdata.h"
#include "QPoint"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
      Xdata dda;
      insertdata *ins;
public:
    void gotestfun();
    void insertdat();
    void closewindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    bool m_Drag;
    QPoint m_DragPosition;

};

#endif // MAINWINDOW_H
