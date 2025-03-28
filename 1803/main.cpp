#include <iostream>
#include "complex_number.hpp"

int main() {
    // Creiamo due numeri complessi, uno con float e uno con double
    complex_number<float> c1(1.5f, 2.5f);
    complex_number<float> c2(3.0, -4.0);

    // Stampiamo i numeri complessi
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;

    // Somma di numeri complessi
    auto sum = c1 + c2;
    std::cout << "Somma: " << sum << std::endl;

    // Prodotto di numeri complessi
    auto prod = c1 * c2;
    std::cout << "Prodotto: " << prod << std::endl;

    // Coniugato
	std::cout << "Il programma restituisce il coniugato solo del primo numero che viene scritto nel main" << std::endl;
    std::cout << "Coniugato di c1: " << c1.coniugato() << std::endl;

    return 0;
}