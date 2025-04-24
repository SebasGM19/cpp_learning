#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <string>

//ejemplo de polimorfismo

////////////////////clase padre////////////////
class Persona{
private:
      std::string nombre;
      unsigned int edad;

public:
    Persona(std::string nombre_,unsigned int edad_);
     virtual ~Persona(); //viertual siempre en el destructor padre 
    virtual void mostrar(void)const;
};


Persona::Persona(std::string nombre_,unsigned int edad_):nombre(nombre_),edad(edad_){
    
}
Persona::~Persona(){ //destructo persona
//    std::cout<<"Persona"<<std::endl;
}

void Persona::mostrar(void)const{ //esto es el polimorfismo, metodos con el mismo nombre
        std::cout<<"nombre: "<<nombre<<std::endl;
        std::cout<<"edad: "<<edad<<std::endl;
    
}
////////////////////////////////////////clase hija 1/////////////////////////////////

class Alumno : public Persona{
    
private:
    unsigned int nota;

public:
    Alumno(std::string nombre_,unsigned int edad_,unsigned int nota_);
    ~Alumno();
    void mostrar(void)const override; //cuando se coloca el override solo se coloca en el prototipo
  
};


    Alumno::Alumno(std::string nombre_,unsigned int edad_,unsigned int nota_):Persona(nombre_,edad_),nota(nota_){
        
    }
    Alumno::~Alumno(){//destructor alumno
//            std::cout<<"Alumno"<<std::endl;

    }
    
    void Alumno::mostrar(void)const{
        Persona::mostrar();     //si los atributos son private, tengo que llamar a la funcion 
                                //dentro de la clase que ejecute lo que quierp
                                
//        std::cout<<"nombre: "<<nombre<<std::endl;
//        std::cout<<"edad: "<<std::to_string(edad)<<std::endl; 

                                //cuando los atributos son protect se pueden usar aqui
        std::cout<<"nota "<<nota<<std::endl;
    
    }
////////////////clase hija 2///////////////////////






////////////////////////////////////__MAIN__///////////////////////////////////
int main(void)
{
    
    int* data = new int[5];
    data[0]=45;
    std::cout<<data[0]<<std::endl;
    std::string in_name = "";
    unsigned int in_edad {0};
    unsigned int in_nota = 0;
    
    Alumno* sebas[3]; 
    
    for(uint8_t i = 0; i<3; i++){
        
        std::cout<< "nombre alumno "<<i+1<< " ";
        std::getline(std::cin,in_name);
        fflush(stdin); //este si usarlo para ingresar letras, cadenas
        std::cout<<std::endl;
	
        std::cout<< "edad alumno "<<i+1<< " ";
        std::cin>>in_edad;
        fflush(stdin); //este si usarlo para ingresar letras, cadenas
        std::cout<<std::endl;

        std::cout<< "nota alumno "<<i+1<< " ";
        std::cin>>in_nota;
        fflush(stdin); //este si usarlo para ingresar letras, cadenas
        std::cout<<std::endl;
        
        sebas[i]= new Alumno(in_name,in_edad,in_nota);
        
        in_name = "";
        in_edad =0;
        in_nota =0;
    }
    
    
    
     for(uint8_t i =0; i<3; i++){
         sebas[i]->mostrar();
     }
    
    for(uint8_t i =0; i<3; i++){
         delete sebas[i];
     }    


//concatenar cadenas
//std::string cadena1 = "hola ";
//
//std::string cadena2 = "mundo";
//
//std::string strFinal = cadena1+cadena2;
//
//std::cout<<strFinal;
    
	return 0;
}
