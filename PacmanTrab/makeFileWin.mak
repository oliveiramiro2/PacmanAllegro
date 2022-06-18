all: Rules.o Entities.o Display.o Game.o main.o
	g++ Rules.o Entities.o Display.o Game.o main.o -o main.exe

Entities.o: Entities.h Entities.cpp
	g++ -c Entities.cpp -o Entities.o

Rules.o: Rules.h Rules.cpp
	g++ -c Rules.cpp -o Rules.o

Display.o: Display.h Display.cpp
	g++ -c Display.cpp -o Display.oGame.o: Game.h Game.cpp

Game.o: Game.h Game.cpp
	g++ -c Game.cpp -o Game.o

main.o: Rules.h Game.h Entities.h Display.h main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm *.o 