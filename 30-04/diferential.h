#pragma once
#include <cmath>

double f(double x);

double forward_diff(double x, double h);
double central_diff(double x, double h);
double richardson_forward(double x, double h);