#include <iostream>
#include <stdint.h>
#include <string>


class Periferico{
    protected:

        std::string name;
        uint8_t pin;
        
        Periferico(std::string set_name,uint8_t set_pin): name(set_name),pin(set_pin){
        }
        
        ~Periferico() = default;

        void info(){

        }
    

};




int main(void){
    std::cout<<"hola mundo"<<std::endl;
    
    return 0;
}