#include <cmath>
#include <fstream>
#include <iostream>
#include <functional>

using fptr = std::function<double(double)>;
using algptr = std::function<double(double, double, fptr)>;

double functio(double x);
double forward_diff(double x, double h, fptr f);
double central_diff(double x, double h, fptr f);
double richardson(double x, double h, fptr f , algptr alg, int alpha, int nreps, int delta);
void figure(double x,double h,  fptr f);



int main(void){
   // std::cout.precision(10);
   // std::cout.setf(std::ios::scientific);
    double const x = 1.2345;
    /*
    std::cout << richardson(x, 0.1, functio, forward_diff, 1, 1, 1) << "\n";
    std::cout << richardson(x, 0.1, functio, forward_diff, 1, 3, 1)<< "\n";
    std::cout << richardson(x, 0.01, functio, forward_diff, 1, 2, 1)<< "\n";
    std::cout << richardson(x, 0.05, functio, forward_diff, 1, 3, 1)<< "\n";
    std::cout << richardson(x, 0.1, functio, central_diff, 2, 2, 2)<< "\n";
    std::cout << richardson(x, 0.01, functio, central_diff, 2, 1, 2)<< "\n";
    */
    figure(x, 0.1, functio);
    figure(x, 0.01, functio);
    figure(x, 0.05, functio);
    return 0;
}

double functio(double x){
    return std::sin(x*x);
}

double forward_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x)) / h;
}

double central_diff(double x, double h, fptr f) {
    return (f(x + h) - f(x - h)) / (2*h);
}

double richardson(double x, double h, fptr f , algptr alg, int alpha, int nreps, int delta)
    {

        if(nreps == 1)
        {
            double original_value_1 = alg(x, h, f);
            double original_velue_2 = alg(x, h/2.0, f);
            double aux = std::pow(2.0, alpha);
            return (aux*original_velue_2 - original_value_1)/(aux - 1.0);   
        }

    for (int i = 1; i < nreps; i++){
        double aux = std::pow(2.0, alpha + ((nreps -1)*delta));
        double val1 = richardson(x, h, f, alg, alpha, nreps - i, delta);
        double val2 = richardson(x, h/2.0, f, alg, alpha, nreps - i, delta);
        return (aux*val2 - val1)/(aux - 1.0);  
    }
    return 0;
}



//Función para el archivo de figura
void figure(double x,double h, fptr f){
    // std::ofstream file("richardson.txt");

    double exact_result = 2*x*std::cos(x*x);

    double forward_result = forward_diff(x, h, f);
    double central_result = central_diff(x, h, f);
    double richardson_forward_result = richardson(x, h, f, forward_diff, 1, 1, 1);
    double richardson_central_result = richardson(x, h, f, central_diff, 2, 1, 2);
    double richardson_central_resultx3 = richardson(x, h, f, central_diff, 2, 3, 2);
    double richardson_forward_resultx3 = richardson(x, h, f, forward_diff, 1, 3, 1);
    double error_forward = std::abs(1.0 - forward_result/exact_result);
    double error_central = std::abs(1.0 - central_result/exact_result);
    double error_forward_r = std::abs(1.0 - richardson_forward_result/exact_result);
    double error_central_r = std::abs(1.0 - richardson_central_result/exact_result);
    double error_forward_rx3 = std::abs(1.0 - richardson_forward_resultx3/exact_result);
    double error_central_rx3 = std::abs(1.0 - richardson_central_resultx3/exact_result);

    std::cout  << x << " " 
            << h << " "
            << forward_result << " "
            << central_result << " "
            << error_forward << " "
            << error_central << " "
            << error_forward_r << " "
            << error_central_r << " "
            << error_forward_rx3 << " "
            << error_central_rx3 << " "
            << std::endl;
    //file.close();

}
