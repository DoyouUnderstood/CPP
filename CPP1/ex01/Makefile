all: program

program: main.o Zombie.o zombieHorde.o
	g++ main.o Zombie.o zombieHorde.o -o program

main.o: main.cpp
	g++ -c main.cpp

Zombie.o: Zombie.cpp
	g++ -c Zombie.cpp

zombieHorde.o: zombieHorde.cpp
	g++ -c zombieHorde.cpp

clean:
	rm -f *.o program
