#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    this->longitud = 0;
    this->profundidad = 0;
    this->altura = 0;
    this->casilleros = new Lista<Casillero*>();
}

Tablero::Tablero(unsigned int longitud, unsigned int profundidad, unsigned int altura) {
    this->longitud = longitud;
    this->profundidad = profundidad;
    this->altura = altura;
    this->casilleros = new Lista<Casillero*>();

    Casillero* casillero;

    for (unsigned int i = 0; i < longitud; i++) {

        for (unsigned int j = 0; j < profundidad; j++) {

            for (unsigned int k = 0; k < altura; k++) {

            	casillero = new Casillero(i, j, k);

            	this->casilleros->agregar(casillero);
            }
        }
    }
}

Tablero::~Tablero() {

	delete this->casilleros;
}

unsigned int Tablero::obtenerLongitud() {

	return this->longitud;
}

void Tablero::asignarLongitud(unsigned int longitud) {

	this->longitud = longitud;
}

unsigned int Tablero::obtenerProfundidad() {

	return this->profundidad;
}

void Tablero::asignarProfundidad(unsigned int profundidad) {

	this->profundidad = profundidad;
}

unsigned int Tablero::obtenerAltura() {

	return this->altura;
}

void Tablero::asignarAltura(unsigned int altura) {

	this->altura = altura;
}

Lista<Casillero*>* Tablero::obtenerCasilleros() {

	return this->casilleros;
}

ostream& operator<<(ostream &strm, const Tablero &tablero) {

	return strm << "Tablero(longitud=" << tablero.longitud
				<< ", profundidad=" << tablero.profundidad
				<< ", altura=" << tablero.altura
				<< ", casilleros=" << tablero.casilleros->contarElementos()
				<< ")";
}
