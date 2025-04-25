/*
Juego para advinar el número

Tomar un número
Preguntar al usuario el número que cree que es
Informar si se adivinó el número o no
*/
#include <iostream>
#include <random>

//declaración de la funcion de juego

void play (int minimo, int maximo){

    std::random_device rd;  // Fuente de entropía aleatoria
    std::mt19937 gen(rd()); // Generador Mersenne Twister
    std::uniform_int_distribution<> distrib(minimo, maximo); // Rango: 0 a 99

    const int num = distrib(gen);
    int guessed_number = num+1; // Asigna el numero adivinado para que while se ejecute ṕor primera vez
    const int min = minimo;
    const int max = maximo;
    std::cout << "Inicia el juego\n";

    while(guessed_number != num){
        std::cout << "Adivina un numero entre 1 y 100\n";
        std::cin >> guessed_number; //Asigna el número adivinado a la variable

        std::cout << "Escribiste el numero:" << guessed_number << "\n";  
        if(guessed_number <= min || guessed_number >= max){ //Comprueba si el numero esta en el rango permitido
            std::cout<< "El numero que ingresate no esta dentro de el rango permitido, por favor vuelve a intentar\n";
            continue;
        }
        else {
            if (guessed_number == num) {
                std::cout << "Ganaste!\n";
            }   else  if (guessed_number > num ) {
                std::cout<<"Te pasaste\n";
            }   else {
                std::cout<<"Te falto\n";
            }
        }
    }
}

int main(void) {
    play();
    return 0;
}   

