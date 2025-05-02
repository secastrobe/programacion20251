#include "diferential.h"
#include <iostream>
#include <cmath>

double f(double x);

int main(){
    
    double x = 1.2345;
    double h = 0.001;

    double forward_result = forward_diff(x,h);
    double central_result = central_diff(x,h);

    std::cout<< "Forward diference: "<< forward_result << std::endl;
    std::cout<< "Central diference: "<< central_result << std::endl;
    std::cout<< "Exact diference: "<< 2*x*std::cos(x*x) << std::endl;


    return 0;
}

double f(double x){
    return std::sin(x*x);
}