#include <vector>
#include <iostream>


int main(void){
    std::vector<int> data;
    data.resize(7); 

    for(int ii = 0; ii < data.size() ; ii++) {
        data[ii] = ii;
    }

    data.push_back(10);
    std::cout << &data[0] << "\n";

    for(int i = 2; i <= data.size();  i++){
        std::cout << "\n" << data[i];
    }

    /*
    Nombres: - Daniela Fuentes
             - Mateo Manosalva
             - Sebastian Castro
    */
}
