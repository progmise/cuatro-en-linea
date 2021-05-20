#ifndef CASILLERO_H_
#define CASILLERO_H_
#include <iostream>

class Casillero {

	private:

		static const char CASILLERO_LIBRE = '*';
		char tipoFicha;
		unsigned int posicionX;
		unsigned int posicionY;
		unsigned int posicionZ;

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
		 * PRE:  No tiene
		 * POST: Devuelve el valor de tipoFicha
		 */
		char obtenerTipoFicha();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de tipoFicha
		 */
		void asignarTipoFicha(char tipoFicha);

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
		 * PRE:  No tiene
		 * POST: Evalua si el casillero, está ocupado por un jugador
		 */
		bool estaOcupado();
};

std::ostream& operator<<(std::ostream &strm, const Casillero &casillero);

#endif /* CASILLERO_H_ */
