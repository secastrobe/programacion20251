#include <iostream>
#include <cmath>

//redefinimos pi para evitar problemas con cmath
#ifndef M_PI 
const double M_PI = 3.14159265358979323846;
#endif

double pi_aprox(int numero){
    double pi_apx = 0; //Hace un reset al valor de pi para volver a calcular
    for (int i = 0; i < numero; i++)
    {
        double mult = ((4.0/((8*i) + 1))
                        -(2.0/((8*i) + 4))
                        -(1.0/((8*i) + 5))
                        -(1.0/((8*i) + 6)));
        pi_apx += mult/std::pow(16,i); //divide el termino por la potencia de 16
    }
    return pi_apx;
}
int main(void){
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific); //Configura notacion cientifica
    int n = 20;
    for(int i=1; i<=n; i++){ //realiza n veces el ciclo
        double pi = pi_aprox(i);
        double dif = (M_PI - pi)/pi;
        double diferencia = std::abs(dif);
        std::cout << "\n" << "La aproximacion de pi es: " << pi << "\n";
        std::cout << "El valor de n usado fue: " << i << "\n";
        std::cout << "La diferencia relativa es: " << diferencia << "\n";
    }
    return 0;
}