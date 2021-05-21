#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <iostream>

class Jugador {

	private:

		std::string nombre;
		unsigned int jugadas;
		char ficha;
		bool flagGanador;
		//Lista<Carta>* cartas;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Jugador&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo jugador
		 */
		Jugador();

        /*
         * PRE:  No tiene
         * POST: El jugador resulta inicializado con un nombre
         * 		 y ficha dadas
         */
		Jugador(std::string nombre, char ficha);

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
		 * POST: Devuelve el valor de ficha
		 */
		char obtenerFicha();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de ficha
		 */
		void asignarFicha(char ficha);

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
		//Lista<Carta>* obtenerCartas();
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Jugador &jugador);

#endif /* JUGADOR_H_ */
