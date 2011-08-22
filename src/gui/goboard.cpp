
#include <iostream>
#include <QGraphicsPixmapItem>
#include "goboard.h"

GoBoard::GoBoard()
{
    boardsize = 19;
    cellsize = 480 / (boardsize+1);
    cellpadding = 1;
    shadowshift = 3;
    move = NULL;
    shadow = new QImage("shadow.png");
    white  = new QImage("white.png");
    black  = new QImage("black.png");
    table  = new QImage("table.png");
    draw();
}

void GoBoard::DrawStone(int i, int j, int color)
{    
    int x = (0.5+i)*cellsize;
    int y = (0.5+j)*cellsize;

    QGraphicsPixmapItem *shadowitem = new QGraphicsPixmapItem( QPixmap::fromImage(*shadow));
    shadowitem->setPos(x+1.3*shadowshift,y+0.7*shadowshift);
    addItem(shadowitem);

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem( QPixmap::fromImage(color ? *white : *black));
    item->setPos(x,y);
    addItem(item);
}

void GoBoard::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    static int player = 0;
    Q_UNUSED(event);
    QPointF mousePos = event->scenePos();

    int x = int(mousePos.x()/cellsize-0.5);
    int y = int(mousePos.y()/cellsize-0.5);
    DrawStone(x, y, player);
    if (move != NULL) {
        move(x, y, player, this);
        player = !player;
    }

    player = !player;
}

void GoBoard::draw(void)
{
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem( QPixmap::fromImage(*table));
    addItem(item);

    QRadialGradient radialGradient(0.3 * boardsize * cellsize,
                                   0.3 * boardsize * cellsize,
                                   boardsize * cellsize);
    radialGradient.setColorAt(0.0, QColor::fromRgbF(1.0,1.0,1.0,0.4));
    radialGradient.setColorAt(0.75, QColor::fromRgbF(220/255.0,179/255.0,92/255.0,0.3));
    radialGradient.setColorAt(1.0, QColor::fromRgbF(210/255.0,160/255.0,52/255.0,0.3));
    addRect(QRectF(0, 0, cellsize * (boardsize+1), cellsize * (boardsize+1)),
            QPen(Qt::black),
            QBrush(radialGradient));

    for (int i = 0; i < (boardsize-1); i++) {
        for (int j = 0; j < (boardsize-1); j++)
        {
            addRect(QRectF(cellsize * (1+i), cellsize * (1+j), cellsize, cellsize),
                    QPen(QColor::fromRgbF(0.0,0.0,0.0,0.7)),
                    Qt::NoBrush);
            if (   (i % 3 == 0) && ((i/3) % 2 == 1)
                && (j % 3 == 0) && ((j/3) % 2 == 1))
            {
                addEllipse(cellsize * (1+i) - cellsize/10,
                           cellsize * (1+j) - cellsize/10,
                           cellsize/5, cellsize/5,
                           QColor::fromRgbF(0,0,0,0.7),
                           QBrush(Qt::black));
            }
        }
    }
}
