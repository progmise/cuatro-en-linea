#include "Consola.h"
#include <stdio.h>
using namespace std;

Consola::Consola() { }

void Consola::mostrarBienvenida() {

	cout << "Algoritmos y Programacion II - T.P. Nro. 2 - Cuatro en línea" << endl;
	cout << "##### Bienvenidos #####" << endl << endl;
	cout << "El objetivo del juego, es el de alinear 4 fichas consecutivas "
		 << "del mismo tipo" << endl;
	cout << "¡Exitos!" << endl << endl;
}

void Consola::mostrarLevanteDeCarta(Jugador* jugador) {

	cout << endl << "¡" << jugador->obtenerNombre()
		 << " ha levantado una carta!" << endl;
}

void Consola::mostrarDatosRonda(Jugador* jugador, unsigned int ronda) {

	cout << endl;
	cout << "######## RONDA " << ronda << " ########" << endl << endl;
	cout << "Turno del jugador " << jugador->obtenerNombre() << endl;
	cout << "Ha hecho " << jugador->obtenerJugadas() << " jugadas" << endl;
	cout << "Tiene un total de " << jugador->obtenerCartas()->contarElementos()
		 << " cartas" << endl;
}

void Consola::mostrarGanador(Lista<Jugador*>* jugadores) {

	Jugador* jugador = NULL;
	bool hayGanador = false;

	jugadores->iniciarCursor();

	while (!hayGanador) {

		jugadores->avanzarCursor();
		jugador = jugadores->obtenerCursor();

		if (jugador->esGanador()) {

			hayGanador = true;
		}
	}

	cout << endl;
	cout << "########## ¡JUEGO TERMINADO! ##########" << endl << endl;
	cout << "El ganador es el jugador " << jugador->obtenerNombre() << endl;
	cout << "Ha hecho " << jugador->obtenerJugadas() << " jugadas" << endl;
}

void Consola::mostrarEmpate(Lista<Jugador*>* jugadores) {

	string mensaje = "";
	stringstream strStream;
	Jugador* jugador = NULL;
	unsigned int tamanio = jugadores->contarElementos();

	strStream << "\n------> ¡Ninguno ha ganado ";

	for (unsigned int i = 1; i < tamanio + 1; i++) {

		jugador = jugadores->obtener(1);

		if (i < tamanio - 1) {

			strStream << jugador->obtenerNombre() << ", ";

		} else if (i == tamanio - 1) {

			strStream << jugador->obtenerNombre() << " y ";

		} else {

			strStream << jugador->obtenerNombre();
		}
	}

	strStream << " han empatado! <------\n" << endl;

	mensaje = strStream.str();
	strStream.clear();

	cout << mensaje;
}

void Consola::mostrarPlano(Lista<Lista<Casillero*>*>* plano, unsigned int longitud,
						   unsigned int profundidad) {

	std::string planoFormateado = "";

	planoFormateado = crearPlano(plano, longitud, profundidad);

	std::cout << std::endl << planoFormateado;
}

unsigned int Consola::ingresarPosicion(string dimension, unsigned int minValor,
									   unsigned int maxValor) {

	stringstream strStream;
	string entrada = "";
	unsigned int posicion = 0;
	bool flagEsValido = false;

	do {

		entrada = solicitarPosicion(dimension);

		if(esNumeroValido(entrada, minValor, maxValor)) {

			flagEsValido = true;
		}

	} while (!flagEsValido);

	strStream << entrada;
	strStream >> posicion;
	strStream.clear();

	return posicion - 1;
}

string Consola::ingresarNombre() {

	string entrada = "";
	string nombre = "";

	entrada = solicitarNombre();
	nombre = validarNombre(entrada);

	return nombre;
}

char Consola::ingresarFicha() {

	string entrada = "";
	char ficha = '\0';

	entrada = solicitarFicha();
	ficha = validarFicha(entrada);

	return ficha;
}

unsigned int Consola::ingresarCantidadJugadores(unsigned int minCantJug,
									   	   	    unsigned int maxCantJug) {

	stringstream strStream;
	string entrada = "";
	unsigned int cantJugadores = 0;
	bool flagEsValido = false;

	do {

		entrada = solicitarCantidadJugadores();

		if(esNumeroValido(entrada, minCantJug, maxCantJug)) {

			flagEsValido = true;
		}

	} while (!flagEsValido);

	strStream << entrada;
	strStream >> cantJugadores;
	strStream.clear();

	return cantJugadores;
}

unsigned int Consola::ingresarCarta(Lista<Carta*>* cartas) {

	Lista<string>* nombresDeCartas = new Lista<string>();
	Carta* carta = NULL;
	unsigned int opcion = 0;

	cartas->iniciarCursor();

	while (cartas->avanzarCursor()) {

		carta = cartas->obtenerCursor();
		nombresDeCartas->agregar(carta->obtenerNombre());
	}

	opcion = validarOpcion(nombresDeCartas, 0, cartas->contarElementos());

	delete nombresDeCartas;

	return opcion;
}

