#include "Carta.h"

using namespace std;

Carta::Carta() {
	this->id = 0;
	this->nombre = "";
	this->descripcion = "";
}

Carta::Carta(unsigned int id, string nombre, string descripcion) {
	this->id = id;
	this->nombre = nombre;
	this->descripcion = descripcion;
}

unsigned int Carta::obtenerId() {

	return this->id;
}

void Carta::asignarId(unsigned int id) {

	this->id = id;
}

string Carta::obtenerNombre() {

	return this->nombre;
}

void Carta::asignarNombre(string nombre) {

	this->nombre = nombre;
}

string Carta::obtenerDescripcion() {

	return this->descripcion;
}

void Carta::asignarDescripcion(string descripcion) {

	this->descripcion = descripcion;
}

void Carta::bloquearTurno(Lista<Jugador*>* jugadores) {

	int tamanio = jugadores->contarElementos();

	if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {

		jugadores->iniciarCursor();
		jugadores->avanzarCursor();

	} else {

		jugadores->avanzarCursor();
	}
}

void Carta::jugarDoble(Lista<Jugador*>* jugadores) {

	unsigned int tamanio = jugadores->contarElementos();

	for (unsigned int i = 1; i < tamanio; i++) {

		jugadores->avanzarCursor();

		if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {

			jugadores->iniciarCursor();
		}
	}
}

ostream& operator<<(ostream &strm, const Carta &carta) {

	return strm << "Carta(id=" << carta.id
				<< ", nombre=" << carta.nombre
				<< ", descripcion=" << carta.descripcion
				<< ")";
}
