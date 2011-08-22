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

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "board.h"

typedef enum
{
  ENGINE_EMPTY = 0,
  ENGINE_BLACK = 1,
  ENGINE_WHITE = 2
} engine_player_type;

typedef struct
{
  board_type *board;
  engine_player_type actual_player;
  int round;
  int finished;
} engine_type;

engine_type *engine_create(int width, int height);
int engine_set(int row, int col, engine_player_type player, engine_type *engine);
int engine_step(int row, int col, engine_type *engine);
int engine_reset(engine_type *engine);
void engine_destruct(engine_type *engine);

#endif
