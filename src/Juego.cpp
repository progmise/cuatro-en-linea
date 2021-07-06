#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->ronda = 1;
	this->tablero = new Tablero(MAX_DIMENSION, MAX_DIMENSION, MAX_DIMENSION);
	this->jugadores = new Lista<Jugador*>();
	this->mazo = new Mazo();
}

Juego::Juego(unsigned int longitud, unsigned int profundidad, unsigned int altura) {
	this->ronda = 1;

	longitud = validarDimension(longitud);
	profundidad = validarDimension(profundidad);
	altura = validarDimension(altura);

	this->tablero = new Tablero(longitud, profundidad, altura);
	this->jugadores = new Lista<Jugador*>();
	this->mazo = new Mazo();
}

Juego::~Juego() {

	Jugador* jugador = NULL;

	delete this->tablero;

	this->jugadores->iniciarCursor();

	while (this->jugadores->avanzarCursor()) {

		jugador = this->jugadores->obtenerCursor();

		delete jugador;
	}

	delete this->jugadores;
	delete this->mazo;
}

Tablero* Juego::obtenerTablero() {

	return this->tablero;
}

Lista<Jugador*>* Juego::obtenerJugadores() {

	return this->jugadores;
}

void Juego::iniciar(Consola consola, Imagen imagen) {

	Jugador* jugador = NULL;
	Lista<Lista<Casillero*>*>* plano = NULL;
	Casillero* coordenadas = NULL;
	unsigned int jugadas = 0;
	bool existeCuatroEnLinea = false;

	consola.mostrarBienvenida();

	ingresarJugadores(consola, this->jugadores);

	this->mazo->llenarMazo();

	while (!hayGanador(this->jugadores) && !hayEmpate(this->tablero)) {

		this->jugadores->iniciarCursor();

		while (this->jugadores->avanzarCursor() && !existeCuatroEnLinea) {

			jugador = this->jugadores->obtenerCursor();

			consola.mostrarDatosRonda(jugador, this->ronda);

			if (jugador->obtenerCartas()->contarElementos() < Mazo::MAX_CARTAS_JUGADOR) {

				this->mazo->levantarCartaTope(jugador);
				consola.mostrarLevanteDeCarta(jugador);
			}

			this->ronda = jugarCarta(jugador, this->jugadores, consola, this->ronda);

			coordenadas = ingresarFicha(consola, this->tablero, jugador);

			plano = this->tablero->obtenerCasilleros()->obtener(
					coordenadas->obtenerPosicionZ() + 1
			);

			consola.mostrarPlano(
					plano,
					this->tablero->obtenerLongitud(),
					this->tablero->obtenerProfundidad()
			);

			existeCuatroEnLinea = hayCuatroEnLinea(
					this->tablero->obtenerCasilleros(),
					coordenadas,
					jugador
			);

			jugadas = jugador->obtenerJugadas() + 1;

			jugador->asignarJugadas(jugadas);
		}

		this->tablero->obtenerCasilleros()->iniciarCursor();

		for (unsigned int k = 1; k < this->tablero->obtenerAltura() + 1; k++) {

			plano = this->tablero->obtenerCasilleros()->obtener(k);

			imagen.dibujarTablero(
					plano,
					this->tablero->obtenerLongitud(),
					this->tablero->obtenerProfundidad(),
					k - 1,
					this->ronda
			);
		}

		this->ronda++;
	}

	if (hayGanador(this->jugadores)) {

		consola.mostrarGanador(this->jugadores);

	} else {

		consola.mostrarEmpate(this->jugadores);
	}

}

unsigned int Juego::validarDimension(unsigned int dimension) {

	unsigned int dimensionValida = 0;

	if (dimension < MIN_DIMENSION) {

		dimensionValida = MIN_DIMENSION;

	} else if (dimension > MAX_DIMENSION) {

		dimensionValida = MAX_DIMENSION;

	} else {

		dimensionValida = dimension;
	}

	return dimensionValida;
}

