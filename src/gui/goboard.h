#ifndef GOBOARD_H
#define GOBOARD_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GoBoard : public QGraphicsScene
{
    Q_OBJECT
public:
    GoBoard();
    void DrawStone(int i, int j, int color);
    void (*move)(int i, int j, int color, GoBoard *board);
protected:
    int boardsize;
    int cellsize;
    int cellpadding;
    int shadowshift;
    QImage *white;
    QImage *black;
    QImage *shadow;
    QImage *table;
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void draw(void);
};

#endif // GOBOARD_H
