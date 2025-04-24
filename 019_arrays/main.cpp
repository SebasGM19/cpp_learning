#include <iostream>
#include <stdint.h>


int const  MAX_LENGHT =100;



//void arregloImpares(uint8_t *arreglo_original, uint32_t& lenght, uint8_t*array_to_pass, uint32_t& num_of_odd){
//    uint32_t count_to_exit =0;
//    uint32_t num_of_odd_numbers =0;
//
//    while(count_to_exit<lenght){
//
//        if(*arreglo_original & 1){
//            *array_to_pass = *arreglo_original;
//            num_of_odd_numbers++;
//            array_to_pass++;
//        }
//        arreglo_original++;
//        count_to_exit++;
//    }
//
//    num_of_odd= num_of_odd_numbers;
//
//}

//para arreglos si es pasar com puntero, no utilizar el &
void arregloImpares(uint8_t *arreglo_original, uint32_t& lenght, uint8_t *array_to_pass, uint32_t& num_of_odd){
    uint32_t count_to_exit =0;
    uint32_t num_of_odd_numbers =0;

    while(count_to_exit<lenght){

        if(arreglo_original[count_to_exit] & 1){
            array_to_pass[num_of_odd_numbers] = arreglo_original[count_to_exit];
            num_of_odd_numbers++;
        }
        count_to_exit++;
    }

    num_of_odd= num_of_odd_numbers;

}


int main(void)
{
    uint8_t arreglo[]={1,2,3,4,5,6,7,8,11,14,15,12,18,27,48};
    uint8_t arreglo2[MAX_LENGHT];
    uint32_t lenght = sizeof(arreglo)/sizeof(arreglo[0]);
    uint32_t odds=0;
    arregloImpares(arreglo,lenght,arreglo2,odds);

    std::cout<<"inicio"<<std::endl;

    for(uint32_t i =0; i< odds; i++){
        std::cout<<"num "<<i+1<<": "<<static_cast<uint32_t>(arreglo2[i])<<std::endl;

    }
    std::cout<<"FIN"<<std::endl;
	return 0;
}
