#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_

// #include <iostream>
#include <string>
#include <stdint.h>

class Personaje{
    friend void funcionX(Personaje &p);
    private:
        std::string nombre;
        std::string raza;
        uint32_t poder;
        uint32_t vida;

    public:
        //override de constructores, segun los parametros que se coloquen va asignarse el constructor
        //en todos los casos se colocan valores
//        Personaje(){ //constructor simple sin argumentos
//            this->nombre = "None";
//            this->raza = "None";
//            this->poder = 100;
//            this-> vida = 1000;
//        }
//        Personaje(std::string nombre, std::string raza, uint32_t poder, uint32_t vida){
//            this->nombre =nombre;
//            this->raza = raza;
//            this-> poder = poder;
//            this-> vida = vida; 
//        }

//mejor opcion para inicializar un constructo
        Personaje():nombre("None"),raza("None"),poder(100),vida(1000){
            
        }
        Personaje(std::string nombr, std::string raz, uint32_t pode, uint32_t vid)
        : nombre(nombr),raza(raz),poder(pode),vida(vid){

        }
        
        //destructor
        ~Personaje();
        
        //prototipe of functions
        void set_Raza(std::string &race);
        std::string get_raza()const;

        void set_nombre(std::string &name);
        std::string get_nombre()const;

        void set_vida(uint32_t HP);
        uint32_t get_vida()const;

        void set_poder(uint32_t MP);
        uint32_t get_poder()const;

        void talk(std::string &dialogo);
        void Move(std::string &side);
        bool Is_alive()const;

        //descructor

};

#endif // _PERSONAJE_H_
