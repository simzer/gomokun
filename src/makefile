
sources := main.c   \
           board.c  \
           engine.c \
           ai.c 

headers := engine.h \
           board.h  \
           ai.h

objects := $(patsubst %.c, %.o, $(sources))

all: gomoku

gomoku: $(objects)
	gcc -o $@ $(objects)

clean:
	rm -rf *.o gomoku

%.o: %c $(headers)
	gcc -c -Wall -o $@ $<
