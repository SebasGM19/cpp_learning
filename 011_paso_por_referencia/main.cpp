#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

//para arreglos el paso por referencia se debe de hacer con puntero
void set_array(uint8_t *arr, uint8_t size, uint32_t valor){ //si se pasa por referencia un arreglo y no se quiere modificar se debe usar CONST
    
    for(uint8_t i {0}; i<size;i++){
        arr[i]=valor;
    }
    
}

//para pasar vectores por referencia se debe de usar el & y trata como un vector normal para modificar su valor, si no se debe modificar ponerl el consr
void print_vector(std::vector<int>  &v){
    
    for(uint8_t i {0}; i<v.size(); i++){
        std::cout<<v[i]<<"\n";
        v[i] = 10; //error si lo hago const 
        v.clear();
    }
    
}

void cambio(std::string &v){

    for(uint8_t i{0}; i<v.size(); i++){
        std::cout<<v[i]<<std::endl;
    }

}


void change_value(uint32_t &valor){
    
    valor = 10;  //al poner el & automaticamente podemos usar sin usar *valor = 10
}



int main(void)
{
    uint32_t data = 2;
    std::cout<<data<<std::endl;
    
    change_value(data);
    std::cout<<data<<std::endl;

	return 0;
}
