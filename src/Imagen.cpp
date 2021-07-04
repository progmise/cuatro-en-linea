#include "Imagen.h"

using namespace std;

Imagen::Imagen() {
    this->tamanioDeUnaFicha = 30;
    this->tamanioPunto = 30;
}

void Imagen::dibujarTablero(Lista<Lista<Casillero*>*>* tablero, unsigned int longitud,
							unsigned int profundidad, unsigned int nivel, unsigned int ronda) {

	Bits* imagen = NULL;
	stringstream strStream;
	string nombreDeArchivo;
    unsigned int ancho = longitud * this->tamanioDeUnaFicha;
    unsigned int alto = profundidad * this->tamanioDeUnaFicha;

    imagen = new Bits(ancho, alto);

    dibujarCuadricula(imagen, ancho, alto);
    dibujarContenidoDelTablero(tablero, longitud, profundidad, imagen);

    strStream << "estado_tablero_ronda" << setfill('0') << setw(3) << ronda
    		  << "_nivel" << setfill('0') << setw(3) << nivel;

    nombreDeArchivo = string(strStream.str());

	strStream.str(string());
	strStream.clear();

    imagen->escribir(nombreDeArchivo);

    delete imagen;
}

void Imagen::dibujarContenidoDelTablero(Lista<Lista<Casillero*>*>* tablero, unsigned int longitud,
										unsigned int profundidad, Bits* imagen) {

	Color* colorDeUnaFicha = NULL;

    for (unsigned int columna = 0; columna < longitud; columna++) {

        for (unsigned int fila = 0; fila < profundidad; fila++) {

            unsigned int desdeX = columna * this->tamanioDeUnaFicha;
            unsigned int desdeY = fila * this->tamanioDeUnaFicha;

            colorDeUnaFicha = tablero->obtener(columna + 1)->obtener(fila + 1)->obtenerFicha()->obtenerColor();

            dibujarUnaFicha(colorDeUnaFicha, imagen, desdeX, desdeY);
        }
    }
}

void Imagen::dibujarCuadricula(Bits* imagen, unsigned int ancho, unsigned int alto) {

    Color* colorDeLineas = new Color(0, 0, 0);

    dibujarLineasVerticales(imagen, ancho, alto, colorDeLineas);
    dibujarLineasHorizontales(imagen, ancho, alto, colorDeLineas);

    delete colorDeLineas;
}

void Imagen::dibujarLineasVerticales(Bits *imagen, unsigned int ancho, unsigned int alto,
									 Color *colorDeLineas) {

    for (unsigned int x = this->tamanioDeUnaFicha - 1; x < ancho; x += this->tamanioDeUnaFicha) {

        for (unsigned int y = 0; y < alto; y++) {

            imagen->asignar(x, y, colorDeLineas);
        }
    }
}

void Imagen::dibujarLineasHorizontales(Bits *imagen, unsigned int ancho, unsigned int alto,
                                       Color *colorDeLineas) {

    for (unsigned int x = 0; x < ancho; x++) {

        for (unsigned int y = this->tamanioDeUnaFicha - 1; y < alto; y += this->tamanioDeUnaFicha) {

            imagen->asignar(x, y, colorDeLineas);
        }
    }
}

void Imagen::dibujarUnaFicha(Color* colorDeFicha, Bits* imagen, unsigned int pixelX,
							 unsigned int pixelY) {

    unsigned int hastaX = pixelX + this->tamanioDeUnaFicha - 2;
    unsigned int hastaY = pixelY + this->tamanioDeUnaFicha - 2;

    dibujarEnAnchoYenAlto(colorDeFicha, imagen, pixelX, hastaX, pixelY, hastaY);
}

void Imagen::dibujarEnAnchoYenAlto(Color* color, Bits* imagen, unsigned int desdeX,
								   unsigned int hastaX, unsigned int desdeY, unsigned int hastaY) {

    for (unsigned int x = desdeX; x <= hastaX; x++) {

        for (unsigned int y = desdeY; y <= hastaY; y++) {

            imagen->asignar(x, y, color);
        }
    }
}

ostream& operator<<(ostream &strm, const Imagen &imagen) {

	return strm << "Imagen(tamanioDeUnaFicha=" << imagen.tamanioDeUnaFicha
				<< ", tamanioPunto=" << imagen.tamanioPunto
				<< ")";
}
