#ifndef CARTA_H_
#define CARTA_H_
#include "Lista.h"
#include "Jugador.h"
#include <iostream>

class Carta {

	private:

		unsigned int id;
		std::string nombre;
		std::string descripcion;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Carta&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una nueva carta
		 */
		Carta();

        /*
         * PRE:  No tiene
         * POST: La carta resulta inicializada con un id,
         * 		 nombre y descripcion dados
         */
		Carta(unsigned int id, std::string nombre, std::string descripcion);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de id
		 */
		unsigned int obtenerId();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de id
		 */
		void asignarId(unsigned int id);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de nombre
		 */
		std::string obtenerNombre();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de nombre
		 */
		void asignarNombre(std::string nombre);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de descripcion
		 */
		std::string obtenerDescripcion();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de descripcion
		 */
		void asignarDescripcion(std::string descripcion);

		/*
		 * PRE:  La lista de jugadores, no debe estar vacía
		 * POST: Mueve el cursor de la lista, al siguiente jugador
		 */
		void bloquearTurno(Lista<Jugador>* jugadores);

		/*
		 * PRE:  La lista de jugadores, no debe estar vacía
		 * POST: Mueve el cursor de la lista, al anterior jugador
		 */
		void jugarDoble(Lista<Jugador>* jugadores);
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Carta &carta);

#endif /* CARTA_H_ */
