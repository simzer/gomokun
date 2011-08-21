
#ifndef _BOARD_H_
#define _BOARD_H_

#include <limits.h>

enum { board_invalid_cell = INT_MAX };

typedef struct
{
  int width;
  int height;
  int *board;
} board_type;

typedef struct
{
  int run;
  int row;
  int col;
  board_type *board;
} board_iterator_type;

board_type *board_create(int width, int height);
void board_clear(board_type *board);
void board_destruct(board_type *board);
int board_get_cell(board_type *board, int row, int col);
int board_set_cell(board_type *board, int row, int col, int cell);
board_type *board_copy(board_type *board);
void board_print(board_type *board);

board_iterator_type *board_iterator_create(board_type *board);
void board_iterator_destruct(board_iterator_type *iterator);
int board_iterate(int *row, int *col, int **pcell, board_iterator_type *iterator);


#endif
