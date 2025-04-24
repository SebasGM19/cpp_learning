#include <iostream>
#include <stdint.h>
#include <vector>

//para modificar vectores si debo de utilzar el & si quiero sobre escribirlos
void print_vector(std::vector<int> &v){
    
    for(uint8_t i {0}; i<v.size(); i++){
        std::cout<<v[i]<<"\n";
        v[i] = 10;
        v.clear();
    }
    
}

int main(void){
    
    std::vector<int> valores(5,10); //se declaran 5 valores con valor de 10

    std::vector<std::vector<uint8_t>> matriz_vector{{2,3},{1,7}};
    matriz_vector.at(1).push_back(10);
    std::cout<<+matriz_vector.at(1).at(0);
    std::cout<<+matriz_vector.at(1).at(2);
    
    
    std::vector<int> otroVector {66,12,-13,-10};
    print_vector(otroVector);
    print_vector(otroVector);


    return 0;
}


