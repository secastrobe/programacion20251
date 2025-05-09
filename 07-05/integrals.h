#pragma once
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid(double a, double b, long n, fptr fun);
double simpson( double a, double b, long n, fptr fun);