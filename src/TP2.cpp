#include "TP2.h"
#include "Imagen.h"

 int main() {

	Consola consola = Consola();
	Imagen imagen = Imagen();
	Juego* juego = new Juego(10, 10, 10);

	juego->iniciar(consola, imagen);

	delete juego;

	return 0;
}
