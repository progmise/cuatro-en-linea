#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"

template <class T>

class Lista {

	private:

		Nodo<T> *nodo;


	public:

		/*
		 * POST: Crea una nueva lista
		 */
		Lista();

		/*
		 * PRE:  La lista debe haber sido creada
		 * POST: Destruye la lista y todos sus elementos
		 */
		~Lista();

		/*
		 * POST: Inserta un nuevo elemento al principio de la lista
		 */
		void insertarPrimero(T dato);

		/*
		 * POST: Inserta un nuevo elemento al final de la lista
		 */
		void insertarUltimo(T dato);

		/*
		 * PRE:  El indice debe ser mayor a 0, y no superar el largo
		 * 		 máximo de la lista
		 * POST: Inserta un nuevo elemento en la lista, en la posición
		 * 		 del indice dado
		 */
		void insertarEnPosicion(T dato, int indice);

		/*
		 * PRE:  La lista debe haber sido creada
		 * POST: Borra la primera ocurrencia en la lista, del dato almacenado allí,
		 * 		 en sentido ascendente
		 */
		void borrarPrimeraOcurrencia(T dato);

		/*
		 * PRE:  La lista debe haber sido creada
		 * POST: Valida si un dato, existe en la lista, verificandolo en sentido
		 * 		 ascendente
		 */
		bool buscar(T dato);

		/*
		 * PRE:  La lista debe haber sido creada
		 * POST: Imprime la información de la lista
		 */
		void imprimir();
};

#endif /* LISTA_H_ */
