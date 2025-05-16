#include "integration.h" 

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

double simpson( double a, double b, long n, fptr fun){
    double step = (b-a)/n;
    double sum1 = 0;
    double sum2 = 0;

    for (long i = 1; i <= (n/(2)); i++){
        double value = a + (step*((2*i)-1));
        sum1 += fun(value);
    }

    for (long i = 1; i <= ((n/2)-1); i++){
        double value = a + (step*(i*2));
        sum2 += fun(value);
    }
    double integ = (step/3)*((fun(a)) + (sum1*4) + (sum2*2) + fun(b));
    return integ;
}
double richardson(double a,double b, double n, fptr f, algptr alg, int alpha)
{
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, n, f);
    double val2 = alg(a, b, n/2.0, f);
    return (aux*val2 - val1)/(aux - 1.0);
}