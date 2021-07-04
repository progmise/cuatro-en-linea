#include "Ficha.h"

using namespace std;

Ficha::Ficha() {
	this->color = new Color(250, 250, 250);
	this->tipoDeFicha = '\0';
}

Ficha::Ficha(char tipoDeFicha) {
	this->color = new Color(250, 250, 250);
	this->tipoDeFicha = tipoDeFicha;
}

Ficha::Ficha(Color* color, char tipoDeFicha) {
	this->color = color;
	this->tipoDeFicha = tipoDeFicha;
}

Ficha::~Ficha() {

	delete this->color;
}

Color* Ficha::obtenerColor() {

	return this->color;
}

void Ficha::asignarColor(Color* color) {

	this->color->asignarAzul(color->obtenerAzul());
	this->color->asignarRojo(color->obtenerRojo());
	this->color->asignarVerde(color->obtenerVerde());
}

char Ficha::obtenerTipoDeFicha() {

	return this->tipoDeFicha;
}

void Ficha::asignarTipoDeFicha(char tipoDeFicha) {

	this->tipoDeFicha = tipoDeFicha;
}

ostream& operator<<(ostream &strm, const Ficha &ficha) {

	return strm << "Ficha(tipoDeFicha=" << ficha.tipoDeFicha
				<< ")";
}
