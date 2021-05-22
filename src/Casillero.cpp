#include "Casillero.h"

Casillero::Casillero() {
	this->tipoFicha = CASILLERO_LIBRE;
    this->posicionX = 0;
    this->posicionY = 0;
    this->posicionZ = 0;
}

Casillero::Casillero(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ) {
	this->tipoFicha = CASILLERO_LIBRE;
    this->posicionX = posicionX;
    this->posicionY = posicionY;
    this->posicionZ = posicionZ;
}

char Casillero::obtenerTipoFicha() {

	return this->tipoFicha;
}

void Casillero::asignarTipoFicha(char tipoFicha) {

	this->tipoFicha = tipoFicha;
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

bool Casillero::estaOcupado() {

	return (this->tipoFicha != CASILLERO_LIBRE);
}

std::ostream& operator<<(std::ostream &strm, const Casillero &casillero) {

	return strm << "Casillero(x=" << casillero.posicionX
				<< ", y=" << casillero.posicionY
				<< ", z=" << casillero.posicionZ
				<< ", tipoFicha=" << casillero.tipoFicha
				<< ")";
}
