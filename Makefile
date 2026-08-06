all: ./preBuild/paquet.o ./preBuild/croupier.o ./preBuild/joueur.o ./preBuild/game.o prog

./preBuild/paquet.o: ./src/paquet.cpp ./build/paquet.hpp
	g++ -c -g ./src/paquet.cpp -o ./preBuild/paquet.o

./preBuild/croupier.o: ./src/croupier.cpp ./build/croupier.hpp
	g++ -c -g ./src/croupier.cpp -o ./preBuild/croupier.o

./preBuild/joueur.o: ./src/joueur.cpp ./build/joueur.hpp
	g++ -c -g ./src/joueur.cpp -o ./preBuild/joueur.o

./preBuild/game.o: ./src/game.cpp ./build/game.hpp
	g++ -c -g ./src/game.cpp -o ./preBuild/game.o

prog: ./preBuild/paquet.o ./preBuild/croupier.o ./preBuild/joueur.o ./preBuild/game.o ./src/main.cpp
	g++ -g ./preBuild/paquet.o ./preBuild/croupier.o ./preBuild/joueur.o ./preBuild/game.o ./src/main.cpp -o prog

