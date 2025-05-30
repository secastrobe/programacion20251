#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double prom(const std::vector<double>& x);
void lineal_aprox (const std::vector<double>& x, const std::vector<double>& y);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " archivo_datos.txt" << std::endl; 
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "No se pudo abrir el archivo " << argv[1] << std::endl;//Retorna un error cuando no se lee correctamente el archivo 
        return 1;
    }

    //Añade los valores a los vectores
    std::vector<double> xdata, ydata;
    double x, y;
    while (fin >> x >> y) {
        xdata.push_back(x);
        ydata.push_back(y);
    }
    fin.close();
    lineal_aprox(xdata,ydata);

}

void lineal_aprox (const std::vector<double>& x, const std::vector<double>& y){
    long N = x.size();
    double e_y = prom(y);
    double e_x = prom(x);

    double e_xx = 0.0, e_xy = 0.0;

    for (long i = 0; i < N; ++i) {
        e_xx += x[i] * x[i];
        e_xy += x[i] * y[i];
    }
    e_xx /= N;
    e_xy /= N;

   //Cálculo de las pendiente 
   double m = (e_xy - (e_x*e_y)) / (e_xx - std::pow(e_x ,2));
   double b = ((e_xx*e_y)-(e_x*e_xy)) / (e_xx - std::pow(e_x ,2));

    double s2 = 0.0;
    for (int i = 0; i < N; ++i) {
        double ylineal = m * x[i] + b;
        s2 += std::pow(y[i] - ylineal, 2);
    }
    s2 /= (N - 2);

    //Calculo de errores

    double delta_m = std::sqrt(s2 / (e_xx - e_x * e_x));
    double delta_b = std::sqrt(delta_m * delta_m * e_xx);

    //Constantes necesarias
    double const e = 1.602176634e-19;
    double const h_exp = m * e;
    double const pi = -b * e;
    double const h_teo = 6.62607015e-34;
    double const diff_rel = std::abs(h_exp - h_teo) / h_teo;


    std::cout << "\nConstante de Planck experimental h = " << h_exp << " J·s" << "\n";
    std::cout << "Constante de Planck teórica h = " << h_teo << " J·s" << "\n";
    std::cout << "\nFunción de trabajo φ = " << pi << " J" << "\n";
    std::cout << "\nDiferencia relativa = " << diff_rel << "\n";
    std::cout << "---------------------------------------------------\n";

 }
// Calcula el promedio
double prom(const std::vector<double>& x){
    double sum = 0.0;
    for (std::size_t i = 0; i < x.size(); ++i) {
        sum += x[i];
    }
    return sum / x.size();
 }
