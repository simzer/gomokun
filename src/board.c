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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"

const char board_signs[] = { ' ', 'X', 'O'};

board_type *board_create(int width,
                        int height)
{
  board_type *board = malloc(sizeof(board_type));
  if (board == NULL) return(NULL);
  board->width  = width;
  board->height = height;
  board->board  = malloc(width * height * sizeof(int));
  board_clear(board);
  return(board);
}

void board_clear(board_type *board)
{
  memset(board->board, 0, board->width * board->height * sizeof(int));
}


board_type *board_copy(board_type *board)
{
  board_type *res = board_create(board->width, board->height);
  if (res == NULL) return (NULL);
  memcpy(res->board, board->board, board->width * board->height * sizeof(int));
  return(res);
}

void board_destruct(board_type *board)
{
  free(board->board);
  free(board);
}

int board_get_cell(board_type *board, int row, int col)
{
  if (   row < 0 || row >= board->height
      || col < 0 || col >= board->width) {
    return(board_invalid_cell);
  } else {
    return(board->board[row*board->width + col]);
  }
}

int board_set_cell(board_type *board, int row, int col, int cell)
{
  if (   row < 0 || row >= board->height
      || col < 0 || col >= board->width)
    return(1);

  board->board[row*board->width + col] = cell;
  return(0);
}

void board_print(board_type *board)
{
  int row, col;
  for(row = 0; row < board->height; row++)
  {
    for(col = 0; col < board->width; col++)
    {
      printf("%c ", board_signs[board_get_cell(board, row, col)]);
    }
    printf("\n");
  }
}

board_iterator_type *board_iterator_create(board_type *board)
{
  board_iterator_type *res = malloc(sizeof(board_iterator_type));
  if (res == NULL)
  {
      fprintf(stderr, "Out of memory.\n");
      exit(1);
  }
  res->row = 0;
  res->col = 0;
  res->run = 0;
  res->board = board;
  return res;
}

void board_iterator_destruct(board_iterator_type *iterator)
{
  free(iterator);
}

int board_iterate(int *row, int *col, int **pcell, board_iterator_type *iterator)
{
  if (!iterator->run)
  {
    iterator->row = 0;
    iterator->col = 0;
    iterator->run = 1;
  }
  else
  {
    iterator->col++;
    if (iterator->col >= iterator->board->width) {
      iterator->col = 0;
      iterator->row++;
    }
    if (iterator->row >= iterator->board->height) {
      iterator->row = 0;
      iterator->run = 0;
    }
  }
  *row  = iterator->row;
  *col  = iterator->col;
  *pcell = &(iterator->board->board[iterator->row*iterator->board->width
                                    + iterator->col]);
  return(iterator->run);
}