unsigned int Consola::navegarPorNiveles(Tablero* tablero) {

	Lista<Lista<Casillero*>*>* plano = NULL;
	Lista<string>* items = new Lista<string>();
	unsigned int opcion = 0;
	unsigned int nivel = 1;

	items->agregar("Siguiente nivel");
	items->agregar("Anterior nivel");

	do {
		cout << "Nivel " << setfill('0') << setw(3) << nivel - 1 << endl;

		plano = tablero->obtenerCasilleros()->obtener(nivel);
		mostrarPlano(plano, tablero->obtenerLongitud(), tablero->obtenerProfundidad());

		opcion = validarOpcion(items, 0, items->contarElementos());

		if (opcion == 1) {

			nivel++;

			if (nivel == tablero->obtenerAltura() + 1) {

				nivel = 1;
			}
		}
		else if (opcion == 2) {

			if (nivel == 1) {

				nivel = tablero->obtenerAltura();

			} else {

				nivel--;
			}
		}

	} while(opcion != 0);

	delete items;

	return nivel;
}

Jugador* Consola::preguntarJugadorParaFatality(Lista<Jugador*>* jugadores) {
	Jugador* jugadorActual = jugadores->obtenerCursor();
	cout << "Por favor, ingrese el nombre de uno de los jugadores" << endl;
	for(unsigned int i = 1; i <= jugadores->contarElementos(); i++){
		Jugador* jugadorCiclo = jugadores->obtener(i);
		if(jugadorCiclo->obtenerCartas()->contarElementos() != 0 &&
				jugadorCiclo->obtenerNombre() != jugadorActual->obtenerNombre()) {
			cout << jugadorCiclo->obtenerNombre() << endl;
		}
	}
	string nombreElegido;
	cin >> nombreElegido;
	bool esValido = false;
	Jugador* jugadorDevolver;
	while (!esValido) {
		unsigned int j = 1;
		while (!esValido && j <= jugadores->contarElementos()){
			Jugador* jugador = jugadores->obtener(j);
			if(nombreElegido == jugador->obtenerNombre() && jugador->obtenerCartas()->contarElementos() != 0 && nombreElegido != jugadorActual->obtenerNombre()) {
				esValido = true;
				jugadorDevolver = jugador;
			}
			j++; //No se incrementaba nunca j
		}
		if (!esValido) {
			cout << "El nombre ingresado no forma parte de la lista de nombres posibles, intentalo de nuevo" << endl;
			cin >> nombreElegido;
		}
	}

	return jugadorDevolver;
}

string Consola::crearEncabezado(unsigned int longitud) {

	string encabezado = "";
	stringstream strStream;

	strStream << ' ';

	for (unsigned int i = 1; i < longitud + 1; i++) {

		strStream << setfill('0') << setw(3) << i << ' ';
	}

	encabezado = strStream.str();
	strStream.clear();

	return encabezado;
}

string Consola::crearFila(Lista<Casillero*>* fila, unsigned int longitud) {

	Ficha* ficha = NULL;
	string filaFormateada = "";
	stringstream strStream;

	for (unsigned int i = 1; i < longitud + 1; i++) {

		ficha = fila->obtener(i)->obtenerFicha();

		strStream << '|' << ' ' << ficha->obtenerTipoDeFicha() << ' ';
	}

	strStream << '|';

	filaFormateada = strStream.str();
	strStream.clear();

	return filaFormateada;
}

string Consola::crearPlano(Lista<Lista<Casillero*>*>* plano, unsigned int longitud,
		  	  	  	  	   unsigned int profundidad) {

	string planoFormateado = "";
	string fila = "";
	string encabezado = "";
	stringstream strStream;

	encabezado = crearEncabezado(longitud);

	strStream << string(4, ' ') << encabezado << endl;
	strStream << string(4, ' ') << string(encabezado.length(), '-') << endl;

	for (unsigned int j = 1; j < profundidad + 1; j++) {

		fila = crearFila(plano->obtener(j), longitud);

		strStream << setfill('0') << setw(3) << j << ' ' << fila << endl;
	}

	strStream << string(4, ' ') << string(encabezado.length(), '-') << endl;

	planoFormateado = strStream.str();
	strStream.clear();

	return planoFormateado;
}

unsigned int Consola::validarOpcion(Lista<string>* items, unsigned int minimaOpcion,
									unsigned int maximaOpcion) {

	stringstream strStream;
	string entrada = "";
	Lista<string>* opciones = NULL;
	unsigned int opcion = 0;
	bool flagEsValido = false;

	opciones = generarOpciones(items);

	do {

		entrada = solicitarOpcion(opciones);

		if(esNumeroValido(entrada, minimaOpcion, maximaOpcion)) {

			flagEsValido = true;
		}

	} while (!flagEsValido);

	strStream << entrada;
	strStream >> opcion;
	strStream.clear();

	delete opciones;

	return opcion;
}

