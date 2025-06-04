#include<iostream>
#include<vector>


void print_matrix(const std::vector<double> & data, int m, int n);
bool check_inverse(std::vector<double> &A,std::vector<double> &B, double epsilon, int n);
void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C);

int main(void){
    std::vector<double> matriz1 = {2,1,
                                    3,2};
    std::vector<double> matriz2 = {2,-1,
                                    -3,2};

    std::cout<<"Matrices usadas: \n";
    print_matrix(matriz1,2,2);
    print_matrix(matriz2,2,2);
    const double presition = 0.01;
    std::cout<<"Presicion usada: "<< presition<< "\n";

    if(check_inverse(matriz1 ,matriz2 ,presition,2)){
        std::cout<< "Son inversas \n";
    }else{
        std::cout<< "No son inversas \n";
    }
}

void print_matrix(const std::vector<double> & data, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << data[i * n + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//Diego Angel y Sebastian Castro y Daniela Fuentes

void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C)
{
  if (nA != mB) {
    std::cerr << "ERROR: nA == mB\n";
    return; 
  }
  // resize result matrix
  int mC = mA;
  int nC = nB;
  C.resize(mC*nC, 0.0);

  // llenar C
  for (int ii = 0; ii < mC; ii++){
    for (int jj = 0; jj < nC; jj++) {
      C[ii*nC + jj] = 0.0;
      for (int kk = 0; kk < nA; kk++) {
        C[ii*nC + jj] += A[ii*nA + kk]*B[kk*nB + jj];
      }
    }   
  }

}

bool check_inverse(std::vector<double> &A,std::vector<double> &B, double epsilon, int n){
    std::vector<double> identity(n*n, 0.0);
    for (int i = 0; i < n; ++i) {
        identity[i * n + i] = 1.0; // Diagonal principal
    }
    
    std::vector<double> AB; matmul(A,n,n,B,n,n,AB);
    std::vector<double> BA; matmul(B,n,n,A,n,n,BA);

    //primer criterio
    for(int i = 0; i < n*n; i++){
        if(AB[i] - identity[i] > epsilon) return false;
    }
    //Segundo criterio
        for(int i = 0; i < n*n; i++){
        if(BA[i] - identity[i] > epsilon) return false;
    }
    return true;

}

//Sebastian Castro y DIego Angel

