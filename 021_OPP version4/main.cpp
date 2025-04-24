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

        void info(void){
            std::cout<<"periferico: "<<this->name<<std::endl;
            std::cout<<"usando el pin: "<<this->pin<<std::endl;
        }
    

};




int main(void){
    std::cout<<"hola mundo"<<std::endl;
    
    return 0;
}