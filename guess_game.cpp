/*
Juego para advinar el número

Tomar un número
Preguntar al usuario el número que cree que es
Informar si se adivinó el número o no
*/
#include <iostream>

int main(void) {
    const int num = 10;
    int guessed_number = num+1;

    while(guessed_number != num){
        std::cout << "Adivina un numero entre 1 y 100\n";
        std::cin >> guessed_number; //Asigna el número adivinado a la variable
  
        if (guessed_number == num) {
            std::cout << "Ganaste!\n";
        }   else  if (guessed_number > num ) {
            std::cout<<"Te pasaste\n";
        }   else {
            std::cout<<"Te falto\n";
        }
    }
    return 0;
}   

