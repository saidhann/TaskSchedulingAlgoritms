CC=g++
CFLAGS=-c -Wall -Iinc
LDFLAGS=
SOURCES=src/main.cpp src/zadania.cpp src/rozwiazania.cpp src/problem.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
