#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"

template<class T>

class Lista {

	private:

		Nodo<T>* primero;
		unsigned int tamanio;
		Nodo<T>* cursor;

	public:

		/*
		 * PRE:  No tiene
		 * POST: Crea una nueva lista
		 */
		Lista();

        /*
         * PRE:  No tiene
         * POST: Lista que tiene los mismos elementos que otra lista
         *       La instancia resulta en una copia de otra lista
         */
        Lista(Lista<T> &lista);

		/*
		 * PRE:  La lista debe haber sido creada
		 * POST: Destruye la lista y todos sus elementos
		 */
		~Lista();

        /*
         * PRE:  No tiene
         * POST: Indica si la lista tiene, o no ,algún elemento
         */
        bool estaVacia();

        /*
         * PRE: No tiene
         * POST: Devuelve la cantidad de elementos que tiene la lista
         */
        unsigned int contarElementos();

		/*
		 * PRE:  No tiene
		 * POST: Inserta un nuevo elemento al final de la lista, en la posición
		 * 		 contarElementos() + 1
		 */
		void agregar(T dato);

        /*
         * PRE:  Posición pertenece al intervalo: [1, contarElementos() + 1]
         * POST: Agrega el elemento en la posición indicada
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * PRE:  No tiene
         * POST: Agrega todos los elementos de otraLista,
         *       a partir de la posición contarElementos() + 1
         */
        void agregar(Lista<T> &otraLista);

        /*
         * PRE:  Posición pertenece al intervalo: [1, contarElementos()]
         * POST: Devuelve el elemento de la posición indicada
         */
        T obtener(unsigned int posicion);

        /*
         * PRE : Posición pertenece al intervalo: [1, contarElementos()]
         * POST: Cambia el elemento en la posición indicada, por el
         *       elemento dado
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * PRE : Posición pertenece al intervalo: [1, contarElementos()]
         * POST: Remueve de la lista el elemento en la posición indicada.
         */
        void remover(unsigned int posicion);

        /*
         * PRE:  No tiene
         * POST: Deja el cursor de la lista listo para hacer un nuevo
         *       recorrido, sobre sus elementos
         */
        void iniciarCursor();

        /*
         * PRE:  Se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()), y desde entonces no se han agregado o
         *       removido elementos de la lista
         * POST: Mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido
         *       El valor de retorno indica si el cursor quedó posicionado,
         *       sobre un elemento o no (en caso de que la lista esté vacía o
         *       no existan más elementos por recorrer)
         */
        bool avanzarCursor();

        /*
         * PRE:  El cursor está posicionado sobre un elemento de la lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * POST: Devuelve el elemento en la posición del cursor
         */
        T obtenerCursor();

        /*
         * PRE: No tiene
         *
         * POST: Vacía la lista y apunta el puntero de entrada a NULL
         */
        void vaciarLista();

    private:

        /*
         * PRE : Posición pertenece al intervalo: [1, contarElementos()]
         * POST: Devuelve el nodo en la posición indicada
         */
        Nodo<T>* obtenerNodo(unsigned int posicion);
};

template<class T> Lista<T>::Lista() {
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T> &lista) {
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    /* Copia los elementos de lista */
    this->agregar(lista);
}

template<class T> Lista<T>::~Lista() {

    while (this->primero != NULL) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->asignarSiguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->asignarSiguiente(anterior->obtenerSiguiente());
            anterior->asignarSiguiente(nuevo);
        }

        this->tamanio++;

        /* Cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::agregar(Lista<T> &lista) {

    lista.iniciarCursor();

    while (lista.avanzarCursor()) {
        this->agregar(lista.obtenerCursor());
    }
}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->asignarDato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtenerSiguiente();

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->asignarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* Cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* Pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;

    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

template<class T> void Lista<T>::vaciarLista() {
	Nodo<T>* actual = this->primero;
	Nodo<T>* aux;
	for (int i = 0; i < this->tamanio; i++) {
		aux = actual;
		actual->obtenerSiguiente();
		delete aux;
	}
	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

#endif /* LISTA_H_ */