bool Juego::hayCuatroEnLinea(Lista<Lista<Lista<Casillero*>*>*>* tablero,
		  	  	  	  	  	 Casillero* ultimoCasillero, Jugador* jugador) {

	Casillero* vecino = NULL;
	bool existeCuatroEnLinea = false;
	unsigned int cantidades[3][3][3];

	for (unsigned int i = 0; i < 3; i++) {

		for (unsigned int j = 0; j < 3; j++) {

			for (unsigned int k = 0; k < 3; k++) {

				cantidades[i][j][k] = 0;
			}
		}
	}

	for (int i = -1; i < 2; i++) {

		for (int j = -1; j < 2; j++) {

			for (int k = -1; k < 2; k++) {

				vecino = ultimoCasillero->obtenerVecino(i, j, k);

				while (vecino != NULL && vecino->esElMismoJugador(ultimoCasillero)) {

					cantidades[i + 1][j + 1][k + 1]++;
					vecino = vecino->obtenerVecino(i, j, k);
				}
			}
		}
	}

	for (unsigned int i = 0; i < 3; i++) {

		for (unsigned int j = 0; j < 3; j++) {

			for (unsigned int k = 0; k < 3; k++) {

				if ((cantidades[i][j][k] + cantidades[k][j][i]) + 1 >= CANT_FICHAS_ALINEADAS) {

					existeCuatroEnLinea = true;
					jugador->asignarGanador(existeCuatroEnLinea);
				}
			}
		}
	}

	return existeCuatroEnLinea;
}

Casillero* Juego::ubicarFichaUltimaPosicionLibre(Tablero* tablero,
											     Jugador* jugador,
											     unsigned int longitud,
											     unsigned int profundidad) {

	Casillero* casillero = NULL;
	bool estaPosicionado = false;

	casillero = tablero->buscarCasillero(tablero->obtenerCasilleros(), longitud, profundidad, 0);

	while (!estaPosicionado && casillero != NULL) {

		if (!casillero->estaOcupado()) {

			estaPosicionado = true;
			casillero->obtenerFicha()->asignarTipoDeFicha(jugador->obtenerFicha()->obtenerTipoDeFicha());
			casillero->obtenerFicha()->asignarColor(jugador->obtenerFicha()->obtenerColor());
			casillero->asignarOcupado(estaPosicionado);

		} else {

			casillero = casillero->obtenerVecino(0, 0, 1);
		}
	}

	return casillero;
}

bool Juego::esFichaValida(Lista<Jugador*>* jugadores, char ficha) {

	unsigned int tamanio = jugadores->contarElementos();
	bool flagEsValido = false;
	bool hayFichaRepetida = false;
	Jugador* jugador;

	if (ficha != Casillero::CASILLERO_LIBRE) {

		for (unsigned int i = 1; i < tamanio + 1; i++) {

			jugador = jugadores->obtener(i);

			if (ficha == jugador->obtenerFicha()->obtenerTipoDeFicha()) {

				hayFichaRepetida = true;
			}
		}


		if (!hayFichaRepetida) {

			flagEsValido = true;

		} else {

			cout << "\n¡Se ingresó una ficha que ya tiene un jugador!\n"
				 << endl;
		}

	} else {

		cout << "\n¡No se puede ingresar '*' como ficha!"
			 << "\n" << endl;
	}

	return flagEsValido;
}

bool Juego::sonPosicionesValidas(Tablero* tablero, unsigned int longitud,
								 unsigned int profundidad) {

	Casillero* casillero = NULL;
	bool hayEspacioLibre = false;

	casillero = tablero->buscarCasillero(tablero->obtenerCasilleros(), longitud, profundidad, 0);

	while (!hayEspacioLibre && casillero != NULL) {

		if (!casillero->estaOcupado()) {

			hayEspacioLibre = true;

		} else {

			casillero = casillero->obtenerVecino(0, 0, 1);
		}
	}

	return hayEspacioLibre;
}

