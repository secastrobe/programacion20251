#include <iostream>
#include <fstream>
#include "diferential.h"

double f(double x);

int main(int argc, char **argv) {
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    double x = 1.2345;
    double exact_result = 2*x*std::cos(x*x);

    // open file for writing
    std::ofstream file("derivatives.txt");

    for(double h = 1.0e-20; h <= 1.0; h *= 10.0) {
        double forward_result = forward_diff(x, h, f);
        double central_result = central_diff(x, h, f);
        double richardson_forward_result = richardson(x, h, f, forward_diff, 1);
        double richardson_central_result = richardson(x, h, f, central_diff, 2);
        double error_forward = std::abs(1.0 - forward_result/exact_result);
        double error_central_r =std::abs(1.0 - richardson_central_result/exact_result);
        double error_central = std::abs(1.0 - central_result/exact_result);
        double error_forward_r = std::abs(1.0 - richardson_forward_result/exact_result);
        file << x << " " 
                << h << " "
                << forward_result << " "
                << central_result << " "
                << error_forward << " "
                << error_central 
                << error_forward_r << " "
                << error_central_r << " "
                << std::endl;
    }
    file.close();
    return 0;
}

double f(double x)
{
   return std::sin(x*x); // 2xcos(x^2) 
}