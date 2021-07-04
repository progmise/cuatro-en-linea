#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    this->longitud = 0;
    this->profundidad = 0;
    this->altura = 0;
    this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>();
}

Tablero::Tablero(unsigned int longitud, unsigned int profundidad, unsigned int altura) {
    this->longitud = longitud;
    this->profundidad = profundidad;
    this->altura = altura;
    this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>();

    Lista<Lista<Casillero*>*>* fila = NULL;
    Lista<Casillero*>* columna = NULL;
    Casillero* casillero = NULL;
    Casillero* casilleroVecino = NULL;

    for (unsigned int k = 0; k < longitud; k++) {

    	fila = new Lista<Lista<Casillero*>*>();

        for (unsigned int j = 0; j < profundidad; j++) {

        	columna = new Lista<Casillero*>();

            for (unsigned int i = 0; i < altura; i++) {

            	casillero = new Casillero(i, j, k);

            	columna->agregar(casillero);
            }

            fila->agregar(columna);
        }

        this->casilleros->agregar(fila);
    }


    for (unsigned int z = 1; z < this->altura + 1; z++) {

    	fila = this->casilleros->obtener(z);

    	for (unsigned int y = 1; y < this->profundidad + 1; y++) {

    		columna = fila->obtener(y);

    		for (unsigned int x = 1; x < this->longitud + 1; x++) {

    			casillero = columna->obtener(x);

    			for (int i = -1; i < 2; i++) {

    				for (int j = -1; j < 2; j++) {

    					for (int k = -1; k < 2; k++) {

    						casilleroVecino = buscarCasillero(
    								this->casilleros,
									i + casillero->obtenerPosicionX(),
									j + casillero->obtenerPosicionY(),
									k + casillero->obtenerPosicionZ()
							);

    						casillero->asignarVecino(
    								casilleroVecino, i, j, k
							);
    					}
    				}
    			}
    		}
    	}
    }
}

Tablero::~Tablero() {

    Lista<Lista<Casillero*>*>* fila = NULL;
    Lista<Casillero*>* columna = NULL;
    Casillero* casillero = NULL;

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		fila = casilleros->obtenerCursor();

		fila->iniciarCursor();

		while (fila->avanzarCursor()) {

			columna = fila->obtenerCursor();

			columna->iniciarCursor();

			while (columna->avanzarCursor()) {

				casillero = columna->obtenerCursor();

				delete casillero;
			}

			delete columna;
		}

		delete fila;
	}

	delete casilleros;
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

Lista<Lista<Lista<Casillero*>*>*>* Tablero::obtenerCasilleros() {

	return this->casilleros;
}

Casillero* Tablero::buscarCasillero(Lista<Lista<Lista<Casillero*>*>*>* tablero, unsigned int posicionX,
									unsigned int posicionY, unsigned int posicionZ) {

	Lista<Lista<Casillero*>*>* fila = NULL;
	Lista<Casillero*>* columna = NULL;
	Casillero* casillero = NULL;
	Casillero* resultado = NULL;

	tablero->iniciarCursor();

	while (tablero->avanzarCursor() && resultado == NULL) {

		fila = tablero->obtenerCursor();
		fila->iniciarCursor();

		while (fila->avanzarCursor() && resultado == NULL) {

			columna = fila->obtenerCursor();
			columna->iniciarCursor();

			while (columna->avanzarCursor() && resultado == NULL) {

				casillero = columna->obtenerCursor();

				if (casillero->obtenerPosicionX() == posicionX &&
					casillero->obtenerPosicionY() == posicionY &&
					casillero->obtenerPosicionZ() == posicionZ) {

					resultado = casillero;
				}
			}
		}
	}

	return resultado;
}

ostream& operator<<(ostream &strm, const Tablero &tablero) {

	return strm << "Tablero(longitud=" << tablero.longitud
				<< ", profundidad=" << tablero.profundidad
				<< ", altura=" << tablero.altura
				<< ", casilleros=" << tablero.casilleros->contarElementos()
				<< ")";
}
