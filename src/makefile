
sources := main.c \
           engine.c

headers := engine.h 

objects := $(patsubst %.c, %.o, $(sources))

all: gomoko

gomoko: $(objects)
	gcc -o $@ $(objects)

%.o: %c $(headers)
	gcc -c -o $@ $<
