#include "Consola.h"

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

	stringstream strStream;
	string entrada = "";
	Lista<string>* opciones = generarOpcionesCartas(cartas);
	unsigned int opcion = 0;
	bool flagEsValido = false;

	do {

		entrada = solicitarOpcion(opciones);

		if(esNumeroValido(entrada, 0, cartas->contarElementos())) {

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

Lista<string>* Consola::generarOpcionesCartas(Lista<Carta*>* cartas) {

	Lista<string>* opciones = new Lista<string>();
	stringstream strStream;
	string opcion;
	unsigned int tamanio = cartas->contarElementos();

	for (unsigned int i = 1; i < tamanio + 1; i++) {

		strStream << i << " - " << cartas->obtener(i)->obtenerNombre() << endl;

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
