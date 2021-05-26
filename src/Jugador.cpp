#include "Jugador.h"

using namespace std;

Jugador::Jugador() {
    this->nombre = "";
    this->jugadas = 0;
    this->ficha = '\0';
    this->flagGanador = false;
    this->cartas = new Lista<Carta*>();
}

Jugador::Jugador(string nombre, char ficha) {
    this->nombre = nombre;
    this->jugadas = 0;
    this->ficha = ficha;
    this->flagGanador = false;
    this->cartas = new Lista<Carta*>();
}

Jugador::~Jugador() {

	Carta* carta = NULL;

	this->cartas->iniciarCursor();

	while (this->cartas->avanzarCursor()) {

		carta = this->cartas->obtenerCursor();

		delete carta;
	}

	delete cartas;
}

string Jugador::obtenerNombre() {

	return this->nombre;
}

void Jugador::asignarNombre(string nombre) {

	this->nombre = nombre;
}

unsigned int Jugador::obtenerJugadas() {

	return this->jugadas;
}

void Jugador::asignarJugadas(unsigned int jugadas) {

	this->jugadas = jugadas;
}

char Jugador::obtenerFicha() {

	return this->ficha;
}

void Jugador::asignarFicha(char ficha) {

	this->ficha = ficha;
}

bool Jugador::esGanador() {

	return this->flagGanador;
}

void Jugador::asignarGanador(bool flagGanador) {

	this->flagGanador = flagGanador;
}

Lista<Carta*>* Jugador::obtenerCartas() {

	return this->cartas;
}

void Jugador::jugarCarta(Lista<Jugador*>* jugadores, unsigned int indiceCarta) {

	Carta* carta = this->cartas->obtener(indiceCarta);

	switch (indiceCarta) {

		case 1:

			carta->bloquearTurno(jugadores);
			break;

		case 2:

			carta->jugarDoble(jugadores);
			break;

		default:

			throw "índice de carta inválido";
			break;
	}

	this->cartas->remover(indiceCarta);
}

ostream& operator<<(ostream &strm, const Jugador &jugador) {

	return strm << "Jugador(nombre=" << jugador.nombre
				<< ", jugadas=" << jugador.jugadas
				<< ", ficha=" << jugador.ficha
				<< ", flagGanador=" << jugador.flagGanador
				<< ", cartas=" << jugador.cartas->contarElementos()
				<< ")";
}

bool operator==(const Jugador &lhs, const Jugador &rhs) {

	return (
		lhs.ficha == rhs.ficha
	);
}

bool operator!=(const Jugador &lhs, const Jugador &rhs) {

	return !(lhs == rhs);
}
