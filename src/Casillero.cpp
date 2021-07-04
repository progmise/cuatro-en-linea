#include "Casillero.h"

using namespace std;

Casillero::Casillero() {
	//TODO: Revisar si es necesaria la inicialización de vecinos
	//		o bien, inicializar el 1, 1, 1 con null o this
	this->ficha = new Ficha(CASILLERO_LIBRE);
	this->ocupado = false;

	for (unsigned int i = 0; i < CANT_VECINOS; i++) {

		for (unsigned int j = 0; j < CANT_VECINOS; j++) {

			for (unsigned int k = 0; k < CANT_VECINOS; k++) {

				this->vecinos[i][j][k] = NULL;
			}
		}
	}

    this->posicionX = 0;
    this->posicionY = 0;
    this->posicionZ = 0;
}

Casillero::Casillero(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ) {
	//TODO: Revisar si es necesaria la inicialización de vecinos
	//		o bien, inicializar el 1, 1, 1 con null o this
	this->ficha = new Ficha(CASILLERO_LIBRE);
	this->ocupado = false;

	for (unsigned int i = 0; i < CANT_VECINOS; i++) {

		for (unsigned int j = 0; j < CANT_VECINOS; j++) {

			for (unsigned int k = 0; k < CANT_VECINOS; k++) {

				this->vecinos[i][j][k] = NULL;
			}
		}
	}

    this->posicionX = posicionX;
    this->posicionY = posicionY;
    this->posicionZ = posicionZ;
}

Casillero::~Casillero() {
	delete this->ficha;
}

Ficha* Casillero::obtenerFicha() {

	return this->ficha;
}

void Casillero::asignarFicha(Ficha* ficha) {

	this->ficha->asignarColor(ficha->obtenerColor());
	this->ficha->asignarTipoDeFicha(ficha->obtenerTipoDeFicha());
}

bool Casillero::estaOcupado() {

	return this->ocupado;
}

void Casillero::asignarOcupado(bool ocupado) {

	this->ocupado = ocupado;
}

Casillero* Casillero::obtenerVecino(int posicionX, int posicionY, int posicionZ) {

	//TODO: Validar
	return vecinos[posicionX + 1][posicionY + 1][posicionZ + 1];
}

void Casillero::asignarVecino(Casillero* casillero, int posicionX, int posicionY, int posicionZ) {

	if (!(posicionX == 0 && posicionY == 0 && posicionZ == 0)) {

		this->vecinos[posicionX + 1][posicionY + 1][posicionZ + 1] = casillero;
	}
}

unsigned int Casillero::obtenerPosicionX() {

	return this->posicionX;
}

void Casillero::asignarPosicionX(unsigned int posicionX) {

	this->posicionX = posicionX;
}

unsigned int Casillero::obtenerPosicionY() {

	return this->posicionY;
}

void Casillero::asignarPosicionY(unsigned int posicionY) {

	this->posicionY = posicionY;
}

unsigned int Casillero::obtenerPosicionZ() {

	return this->posicionZ;
}

void Casillero::asignarPosicionZ(unsigned int posicionZ) {

	this->posicionZ = posicionZ;
}

bool Casillero::esElMismoJugador(Casillero* casillero) {

	return this->ficha->obtenerTipoDeFicha() == casillero->ficha->obtenerTipoDeFicha();
}

ostream& operator<<(ostream &strm, const Casillero &casillero) {

	return strm << "Casillero(ocupado=" << boolalpha << casillero.ocupado
				<< ", x=" << casillero.posicionX
				<< ", y=" << casillero.posicionY
				<< ", z=" << casillero.posicionZ
				<< ")";
}
