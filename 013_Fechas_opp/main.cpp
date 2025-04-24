#include <iostream>
#include <stdint.h>

class Celebracion{
    
protected:
    uint8_t day;
    uint8_t month;
    uint16_t year;
    std::string name;

public:
    Celebracion(uint8_t day_,uint8_t month_,uint16_t year_, std::string name_):
    day(day_),month(month_),year(year_),name(name_){
        
    }
    virtual ~Celebracion(){ //el destructor de una clase padre siempre debera ser virtual
    std::cout<<"ADIOS "<<name<<std::endl;
    }
    
    void get_miCelebracion(void)const{
       std::cout<<name<< " dia: "<<std::to_string(day)<<" mes: "<<(unsigned int)month<<std::endl;
    }
    
    
    void get_str_of_day(void)const{
        std::string data;
        data=std::to_string(day);
        std::cout<<data<<std::endl;
    }
    
    virtual void get_info()const { //es virtual cuando es un metodo polimorfismo
        std::cout<<"la fecha sera: "<<std::to_string(day)<<" "<<std::to_string(month)<<" "<<std::to_string(year)<<std::endl;
        std::cout<<"el nombre es:  "<<name<<"\n"<<std::endl;

    }
    
    
};


class Fiesta : public Celebracion{
    
private:
    std::string evento;
    uint32_t invitados;
    
public:
    Fiesta(uint8_t day_,uint8_t month_,uint16_t year_,
            std::string name_,std::string evento_,uint32_t invitados_):
            Celebracion(day_,month_,year_,name_),
            evento(evento_),invitados(invitados_) {
            }
    

    ~Fiesta(){
        std::cout<<"se acabo el evento "<<evento;
    }
    
    
    
    void get_info(void)const override{ //para usar el override deben tener lo mismo en el nombre y parametros y ser de una clase hija que use un nombre igual al padre
        std::cout<<"la fecha sera: "<<std::to_string(day)<<" "<<std::to_string(month)<<" "<<std::to_string(year)<<std::endl;
        std::cout<<"el festejo se llama: "<<evento<<std::endl;
        std::cout<<"la cantidad de invitados son: "<<std::to_string(invitados)<<std::endl;
    }
    
};

int main(void)
{
    Celebracion* cumple = new Celebracion(14,11,2024,"cumple sebas");
    
//    cumple->get_miCelebracion();
//    cumple->get_str_of_day();
cumple->get_info();    
    
    Fiesta* navidad = new Fiesta(24,12,2024,"Navidad","fiesta de navidad",20);
    
    navidad->get_info();
    
//    delete navidad;
//    delete cumple;
	return 0;
}
