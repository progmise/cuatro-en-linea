#include "Color.h"
#include "lib/EasyBMP.h"

Color::Color() {
	this->bmp = new BMP();
    this->color = new RGBApixel();
    this->color->Red = 255;
    this->color->Green = 255;
    this->color->Blue = 255;

	bmp->SetBitDepth(8);
    EasyBMP::SetEasyBMPwarningsOff();
}

Color::Color(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul) {
	this->bmp = new BMP();
    this->color = new RGBApixel();
    this->color->Red = rojo;
    this->color->Green = verde;
    this->color->Blue = azul;

    bmp->SetBitDepth(8);
    EasyBMP::SetEasyBMPwarningsOff();
}

Color::~Color() {
	delete this->bmp;
    delete this->color;
}

ebmpBYTE Color::obtenerRojo() {

    return this->color->Red;
}

void Color::asignarRojo(ebmpBYTE rojo) {

    this->color->Red = rojo;
}

ebmpBYTE Color::obtenerVerde() {

    return this->color->Green;
}

void Color::asignarVerde(ebmpBYTE verde) {

    this->color->Green = verde;
}

ebmpBYTE Color::obtenerAzul() {

    return this->color->Blue;
}

void Color::asignarAzul(ebmpBYTE azul) {

    this->color->Blue = azul;
}

RGBApixel* Color::obtenerPixel() {

    return this->color;
}

void Color::asignarPixel(int numeroDeColor) {

	RGBApixel color;
	bool estaCreadoTablaDeColores = this->bmp->CreateStandardColorTable();

	if (estaCreadoTablaDeColores) {

		color = this->bmp->GetColor(numeroDeColor);
	}

	*(this->color) = color;
}
