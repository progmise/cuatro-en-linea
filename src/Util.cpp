#include "Util.h"

Util::Util() { }

bool esNumero(std::string entrada) {

    std::string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, representa a un dígito
     */
    while (it != entrada.end() && std::isdigit(*it)) {

    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool esAlfanumerico(std::string entrada) {

    std::string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, es alfanumérico
     */
    while (it != entrada.end() && std::isalpha(*it)) {

    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool validarNumeroAcotado(int numero, int valorMinimo, int valorMaximo) {

	return numero >= valorMinimo && numero <= valorMaximo;
}
