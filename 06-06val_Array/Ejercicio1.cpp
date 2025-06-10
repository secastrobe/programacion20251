#include <valarray>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <numeric>

void print(std::string msg, const std::valarray<double>& v);

int main(void){
    std::valarray <double> steps(1000);
    double const step = (2.0*M_PI) / 10.0;
     std::iota(std::begin(steps), std::end(steps), 1.0);
    steps *= step;
    print("pi: ",steps);
}
void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (int n: v) { std::cout << std::setw(3) << n; }
    std::cout << '\n';
}
