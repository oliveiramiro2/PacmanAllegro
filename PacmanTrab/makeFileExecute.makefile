all: Display.o Entities.o Game.o Rules.o main.o
	g++ Display.o Entities.o Game.o Rules.o main.o -o main.exe

Display.o: Display.h Display.cpp
	g++ -c Display.cpp -o Display.o

Entities.o: Entities.h Entities.cpp
	g++ -c Entities.cpp -o Entities.o

Rules.o: Rules.h Rules.cpp
	g++ -c Rules.cpp -o Rules.o

Game.o: Game.h Game.cpp
	g++ -c Game.cpp -o Game.o

main.o: Rules.h Game.h Entities.h Display.h main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm *.o *.exe