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


//A partir de qui todo va en integration.h !!!
#pragma once
#include <functional>
#include <cmath>
// punteros de las funciones
using fptr = std::function<double(double)>;
using algptr = std::function<double(double, double, long, fptr)>;
// Declaracion de las funciones
double trapezoid(double a, double b, long n, fptr fun);
double simpson( double a, double b, long n, fptr fun);
double richardson(double a,double b, double n, fptr f, algptr alg, int alpha);

//A partir de aqui todo va en integration.cpp !!!


#include "integration.h" 

double trapezoid(double a, double b, long n, fptr fun){
    double step = (b-a)/n; // Tamaño de h
    double sum = 0;
    for (long i = 0; i < n; i++){ // calculo de la sumatoria
        double value = a + (step*i);
        sum += fun(value);
    }
    double integ = step*((fun(a)/2) + sum + fun(b)/2);
    return integ;
}

double simpson( double a, double b, long n, fptr fun){
    double step = (b-a)/n; //Tamaño de h
    double sum1 = 0;
    double sum2 = 0;

    for (long i = 1; i <= (n/(2)); i++){ // calculo de la primera sumatoria
        double value = a + (step*((2*i)-1));
        sum1 += fun(value);
    }

    for (long i = 1; i <= ((n/2)-1); i++){ // calculo de la segunda sumatoria
        double value = a + (step*(i*2));
        sum2 += fun(value);
    }
    double integ = (step/3)*((fun(a)) + (sum1*4) + (sum2*2) + fun(b));
    return integ;
}
double richardson(double a,double b, double n, fptr f, algptr alg, int alpha)
{
    double aux = std::pow(2.0, alpha); // implementacion de richardson
    double val1 = alg(a, b, n, f);
    double val2 = alg(a, b, n/2.0, f);
    return (aux*val2 - val1)/(aux - 1.0);
}
