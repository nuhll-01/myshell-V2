CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: myshell mycat myhead myuniq

myshell: myshell.o
	$(CC) $(CFLAGS) -o myshell myshell.o

mycat: mycat.o
	$(CC) $(CFLAGS) -o mycat mycat.o

myhead: myhead.o
	$(CC) $(CFLAGS) -o myhead myhead.o

myuniq: myuniq.o
	$(CC) $(CFLAGS) -o myuniq myuniq.o

# Compile all C files
myshell.o: myshell.c
	$(CC) $(CFLAGS) -c myshell.c

mycat.o: mycat.c
	$(CC) $(CFLAGS) -c mycat.c

myhead.o: myhead.c
	$(CC) $(CFLAGS) -c myhead.c

myuniq.o: myuniq.c
	$(CC) $(CFLAGS) -c myuniq.c

clean:
	rm -f myshell mycat myhead myuniq *.o
