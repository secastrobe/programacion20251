#include <iostream>
#include <cmath>

int isprime(int n);
int largest_prime_factor(int n);

int main(void){
    std::cout << largest_prime_factor(9) << std::endl;
    std::cout << largest_prime_factor(97) << std::endl;
    std::cout << largest_prime_factor(100) << std::endl;
    std::cout << largest_prime_factor(12345) << std::endl;
    std::cout << largest_prime_factor(1000099) << std::endl;
    std::cout << largest_prime_factor(5412345) << std::endl;

    return 0;
}

int isprime(int n){
    if (n <= 1) {
        std::cerr << "Out of range number: " << n << "\n";
        return 0;
    }

    // suppose it is prime
    int flag = 1; 

    if (n == 2) {
        return 1;
    }

    // find divisors
    for (long ii = 2; ii <= std::sqrt(n) + 1; ii++) {
        if (n%ii == 0) { // ii is divisor
            flag = 0;
            break;
        }
    }
    return flag;
}

int largest_prime_factor(int n){
    if (isprime(n)){ //Retorna el mismo numero si este es primo
        return n;
    }
    int max_prime = 0; //retorna 0 para numeros como 1 o menores a 1
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