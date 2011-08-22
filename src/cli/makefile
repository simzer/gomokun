
sources := main.c    \
           board.c   \
           engine.c  \
           ai.c      \
           about.c   \
           gcup.c    \
           lex.yy.c  \
           y.tab.c

headers := engine.h  \
           board.h   \
           ai.h      \
           about.h   \
           gcup.h    \
           y.tab.h

objects := $(patsubst %.c, %.o, $(sources))

all: gomoku

gomoku: $(objects)
	gcc -o $@ $(objects)

clean:
	rm -rf *.o gomoku y.tab.* lex.yy.c

%.o: %.c $(headers)
	gcc -c -Wall -o $@ $<

lex.yy.c: gomocup.l
	lex $<

y.tab.c y.tab.h: gomocup.y
	yacc -d $<
