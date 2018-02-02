CC=g++
CFLAG=-O2
TESTFLAGS=-Wall -g
SOURCES=main.cpp List.cpp briefing.cpp parent.cpp teacher.cpp
OBJS=main.o List.o briefing.o parent.o teacher.o
EXECUTABLE=main
LIB=

all: buildTests
	
buildTests: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(EXECUTABLE) $(LIB)

run:
	./$(EXECUTABLE) 150 40 50 8 10 100 10

main.o: main.cpp
	$(CC) -c $(TESTFLAGS) main.cpp -o main.o

List.o: List.cpp
	$(CC) -c $(TESTFLAGS) List.cpp -o List.o
	
briefing.o: briefing.cpp
	$(CC) -c $(TESTFLAGS) briefing.cpp -o briefing.o
	
parent.o: parent.cpp
	$(CC) -c $(TESTFLAGS) parent.cpp -o parent.o
	
teacher.o: teacher.cpp
	$(CC) -c $(TESTFLAGS) teacher.cpp -o teacher.o
	
clean:
	rm -f $(EXECUTABLE) $(OBJS)
