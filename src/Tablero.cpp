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

Lista<Casillero*>* Tablero::obtenerRectaEnX(unsigned int profundidad,
								   	   	    unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionY = 0;
	unsigned int posicionZ = 0;
	Lista<Casillero*>* recta = new Lista<Casillero*>();

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		casillero = this->casilleros->obtenerCursor();

		posicionY = casillero->obtenerPosicionY();
		posicionZ = casillero->obtenerPosicionZ();

		if (posicionY == profundidad && posicionZ == altura) {

			recta->agregar(casillero);
		}
	}

	return recta;
}
/*
Lista<Casillero*>* Tablero::obtenerRectaEnY(unsigned int longitud,
								   	   	    unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionZ = 0;
	Lista<Casillero*>* recta = new Lista<Casillero*>();

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		casillero = this->casilleros->obtenerCursor();

		posicionX = casillero->obtenerPosicionX();
		posicionZ = casillero->obtenerPosicionZ();

		if (posicionX == longitud && posicionZ == altura) {

			recta->agregar(casillero);
		}
	}

	return recta;
}

Lista<Casillero*>* Tablero::obtenerRectaEnZ(unsigned int longitud,
											unsigned int profundidad) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	Lista<Casillero*>* recta = new Lista<Casillero*>();

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		casillero = this->casilleros->obtenerCursor();

		posicionX = casillero->obtenerPosicionX();
		posicionY = casillero->obtenerPosicionY();

		if (posicionX == longitud && posicionY == profundidad) {

			recta->agregar(casillero);
		}
	}

	return recta;
}
*/
Lista<Lista<Casillero*>*>* Tablero::obtenerDiagonalesPlanoXY(unsigned int longitud,
														  	 unsigned int profundidad,
															 unsigned int altura) {

	Lista<Casillero*>* diagonal;
	Lista<Casillero*>* plano;
	Lista<Lista<Casillero*>*>* diagonales = new Lista<Lista<Casillero*>*>();

	plano = obtenerPlanoXY(altura);

	diagonal = obtenerDiagonalIzquierdaPlanoXY(plano, longitud, profundidad);
	diagonales->agregar(diagonal);

	diagonal = obtenerDiagonalDerechaPlanoXY(plano, longitud, profundidad);
	diagonales->agregar(diagonal);

	return diagonales;
}

Lista<Lista<Casillero*>*>* Tablero::obtenerDiagonales(unsigned int longitud,
													  unsigned int profundidad,
													  unsigned int altura) {

	Lista<Casillero*>* diagonal;
	Lista<Lista<Casillero*>*>* diagonales = new Lista<Lista<Casillero*>*>();

	diagonal = obtenerDiagonalIzquierdaTrasera(longitud, profundidad, altura);
	diagonales->agregar(diagonal);

	diagonal = obtenerDiagonalDerechaTrasera(longitud, profundidad, altura);
	diagonales->agregar(diagonal);

	diagonal = obtenerDiagonalIzquierdaFrontal(longitud, profundidad, altura);
	diagonales->agregar(diagonal);

	diagonal = obtenerDiagonalDerechaFrontal(longitud, profundidad, altura);
	diagonales->agregar(diagonal);

	return diagonales;
}

void Tablero::transponerTablero() {

	Casillero* casillero;
	unsigned int aux = 0;

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		casillero = this->casilleros->obtenerCursor();

		aux = casillero->obtenerPosicionX();

		casillero->asignarPosicionX(
			casillero->obtenerPosicionZ()
		);

		casillero->asignarPosicionZ(
			casillero->obtenerPosicionY()
		);

		casillero->asignarPosicionY(
			aux
		);
	}

	aux = this->longitud;

	this->longitud = this->altura;
	this->altura = this->profundidad;
	this->profundidad = aux;
}

Lista<Casillero*>* Tablero::obtenerPlanoXY(unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionZ = 0;
	Lista<Casillero*>* plano = new Lista<Casillero*>();

	this->casilleros->iniciarCursor();

	while (this->casilleros->avanzarCursor()) {

		casillero = this->casilleros->obtenerCursor();

		posicionZ = casillero->obtenerPosicionZ();

		if (posicionZ == altura) {

			plano->agregar(casillero);
		}
	}

	return plano;
}

Lista<Casillero*>* Tablero::obtenerDiagonalIzquierdaPlanoXY(Lista<Casillero*>* plano,
														    unsigned int columna,
															unsigned int fila) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	//unsigned int dimension = this->longitud;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	if (fila <= columna) {

		fila -= fila;
		columna -= fila;

	} else {

		fila -= columna;
		columna -= columna;
	}

	while (columna < this->longitud && fila < this->profundidad) {

		plano->iniciarCursor();

		while (plano->avanzarCursor()) {

			casillero = plano->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();

			if (posicionX == columna && posicionY == fila) {

				diagonal->agregar(casillero);
			}
		}

		columna++;
		fila++;
	}

	return diagonal;
}

