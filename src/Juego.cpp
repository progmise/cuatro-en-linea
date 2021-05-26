#include "Juego.h"

using namespace std;

Juego::Juego() {
	this->ronda = 1;
	this->tablero = new Tablero(MAX_DIMENSION, MAX_DIMENSION, MAX_DIMENSION);
	this->jugadores = new Lista<Jugador*>;
	this->mazo = new Mazo();
}

Juego::Juego(unsigned int longitud, unsigned int profundidad, unsigned int altura) {
	this->ronda = 1;

	longitud = validarDimension(longitud);
	profundidad = validarDimension(profundidad);
	altura = validarDimension(altura);

	this->tablero = new Tablero(longitud, profundidad, altura);
	this->jugadores = new Lista<Jugador*>;
	this->mazo = new Mazo();
}

Juego::~Juego() {

	Casillero* casillero;
	Jugador* jugador;

	this->tablero->obtenerCasilleros()->iniciarCursor();

	while (this->tablero->obtenerCasilleros()->avanzarCursor()) {

		casillero = this->tablero->obtenerCasilleros()->obtenerCursor();

		delete casillero;
	}

	this->jugadores->iniciarCursor();

	while (this->jugadores->avanzarCursor()) {

		jugador = this->jugadores->obtenerCursor();

		delete jugador;
	}

	delete this->tablero;
	delete this->jugadores;
	delete this->mazo;
}

Tablero* Juego::obtenerTablero() {

	return this->tablero;
}

Lista<Jugador*>* Juego::obtenerJugadores() {

	return this->jugadores;
}

