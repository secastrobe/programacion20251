/*
Juego para advinar el número

Tomar un número
Preguntar al usuario el número que cree que es
Informar si se adivinó el número o no
*/
#include <iostream>

//declaración de la funcion de juego

void play (void){
    const int num = 10;
    int guessed_number = num+1; // Asigna el numero adivinado para que while se ejecute ṕor primera vez

    while(guessed_number != num){
        std::cout << "Adivina un numero entre 1 y 100\n";
        std::cin >> guessed_number; //Asigna el número adivinado a la variable

        std::cout << "Escribiste el numero:" << guessed_number << "\n";  
        if(guessed_number <= 1 || guessed_number >= 100){ //Comprueba si el numero esta en el rango permitido
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

