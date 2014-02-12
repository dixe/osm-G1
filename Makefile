CC		= gcc
CFLAGS 		= -Wall -pedantic -std=c99 -ggdb
EXECUTABLE	= task1
SOURCES		= main.c double_linked_list.c

default: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXECUTABLE) $(SOURCES)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE) $(EXECUTABLE).dSYM

totalitarian:
	splint -strict -preproc $(SOURCES)
