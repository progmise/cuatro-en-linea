#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T>

class Nodo {

	private:

		T dato;
		Nodo<T>* siguiente;

	public:

        /*
         * PRE:  No tiene
         * POST: El nodo resulta inicializado con el dato dado
         *       y sin un nodo siguiente.
         */
        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = NULL;
        }

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el valor del dato
		 */
		T obtenerDato() {
			return this->dato;
		}

		/*
		 * PRE:  No tiene
		 * POST: Asigna el valor del dato
		 */
		void asignarDato(T dato) {
			this->dato = dato;
		}

		/*
		 * PRE:  No tiene
		 * POST: Devuelve el siguiente nodo
		 */
		Nodo<T>* obtenerSiguiente() {
			return this->siguiente;
		}

		/*
		 * PRE:  No tiene
		 * POST: Asigna el siguiente nodo
		 */
		void asignarSiguiente(Nodo<T>* siguiente) {
			this->siguiente = siguiente;
		}
};

#endif /* NODO_H_ */
