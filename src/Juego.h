#ifndef JUEGO_H_
#define JUEGO_H_
#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Consola.h"
#include "Imagen.h"

class Juego{
	private:
		static const unsigned int COORDENADA_VALOR_MINIMO = 0;
		static const unsigned int CANT_MIN_JUGADORES = 2;
		static const unsigned int CANT_MAX_JUGADORES = 6;
		static const unsigned int MIN_DIMENSION = 1;
		static const unsigned int MAX_DIMENSION = 10;
		unsigned int CANT_FICHAS_ALINEADAS;
		unsigned int ronda;
		Tablero* tablero;
		Lista<Jugador*>* jugadores;
		Mazo* mazo;

		friend std::ostream& operator<<(std::ostream&, const Juego&);

	public:

		Juego();

		Juego(unsigned int longitud, unsigned int profundidad, unsigned int altura, int nFichas);

		~Juego();

		Tablero* obtenerTablero();

		Lista<Jugador*>* obtenerJugadores();

		void iniciar(Consola consola, Imagen imagen);

	private:

		unsigned int validarDimension(unsigned int dimension);

		bool hayCuatroEnLinea(Lista<Lista<Lista<Casillero*>*>*>* tablero,
							  Casillero* ultimoCasillero, Jugador* jugador);

		Casillero* ubicarFichaUltimaPosicionLibre(Tablero* tablero,
												  Jugador* jugador,
												  unsigned int longitud,
												  unsigned int profundidad);

		bool esFichaValida(Lista<Jugador*>* jugadores, char ficha);

		bool sonPosicionesValidas(Tablero* tablero, unsigned int longitud,
								  unsigned int profundidad);

		void ingresarJugadores(Consola consola, Lista<Jugador*>* jugadores);

		Casillero* ingresarFicha(Consola consola, Tablero* tablero,
							     Jugador* jugador);

		bool hayEmpate(Tablero* tablero);

		bool hayGanador(Lista<Jugador*>* jugadores);

		unsigned int jugarCarta(Jugador* jugador, Lista<Jugador*>* jugadores,
								Consola consola, unsigned int ronda);
};

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que es una descripción de la instancia,
 * 		 con los valores actuales de sus atributos
 */
std::ostream& operator<<(std::ostream &strm, const Juego &juego);

#endif /* JUEGO_H_ */
