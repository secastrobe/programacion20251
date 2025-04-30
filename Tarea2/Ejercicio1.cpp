#include <iostream>
#include "prime_fuctions.h"
#include <string>

int main(int argc, char **argv){
    long numero = std::stoi(argv[1]);
    std::cout<<"La suma de los primos menores o iguales a " << numero <<" es: "<< prime_sum(numero) << "\n";
    return 0;
}