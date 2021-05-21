#include "Jugador.h"

Jugador::Jugador() {
    this->nombre = "";
    this->jugadas = 0;
    this->ficha = '';
    this->flagGanador = false;
    //this->cartas = new Lista<Carta>();
}

Jugador::Jugador(std::string nombre, char ficha) {
    this->nombre = nombre;
    this->jugadas = 0;
    this->ficha = ficha;
    this->flagGanador = false;
    //this->cartas = new Lista<Carta>();
}

Jugador::~Jugador() {
	//delete this->cartas;
}

std::string Jugador::obtenerNombre() {

	return this->nombre;
}

void Jugador::asignarNombre(std::string nombre) {

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

/*
Lista<Carta>* Jugador::obtenerCartas() {

	return this->cartas;
}
*/

std::ostream& operator<<(std::ostream &strm, const Jugador &jugador) {

	return strm << "Jugador(nombre=" << jugador.nombre
				<< ", jugadas=" << jugador.jugadas
				<< ", ficha=" << jugador.ficha
				<< ", flagGanador=" << jugador.flagGanador
				//<< ", cartas=" << jugador.cartas->contarElementos()
				<< ")";
}
