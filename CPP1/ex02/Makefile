all: program

program: main.o
	g++ main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o program
