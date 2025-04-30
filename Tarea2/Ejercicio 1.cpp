#include <iostream>
#include <cmath>
#include <string>

long prime_sum(long n);
bool isprime(long n);

int main(int argc, char **argv){
    long numero = std::stoi(argv[1]);
    std::cout<<"La suma de los primos menores o iguales a " << numero <<" es: "<< prime_sum(numero) << "\n";
    return 0;
}

long prime_sum(long n){
    long sum = 0;
    for (long i = 2; i < n; i++){
        if (isprime(i)){
            sum += i;
        }
    }
    return sum ; 
}

bool isprime(long n) {
    if (n <= 1) { //Compruebq que el numero ingresado este dentro de el rango
        std::cerr << "Numero fuera de rango: " << n << "\n";
        return false;
    }

    // Suponemos que es primo
    bool flag = true; 

    if (n == 2) {
        return true;
    }
    // Buscamos los divisores
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii es un divisor
            flag = false;
            break; // eSe termina el ciclo dado que se encontro al menos un divisor
        }
   
    } 
return flag;
}