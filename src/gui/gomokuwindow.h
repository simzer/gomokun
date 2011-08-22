#ifndef GOMOKUWINDOW_H
#define GOMOKUWINDOW_H

#include <QMainWindow>

namespace Ui {
    class GomokuWindow;
}

class GomokuWindow : public QMainWindow {
    Q_OBJECT
public:
    GomokuWindow(QWidget *parent = 0);
    ~GomokuWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GomokuWindow *ui;

};

#endif // GOMOKUWINDOW_H
