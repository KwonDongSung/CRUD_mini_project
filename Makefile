CC = gcc
CFlags = -W -Wall
TARGET = bookstore
DTARGET = bookstore_debug
OBJECTS = bookstore.c book.o file.o search.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)
