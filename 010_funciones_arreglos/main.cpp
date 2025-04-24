#include <iostream>
#include <stdint.h>

void set_array(uint8_t arr[], uint8_t size, uint32_t valor){ //si se pasa por referencia un arreglo y no se quiere modificar se debe usar CONST
    
    for(uint8_t i {0}; i<size;i++){
        arr[i]=valor;
    }
    
}

int main(void)
{
    uint8_t arreglo[]={2,3,1,7,5};
    
    for(auto s:arreglo){
        std::cout<<+s<<std::endl;
    }
    int size = sizeof(arreglo)/sizeof(arreglo[0]);
    set_array(arreglo,size,10);
    
    for(auto s:arreglo){
        std::cout<<+s<<std::endl;
    }
	return 0;
}
