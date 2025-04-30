#include "prime_fuctions.h"

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

long b_factorp(long n){
    if (isprime(n)){
        return n;
    }
    for (long i = n-1; i >=1 ; i--)
    {
        if(n % i == 0){
            return i;
        }
    }
    return 1;
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