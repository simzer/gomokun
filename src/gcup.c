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
 *  \file Gomocup protokol modul.
 */

#include <stdlib.h>
#include <stdio.h>

#include "engine.h"
#include "ai.h"
#include "gcup.h"
#include "about.h"

static engine_type *engine;
static int lock = 0;

static int board_error(void)
{
  if (engine == NULL) {
    printf("ERROR Board is not initialized.\n");
    fflush(stdout);
    return(1);
  }
  return(0);
}

static int board_locked(void)
{
  if (lock) {
    printf("ERROR Board is locked for BOARD command.\n");
    fflush(stdout);
    return(1);
  }
  return(0);
}


void gcup_start(int size)
{
  gcup_rectstart(size,size);
}

void gcup_rectstart(int width, int height)
{
  if (board_locked()) return;
  if (engine != NULL) engine_destruct(engine);
  engine = engine_create(width,height);
  if (engine != NULL) {
    printf("OK\n");
    fflush(stdout);
  } else {
    printf("ERROR Can not initialize board.\n");
    fflush(stdout);
  }
}

void gcup_restart(void)
{
  if (board_locked()) return;
  if (engine == NULL) {
    printf("ERROR Board is not initialized.\n");
    fflush(stdout);
    return;
  }
  engine_reset(engine);
  printf("OK\n");
  fflush(stdout);
}

void gcup_begin(void)
{
  int row, col;
  if (board_locked()) return;
  if (board_error()) return;
  ai_calculate_step(engine, &row, &col);
  printf("%d,%d\n", col, row);
  fflush(stdout);
}

void gcup_board(void )
{
  lock = 1;
}

void gcup_board_move(int x, int y, int field)
{
  if (!lock) {
    printf("ERROR Board command not received.\n");
    fflush(stdout);
    return;
  }
  if (board_error()) return;
  // todo:  handle field=3
  // todo: 0,1 != black, white but own, enemy! fix it
  engine_set(y, x, field, engine);
}

void gcup_board_done(void )
{
  if (!lock) {
    printf("ERROR Board command not received.\n");
    fflush(stdout);
    return;
  }
  lock = 0;
  gcup_begin();
}

void gcup_end(void)
{
  if (engine != NULL) engine_destruct(engine);
  exit(0);
}

void gcup_about(void)
{
  printf("name=\"pbrain-%s\", "
         "version=\"%s\", "
         "author=\"%s\", "
         "country=\"%s\", "
         "email=\"%s\", "
         "www=\"%s\"\n",
         name, version, author, country, email, www);
  fflush(stdout);
}

void gcup_turn(int x, int y)
{
  if (board_locked()) return;
  if (board_error()) return;
  if (engine_step(y, x, engine) == 0)
  {
    int row, col;
    ai_calculate_step(engine, &row, &col);
    printf("%d,%d\n", col, row);
    fflush(stdout);
  }
  else
  {
    printf("ERROR Invalid move.\n");
    fflush(stdout);
  }
}

void gcup_takeback(int x, int y)
{
  if (board_locked()) return;
  if (board_error()) return;
  engine_set(y, x, 0, engine);
  printf("OK\n");
  fflush(stdout);
}

void gcup_play(int x, int y)
{
  if (board_locked()) return;
  if (board_error()) return;
  if (engine_step(y, x, engine) == 0)
  {
    printf("%d,%d\n", x, y);
    fflush(stdout);
  }
  else
  {
    printf("ERROR Invalid move.\n");
    fflush(stdout);
  }
}

void gcup_info_timeout_turn(int val)
{
  // TODO: not implemented
}

void gcup_info_timeout_match(int val)
{
  // TODO: not implemented
}

void gcup_info_max_memory(int val)
{
  // TODO: not implemented
}

void gcup_info_time_left(int val)
{
  // TODO: not implemented
}

void gcup_info_game_type(int val)
{
  // TODO: not implemented
}

void gcup_info_rule(int val)
{
  // TODO: not implemented
}

void gcup_info_evaluate(int x, int y)
{
  // TODO: not implemented
}

void gcup_info_folder(char *path)
{
  // TODO: not implemented
}
