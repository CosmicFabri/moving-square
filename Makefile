all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp mover.cpp -lmingw32 -lSDL2main -lSDL2