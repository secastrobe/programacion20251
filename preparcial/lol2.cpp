#include <fstream>
#include <cmath>
#include <iostream>
#include <functional>
using fptr = std::function<double(double)>;
using algptr = std::function<double(double,double)>;




double potential(double x);
double dev_central(double x, double h);
double dev_central_richardson(double x, double h, fptr f , algptr alg);
double electricfield(double x, double h);
double exact(double x);

int main (void)
{
    std::ofstream.file("electricfields.txt");
    file.precision(16);
    file.setf(std::ios::scientific);
    for( double i = 1.0; i <= 1.8 ; 1 + 0.2){
    file << i << exact(i) << "  "
    << dev_central_richardson(i, 0.05,potential,dev_central) << "\n";
    }
    
    file.close();
    return 0;
}

double dev_central(double x, double h)
{
    return ((2*(x + h)*std::sin(x+h)) - (2*(x - h)*std::sin(x - h))) / (2*h);
}

double potential(double x){
    return 2*x*std::sin(x);
}

double dev_central_richardson(double x, double h, fptr f , algptr alg)
{
    double aux = std::pow(2.0, 2.0);
    double val1 = alg(x, h);
    double val2 = alg(x, h/2.0);
    return (aux*val2 - val1)/(aux - 1.0);
}

double electricfield(double x, double h)
{
    double elecvalue = (-1)*dev_central_richardson(x,h,potential,dev_central);
    return elecvalue;
}

double exact(double x){
    return ((2*std::sin(x))+(2*x*std::cos(x)));
}