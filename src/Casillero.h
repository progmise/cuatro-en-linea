#ifndef CASILLERO_H_
#define CASILLERO_H_
#include "Ficha.h"
#include <iostream>

class Casillero {

	public:

		static const char CASILLERO_LIBRE = '*';
		static const unsigned int CANT_VECINOS = 3;

	private:

		Ficha* ficha;
		bool ocupado;
		Casillero* vecinos[CANT_VECINOS][CANT_VECINOS][CANT_VECINOS];
		unsigned int posicionX;
		unsigned int posicionY;
		unsigned int posicionZ;

		/*
		 * A fin de poder sobrescribir el operador '<<', se debe declarar
		 * la función 'friend', de modo que pueda acceder a los atributos
		 * privados o protegidos, de la clase
		 */
		friend std::ostream& operator<<(std::ostream&, const Casillero&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo casillero
		 */
		Casillero();

        /*
         * PRE:  No tiene
         * POST: El casillero resulta inicializado con una posicionX,
         * 		 posicionY y posicionZ dadas
         */
		Casillero(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ);

		/*
		 * PRE:  El casillero debe haber sido creado
		 * POST: Destruye el casillero y todos sus elementos
		 */
		~Casillero();

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
		 * POST: Devuelve el valor de ocupado
		 */
		bool estaOcupado();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de ocupado
		 */
		void asignarOcupado(bool ocupado);

		/*
		 * PRE:  posicionX, posicionY, posicionZ deben tomar valores entre
		 * 		 -1 y 1
		 * POST: Devuelve el casillero vecino, de dichas coordenadas
		 */
		Casillero* obtenerVecino(int posicionX, int posicionY, int posicionZ);

		/*
		 * PRE:  posicionX, posicionY, posicionZ deben tomar valores entre
		 * 		 -1 y 1
		 * POST: Asigna un casillero a vecinos
		 */
		void asignarVecino(Casillero* casillero, int posicionX, int posicionY, int posicionZ);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de posicionX
		 */
		unsigned int obtenerPosicionX();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de posicionX
		 */
		void asignarPosicionX(unsigned int posicionX);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de posicionY
		 */
		unsigned int obtenerPosicionY();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de posicionY
		 */
		void asignarPosicionY(unsigned int posicionY);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de posicionZ
		 */
		unsigned int obtenerPosicionZ();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de posicionZ
		 */
		void asignarPosicionZ(unsigned int posicionZ);

		/*
		 * PRE:  El casillero debe estar inicializado
		 * POST: Evalua si ambos casilleros, tienen el mismo tipo
		 * 		 de ficha, de un jugador
		 */
		bool esElMismoJugador(Casillero* casillero);
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Casillero &casillero);

#endif /* CASILLERO_H_ */
