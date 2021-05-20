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

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo tablero
		 */
		Tablero();

        /*
         * PRE:  No tiene
         * POST: El tablero resulta inicializado con una longitud,
         * 		 profundidad y altura dadas. A partir de dichos valores,
         * 		 se inicializará la lista de casilleros, agregandole
         * 		 longitud x profundidad x altura casilleros
         */
		Tablero(unsigned int longitud, unsigned int profundidad, unsigned int altura);

		/*
		 * PRE:  El tablero debe haber sido creado
		 * POST: Destruye el tablero y todos sus elementos
		 */
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

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de casilleros
		 */
		Lista<Casillero>* obtenerCasilleros();
};



#endif /* TABLERO_H_ */
