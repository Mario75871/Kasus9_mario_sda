CC=gcc
CFLAGS=-Wall

OBJS = main.o node.o tree_builder.o encode.o decode.o traversal.o cleanup.o

morse: $(OBJS)
	$(CC) -o morse $(OBJS)

clean:
	rm -f *.o morse
