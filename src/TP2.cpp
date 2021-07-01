#include "TP2.h"
#include <iostream>

int main() {

	Tablero* tablero = new Tablero(10, 10, 10);

	Lista<Casillero*>* recta = tablero->obtenerRectaEnX(8, 8);

	recta->iniciarCursor();
	while (recta->avanzarCursor()) {
		Casillero* casillero = recta->obtenerCursor();
		std::cout << casillero->obtenerPosicionX() << std::endl;
		std::cout << casillero->obtenerPosicionY() << std::endl;
		std::cout << casillero->obtenerPosicionZ() << std::endl;
	}
	Consola consola = Consola();
	Juego juego = Juego(10, 10, 10);
	juego.iniciar(consola);

	return 0;
}
