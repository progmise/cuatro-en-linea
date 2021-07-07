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

	Jugador* jugador = NULL;
	unsigned int tamanio = jugadores->contarElementos();

	for (unsigned int i = 1; i < tamanio + 1; i++) {

		jugador = jugadores->obtenerCursor();

		if (jugador == jugadores->obtener(tamanio)) {

			jugadores->iniciarCursor();

		} else {

			jugadores->avanzarCursor();
		}
	}
}

void Carta::borrarCartas(Jugador* jugador) {

	Lista<Carta*>* cartas = jugador->obtenerCartas();
	Carta* carta = NULL;

	for (unsigned int i = cartas->contarElementos(); i > 0; i--) {

		carta = cartas->obtener(i);
		cartas->remover(i);

		delete carta;
	}
}

void Carta::usurpar(Lista<Jugador*>* jugadores, Casillero* casillero){
	Jugador* jugadorUsurpar = NULL;
	Jugador* jugador = jugadores->obtenerCursor();
	char ficha = casillero->obtenerFicha()->obtenerTipoDeFicha();

	for(unsigned int i = 1; i <= jugadores->contarElementos(); i++){
		Jugador* jugadorActual = jugadores->obtener(i);
		if(jugadorActual->obtenerFicha()->obtenerTipoDeFicha() == ficha && jugador->obtenerFicha()->obtenerTipoDeFicha() != ficha){
			jugadorUsurpar = jugadorActual;
		}
	}

	Lista<Casillero*>* casilleros = jugadorUsurpar->obtenerCasilleros();
	bool seguir = true;
	int contador = 1;
	while(seguir && contador <= casilleros->contarElementos()){
		if(casilleros->obtener(contador) == casillero){
			casilleros->remover(contador);
			seguir = false;
		}
		contador++;
	}
	casillero->asignarFicha(jugador->obtenerFicha());
	jugador->obtenerCasilleros()->agregar(casillero);
}

ostream& operator<<(ostream &strm, const Carta &carta) {

	return strm << "Carta(id=" << carta.id
				<< ", nombre=" << carta.nombre
				<< ", descripcion=" << carta.descripcion
				<< ")";
}