Lista<Casillero*>* Tablero::obtenerDiagonalDerechaPlanoXY(Lista<Casillero*>* plano,
														    unsigned int columna,
															unsigned int fila) {
	
	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	unsigned int profundidad = this->profundidad - 1;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	if (columna + fila < profundidad) {

		fila -= fila;
		columna += fila;

	} else {

		fila -= (profundidad - columna);
		columna += (profundidad - columna);
	}

	while (columna < this->longitud && fila < this->profundidad) {

		plano->iniciarCursor();

		while (plano->avanzarCursor()) {

			casillero = plano->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();

			if (posicionX == columna && posicionY == fila) {

				diagonal->agregar(casillero);
			}
		}

		columna--;
		fila++;
	}

	return diagonal;	
}


Lista<Casillero*>* Tablero::obtenerDiagonalIzquierdaTrasera(unsigned int longitud,
												   	   	    unsigned int profundidad,
															unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	unsigned int posicionZ = 0;
	unsigned int menor = 0;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	menor = Util::obtenerMenorDeTres(longitud, profundidad, altura);

	longitud -= menor;
	profundidad -= menor;
	altura -= menor;

	while (longitud < this->longitud && profundidad < this->profundidad &&
		   altura < this->altura) {

		this->casilleros->iniciarCursor();

		while (this->casilleros->avanzarCursor()) {

			casillero = this->casilleros->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();
			posicionZ = casillero->obtenerPosicionZ();

			if (posicionX == longitud && posicionY == profundidad &&
				posicionZ == altura) {

				diagonal->agregar(casillero);
			}
		}

		longitud++;
		profundidad++;
		altura++;
	}

	return diagonal;
}

Lista<Casillero*>* Tablero::obtenerDiagonalDerechaTrasera(unsigned int longitud,
														  unsigned int profundidad,
														  unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	unsigned int posicionZ = 0;
	unsigned int menor = 0;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	menor = Util::obtenerMenorDeTres(longitud, profundidad, altura);

	longitud -= menor;
	profundidad += menor;
	altura -= menor;

	while (longitud < this->longitud && profundidad < this->profundidad &&
		   altura < this->altura) {

		this->casilleros->iniciarCursor();

		while (this->casilleros->avanzarCursor()) {

			casillero = this->casilleros->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();
			posicionZ = casillero->obtenerPosicionZ();

			if (posicionX == longitud && posicionY == profundidad &&
				posicionZ == altura) {

				diagonal->agregar(casillero);
			}
		}

		longitud++;
		profundidad--;
		altura++;
	}

	return diagonal;
}

Lista<Casillero*>* Tablero::obtenerDiagonalIzquierdaFrontal(unsigned int longitud,
													  	    unsigned int profundidad,
														    unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	unsigned int posicionZ = 0;
	unsigned int menor = 0;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	menor = Util::obtenerMenorDeTres(longitud, profundidad, altura);

	longitud += menor;
	profundidad -= menor;
	altura -= menor;

	while (longitud < this->longitud && profundidad < this->profundidad &&
		   altura < this->altura) {

		this->casilleros->iniciarCursor();

		while (this->casilleros->avanzarCursor()) {

			casillero = this->casilleros->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();
			posicionZ = casillero->obtenerPosicionZ();

			if (posicionX == longitud && posicionY == profundidad &&
				posicionZ == altura) {

				diagonal->agregar(casillero);
			}
		}

		longitud--;
		profundidad++;
		altura++;
	}

	return diagonal;
}

Lista<Casillero*>* Tablero::obtenerDiagonalDerechaFrontal(unsigned int longitud,
													  	  unsigned int profundidad,
														  unsigned int altura) {

	Casillero* casillero;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	unsigned int posicionZ = 0;
	unsigned int menor = 0;
	Lista<Casillero*>* diagonal = new Lista<Casillero*>();

	menor = Util::obtenerMenorDeTres(longitud, profundidad, altura);

	longitud += menor;
	profundidad += menor;
	altura -= menor;

	while (longitud < this->longitud && profundidad < this->profundidad &&
		   altura < this->altura) {

		this->casilleros->iniciarCursor();

		while (this->casilleros->avanzarCursor()) {

			casillero = this->casilleros->obtenerCursor();

			posicionX = casillero->obtenerPosicionX();
			posicionY = casillero->obtenerPosicionY();
			posicionZ = casillero->obtenerPosicionZ();

			if (posicionX == longitud && posicionY == profundidad &&
				posicionZ == altura) {

				diagonal->agregar(casillero);
			}
		}

		longitud--;
		profundidad--;
		altura++;
	}

	return diagonal;
}

ostream& operator<<(ostream &strm, const Tablero &tablero) {

	return strm << "Tablero(longitud=" << tablero.longitud
				<< ", profundidad=" << tablero.profundidad
				<< ", altura=" << tablero.altura
				<< ", casilleros=" << tablero.casilleros->contarElementos()
				<< ")";
}
