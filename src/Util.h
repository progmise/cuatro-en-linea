#ifndef UTIL_H_
#define UTIL_H_
#include <iostream>

class Util {

	public:
		/*
		 * PRE:  No tiene
		 * POST: Crea un nuevo util
		 */
		Util();

		/*
		 * PRE:  No tiene
		 * POST: Devuelve un boolean, que representa si la entrada dada
		 * 		 es efectivamente un número
		 */
		static bool esNumero(std::string entrada);

	    /*
	     * PRE:  No tiene
	     * POST: Devuelve un boolean, que representa si la entrada dada
	     *	 	 es efectivamente alfanumérica
	     */
		static bool esAlfanumerico(std::string entrada);
	    /*
	     * PRE:  No tiene
	     * POST: Devuelve un boolean, que representa si la entrada dada
	     *	 	 es efectivamente un espacio
	     */
		static bool esEspacio(std::string entrada);

		/*
		 * PRE:  valorMinimo debe ser igual o menor a valorMaximo
		 * POST: Devuelve un boolean, que representa si el número dado,
		 * 		 se encuentra dentro del rango de un valor mínimo y otro
		 * 		 máximo
		 */
		static bool validarNumeroAcotado(int numero, int valorMinimo, int valorMaximo);
};



#endif /* UTIL_H_ */
