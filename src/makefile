CC = g++ 
CFLAGS = -g -Wall -Werror -Wconversion -std=c++98 -pedantic -O0
VFLAGS = --leak-check=full

.PHONY: clean all

TP2: Lista.h Cola.h Carta.cpp Casillero.cpp Consola.cpp Juego.cpp Jugador.cpp Mazo.cpp Tablero.cpp Util.cpp TP2.cpp
	$(CC) $(CFLAGS) *.cpp -o TP2

exe_TP2: TP2
	./TP2

valgrind: TP2
	valgrind $(VFLAGS) ./TP2