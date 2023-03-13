PROG=inl2.exe
CC=gcc
CFLAGS=-g -Wall
DEPS = safeinput.h
OBJ = menu.o main.o safeinput.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)