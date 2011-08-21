
sources := main.c   \
           board.c  \
           engine.c \
           ai.c 

headers := engine.h \
           board.h  \
           ai.h

objects := $(patsubst %.c, %.o, $(sources))

all: gomoko

gomoko: $(objects)
	gcc -o $@ $(objects)

clean:
	rm -rf *.o gomoko

%.o: %c $(headers)
	gcc -c -Wall -o $@ $<