void Juego::iniciar(Consola* consola) {

	Jugador* jugador;
	Casillero* coordenadas;
	unsigned int jugadas = 0;
	bool existeCuatroEnLinea = false;

	consola->mostrarBienvenida();

	ingresarJugadores(consola, this->jugadores);

	mazo->llenarMazo();

	while (!hayGanador(this->jugadores) && !hayEmpate(this->tablero)) {

		this->jugadores->iniciarCursor();

		while (this->jugadores->avanzarCursor() && !existeCuatroEnLinea) {

			jugador = this->jugadores->obtenerCursor();

			consola->mostrarDatosRonda(jugador, this->ronda);

			if (jugador->obtenerCartas()->contarElementos() < Mazo::MAX_CARTAS_JUGADOR) {

				mazo->levantarCartaTope(jugador);
				consola->mostrarLevanteDeCarta(jugador);
			}

			//Revisar
			this->ronda = jugarCarta(jugador, this->jugadores, consola, this->ronda);

			coordenadas = ingresarFicha(consola, tablero, jugador);

			existeCuatroEnLinea = hayCuatroEnLinea(this->tablero, coordenadas, jugador);

			jugadas = jugador->obtenerJugadas() + 1;

			jugador->asignarJugadas(jugadas);
		}

		this->ronda++;
	}

	if (hayGanador(this->jugadores)) {

		consola->mostrarGanador(this->jugadores);

	} else {

		consola->mostrarEmpate(this->jugadores);
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

bool Juego::hayCuatroEnLineaEnRecta(Lista<Casillero*>* recta, char ficha) {

	Casillero* casillero;
	bool existeCuatroEnLinea = false;
	unsigned int cantFichasAlineadas = 0;

	if (recta->contarElementos() >= CANT_FICHAS_ALINEADAS) {

		recta->iniciarCursor();

		while (recta->avanzarCursor() && !existeCuatroEnLinea) {

			casillero = recta->obtenerCursor();

			if (casillero->obtenerTipoFicha() == ficha) {

				cantFichasAlineadas++;

			} else {

				cantFichasAlineadas = 0;
			}

			if (cantFichasAlineadas == 4) {

				existeCuatroEnLinea = true;
			}
		}
	}

	return existeCuatroEnLinea;
}

bool Juego::hayCuatroEnLineaEnDiagonalesDePlano(Lista<Lista<Casillero*>*>* diagonales,
												char ficha) {

	Lista<Casillero*>* diagonal;
	bool existeCuatroEnLinea = false;

	diagonales->iniciarCursor();

	while (diagonales->avanzarCursor() && !existeCuatroEnLinea) {

		diagonal = diagonales->obtenerCursor();

		if (hayCuatroEnLineaEnRecta(diagonal, ficha)) {

			existeCuatroEnLinea = true;
		}
	}

	return existeCuatroEnLinea;
}

bool Juego::hayCuatroEnLineaEnDiagonalesDePlanos(Tablero* tablero, Casillero* coordenadas,
		  	  	  	  	  	  	  	  	  	  	 char ficha) {

	Lista<Lista<Casillero*>*>* diagonales;
	unsigned int posicionX = coordenadas->obtenerPosicionX();
	unsigned int posicionY = coordenadas->obtenerPosicionY();
	unsigned int posicionZ = coordenadas->obtenerPosicionZ();
	bool existeCuatroEnLinea = false;

	diagonales = tablero->obtenerDiagonalesPlanoXY(posicionX, posicionY, posicionZ);

	if (hayCuatroEnLineaEnDiagonalesDePlano(diagonales, ficha)) {

		existeCuatroEnLinea = true;

	} else {

		tablero->transponerTablero();

		diagonales = tablero->obtenerDiagonalesPlanoXY(posicionZ, posicionX, posicionY);

		if (hayCuatroEnLineaEnDiagonalesDePlano(diagonales, ficha)) {

			existeCuatroEnLinea = true;

			tablero->transponerTablero();
			tablero->transponerTablero();

		} else {

			tablero->transponerTablero();

			diagonales = tablero->obtenerDiagonalesPlanoXY(posicionY, posicionZ, posicionX);

			if (hayCuatroEnLineaEnDiagonalesDePlano(diagonales, ficha)) {

				existeCuatroEnLinea = true;

				tablero->transponerTablero();

			} else {

				tablero->transponerTablero();
			}
		}
	}

	return existeCuatroEnLinea;
}

bool Juego::hayCuatroEnLineaEnDiagonales(Tablero* tablero, Casillero* coordenadas,
		  	  	  	  	  	  	  	  	 char ficha) {

	Lista<Lista<Casillero*>*>* diagonales;
	Lista<Casillero*>* diagonal;
	unsigned int posicionX = coordenadas->obtenerPosicionX();
	unsigned int posicionY = coordenadas->obtenerPosicionY();
	unsigned int posicionZ = coordenadas->obtenerPosicionZ();
	bool existeCuatroEnLinea = false;

	diagonales = tablero->obtenerDiagonales(posicionX, posicionY, posicionZ);

	diagonales->iniciarCursor();

	while (diagonales->avanzarCursor() && !existeCuatroEnLinea) {

		diagonal = diagonales->obtenerCursor();

		if (hayCuatroEnLineaEnRecta(diagonal, ficha)) {

			existeCuatroEnLinea = true;
		}
	}

	return existeCuatroEnLinea;
}

bool Juego::hayCuatroEnLineaEnRectas(Tablero* tablero, Casillero* coordenadas, char ficha) {

	Lista<Casillero*>* recta;
	unsigned int posicionX = coordenadas->obtenerPosicionX();
	unsigned int posicionY = coordenadas->obtenerPosicionY();
	unsigned int posicionZ = coordenadas->obtenerPosicionZ();
	bool existeCuatroEnLinea = false;

	recta = tablero->obtenerRectaEnX(posicionY, posicionZ);

	if (hayCuatroEnLineaEnRecta(recta, ficha)) {

		existeCuatroEnLinea = true;

	} else {

		tablero->transponerTablero();

		recta = tablero->obtenerRectaEnX(posicionX, posicionY);

		if (hayCuatroEnLineaEnRecta(recta, ficha)) {

			existeCuatroEnLinea = true;

			tablero->transponerTablero();
			tablero->transponerTablero();

		} else {

			tablero->transponerTablero();

			recta = tablero->obtenerRectaEnX(posicionZ, posicionX);

			if (hayCuatroEnLineaEnRecta(recta, ficha)) {

			  existeCuatroEnLinea = true;

			  tablero->transponerTablero();

			} else {

			  tablero->transponerTablero();
			}
		}
	}

	return existeCuatroEnLinea;
}

bool Juego::hayCuatroEnLinea(Tablero* tablero, Casillero* coordenadas, Jugador* jugador) {

	bool existeCuatroEnLinea = false;
	char ficha = jugador->obtenerFicha();

	existeCuatroEnLinea = hayCuatroEnLineaEnRectas(tablero, coordenadas, ficha);

	if (!existeCuatroEnLinea) {

		existeCuatroEnLinea = hayCuatroEnLineaEnDiagonales(
			tablero, coordenadas, ficha
		);
	}

	if (!existeCuatroEnLinea) {

		existeCuatroEnLinea = hayCuatroEnLineaEnDiagonalesDePlanos(
			tablero, coordenadas, ficha
		);
	}

	if (existeCuatroEnLinea) {

		jugador->asignarGanador(existeCuatroEnLinea);
	}

	return existeCuatroEnLinea;
}

Casillero* Juego::ubicarFichaUltimaPosicionLibre(Tablero* tablero,
											     Jugador* jugador,
											     unsigned int longitud,
											     unsigned int profundidad) {

	Casillero* casillero;
	Lista<Casillero*>* casilleros;
	bool estaPosicionado = false;
	char ficha = jugador->obtenerFicha();

	tablero->transponerTablero();

	casilleros = tablero->obtenerRectaEnX(longitud, profundidad);
	casilleros->iniciarCursor();

	while (casilleros->avanzarCursor() && !estaPosicionado) {

		casillero = casilleros->obtenerCursor();

		if (casillero->obtenerTipoFicha() == Casillero::CASILLERO_LIBRE) {

			casillero->asignarTipoFicha(ficha);
			estaPosicionado = true;
		}
	}

	tablero->transponerTablero();
	tablero->transponerTablero();

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

			if (ficha == jugador->obtenerFicha()) {

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

	Casillero* casillero;
	Lista<Casillero*>* casilleros;
	bool hayEspacioLibre = false;

	tablero->transponerTablero();

	casilleros = tablero->obtenerRectaEnX(longitud, profundidad);
	casilleros->iniciarCursor();

	while (casilleros->avanzarCursor() && !hayEspacioLibre) {

		casillero = casilleros->obtenerCursor();

		if (casillero->obtenerTipoFicha() == Casillero::CASILLERO_LIBRE) {

			hayEspacioLibre = true;
		}
	}

	tablero->transponerTablero();
	tablero->transponerTablero();

	return hayEspacioLibre;
}

void Juego::ingresarJugadores(Consola* consola, Lista<Jugador*>* jugadores) {

	Jugador* jugador;
	string nombre = "";
	char ficha = '\0';
	unsigned int cantJugadores = CANT_MIN_JUGADORES;

	cantJugadores = consola->ingresarCantidadJugadores(CANT_MIN_JUGADORES, CANT_MAX_JUGADORES);

	for (unsigned int i = 0; i < cantJugadores; i++) {

		cout << endl << "######## JUGADOR " << i + 1
			 << " ########" << std::endl;

		nombre = consola->ingresarNombre();

		do {

			ficha = consola->ingresarFicha();

		} while (!esFichaValida(jugadores, ficha));

		jugador = new Jugador(nombre, ficha);

		this->jugadores->agregar(jugador);
	}
}

Casillero* Juego::ingresarFicha(Consola* consola, Tablero* tablero,
							    Jugador* jugador) {

	Casillero* coordenadas;
	unsigned int posicionX = 0;
	unsigned int posicionY = 0;
	bool hayEspacioLibre = false;

	do {

		posicionX = consola->ingresarPosicion(
			"longitud",
			COORDENADA_VALOR_MINIMO + 1,
			tablero->obtenerLongitud()
		);

		posicionY = consola->ingresarPosicion(
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

	return coordenadas;
}

bool Juego::hayEmpate(Tablero* tablero) {

	Casillero* casillero;
	Lista<Casillero*>* casilleros;
	bool esEmpate = true;

	//casilleros = tablero->obtenerCasilleros();
	casilleros->iniciarCursor();

	while(casilleros->avanzarCursor() && esEmpate) {

		casillero = casilleros->obtenerCursor();

		if (casillero->obtenerTipoFicha() == Casillero::CASILLERO_LIBRE) {

			esEmpate = false;
		}
	}

	return esEmpate;
}

bool Juego::hayGanador(Lista<Jugador*>* jugadores) {

	bool existeGanador = false;
	unsigned int contador = 1;
	unsigned int tamanio = jugadores->contarElementos();
	Jugador* jugador;

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
							   Consola* consola, unsigned int ronda) {

	unsigned int opcion = 0;
	unsigned int tamanio = 0;

	opcion = consola->ingresarCarta(jugador->obtenerCartas());

	if (opcion != 0) {

		Carta* carta;

		carta = jugador->obtenerCartas()->obtener(opcion);

		tamanio = jugadores->contarElementos();

		switch (carta->obtenerId()) {
			case 1:

				if (jugadores->obtener(tamanio) == jugadores->obtenerCursor()) {

					ronda++;
				}

				carta->bloquearTurno(jugadores);
				jugador->obtenerCartas()->remover(opcion);

				break;

			case 2:

				carta->jugarDoble(jugadores);
				jugador->obtenerCartas()->remover(opcion);

				break;

			default:

				cout << "Opción de carta no válida";
				break;
		}
	}

	return ronda;
}

ostream& operator<<(ostream &strm, const Juego &juego) {

	return strm << "Juego(ronda=" << juego.ronda
				<< ", jugadores=" << juego.jugadores->contarElementos()
				<< ")";
}
