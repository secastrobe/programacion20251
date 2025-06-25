#include "matrix_utils.h"

void fill_matrix(std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      data[ii*n + jj] = ii*n+jj; // A_(i, j) = i*n + j = id
    }
  }
}

void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
  // TODO
   for (int ii = 0; ii < m; ++ii) {
     for (int jj = 0; jj < n; ++jj) {
       dataout[jj*m + ii] = datain[ii*n + jj];
     }
   }
}

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