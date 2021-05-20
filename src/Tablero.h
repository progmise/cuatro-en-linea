#ifndef TABLERO_H_
#define TABLERO_H_
#include "Lista.h"
#include "Casillero.h"

class Tablero {

	private:

		unsigned int longitud;
		unsigned int profundidad;
		unsigned int altura;
		Lista<Casillero>* casilleros;

	public:

		Tablero();

		Tablero(unsigned int longitud, unsigned int profundidad, unsigned int altura);

		~Tablero();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de longitud
		 */
		unsigned int obtenerLongitud();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de longitud
		 */
		void asignarLongitud(unsigned int longitud);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de profundidad
		 */
		unsigned int obtenerProfundidad();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de longitud
		 */
		void asignarProfundidad(unsigned int profundidad);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de altura
		 */
		unsigned int obtenerAltura();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de altura
		 */
		void asignarAltura(unsigned int altura);

		Lista<Casillero>* obtenerCasilleros();
};



#endif /* TABLERO_H_ */
