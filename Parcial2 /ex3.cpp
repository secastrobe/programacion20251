#include <iostream>
#include <valarray>
#include <random>
#include <iomanip>
#include <cmath>

double mean_field(long values, int seed);
void normal_random_fill(std::valarray<double> & v1, std::valarray<double> & v2, long min, long max, int seed);
void print(std::string msg, const std::valarray<double>& v);

int main (void){

std::cout << mean_field(1000,42)<< std::endl;

}

double mean_field(long values, int seed){
    std::valarray<double> x(values);
    std::valarray<double> y(values);

    //Llenado de los vectores con números aleatorios

    normal_random_fill(x, y, -5, 5, seed);

    std::valarray<double> vx = ((x*x)-(y*y));
    std::valarray<double> vy = 2*x*y;
    auto nlambda = [](std::valarray<double> &vx, std::valarray<double> &vy){
        std::valarray<double> vx2 = vx*vx;
        std::valarray<double> vy2 = vy*vy;
        std::valarray<double> vt = vx2 + vy2;
        vt = std::sqrt(vt);
        return vt;
    };

    std::valarray<double> v = nlambda(vx, vy);


    double mean_v = (v.sum()/v.size());
    return mean_v;
}

void normal_random_fill(std::valarray<double> & v1,std::valarray<double> & v2, long min, long max, int seed){
    //std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(seed); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max); //min and max values

    for(int i = 0; i < v1.size(); i++) v1[i] = distrib(gen);
    for(int i = 0; i < v2.size(); i++) v2[i] = distrib(gen);
    //Es necesario llenar con el mismo generador x y luego y para que los valores sean distintos :)
}

void print(std::string msg, const std::valarray<double>& v)
{
    std::cout << msg << " ";
    for (double n: v) { std::cout << std::setw(3) << n; }
    std::cout << '\n';
}