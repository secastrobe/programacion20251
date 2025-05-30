#include <iostream>

int main (void){

    int * dynamic_array = new int[6];
    for(int i = 0; i <= 5; i++){
        dynamic_array[i] = (i+2);
    }
    std::cout << &dynamic_array[0] << "\n";
    delete[] dynamic_array;
}