void Juego::ingresarJugadores(Consola consola, Lista<Jugador*>* jugadores) {

	Jugador* jugador = NULL;
	Color* color = NULL;
	string nombre = "";
	Ficha* ficha = NULL;
	char tipoDeFicha = '\0';
	unsigned int cantJugadores = CANT_MIN_JUGADORES;

	cantJugadores = consola.ingresarCantidadJugadores(CANT_MIN_JUGADORES, CANT_MAX_JUGADORES);

	for (unsigned int i = 0; i < cantJugadores; i++) {

		cout << endl << "######## JUGADOR " << i + 1
			 << " ########" << std::endl;

		nombre = consola.ingresarNombre();

		do {

			tipoDeFicha = consola.ingresarFicha();

		} while (!esFichaValida(jugadores, tipoDeFicha));

		color = new Color();
		color->asignarPixel((i + 1) * 2);

		ficha = new Ficha(color, tipoDeFicha);

		jugador = new Jugador(nombre, ficha);

		this->jugadores->agregar(jugador);
	}
}

Casillero* Juego::ingresarFicha(Consola consola, Tablero* tablero,
							    Jugador* jugador) {

	Casillero* coordenadas = NULL;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	bool hayEspacioLibre = false;

	do {

		posicionX = consola.ingresarPosicion(
			"longitud",
			COORDENADA_VALOR_MINIMO + 1,
			tablero->obtenerLongitud()
		);

		posicionY = consola.ingresarPosicion(
			"profundidad",
			COORDENADA_VALOR_MINIMO + 1,
			tablero->obtenerProfundidad()
		);

		hayEspacioLibre = sonPosicionesValidas(tablero, posicionX, posicionY);

		if (!hayEspacioLibre) {

			cout << "\n¡No hay lugar en la longitud " << posicionX + 1
				 << " y en la profundidad " << posicionY + 1
				 << " que elegiste!\n" << std::endl;
		}

	} while (!hayEspacioLibre);

	coordenadas = ubicarFichaUltimaPosicionLibre(tablero, jugador, posicionX, posicionY);

	jugador->obtenerCasilleros()->agregar(coordenadas);

	return coordenadas;
}

bool Juego::hayEmpate(Tablero* tablero) {

	Casillero* casillero = NULL;
	bool esEmpate = true;
	unsigned int i = 1;

	while (i < (tablero->obtenerLongitud() + 1) && esEmpate) {

		unsigned int j = 1;

		while (j < (tablero->obtenerProfundidad() + 1) && esEmpate) {

			unsigned int k = 1;

			while (k < (tablero->obtenerProfundidad() + 1) && esEmpate) {

				casillero = tablero->buscarCasillero(tablero->obtenerCasilleros(), i, j, k);

				if (casillero->obtenerFicha()->obtenerTipoDeFicha() == Casillero::CASILLERO_LIBRE) {

					esEmpate = false;
				}

				k++;
			}

			j++;
		}

		i++;
	}

	return esEmpate;
}

bool Juego::hayGanador(Lista<Jugador*>* jugadores) {

	bool existeGanador = false;
	unsigned int contador = 1;
	unsigned int tamanio = jugadores->contarElementos();
	Jugador* jugador = NULL;

	while (!existeGanador && contador < tamanio + 1) {

		jugador = jugadores->obtener(contador);

		if (jugador->esGanador()) {

			existeGanador = true;
		}

		contador++;
	}

	return existeGanador;
}

unsigned int Juego::jugarCarta(Jugador* jugador, Lista<Jugador*>* jugadores,
							   Consola consola, unsigned int ronda) {

	Jugador* jugadorFatality = NULL;
	Casillero* casillero = NULL;
	unsigned int opcion = 0;
	unsigned int idCarta = 0;
	unsigned int tamanio = jugadores->contarElementos();

	opcion = consola.ingresarCarta(jugador->obtenerCartas());

	if (opcion != 0) {
		idCarta = jugador->obtenerCartas()->obtener(opcion)->obtenerId();

		if (idCarta == 1) {

			if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {
				ronda++;
			}
		}
		else if (idCarta == 3) {
			jugadorFatality = consola.preguntarJugadorParaFatality(jugadores);
		}

		else if(idCarta == 4){
			casillero = consola.preguntarCasilleroParaUsurpar(jugadores);
		}

		jugador->jugarCarta(jugadores, opcion, jugadorFatality, casillero);
	}

	return ronda;
}

ostream& operator<<(ostream &strm, const Juego &juego) {

	return strm << "Juego(ronda=" << juego.ronda
				<< ", jugadores=" << juego.jugadores->contarElementos()
				<< ")";
}
