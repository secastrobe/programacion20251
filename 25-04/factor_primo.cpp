#include <iostream>
#include <string>
#include "prime_utils.h"

int main(int argc,char **argn){
    int n = std::stoi(argn[1]);
    int bprime = isprime_factor(n);
    std::cout<<"El factor primo mas grande del numero "<< n << " es: "<< bprime << "\n"; 

}