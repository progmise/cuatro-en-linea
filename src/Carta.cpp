#include "Carta.h"

Carta::Carta() {
	this->id = 0;
	this->nombre = "";
	this->descripcion = "";
}

Carta::Carta(unsigned int id, std::string nombre, std::string descripcion) {
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

std::string Carta::obtenerNombre() {

	return this->nombre;
}

void Carta::asignarNombre(std::string nombre) {

	this->nombre = nombre;
}

std::string Carta::obtenerDescripcion() {

	return this->descripcion;
}

void Carta::asignarDescripcion(std::string descripcion) {

	this->descripcion = descripcion;
}

void Carta::bloquearTurno(Lista<Jugador>* jugadores) {

	int tamanio = jugadores->contarElementos();

	if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {

		jugadores->iniciarCursor();

	} else {
		jugadores->avanzarCursor();
	}
}

void Carta::jugarDoble(Lista<Jugador>* jugadores) {

	unsigned int tamanio = jugadores->contarElementos();

	for (int i = 1; i < tamanio; i++) {

		jugadores->avanzarCursor();

		if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {

			jugadores->iniciarCursor();
		}
	}
}

std::ostream& operator<<(std::ostream &strm, const Carta &carta) {

	return strm << "Carta(id=" << carta.id
				<< ", nombre=" << carta.nombre
				<< ", descripcion=" << carta.descripcion
				<< ")";
}
