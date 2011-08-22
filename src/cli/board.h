/****************************************************************************
Copyright (C) 2011 Laszlo Simon <laszlo.simon@gmail.com>

This file is part of GomoKun project.

GomoKun is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GomoKun is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GomoKun. If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
/**
 *  \file General board class.
 */

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
