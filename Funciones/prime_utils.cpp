#include "prime_utils.h"

// implementation
bool isprime(long n) {
    // precondition checks
    // do something if n <= 1
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return false;
    }

    // suppose it is prime
    bool flag = true; 

    if (n == 2) {
        return true;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = false;
            break; // end, at least one divisor
        }
    }

    return flag;
}

int isprime_factor(int n){
    for(int i = n/2 / 2; i >= 1; i--){
        if(n % i == 0){
            return i;
        }
    }
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