#include <iostream>
#include <cmath>
#include <string>
#include "prime_utils.h" //En este archivo se encuentra la declaración de la función isprime()

int main(int argc, char **argv){

    // Ejepmplo uso de los argumentos en consola:
    // ./a.out -> argc = 1, argv = ["./a.out"]
    // ./a.out 10 -> argc = 2, argv = ["./a.out", "10"]
    // ./a.out 10 0.55 -> argc = 3, argv = ["./a.out", "10", "0.55"]
    // ./a.out 300 400 -> argc = 3, argv = ["./a.out", "300", "400"]

    int vmin = std::stoi(argv[1]); // Convierte las cadenas de caracteres en valores enteros
    int vmax = std::stoi(argv[2]);

    for(int ii = vmin; ii <= vmax-4; ++ii) {
        if (isprime(ii) == true and isprime(ii+4) == true) {
            std::cout << "(" << ii << ", " << ii+4 << ") ";
        }
    }
    std::cout << "\n";

    return 0;
}

