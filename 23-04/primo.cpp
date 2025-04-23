#include<iostream>

bool is_prime(int n){
    for(int i = n / 2; i>1; i--){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int num = 0; //Es recomendable usar long para enteros mas grandes
    bool primo = true;
    while(true){
        int num = 0;
        std::cout << "write your number: ";
        std::cin >> num;
        if(num < 1){
            std::cout<<"Your number should be grater than 1, try again\n";
            continue;
        }else{
        primo = is_prime(num);
        break;
        }
    }
    if(primo){
        std::cout<<"\n Your number is prime\n";
    }else{
        std::cout<<"\n Yout number is not prime\n";
    }
    
}