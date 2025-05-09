#include<iostream>
#include<string>

long fi_sum_odd(long n); //Declaración de la funcion de suma

int main(int argc, char **argv){
    long num = std::stol(argv[1]); //tomamos el valor de la linea de comandos
    std::cout<<fi_sum_odd(num)<<"\n";
    return 0;
}

long fi_sum_odd(long n){
    if(n < 2){ //verificamos que se encuentre dentro del rango
        std::cerr << "Numero menor al rango " << n << "\n";
        return 0;
    }
    //Definimos las variables para el cálculo de la secuencia y la suma de los terminos impares
    long sum = 1;
    long fi_1 = 1; 
    long fi = 2;
    for(long i = n-1; i > 2; i--){ 
        //Cálculo secuencia
        fi += fi_1;
        fi_1 = fi - fi_1;
        //Verificamos si es impar 
        if(fi % 2 != 0 ){
            //Verificamos que el siguiente valor de la secuancia no sea mayor al actual 
            if ((sum+fi)>=(n)){
                sum += fi;
                break;
            }
            sum += fi;
        }
        
    }
    return sum;
}