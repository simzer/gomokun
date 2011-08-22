#include <QProcess>
#include <cstdio>
#include <iostream>
#include "gomokuwindow.h"
#include "ui_gomokuwindow.h"
#include "goboard.h"

QProcess engine;

void onMove(int i, int j, int player, GoBoard *board)
{
    char buf[1024];
    sprintf(buf, "TURN %d,%d\n", i, j);
    engine.write(QByteArray(buf));
    engine.waitForReadyRead();
    qint64 lineLength = engine.readLine(buf, sizeof(buf));
    if (lineLength != -1) {
        sscanf(buf, "%d,%d", &i, &j);
        board->DrawStone(i,j,!player);
    }
}


GomokuWindow::GomokuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GomokuWindow)
{
    ui->setupUi(this);

    engine.start("./gomoku",QIODevice::ReadWrite);
    if(engine.waitForStarted() == false) {
        std::cerr<< "Can not run gomoku engine.\n";
        exit(1);
    }

    GoBoard *goboard = new GoBoard();
    goboard->move = &onMove;

    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->graphicsView->setScene(goboard);
}

GomokuWindow::~GomokuWindow()
{
    delete ui;
}

void GomokuWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
