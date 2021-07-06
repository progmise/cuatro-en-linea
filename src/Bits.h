#ifndef BITS_H_
#define BITS_H_
#include "lib/EasyBMP.h"
#include "Color.h"
#include <string>
#include <sstream>

class Bits {

	private:

		BMP* imagen;

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una imagen de dimensiones ancho x alto en pixeles.
		 * 		 Origen de coordenadas en extremo superior izquierdo, de la imagen
		 */
		Bits(unsigned int ancho, unsigned int alto);

		/*
		 * PRE:  No tiene
		 * POST: Destruye la imagen
		 */
		~Bits();

		/*
		 * PRE:  No tiene
		 * POST: Asigna al pixel ubicado en (pixelX, pixelY) el color indicado
		 */
		void asignar(unsigned int pixelX, unsigned int pixelY, Color* color);

		/*
		 * PRE:  No tiene
		 * POST: Genera un archivo de imagen con extension .bmp
		 */
		void escribir(std::string nombreDeArchivo);
};

#endif /* BITS_H_ */
