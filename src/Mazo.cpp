#include "Mazo.h"
#include <cstdlib> //rand() MAX_RAND

using namespace std;

Mazo::Mazo() {
	this->cartas = new Cola<Carta*>();
	this->cartasLevantadas = 0;
}

Mazo::~Mazo() {

	Carta* carta = NULL;

	while (!this->cartas->estaVacia()) {

		carta = this->cartas->desacolar();

		delete carta;
	}

	delete this->cartas;
}

Cola<Carta*>* Mazo::obtenerCartas() {

	return this->cartas;
}

void Mazo::llenarMazo() {

	Carta* carta = NULL;

	for (int i = 0; i < MAX_CARTAS_MAZO; i++) {

		carta = generarAzarmenteCarta();

		this->cartas->acolar(carta);

		carta = NULL;
	}
}

void Mazo::levantarCartaTope(Jugador* jugador) {

	Carta* carta = NULL;
	unsigned int cantCartas = jugador->obtenerCartas()->contarElementos();

	if (cantCartas < MAX_CARTAS_JUGADOR) {

		carta = this->cartas->desacolar();
		this->cartasLevantadas++;
		jugador->obtenerCartas()->agregar(carta);

		carta = generarAzarmenteCarta();
		this->cartas->acolar(carta);
	}
}

Carta* Mazo::generarAzarmenteCarta() {

	int numero = 0;
	Carta* carta = NULL;

	numero = (rand() % CANT_TIPOS_CARTAS) + 1;

	switch(numero){
		case 1:
			carta = new Carta(
				numero,
				"Carta Bloquear Turno",
				"Hace perder un turno al siguiente jugador"
			);
			break;

		case 2:
			carta = new Carta(
				numero,
				"Carta Juega Doble",
				"Permite al jugador jugar dos fichas, en vez de una"
			);
			break;

		case 3:
			carta = new Carta(
					numero,
					"Carta Fatality",
					"Permite al jugador borrar las cartas de otro jugador seleccionado"
			);
			break;

		case 4:
			carta = new Carta(
					numero,
					"Carta Usurpadora",
					"Permite al jugador usurpar una ficha adyacente al jugador"
					);
			break;

		default:
			throw "Número al azar inválido";
			break;
	}

	return carta;
}

ostream& operator<<(ostream &strm, const Mazo &mazo) {

	return strm << "Mazo(cartas=" << mazo.cartas->contarElementos()
				<< ")";
}
