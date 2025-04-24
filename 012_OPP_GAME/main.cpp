#include <iostream>
#include "Personaje.h"
#include <stdint.h>

void funcionX(Personaje &p){ //esta funcion puede acceder a toda la informacion de un objeto personaje que se le pase
    std::cout<<p.nombre<<std::endl;
    
}

int main(void){

     Personaje *villano = new Personaje("sebas","mexica",100,23);
     //tambien podemos hacer variables de tipo clase
     Personaje heroe;
//    Personaje* villano2 = new Personaje();
    villano->set_vida(120);
    std::cout<<villano->get_vida();

    delete villano; //llamamos al destructor
//    delete villano2; //llamamos al destructor



    return 0;
}