#include "TP2.h"
#include "Imagen.h"

int main() {

	Consola consola = Consola();
	int dimensionTablero = consola.preguntarDimensionesDelTablero();
	int nFichas = consola.preguntarNFichasAlineadas(dimensionTablero);
	Imagen imagen = Imagen();
	Juego* juego = new Juego(dimensionTablero, dimensionTablero, dimensionTablero, nFichas);

	juego->iniciar(consola, imagen);

	delete juego;

	return 0;
}
