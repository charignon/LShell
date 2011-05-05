CC      = gcc
SOURCES = main.c 
EXEC    = LShell
CFLAGS  = -Wall -O2 -o 

all : $(EXEC)

$(EXEC) : $(SOURCES)
	$(CC) $^ $(CFLAGS) $@

clean : 
	rm -rf $(EXEC)

