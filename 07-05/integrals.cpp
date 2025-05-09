#include "integrals.h" 

double trapezoid(double a, double b, long n, fptr fun){
    double step = (b-a)/n;
    double sum = 0;
    for (long i = 0; i < n; i++){
        double value = a + (step*i);
        sum += fun(value);
    }
    double integ = step*((fun(a)/2) + sum + fun(b)/2);
    return integ;
}