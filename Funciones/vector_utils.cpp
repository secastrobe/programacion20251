#include "vector_utils.h"

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
    for(unsigned int i = 0; i < A.size(); i++) sum_result += (A[i]*B[i]);
    return sum_result;
}

double angle_vector_scale(std::vector<double> &A, std::vector<double> &B){
    return std::acos(scalar_product(A,B)/(norma(A)*norma(B))); //acos = Arcoseno
}

void normal_random_fill(std::vector<double> & v, long min, long max){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max); //min and max values

    for(int i = 0; i < v.size(); i++) v[i] = distrib(gen);
}

double vector_product(std::vector<double> &A, std::vector<double> &B, std::vector<double> &C){
    std::vector <double> cross = cross_product(B,C);
    return (scalar_product(A,cross));
}