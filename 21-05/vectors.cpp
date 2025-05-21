#include <vector>
#include <iostream>
#include <string>


void fill( std:: vector<double> & vec);
double promedio(const std:: vector<double> & vec);

int main(int argc , char **argv)
{
    std::vector<double> data;

    // declare the vector

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    auto lambda = [][std::vector<double> ]
    // resize the vector
    data.resize(N, 0);
    fill(data);
    std::cout<< "\n" << promedio(data) << "\n";
    return 0;
}


double promedio(const std::vector<double> &vec){
     double suma = 0.0;
    for(int ii = 0; ii < vec.size(); ii++) {
        suma = suma + vec[ii];
    }
    suma /= vec.size();
    return suma;
}

void fill( std::vector<double> & vec){
    for(int ii = 0; ii < vec.size() ; ii++) {
        vec[ii] = ii;
    }
}

//Sebastian Castro y Daniela Fuentes