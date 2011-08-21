
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"
#include "engine.h"
#include "ai.h"

int directions[4][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 } };

void ai_calculate_step(engine_type *engine, int *row, int *col)
{
  int counters[engine->board->height][engine->board->width][5][2];
  int row0, col0, *pcell0;
  int row1, col1, *pcell1;
  int dir, dist;
  int side;
  int score;
  board_iterator_type *iterator0 = board_iterator_create(engine->board);
  board_iterator_type *iterator1 = board_iterator_create(engine->board);
  // init
  memset(counters, 0, engine->board->height*engine->board->width*5*2*sizeof(int));
  // Count connected sections for each possible move (xx, xxx, xxxx, xxxxx)
  while(board_iterate(&row0, &col0, &pcell0, iterator0))
  {
    if (*pcell0 == ENGINE_EMPTY) {
      while(board_iterate(&row1, &col1, &pcell1, iterator1))
      {
        for (dir = 0; dir < 4; dir++)
        {
          int friends = 0;
          int enemies = 0;
          int contains_p0 = 0;
          for (dist = 0; dist < 5; dist++)
          {
            *row = row1 + dist * directions[dir][0];
            *col = col1 + dist * directions[dir][1];
            int cell = board_get_cell(engine->board, *row, *col);
            if (cell == engine->actual_player) {
              friends++;
            } else if (   cell != ENGINE_EMPTY
                       && cell != board_invalid_cell) {
              enemies++;
            }
            if ((row0 == *row) && (col0 == *col)) {
              contains_p0 = 1;
            }
          }
          if ((enemies == 0) && (friends+contains_p0 > 0)) {
            counters[row0][col0][friends+contains_p0-1][0]++;
          }
          if ((friends == 0) && (enemies+contains_p0 > 0)) {
            counters[row0][col0][enemies+contains_p0-1][1]++;
          }
        }
      }
    }
  }

  // Search for best move
  *row = -1;
  *col = -1;
  score = 0;
  for (dist = 5; dist > 0; dist--) {
    for (side = 0; side <= 1; side++) {
      if (score == 0) {
        for (row0 = 0; row0 < engine->board->height; row0++) {
          for (col0 = 0; col0 < engine->board->width; col0++) {
            if (score < counters[row0][col0][dist-1][side]) {
              *row = row0;
              *col = col0;
              score = counters[row0][col0][dist-1][side];
            }
          }
        }
      }
    }
  }/*
  // Debug
  {
    int r,c,k;
    for (k = 0; k < 5; k++) {
      printf("K = %d\n", k+1);
      for (side = 0; side <= 1; side++) {
       printf("side %d\n", side+1);
      for (r = 0; r < engine->board->height; r++) {
        for (c = 0; c < engine->board->width; c++) {
          //printf("(%d,%d,%d):%d ",r, c, k, counters[r][c][k]);
          printf("%d ", counters[r][c][k][side]);
        }
        printf("\n");
      }
    }
    }
  }*/
}
