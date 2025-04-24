#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
//desarrollar los elementos de un juego
//personaje principal, enemigos, armas, escudos, posiones, items son clases y de estas clases voy a creas instancias

//clase armas se podran heredar, espadas, pistola, martillo, de la clase espada se podran poner los tipos

class Personaje{
    
public:
//private:
    std::string nombre;
    std::string raza;
    uint32_t poder;
    uint32_t vida;
    uint32_t defensa;
    

    void talk(std::string dialogo){
        std::cout <<dialogo<<std::endl;
    }
    
    void move();
    bool is_alive(void);
    
};


int main(void)
{
    Personaje *heroe= new Personaje();
    Personaje *villano = new Personaje();
    Personaje *personajes[2];
    
    villano->poder = 12;
    villano->nombre = "ZeusZeusZeusZesus";
    villano->talk("soy malo");
    
    //declarar vector de objetos instanciados a Clase Personaje
//    std::vector<Personaje> vec_personajes{villano};
//    vec_personajes.push_back(heroe);
    std::cout<<villano->nombre<<std::endl;


	return 0;
}
