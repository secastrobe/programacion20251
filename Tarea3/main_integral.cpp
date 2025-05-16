#include "integration.h" // Nombre del archivo para la modularizacion
#include <iostream>
#include <fstream>
#include <cmath>

double fun(double x);

int main(void){
     
    double exact = 1.56898093601156; // Valor exacto de la integral con 15 cifras signidficativas

    std::ofstream file("integrals.txt"); // Abre el archivo txt 
    file.precision(15); 
    file.setf(std::ios::scientific);  // COnfigura la notacion cinetifica a 15 cifras significativas

    for (long i=2; i <= 2000000; i*=2){

        //Las siguientes lineas de codigo calculasn los valores de las aproximaciones y sus errores

        double trapezoid_result = trapezoid(-5.0, 5.0, i, fun);
        double error_trapezoid = std::abs(1.0 - trapezoid_result/exact);
        double simpson_result = simpson(-5.0, 5.0, i, fun);
        double error_simpson = std::abs(1.0 - simpson_result/exact);
        double richardson_trapezoid = richardson(-5.0, 5.0, i, fun, trapezoid, 2);
        double error_richardson_trapezoid = std::abs(1.0- richardson_trapezoid/exact);
        double richardson_simpson = richardson(-5.0, 5.0, i, fun, simpson, 4);
        double error_richardson_simpson = std::abs(1.0- richardson_simpson/exact);

        //Impreime en el archivo los reultados obtenidos
        file << "-5" << " "
             << "5" << " "
             << i << " "
             << trapezoid_result << " "
             << error_trapezoid << " "
             << simpson_result << " "
             << error_simpson << " "
             << richardson_trapezoid << " "
             << error_richardson_trapezoid << " "
             << richardson_simpson << " "
             << error_richardson_simpson << " "
             << std::endl;
            
    }

    file.close(); //cierra el archivo txt
    return 0;
}

double fun(double x){
    return std::sin(std::exp(x)); //Funcion sen(e^x)
}

