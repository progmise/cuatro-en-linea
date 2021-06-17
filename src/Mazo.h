#ifndef MAZO_H_
#define MAZO_H_
#include "Cola.h"
#include "Carta.h"
#include "Jugador.h"

class Mazo {

	public:

		static const int MAX_CARTAS_JUGADOR = 3;

	private:

		static const int MAX_CARTAS_MAZO = 20;
		static const int CANT_TIPOS_CARTAS = 3;
		Cola<Carta*>* cartas;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Mazo&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo mazo
		 */
		Mazo();

        /*
		 * PRE:  El mazo debe haber sido creado
		 * POST: Destruye el mazo y todos sus elementos
		 */
		~Mazo();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de cartas
		 */
		Cola<Carta*>* obtenerCartas();

		/*
		 * PRE:  No tiene
		 * POST: Llena la cola de cartas, con un total de
		 *		 MAX_CARTAS
		 */
		void llenarMazo();

		/*
		 * PRE:  No tiene
		 * POST: Desencola una carta, y de no superar el límite de
		 * 		 cartas por jugador, dicha carta se suma a la lista de
		 * 		 cartas del jugador e inmediatamente, se encola una
		 * 		 nueva carta
		 */
		void levantarCartaTope(Jugador* jugador);

	private:

		/*
		 * PRE:  No tiene
		 * POST: Devuelve una instancia de alguno de los distintos
		 * 		 tipos de cartas
		 */
		Carta* generarAzarmenteCarta();
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Mazo &mazo);

#endif /* MAZO_H_ */
