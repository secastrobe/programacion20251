#include <iostream>
#include <vector>
#include <random>

void argmax(int size, int seed, int &i, int &j);
void normal_random_fill(std::vector<double> & v, long min, long max, int seed); //Llena un vector con una distribución normal, pseudoaleatoria de enteros


int main (void){
    int ii;
    int jj;
    argmax(60,10, ii, jj);
    std::cout<< ii<< " "<< jj<< "\n";;
}

void argmax(int size, int seed, int &i, int &j){
    std::vector<double> matrix(size*size, 0.0);
    normal_random_fill(matrix,-1,1,seed);
    //for (double n : matrix)std::cout << n <<"\n";
    int imax = 0, jmax = 0;
    for (int ii = 0; ii < size; ++ii) {
     for (int jj = 0; jj < size; ++jj) {
        if (matrix[ii*size + jj] >= matrix[ii*size + jj +1] &&  matrix[ii*size + jj] >= matrix[imax*size + jmax]){
            imax = ii; jmax = jj;
        }
        //if((ii*size +jj) ==  (matrix.size()-2)) break;
     }
   }
   i = imax; j = jmax;
}

void normal_random_fill(std::vector<double> & v, long min, long max, int seed){
        //std::random_device rd;
        std::mt19937 gen(seed);
        std::uniform_real_distribution<float> dis(min, max);
        for(int i = 0; i < v.size(); i++) v[i] = dis(gen);
}
