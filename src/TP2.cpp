#include "TP2.h"

int main() {

	Consola consola = Consola();
	Juego juego = Juego(10, 10, 10);

	juego.iniciar(consola);

	return 0;
}
