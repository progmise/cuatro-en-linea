#include "Util.h"

using namespace std;

Util::Util() { }

bool Util::esNumero(string entrada) {

    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, representa a un dígito
     */
    while (it != entrada.end() && isdigit(*it)) {

    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool Util::esAlfanumerico(string entrada) {

    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, es alfanumérico
     */
    while (it != entrada.end() && isalnum(*it)) {

    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool Util::esEspacio(string entrada) {

    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, es alfanumérico
     */
    while (it != entrada.end() && isspace(*it)) {

    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool Util::validarNumeroAcotado(int numero, int valorMinimo, int valorMaximo) {

	return numero >= valorMinimo && numero <= valorMaximo;
}

unsigned int Util::obtenerMenorDeTres(unsigned int num1, unsigned int num2,
									  unsigned int num3) {

	unsigned int menor = 0;

	if (num1 == num2 && num2 == num3) {

		menor = num1;

	} else if (num1 < num2 && num1 < num3) {

		menor = num1;

	} else if (num2 < num3) {

		menor = num2;

	} else {

		menor = num3;
	}

	return menor;
}
