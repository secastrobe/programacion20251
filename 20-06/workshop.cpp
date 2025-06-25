#include <iostream>
#include <Eigen/Dense>

int main(int argc, char **argv){
    //Declaration on propieties of the lense
    double d = 1;
    double n =1;
    double R_1  = 1;
    double R_2 = 1;

    //Declararion of matrixes
    Eigen::Matrix2d A;
    A << 1, (n-1)/R_2,
        0 , 1;
    Eigen::Matrix2d B;
    B << 1,  0,
        d/n, 1;
    Eigen::Matrix2d C;
    C << 1, -(n-1)/R_1,
        0,  1;

    Eigen::Matrix2d Result = (A*B)*C;
    double f_inverse = -Result(0,1);
    double Result_determinant = Result.determinant();
    std::cout << "1/f = " << f_inverse << " Determinante = " << Result_determinant << std::endl ;
}