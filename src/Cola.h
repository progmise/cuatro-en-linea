#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"
#include <string>

template<class T>

class Cola {

	private:

        Nodo<T>* frente;
        Nodo<T>* fondo;

    public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una nueva cola
		 */
        Cola();

        /*
		 * PRE:  La cola debe haber sido creada
		 * POST: Destruye la cola y todos sus elementos
		 */
        ~Cola();

        /*
         * PRE:  No tiene
         * POST: Devuelve si la cola no tiene ningún elemento
         */
        bool estaVacia();

        /*
         * PRE:  No tiene
         * POST: Agrega un 'elemento' en el fondo de la cola
         */
        void acolar(T elemento);

        /*
         * PRE : La cola no debe estar vacía
         * POST: Devuelve y remueve el frente de la cola
         */
        T desacolar();

        /*
         * PRE: La cola no debe estar vacía
         * POST: Devuelve el frente de la cola
         */
        T obtenerFrente();
};

template<class T> Cola<T>::Cola() {
    this->frente = NULL;
    this->fondo = NULL;
}

template<class T> Cola<T>::~Cola() {

    while (! this->estaVacia()) {

        this->desacolar();
    }
}

template<class T> bool Cola<T>::estaVacia() {

    return (this->frente == NULL);
}

template<class T> void Cola<T>::acolar(T elemento) {

    Nodo<T>* nuevoFondo = new Nodo<T>(elemento);

    if (this->estaVacia()) {

        this->frente = nuevoFondo;

    } else {

        this->fondo->cambiarSiguiente(nuevoFondo);
    }

    this->fondo = nuevoFondo;
}

template<class T> T Cola<T>::desacolar() {

    if (this->estaVacia()) {

        throw std::string("No se puede desacolar, la cola está vacía");
    }

    /* Remueve el frente de la estructura */
    Nodo<T>* frenteAnterior = this->frente;
    this->frente = frenteAnterior->obtenerSiguiente();

    if (this->frente == NULL) {

        this->fondo = NULL;
    }

    /* Devuelve el elemento y libera los recursos asociados */
    T elemento = frenteAnterior->obtenerDato();
    delete frenteAnterior;

    return elemento;
}

template<class T> T Cola<T>::obtenerFrente() {

    if (this->estaVacia()) {

        throw std::string("No se puede obtener el frente, la cola está vacía");
    }

    T elemento = this->frente->obtenerDato();

    return elemento;
}

#endif /* COLA_H_ */
