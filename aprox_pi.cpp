#include <iostream>
#include <math.h>



float pi_aprox(int numero){
    double pi_apx = 0;
    for (int i = 0; i < numero; i++)
    {
        double potencia = pow(16,i);
        double mult = ((4.0/((8*i) + 1))-(2.0/((8*i) + 4))-(1.0/((8*i) + 5))-(1.0/((8*i) + 6)));
        pi_apx += (1/potencia)*mult;
        //std::cout << "\nPotencia:" << potencia << "\ntermino:" << mult;
    }
    return pi_apx;
}
int main(void){
    int num;
    while(true){
        std::cout << "Ingrese el numero de terminos que desea tenga la aproximacion de pi (entre 1 y 20 terminos) : ";
        std::cin >> num;
        std ::cout << num;
        if (num < 1 or num > 20){
            std::cout << "\nEl numero no esta dentro del rango permitido, intentalo de nuevo:" << "\n";
            continue;
        }
        float pi = pi_aprox(num);
        std::cout << "\n" << "La aproximacion de pi es:" << pi << "\n";
        break;
    }
    return 0;
}