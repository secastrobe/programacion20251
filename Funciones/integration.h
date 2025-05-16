#pragma once
#include <functional>
#include <cmath>

using fptr = std::function<double(double)>;
using algptr = std::function<double(double, double, long, fptr)>;


double trapezoid(double a, double b, long n, fptr fun);
double simpson( double a, double b, long n, fptr fun);
double richardson(double a,double b, double n, fptr f, algptr alg, int alpha);
double gauss_2(double a, double b, fptr fun);
double gauss_3(double a, double b, fptr fun);