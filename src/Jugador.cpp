#include "Jugador.h"

using namespace std;

Jugador::Jugador() {
    this->nombre = "";
    this->jugadas = 0;
    this->ficha = new Ficha();
    this->flagGanador = false;
    this->cartas = new Lista<Carta*>();
    this->casilleros = new Lista<Casillero*>();
}

Jugador::Jugador(string nombre, Ficha* ficha) {
    this->nombre = nombre;
    this->jugadas = 0;
    this->ficha = ficha;
    this->flagGanador = false;
    this->cartas = new Lista<Carta*>();
    this->casilleros = new Lista<Casillero*>();
}

Jugador::~Jugador() {

	Carta* carta = NULL;

	this->cartas->iniciarCursor();

	while (this->cartas->avanzarCursor()) {

		carta = this->cartas->obtenerCursor();

		delete carta;
	}

	delete cartas;
	delete ficha;
	delete casilleros;
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

Ficha* Jugador::obtenerFicha() {

	return this->ficha;
}

void Jugador::asignarFicha(Ficha* ficha) {

	this->ficha->asignarColor(ficha->obtenerColor());
	this->ficha->asignarTipoDeFicha(ficha->obtenerTipoDeFicha());
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

Lista<Casillero*>* Jugador::obtenerCasilleros(){
	return this->casilleros;
}

void Jugador::jugarCarta(Lista<Jugador*>* jugadores, unsigned int indiceCarta, Jugador* jugador,
						 Casillero* casillero) {

	Carta* carta = this->cartas->obtener(indiceCarta);

	switch (carta->obtenerId()) {
		case 1:
			carta->bloquearTurno(jugadores);
			this->cartas->remover(indiceCarta);

			delete carta;

			break;

		case 2:
			carta->jugarDoble(jugadores);
			this->cartas->remover(indiceCarta);

			delete carta;

			break;

		case 3:

			carta->borrarCartas(jugador);
			this->cartas->remover(indiceCarta);

			delete carta;

			break;

		case 4:
			if(casillero != NULL){
				carta->usurpar(jugadores, casillero);
				this->cartas->remover(indiceCarta);
				delete carta;
			}

			break;

		default:
			throw "índice de carta inválido";
			break;
	}
}

ostream& operator<<(ostream &strm, const Jugador &jugador) {

	return strm << "Jugador(nombre=" << jugador.nombre
				<< ", jugadas=" << jugador.jugadas
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
