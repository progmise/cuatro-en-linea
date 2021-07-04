#include "Bits.h"

using namespace std;

Bits::Bits(unsigned int ancho, unsigned int alto) {
    this->imagen = new BMP();
    this->imagen->SetSize(ancho, alto);
    this->imagen->SetBitDepth(24);
}

Bits::~Bits() {
    delete this->imagen;
}

void Bits::asignar(unsigned int pixelX, unsigned int pixelY, Color* color) {

    this->imagen->SetPixel(pixelX, pixelY, *(color->obtenerPixel()));
}

void Bits::escribir(string nombreDeArchivo) {

	stringstream strStream;
	string rutaDeArchivo;

	strStream << "images/" << nombreDeArchivo << ".bmp";

	rutaDeArchivo = string(strStream.str());

	strStream.str(string());
	strStream.clear();

    this->imagen->WriteToFile(rutaDeArchivo.c_str());
}
