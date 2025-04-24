#include <iostream>
#include "Personaje.h"


Personaje::~Personaje() {
//    std::cout<<"destructor"<<std::endl;
} 


void Personaje::set_Raza(std::string &race){
    this->raza=  race;
}

std::string Personaje::get_raza()const{
    return raza;
}

void Personaje::set_nombre(std::string &name){
    this->nombre=  name;
}

std::string Personaje::get_nombre() const{
    return nombre;
}

void Personaje::set_vida(uint32_t HP){
    this -> vida = HP;
}

uint32_t Personaje::get_vida() const{
    return vida;
}

void Personaje::set_poder(uint32_t MP){
    this->poder= MP;
}

uint32_t Personaje::get_poder()const{
    return poder;
}

void Personaje::talk(std::string &dialogo){
    std::cout<<dialogo<<std::endl;

}

void Personaje::Move(std::string &side){
    std::cout<<"me muevo a la "<<side<<std::endl;
}

bool Personaje::Is_alive()const{
    
    return get_vida() > 0;
}
