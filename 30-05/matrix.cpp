#include <iostream>
#include <vector>
#include <string>

// Prototipos
void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout);

int main(int argc, char **argv)
{
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " M N\n";
        return 1;
    }
    const int M = std::stoi(argv[1]);
    const int N = std::stoi(argv[2]);

    std::vector<double> array2d(M * N, 0.0);

    fill_matrix(array2d, M, N);
    std::cout << "Matriz original:\n";
    print_matrix(array2d, M, N);

    std::vector<double> array2d_T(N * M, 0.0);  // Tamaño: N x M
    transpose_matrix(array2d, M, N, array2d_T);
    std::cout << "Matriz transpuesta:\n";
    print_matrix(array2d_T, N, M);

    return 0;
}

// Definiciones

void fill_matrix(std::vector<double> & data, int m, int n)
{
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            data[ii * n + jj] = ii * n + jj;
        }
    }
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

void transpose_matrix(const std::vector<double> & datain, int m, int n,
                      std::vector<double> & dataout)
{
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            dataout[jj * m + ii] = datain[ii * n + jj];
        }
    }
}