#include <iostream>
#include <stdint.h>


class Carta{
        
private:
    
        std::string nombre= "";
        uint32_t largo {0};
        uint32_t ancho {0};
        std::string color = "";
    
public:

        Carta():nombre("NONE"),largo(70),ancho(30),color("Cafe"){
            
        }
        Carta(std::string nombre_,uint32_t  largo_,uint32_t ancho_, std::string color_) //constructor
        : nombre(nombre_), largo(largo_),ancho(ancho_),color(color_){
            
        }
        
        ~Carta(){
            //destructor
        }
        
        
        void Set_nombre(std::string const & new_nombre){//si pasamos un valor por referencia que no se va a modificar, lo mejor es ponerle const
            this->nombre = new_nombre;
        }
        
        std::string get_nombre(void)const{
            return nombre;
        }
        
        void set_tamano(uint32_t const *largo,uint32_t const *ancho){
            if(largo != nullptr && ancho != nullptr){
                this->ancho = *ancho;
                this->largo = *largo;
            }
        }
        
        void get_tamano(uint32_t *largo_,uint32_t *ancho_)const{
            if(largo_ !=nullptr){
                *largo_ = this->largo;
            }
            
            if(ancho_!= nullptr){//asegurarse que si se usa punteros, primero checar que no sean nulos
                *ancho_ = this->ancho;
            }
        }
        
        //tambien puede ser de esta manera
        void get_otro_tamano(uint32_t &largo_,uint32_t &ancho_)const{ //el const es bueno usarlo en getters
            largo_ = this->largo;
            ancho_ = this->ancho;
        }
        
        
    };



class MagicCart : public Carta{
    
};


int main(void)
{
            
    Carta* micarta = new Carta("dragon",40,50,"roja");
    
    Carta maso[2];//aqui tomara el valor del constructor por default por que no es puntero*
    Carta *maso2[2];
    maso2[0] = new Carta("enano",1,2,"verde");
    maso2[1] = new Carta("trol",1,2,"rojo");

    std::cout<<maso[0].get_nombre() <<std::endl;
        std::cout<<maso2[0]->get_nombre() <<std::endl;
        std::cout<<maso2[1]->get_nombre() <<std::endl;

    std::cout<<micarta->get_nombre();
    
    delete micarta;
    delete maso2[0];
        delete maso2[1];

//    delete maso; //no se borra algo que no se crea con new
    
    
	return 0;
}
