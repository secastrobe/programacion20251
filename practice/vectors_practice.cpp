#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double norma(std::vector <double> &v);
double angle_vectors_cross(std::vector<double> &A, std::vector<double> &B);
std::vector<double> cross_product(std::vector<double> &A, std::vector<double> &B);
double scalar_product(std::vector<double> &A, std::vector<double> &B);

int main(void){
    std::vector<double> prueba = {12,13.22,12.3,18,0.9,1,0};
    std::vector<double> A = {12,13.22,12.3};
    std::vector<double> B = {2,-5.3,3};
    std::vector<double> cross_AB = cross_product(A,B);
    for(double element : cross_AB) std::cout<< element << " ";
    std::cout<< "\n";
    std::cout << norma(prueba) << "\n";
    std::cout << " Angulo entre A y B: "<< angle_vectors_cross(A,B) << "\n";
    std::cout << "Producto punto entre A y B: " << scalar_product(A,B) << std::endl;
}



double norma(std::vector <double> &v){
    double sum = 0;
    for(double element : v) sum += std::pow(element,2);
    return std::sqrt(sum);
}



std::vector<double> cross_product(std::vector<double> &A, std::vector<double> &B){
    std::vector<double> result;
    result.resize(0);
    result.push_back((A[1]*B[2])-(A[2]*B[1]));
    result.push_back((A[2]*B[0])-(A[0]*B[2]));
    result.push_back((A[0]*B[1])-(A[1]*B[0]));
    return result;
}

//Only valid for angles between -pi/2 and pi/2
double angle_vectors_cross(std::vector<double> &A, std::vector<double> &B){
    std::vector<double> cross = cross_product(A,B);
    return std::asin(norma(cross) / (norma(A) * norma(B)));
}

double scalar_product(std::vector<double> &A, std::vector<double> &B){
    // Verify the lenght of the vectors 
    if (A.size() != B.size()) std::cerr <<"The lenghts of the vectors are different"<< std::endl;

    double sum_result = 0;
    for(int i = A.size(); i > 0; i--){
        sum_result += A[i]*B[i];
    }
    return sum_result;
}