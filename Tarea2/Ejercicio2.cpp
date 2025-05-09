#include <iostream>
#include <string>
#include <cmath>
//Declaramos las funciones
bool isprime(long n); 
long b_factorp(long n);

int main(int argc, char **argv){
    long numero = std::stol(argv[1]); //Extraemos el valor de la linea de comandos
    //Imprimimos el resultado
    std::cout<<"EL factor primo mas grande de "<< numero<<" es: "<< b_factorp(numero)<<"\n";
    return 0;
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

long b_factorp(long n){
    if (isprime(n)){ //Retorna el mismo numero si este es primo
        return n;
    }
    long max_prime = 0; //retorna 0 para numeros como 1 o menores a 1
    for (long i = 2; i <= std::sqrt(n) + 1  ; i++) //Cálculo de el mayor factor primo igual que en el ejemplo del profesor
    {
        while(n % i == 0){
            if(isprime(i)){
            max_prime = i;
            }
            n /= i;
        }

    }
    if (n > 2 and isprime(n)){
        max_prime = n;
    }
    return max_prime;
}
