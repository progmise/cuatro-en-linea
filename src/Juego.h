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
		unsigned int cantidadDeFichasAlineadas;
		unsigned int ronda;
		Tablero* tablero;
		Lista<Jugador*>* jugadores;
		Mazo* mazo;

		friend std::ostream& operator<<(std::ostream&, const Juego&);

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo juego
		 */
		Juego();

        /*
         * PRE:  No tiene
         * POST: El juego resulta inicializado con una longitud,
         * 		 profundidad, altura y nFichas dadas
         */
		Juego(unsigned int longitud, unsigned int profundidad, unsigned int altura, int nFichas);

		/*
		 * PRE:  El juego debe haber sido creado
		 * POST: Destruye el juego y todos sus elementos
		 */
		~Juego();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de cantidadDeFichasAlineadas
		 */
		int obtenerCantidadDeFichasAlineadas();

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor de cantidadDeFichasAlineadas
		 */
		void asignarCantidadDeFichasAlineadas(int cantidadDeFichasAlineadas);

		/*
		 * PRE:  No tiene
		 * POST: Devuelve puntero del tablero
		 */
		Tablero* obtenerTablero();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor de jugadores
		 */
		Lista<Jugador*>* obtenerJugadores();

		/*
		 * PRE:  Consola y juego deben estar inicializados
		 * POST: Ejecuta la lógica del juego de cuatro en línea
		 */
		void iniciar(Consola consola, Imagen imagen);

	private:

		/*
		 * PRE:  No tiene
		 * POST: Devuelve y valida un int el cual, dada una dimension,
		 * 		 verifica que su valor se encuentre entre MIN_DIMENSION y
		 * 		 MAX_DIMENSION
		 */
		unsigned int validarDimension(unsigned int dimension);

		/*
		 * PRE:  tablero debe contar con elementos. ultimoCasillero y jugador
		 * 		 deben estar inicializados
		 * POST: Evalua, dado un casillero, si a partir del mismo hay casilleros
		 * 		 vecinos con los cuales se encuentran alineados N casilleros con
		 * 		 la misma ficha del jugador
		 */
		bool hayCuatroEnLinea(Lista<Lista<Lista<Casillero*>*>*>* tablero,
							  Casillero* ultimoCasillero, Jugador* jugador);

		/*
		 * PRE:  tablero y jugador deben estar inicializados. longitud y
		 * 		 profundidad deben ser números enteros positivos
		 * POST: Devuelve un casillero, dada una longitud y profundidad,
		 * 		 en la altura mínima donde no se haya posicionado ninguna
		 * 		 otra ficha de otro jugador
		 */
		Casillero* ubicarFichaUltimaPosicionLibre(Tablero* tablero,
												  Jugador* jugador,
												  unsigned int longitud,
												  unsigned int profundidad);

		/*
		 * PRE:  jugadores debe contar con elementos y ficha debe ser un
		 * 		 carácter distinto al del CASILLERO_LIBRE
		 * POST: Valida, dada una ficha que la misma no haya sido seleccionada
		 * 		 previamente por algún jugador
		 */
		bool esFichaValida(Lista<Jugador*>* jugadores, char ficha);

		/*
		 * PRE:  El tablero debe estar inicializado, longitud y profundidad deben
		 * 		 ser números enteros positivos
		 * POST: Valida, dadas una longitud y profundidad, que alguno de los
		 * 		 casilleros que se encuentren en esa posición, este vacío
		 */
		bool sonPosicionesValidas(Tablero* tablero, unsigned int longitud,
								  unsigned int profundidad);

		/*
		 * PRE:  La consola debe estar inicializada y jugadores debe contar con
		 * 		 elementos
		 * POST: Solicita al usuario ingresar la cantidad de jugadores para el juego
		 * 		 y se encarga de solicitar los datos de cada uno
		 */
		void ingresarJugadores(Consola consola, Lista<Jugador*>* jugadores);

		/*
		 * PRE:  La consola, el tablero y el jugador deben estar inicializados
		 * POST: Devuelve un casillero, para el cual previamente se le solicitó
		 * 		 al usuario ingresar una longitud y una profundidad, para
		 * 		 obtener el primer casillero que este libre en dichas coordenadas
		 */
		Casillero* ingresarFicha(Consola consola, Tablero* tablero,
							     Jugador* jugador);

		/*
		 * PRE:  El tablero debe estar inicializado
		 * POST: Evalua si cada casillero que compone el tablero, se encuentra
		 * 		 ocupado por algún jugador
		 */
		bool hayEmpate(Tablero* tablero);

		/*
		 * PRE:  jugadores debe contar con elementos
		 * POST: Evalua si alguno de los jugadores ha ganado
		 */
		bool hayGanador(Lista<Jugador*>* jugadores);

		/*
		 * PRE:  jugadores debe contar con elementos. jugador y consola
		 * 		 deben estar inicializados. ronda debe ser un número entero
		 * 		 positivo
		 * POST: Devuelve un entero, el cual tiene el mismo valor de ronda, salvo
		 * 		 que se juegue la carta bloquearTurno. Pregunta al jugador si quiere
		 * 		 jugar alguna de sus cartas, y ejecuta la acción correspondiente a
		 * 		 dicha carta
		 */
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
