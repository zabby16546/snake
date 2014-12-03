cxflags = -std=c++11
sfml = -LDEPS/lib -lsfml-main -lsfml-graphics -lsfml-window -lsfml-system
sfinclude = -IDEPS/include

game.exe: snake.o main.o
	g++ snake.o main.o $(sfml) -o game.exe

snake.o: snake.cpp snake.h
	g++ -c snake.cpp $(cxflags) $(sfinclude) -o snake.o

main.o: main.cpp snake.h
	g++ -c main.cpp $(cxflags) $(sfinclude) -o main.o