#include <iostream>
#include <vector>
#include <string>
#include <cmath>

void print_matrix(const std::vector<double> & data, int m, int n);

int main (int argc,char  **argv){

    // Captueamos los valores del vector
    double vx = std::stod(argv[0]);
    double vy = std::stod(argv[1]);
    double vz = std::stod(argv[2]);

    //Capturamos los valores de retacion (Radianes)
    double thetax = std::stod(argv[3]);
    double thetay = std::stod(argv[4]);
    double thetaz = std::stod(argv[5]);

    std::vector<double> array2d(3 * 3, 0.0); 
    print_matrix(array2d,3,3);
    return 0;
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            std::cout << data[ii * n + jj] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}