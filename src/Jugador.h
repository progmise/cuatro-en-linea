#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Lista.h"
#include "Color.h"
#include "Carta.h"
#include "Ficha.h"
#include <iostream>

class Carta;

class Jugador {

	private:

		std::string nombre;
		unsigned int jugadas;
		Ficha* ficha;
		bool flagGanador;
		Lista<Carta*>* cartas;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Jugador&);

		/*
		 * A fin de poder sobrescribir el operador '==', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend bool operator==(const Jugador &lhs, const Jugador &rhs);

		/*
		 * A fin de poder sobrescribir el operador '!=', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend bool operator!=(const Jugador &lhs, const Jugador &rhs);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo jugador
		 */
		Jugador();

        /*
         * PRE:  No tiene
         * POST: El jugador resulta inicializado con un nombre y una
         * 		 ficha dadas
         */
		Jugador(std::string nombre, Ficha* ficha);

		/*
		 * PRE:  El jugador debe haber sido creado
		 * POST: Destruye el jugador y todos sus elementos
		 */
		~Jugador();

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
		 * POST: Devuelve el valor de jugadas
		 */
		unsigned int obtenerJugadas();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de jugadas
		 */
		void asignarJugadas(unsigned int jugadas);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el puntero de ficha
		 */
		Ficha* obtenerFicha();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de ficha
		 */
		void asignarFicha(Ficha* ficha);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de flagGanador
		 */
		bool esGanador();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de flagGanador
		 */
		void asignarGanador(bool flagGanador);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de cartas
		 */
		Lista<Carta*>* obtenerCartas();

		/*
		 * PRE:  La lista de jugadores, no debe estar vacía e
		 * 		 indiceCarta, debe corresponderse a una posición
		 * 		 existente, dentro de lista cartas
		 * POST: Ejecuta la acción correspondiente a una carta,
		 * 		 sobre la lista de jugadores. Finalizada la ejecución,
		 * 		 se elimina la carta jugada
		 */
		void jugarCarta(Lista<Jugador*>* jugadores, unsigned int indiceCarta, Jugador* jugador);
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Jugador &jugador);

/*
 * PRE:  No tiene
 * POST: Valida si se trata de la misma instancia, a partir de la
 * 		 dirección de memoria
 */
bool operator==(const Jugador &lhs, const Jugador &rhs);
/*
 * PRE:  No tiene
 * POST: Valida si no se trata de la misma instancia, a partir de la
 * 		 dirección de memoria
 */
bool operator!=(const Jugador &lhs, const Jugador &rhs);

#endif /* JUGADOR_H_ */
