C=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=hash.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=oovedjeproject11

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.C.O:
	$(CC) $(CFLAGS) $< -o $@
clean:
	@rm -f $(PROGRAMS) *.o core
