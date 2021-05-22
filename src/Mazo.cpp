#include "Mazo.h"

Mazo::Mazo() {
	this->cartas = new Cola<Carta>();
}

Mazo::~Mazo() {
	delete this->cartas;
}

Cola<Carta>* Mazo::obtenerCartas() {

	return this->cartas;
}

void Mazo::llenarMazo() {

	Carta* carta;

	for (int i = 0; i < MAX_CARTAS_MAZO; i++) {

		carta = generarAzarmenteCarta();

		this->cartas->acolar(*carta);
	}
}

void Mazo::levantarCartaTope(Jugador* jugador) {

	Carta* carta;
	unsigned int cantCartas = jugador->obtenerCartas()->contarElementos();

	if (cantCartas < MAX_CARTAS_JUGADOR) {

		carta = this->cartas->desacolar();
		jugador->obtenerCartas()->agregar(*carta);

		carta = generarAzarmenteCarta();
		this->cartas->acolar(*carta);
	}
}

Carta* Mazo::generarAzarmenteCarta() {

	int numero = 0;
	Carta* carta;

	numero = (rand() % CANT_TIPOS_CARTAS) + 1;

	switch (numero) {

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

		default:

			throw "Número al azar inválido";
			break;
	}

	return carta;
}
