#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <random>

double norma(std::vector <double> &v); //Norma de un vector

//Ojo, este ángulo solo sirve entre -pi/2 y pi/2
double angle_vectors_cross(std::vector<double> &A, std::vector<double> &B); //Angulo entre 2 vectores usando porducto cruz

//Producto cruz de vectores 3x3
std::vector<double> cross_product(std::vector<double> &A, std::vector<double> &B);
double scalar_product(std::vector<double> &A, std::vector<double> &B); //Producto punto
double angle_vector_scale(std::vector<double> &A, std::vector<double> &B); // Angulo entre 2 vectores usando el producto punto
void normal_random_fill(std::vector<double> & v, long min, long max); //Llena un vector con una distribución normal, pseudoaleatoria de enteros
double vector_product(std::vector<double> &A, std::vector<double> &B, std::vector<double> &C); //Producto triple de 3 vectores 3x3