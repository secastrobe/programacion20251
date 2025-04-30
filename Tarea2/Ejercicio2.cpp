#include <iostream>
#include "prime_fuctions.h"
#include <string>

int main(int argc, char **argv){
    long numero = std::stol(argv[1]);
    std::cout<<"EL factor primo mas grande de "<< numero<<" es: "<< b_factorp(numero)<<"\n";
    return 0;
}