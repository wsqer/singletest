#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>

namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    void goindex();
    void setres(float s);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void closewindow();
    explicit result(QWidget *parent = 0);
    ~result();

private:
    bool m_Drag;
    QPoint m_DragPosition;
    Ui::result *ui;
};

#endif // RESULT_H
