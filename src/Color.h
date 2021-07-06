#ifndef COLOR_H_
#define COLOR_H_
#include "EasyBMP.h"

class Color {

private:

	BMP* bmp;
    RGBApixel* color;

	public:

		/*
		 * PRE:  No tiene
		 * POST: Genera el color blanco del modelo RGB
		 */
    	Color();

		/*
		 * PRE: Rojo, verde y azul son enteros que toman valores entre 0 y 255
		 * POST: Genera un nuevo color del modelo RGB
		 */
		Color(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

		/*
		 * PRE:  El color debe haber sido creado
		 * POST: Destruye el color
		 */
		~Color();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de rojo, la cantidad
		 */
		ebmpBYTE obtenerRojo();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de rojo
		 */
		void asignarRojo(ebmpBYTE rojo);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de verde, la cantidad
		 */
		ebmpBYTE obtenerVerde();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de rojo
		 */
		void asignarVerde(ebmpBYTE verde);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de azul, la cantidad
		 */
		ebmpBYTE obtenerAzul();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de azul
		 */
		void asignarAzul(ebmpBYTE azul);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un RGBApixel con los colores asociados
		 */
		RGBApixel* obtenerPixel();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor a RGBApixel, de acuerdo al número
		 * 		 de color ingresado
		 */
		void asignarPixel(int numeroDeColor);
};

#endif /* COLOR_H_ */
