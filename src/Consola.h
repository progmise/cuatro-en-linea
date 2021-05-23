#ifndef CONSOLA_H_
#define CONSOLA_H_
#include "Util.h"
#include "Jugador.h"
#include <sstream>

class Consola {

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una nueva consola
		 */
		Consola();

		/*
		 * PRE:  No tiene
		 * POST: Imprime por consola, un mensaje de bienvenida
		 */
		void mostrarBienvenida();

		/*
		 * PRE:  No tiene
		 * POST: Imprime por consola el número de la ronda y el
		 * 		 nombre del jugador
		 */
		void mostrarDatosRonda(Jugador* jugador, unsigned int ronda);

		/*
		 * PRE:  La lista de jugadores, no debe estar vacía
		 * POST: Imprime por consola, un mensaje con el nombre del jugador
		 * 		 que ganó el juego
		 */
		void mostrarGanador(Lista<Jugador*>* jugadores);

		/*
		 * PRE:  La lista de jugadores, no debe estar vacía
		 * POST: Imprime por consola, un mensaje informando todos los nombres
		 * 		 de los jugadores que empataron
		 */
		void mostrarEmpate(Lista<Jugador*>* jugadores);

		/*
		 * PRE:  minValor y maxValor, deben ser números mayores o iguales a 0,
		 * 		 y minValor puede ser menor o igual a maxValor
		 * POST: Solicita al usuario ingresar un número, el cual se validará
		 * 		 para que se ingrese int, y valores entre minValor y maxValor.
		 * 		 Se muestra un mensaje distinto, de acuerdo a la dimensión que
		 * 		 uno quiera una posición
		 */
		unsigned ingresarPosicion(std::string dimension, unsigned int minValor, unsigned int maxValor);

		/*
		 * PRE:  No tiene
		 * POST: Solicita al usuario ingresar su nombre, el cual se validará
		 * 		 para que se ingresen sólo valores alfanuméricos
		 */
		std::string ingresarNombre();

		/*
		 * PRE:  No tiene
		 * POST: Solicita al usuario ingresar un carácter, el cual se validará
		 * 		 para que no se ingrese un espacio en blanco y un sólo carácter
		 */
		char ingresarFicha();

		/*
		 * PRE:  minCantJug y maxCantJug, deben ser números mayores o iguales a 2,
		 * 		 y minValor puede ser menor o igual a maxValor
		 * POST: Solicita al usuario ingresar, la cantidad de jugadores que
		 * 		 participarán en el juego, el cual se validará para que se
		 * 		 ingrese int, y valores entre minValor y maxValor
		 */
		unsigned int ingresarCantidadJugadores(unsigned int minCantJug,
											   unsigned int maxCantJug);

		/*
		 * PRE:  Cartas no debe ser una lista vacía
		 * POST: Devuelve la opción ingresada por el usuario, que puede ser el
		 * 		 índice de alguna carta o la opción salir
		 */
		unsigned int ingresarCarta(Lista<Carta*>* cartas);

	private:

		/*
		 * PRE:  No tiene
		 * POST: Devuelve y valida un string el cual, dada una entrada,
		 * 		 verifica que el mismo contenga sólo valores alfanuméricos
		 */
		std::string validarNombre(std::string entrada);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve y valida un char el cual, dada una entrada, verifica
		 * 		 que el mismo no sea algún espacio en blanco y sea un sólo carácter
		 */
		char validarFicha(std::string entrada);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un string, que representa a una posicion
		 * 		 del tablero, solicitado al usuario
		 */
		std::string solicitarPosicion(std::string dimension);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un string, que representa a un nombre,
		 * 		 solicitado al usuario
		 */
		std::string solicitarNombre();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un char, que representa a una ficha,
		 * 		 solicitado al usuario
		 */
		std::string solicitarFicha();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un string, que representa a la cantidad
		 * 		 de jugadores, solicitado al usuario
		 */
		std::string solicitarCantidadJugadores();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un string, que representa a una opción
		 * 		 de un menú, solicitado al usuario
		 */
		std::string solicitarOpcion(Lista<std::string*>* opciones);

		/*
		 * PRE:  minValor y maxValor, deben ser números mayores o iguales a 0,
		 * 		 y minValor puede ser menor o igual a maxValor
		 * POST: Valida, dada una entrada, si se trata de un int y si se encuentra
		 * 		 entre los valores de minValor y maxValor.
		 */
		bool esNumeroValido(std::string entrada, unsigned int minValor,
						    unsigned int maxValor);

		/*
		 * PRE:  Cartas no debe ser una lista vacía
		 * POST: Devuelve una lista, con cartas como opciones
		 */
		Lista<std::string*>* generarOpcionesCartas(Lista<Carta*>* cartas);
};

#endif /* CONSOLA_H_ */
