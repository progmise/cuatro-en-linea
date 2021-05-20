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
		 * POST: El nodo resulta inicializado con el dato dado
		 *       y el puntero del siguiente nodo
		 */
		Nodo(T dato, Nodo<T>* siguiente) {
			this->dato = dato;
			this->siguiente = siguiente;
		}

		/*
		 * POST: Devuelve el valor del dato
		 */
		T obtenerDato() {
			return this->dato;
		}

		/*
		 * POST: Asigna el valor del dato.
		 */
		void asignarDato(T dato) {
			this->dato = dato;
		}

		/*
		 * POST: Devuelve el siguiente nodo
		 */
		Nodo<T>* obtenerSiguiente() {
			return this->siguiente;
		}

		/*
		 * POST: Asigna el siguiente nodo
		 */
		void asignarSiguiente(Nodo<T>* siguiente) {
			this->siguiente = siguiente;
		}
};

#endif /* NODO_H_ */
