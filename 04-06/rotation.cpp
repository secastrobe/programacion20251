#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//Declaracion de funciones
void print_matrix(const std::vector<double> & data, int m, int n);
std::vector<double> product_matrix(const std::vector<double> & matrix1, const std::vector<double> & matrix2, int m, int n, int p);
std::vector<double> vector_rotation(const std::vector<double> & vec, const std::vector<double> & rad);

int main(int argc, char **argv) {

    //Vectores de porsicion original
    std::vector<double> original_position(3);
    original_position[0] = std::stod(argv[1]);
    original_position[1] = std::stod(argv[2]);
    original_position[2] = std::stod(argv[3]);

    //Vectores de angulo de rotacion en radianes
    std::vector<double> radians(3);
    radians[0] = std::stod(argv[4]);
    radians[1] = std::stod(argv[5]);
    radians[2] = std::stod(argv[6]);

    //Se ejecuta la rotacion
    std::vector<double> rotated_coordinates = vector_rotation(original_position, radians);
    print_matrix(rotated_coordinates, 1, 3); //Imprime el nuevo vector rotado
    return 0;
}

//Función para imprimir vectores y matrices
void print_matrix(const std::vector<double> & data, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << data[i * n + j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


std::vector<double> vector_rotation(const std::vector<double> & vec, const std::vector<double> & rad) {
    //Matriz de rotación de el eje x
    std::vector<double> rot_x = {
        1, 0, 0,
        0, std::cos(rad[0]), -std::sin(rad[0]),
        0, std::sin(rad[0]),  std::cos(rad[0])
    };

    //Matriz de rotación de el eje y
    std::vector<double> rot_y = {
         std::cos(rad[1]), 0, std::sin(rad[1]),
         0, 1, 0,
        -std::sin(rad[1]), 0, std::cos(rad[1])
    };

    //Matriz de rotación de el eje z
    std::vector<double> rot_z = {
        std::cos(rad[2]), -std::sin(rad[2]), 0,
        std::sin(rad[2]),  std::cos(rad[2]), 0,
        0, 0, 1
    };

    // R = Rz * Ry * Rx
    std::vector<double> R = product_matrix(rot_z, rot_y, 3, 3, 3);
    R = product_matrix(R, rot_x, 3, 3, 3);

    // Vector ressultante
    std::vector<double> rotated = product_matrix(R, vec, 3, 3, 1);

    return rotated;
}

//Función de multiplicación de matrices
std::vector<double> product_matrix(const std::vector<double> & matrix1, const std::vector<double> & matrix2, int m, int n, int p) {
    std::vector<double> result(m * p, 0.0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i * p + j] += matrix1[i * n + k] * matrix2[k * p + j];
            }
        }
    }
    return result;
}