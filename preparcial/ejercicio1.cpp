#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

bool isprime(long n);
double nth_twin_primes(long n);

int main(){
    //long numero = std::stol(argv[1]);
    std::ofstream file("nth_twin_primes.txt");
    for(long i =1;i<=100; i++){
    double f_twin = nth_twin_primes(i);
    double norma = std::sqrt((std::pow(f_twin)+std::pow(f_twin+2)));
    file << i << " " << norma << std::endl;
    }
    file.close();
    return 0;
}

double nth_twin_primes(long n){
    long count = 0;
    for (double i = 2;; i++){
        if(isprime(i) && isprime(i+2)){
            count++;
        }
        if(count == n){
            return i;
            break;
        }
    }
}

bool isprime(long n) {
    if (n <= 1) { //Comprueba que el numero ingresado este dentro de el rango
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