string Consola::validarNombre(string entrada) {

	string nombre = "";
	bool flagEsValido = false;

	while (!flagEsValido) {

		if (!Util::esNumero(entrada)) {

			nombre = entrada;

			if (Util::esAlfanumerico(nombre)) {

				flagEsValido = true;

			} else {

				cout << "\n¡Revisa de no haber ingresado espacios o caracteres especiales!"
					 << "\n" << endl;

				entrada = solicitarNombre();
			}

		} else {

			cout << "\n¡No puedes ingresar numeros como nombre!"
				 << "\n" << endl;

			entrada = solicitarNombre();
		}
	}

	return nombre;
}

char Consola::validarFicha(std::string entrada) {

	string ficha = "";
	bool flagEsValido = false;

	while (!flagEsValido) {

		if (entrada.size() == 1) {

			ficha = entrada;

			if (!Util::esEspacio(ficha)) {

				flagEsValido = true;

			} else {

				cout << "\n¡Revisa de no haber ingresado algún tipo de espacio como ficha!"
					 << "\n" << endl;
				entrada = solicitarFicha();
			}

		} else {

			cout << "\n¡No puedes ingresar más de un carácter como ficha!"
				 << "\n" << endl;

			entrada = solicitarFicha();
		}
	}

	return ficha[0];
}

string Consola::solicitarPosicion(string dimension) {

	string entrada = "";

	cout << endl << "¿En qué "<< dimension <<" desea introducir la ficha?: ";
	cin >> entrada;

	return entrada;
}

string Consola::solicitarNombre() {

	string entrada = "";

	cout << "Ingrese su nombre: ";
	cin >> entrada;

	return entrada;
}

string Consola::solicitarFicha() {

	string entrada = "";

	cout << "Ingrese la ficha que usará: ";
	cin >> entrada;

	return entrada;
}

string Consola::solicitarCantidadJugadores() {

	string entrada = "";

	cout << "Ingrese la cantidad de jugadores: ";
	cin >> entrada;

	return entrada;
}

string Consola::solicitarOpcion(Lista<string>* opciones) {

	string entrada = "";

	cout << endl << "######## " << "CARTAS" << " ########" << endl;

	opciones->iniciarCursor();

	while (opciones->avanzarCursor()) {

		cout << opciones->obtenerCursor();
	}

	cout << endl << "Ingrese una opción: ";
	cin >> entrada;

	return entrada;
}

bool Consola::esNumeroValido(std::string entrada, unsigned int minValor,
					unsigned int maxValor) {

	unsigned int numero = 0;
	bool flagEsValido = false;
	stringstream strStream;

	if (Util::esNumero(entrada)) {

		strStream << entrada;
		strStream >> numero;
		strStream.clear();

		if (Util::validarNumeroAcotado(numero, minValor, maxValor)) {

			flagEsValido = true;

		} else {

			cout << "\n¡Sólo se pueden ingresar numeros entre el "
				 << minValor << " y el " << maxValor
				 << "!\n" << endl;
		}

	} else {

		cout << "\n¡Sólo se pueden ingresar numeros enteros positivos!"
			 << "\n" << endl;
	}

	return flagEsValido;
}

Lista<string>* Consola::generarOpciones(Lista<string>* items) {

	Lista<string>* opciones = new Lista<string>();
	stringstream strStream;
	string opcion;
	unsigned int tamanio = items->contarElementos();

	for (unsigned int i = 1; i < tamanio + 1; i++) {

		strStream << i << " - " << items->obtener(i) << endl;

		opcion = string(strStream.str());

		strStream.str(string());
		strStream.clear();

		opciones->agregar(opcion);
	}

	strStream << endl << "0" << " - " << "Salir" << endl;

	opcion = string(strStream.str());

	strStream.str(string());
	strStream.clear();

	opciones->agregar(opcion);

	return opciones;
}

Jugador* Consola::preguntarJugadorParaFatality(Lista<Jugador*>* jugadores) {
	Jugador* jugadorActual = jugadores->obtenerCursor();
	cout << "Por favor, ingrese el nombre de uno de los jugadores" << endl;
	for(int i = 1; i <= jugadores->contarElementos(); i++){
		Jugador* jugadorCiclo = jugadores->obtener(i);
		if(jugadorCiclo->obtenerCartas()->contarElementos() != 0 &&
				jugadorCiclo->obtenerNombre() != jugadorActual->obtenerNombre()) {
			cout << jugadorCiclo->obtenerNombre() << endl;
		}
	}
	string nombreElegido;
	cin >> nombreElegido;
	bool esValido = false;
	Jugador* jugadorDevolver;
	while (!esValido) {
		unsigned int j = 1;
		while (!esValido && j <= jugadores->contarElementos()){
			Jugador* jugador = jugadores->obtener(j);
			if(nombreElegido == jugador->obtenerNombre() && jugador->obtenerCartas()->contarElementos() != 0 && nombreElegido != jugadorActual->obtenerNombre()) {
				esValido = true;
				jugadorDevolver = jugador;
			}
			j++; //No se incrementaba nunca j
		}
		if (!esValido) {
			cout << "El nombre ingresado no forma parte de la lista de nombres posibles, intentalo de nuevo" << endl;
			cin >> nombreElegido;
		}
	}

	return jugadorDevolver;
}
