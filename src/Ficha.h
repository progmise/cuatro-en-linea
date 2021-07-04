#ifndef FICHA_H_
#define FICHA_H_
#include "Color.h"

class Ficha {

	private:

		Color* color;
		char tipoDeFicha;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Ficha&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una instancia de una ficha de color blanco
		 */
		Ficha();

        /*
         * PRE:  No tiene
         * POST: La ficha resulta inicializada con un tipoDeFicha dado
         */
		Ficha(char tipoDeFicha);

        /*
         * PRE:  No tiene
         * POST: La ficha resulta inicializada con un color y tipoDeFicha dado
         */
		Ficha(Color* color, char tipoDeFicha);

		/*
		 * PRE:  La ficha debe haber sido creada
		 * POST: Destruye la ficha
		 */
		~Ficha();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el puntero de color
		 */
		Color* obtenerColor();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de color
		 */
		void asignarColor(Color* color);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de tipoDeFicha
		 */
		char obtenerTipoDeFicha();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de tipoDeFicha
		 */
		void asignarTipoDeFicha(char tipoDeFicha);
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Ficha &ficha);

#endif /* FICHA_H_ */
