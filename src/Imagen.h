#ifndef IMAGEN_H_
#define IMAGEN_H_
#include "Lista.h"
#include "Casillero.h"
#include "Bits.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

/*
 * Se encarga de generar un archivo .bmp que representa un tablero con los elementos
 * que lo componen durante una partida del cuatro en línea
 */
class Imagen {

	private:

		unsigned int tamanioDeUnaFicha;
		unsigned int tamanioPunto;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Imagen&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una instancia de una imagen, que representa a un
		 * 		 tablero 2D
		 */
		Imagen();

		/*
		 * PRE:  El tablero debe contar con elementos. longitud, profundidad y ronda
		 * 		 deben ser números enteros no negativos
		 * POST: Crea una imagen de un tablero y la guarda como formato .bmp
		 */
		void dibujarTablero(Lista<Lista<Casillero*>*>* tablero, unsigned int longitud,
							unsigned int profundidad, unsigned int nivel, unsigned int ronda);

	private:

		/*
		 * PRE:  El tablero debe contar con elementos
		 * POST: Dibuja dentro de imagen todos los elementos que conforman el tablero
		 */
		void dibujarContenidoDelTablero(Lista<Lista<Casillero*>*>* tablero, unsigned int longitud,
										unsigned int profundidad, Bits* imagen);

		/*
		 * PRE:  imagen debe ser un mapa de bits
		 * POST: Dibuja una cuadricula en el mapa de bits
		 */
		void dibujarCuadricula(Bits* imagen, unsigned int ancho, unsigned int alto);

		/*
		 * PRE:  imagen debe ser un mapa de bits
		 * POST: Dibuja las lineas verticales de la cuadricula
		 */
		void dibujarLineasVerticales(Bits *imagen, unsigned int ancho, unsigned int alto, Color *colorDeLineas);

		/*
		 * PRE:  imagen debe ser un mapa de bits
		 * POST: Dibuja las lineas horizontales de la cuadricula
		 */
		void dibujarLineasHorizontales(Bits *imagen, unsigned int ancho, unsigned int alto, Color *colorDeLineas);

		/*
		 * PRE:  colorDeFicha es el color de una ficha
		 * POST: Dibuja un cuadrado en el mapa de bits
		 */
		void dibujarUnaFicha(Color* colorDeFicha, Bits* imagen, unsigned int pixelX, unsigned int pixelY);

		/*
		 * PRE:  desdeX debe ser menor o igual a hastaX
		 * 		 desdeY debe ser menor o igual a hastaY
		 * POST: Dibuja una seccion rectangular en la imagen determinada
		 */
		void dibujarEnAnchoYenAlto(Color* color, Bits* imagen, unsigned int desdeX,
								   unsigned int hastaX, unsigned int desdeY, unsigned int hastaY);
};

#endif /* IMAGEN_H_ */
