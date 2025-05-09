#include <iostream>
#include <string>
#include <cmath>

//Declaramos las funciones
bool isprime(long n);
long prime_sum(long n);

int main(int argc, char **argv){
    long numero = std::stoi(argv[1]); //Obtenemos el valor de la consola de comandos
    //Imprimimos el resultado
    std::cout<<"La suma de los primos menores o iguales a " << numero <<" es: "<< prime_sum(numero) << "\n";
    return 0;
}

long prime_sum(long n){
    long sum = 0; //Inicia la suma en 0
    for (long i = 2; i < n; i++){
        if (isprime(i)){ //Se suma cada numero primo
            sum += i;
        }
    }
    return sum ; //Se retorna el resultado de la suma
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