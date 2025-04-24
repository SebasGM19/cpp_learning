#include <iostream>
#include <stdint.h>

class Persona{
private:
    std::string nombre;
    int edad;
public:
    //constructor
    Persona(std::string name, int age){
        this->nombre = name;
        this->edad = age;
    }
    virtual void hablar(){ //el virtual va en la clase padre
        std::cout<<"soy "<<nombre<<std::endl;
    }
    std::string get_name(){
        return nombre;
    }
    void set_name(std::string& new_name){
        this->nombre=new_name;
    }

};

class Alumno:public Persona{
private:
    int nota;
    std::string nombre2,aux_name;
    
public:
    Alumno(std::string name, int age, int notaa):Persona(name,age){
        this->nota = notaa;
//        this->nombre2 =_nombre2;
    }
    void hablar()override{
//        Persona::hablar();
        nombre2=Persona::get_name();
        std::cout<<"soy " <<nombre2<< " un alumno y saque: "<<nota<<std::endl;
        aux_name="felipe";
        set_name(aux_name);
        nombre2=Persona::get_name();
        std::cout<<"ahora soy " <<nombre2<< " un alumno y saque: "<<nota<<std::endl;
        
    }

};


class Profesor:public Persona{
private:
    std::string materia;
public:
    Profesor(std::string name,int age, std::string mate): Persona(name,age){
        this->materia = mate;
    }
    
    void hablar()override{
        Persona::hablar();
        std::cout<<"soy el profesor de "<<materia<<std::endl;
    }  
  
};

class Perro:public Persona{
private:
    std::string wow;
public:
    Perro(std::string name, int age, std::string _wow):Persona(name,age){
        this->wow = _wow;
    }
    void hablar()override{
        
        }
};

int main(void)
{
    Alumno* mi_persona[3];
    
    mi_persona[0] = new Alumno("sebas",20,10);
    mi_persona[0]->hablar();
    
    Profesor *otra_persona= new Profesor("daniel",30,"matematicas");
    otra_persona->hablar();
	
    return 0;
}
