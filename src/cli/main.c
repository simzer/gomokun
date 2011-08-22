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

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "board.h"
#include "engine.h"
#include "ai.h"

int main(int argc, char **argv)
{
  if (argc == 3)
  {
    if (strcmp(argv[1], "--mode") == 0)
    {
      if (strcmp(argv[2], "gomocup") == 0)  yyparse();
    }
  }

  return(0);
}
