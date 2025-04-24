#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <memory>


//#################################### sobrecarga (overloading) y sobreescritura (override) ###################################333


// int main(void){
    
//     uint32_t volatile * data = (uint32_t volatile*)(0x40000);
    
//     uintptr_t data = (0x42);
//     return 0;
// }


//#################################### smart pointers ###################################333
//requiere:  #include <memory>
//class Myclass{
//public:
//
//    Myclass(){ 
//        }
//    ~Myclass() = default;
//    
//    void mostrar(uint32_t a, uint32_t b){
//        std::cout<<a<<" y "<<b<<std::endl;
//    }
//    
//    
//};
//
//int main(void){
//    
//    // std::unique_ptr: Es un puntero exclusivo.
//    std::unique_ptr<Myclass> mi_objet = std::make_unique<Myclass>(); //dentro del () van los argumentos del construcor
//    mi_objet->mostrar(3,1);
//    Myclass * mio  = mi_objet;
//    
//    mio->mostrar(11,11);
//
//    //std::shared_ptr: Es un puntero compartido.
//    std::shared_ptr<Myclass> ptr1 = std::make_shared<Myclass>();
//           
//    std::shared_ptr<Myclass> ptr2 = ptr1; //se copea la referencia del puntero tambien funciona al poner auto
//    
//    ptr2->mostrar(5,6);
//    ptr1->mostrar(9,1);
//
//
//    
//    return 0;
//}



//######################################3 define #########################################33
//#define day (1)
//
//int main(void){
//    
//
//    int aux =0;
//  #if day
//    aux=100;
//  #endif  
//  
//  #if !day
//      aux=30;
//  #endif
//  
//  std::cout<<aux<<std::endl;
//  
//    return 0;
//}



//################################# try catch throw manejo de excepciones ##############################
//void testRango(int index) {
//    if (index > 10) {
//        throw std::out_of_range("out of range");
//    }
//    std::cout << "Índice dentro del rango" << std::endl;
//}
//
//int main(void){
//
//    //_________excepcion por throw intencional_________
//    try {
//        // Código que puede generar una excepción
//        testRango(12);
//    } catch (const std::exception& e) {
//        // Manejo de la excepción: se captura el error y se imprime
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//    
//    
//    
//    //excepcion de vectore
//    std::vector <uint32_t> vec = {1,4,2};
//    try {
//        std::cout<<vec.at(5)<<std::endl;
//    } catch (const std::exception& e) {
//        std::cout << "Error: " << e.what() << std::endl;
//    }
//    
//    return 0;
//}


//########################################### map (diccionario) ##################################
//int main(void)
//{
//
//    std::map<std::string, std::string> my_dict_s_s;
//
//
//    my_dict_s_s["COM1"] = "P1"; ///manera para agregar datos
//    my_dict_s_s["COM2"] = "P2";
//    
//    for(auto valores:my_dict_s_s){
//        std::cout<<"Key: "<<valores.first<<", Value: "<<valores.second<<std::endl;
//    }
//    
//  std::cout<<my_dict_s_s.size()<<std::endl;
//
//  std::cout<<my_dict_s_s.at("COM1")<<std::endl; //usando at es mejor consultar, ya que no agrega esa llave en caso de no existir, 
//                                                //regresa el valor de esa llave, si la llave no existe regresa una exepcion
//  
//  std::cout<<my_dict_s_s["COM4"]<<std::endl; //aqui se creara el espacio para guardar
//
//  std::cout<<my_dict_s_s.size()<<std::endl;
//
//    for(auto valores:my_dict_s_s){
//        std::cout<<"Key: "<<valores.first<<", Value: "<<valores.second<<std::endl;
//    }
//    
//    my_dict_s_s.erase("COM2");
//    
//    for(auto valores:my_dict_s_s){
//        std::cout<<"Key: "<<valores.first<<", Value: "<<valores.second<<std::endl;
//    }
//
//    std::cout<<"_________________"<<std::endl;
//
//    auto it = my_dict_s_s.find("COM1"); // mejor opcion para validar si existe una llave, se puede evaluar con el if
//                                        //aqui lo que guarda auto es "std::map<std::string,std::string>::iterator it"
//    if (it != my_dict_s_s.end()) {
//        std::cout << it->second << std::endl;
//    } else {
//        std::cout << "La llave no existe." << std::endl;
//    }
//    
//
//    /////////___________otro MAP con valor entero y string______________ ///////////////
//    std::cout<<"________________________"<<std::endl;
//
//    std::map<int, std::string> my_dict_i_s = {{2,"sebas"},{3,"emily"},{4,"dany"}}; //manera de inicializar 
//
//    my_dict_i_s.insert({0,"manzana"});
//    
//    for(auto valores:my_dict_i_s){
//        std::cout<<"Key: "<<valores.first<<", Value: "<<valores.second<<std::endl;
//    }
//    
//    my_dict_i_s.erase(2);
//    
//    for(auto valores:my_dict_i_s){
//        std::cout<<"Key: "<<valores.first<<", Value: "<<valores.second<<std::endl;
//    }
//	return 0;
//}
//

////################################################ list #####################################################
//int main(void)
//{
//    std::list <uint32_t > lista_entera = {2,3,4,4};
//    std::list <uint32_t > lista_entera_vacia; //definicion de lista pero vacia
//
//    std::list <std::string> lista_cadenas = {"hola","mundo"};
//
//
//    lista_entera.push_back(22);
//    lista_entera.push_front(11);
//
//    for(auto i : lista_entera){
//         std::cout<<"lista enteros: "<<i<<std::endl;
//
//    }
//
//     std::cout<<"lista vacia elementos: "<<lista_entera_vacia.size()<<std::endl;
//
//    lista_cadenas.push_back("emily");
//    for(auto i : lista_cadenas){
//         std::cout<<"lista nombres: "<<i<<std::endl;
//
//    }
//    
//    auto it = lista_cadenas.begin(); // Inicio de la lista std::list <std::string>::iterator it
//
//    std::advance(it,1); //avanza en 1 el pasa de hola -> mundo
//    std::cout<<"elemento especifico: "<<*it<<std::endl; //debe de llamarse como puntero
//     
//    std::advance(it,-1); //retrocede 1 pasa de mundo ->hola
//    std::cout<<"elemento especifico: "<<*it<<std::endl;
//
//  
//	return 0;
//}

//############################################# vectores ########################################
//void Mysort(std::vector<uint32_t> & new_vect){
//    
//    uint32_t aux=0;
//    
//    for(uint32_t i =0; i<new_vect.size();i++){
//        for(uint32_t j = 1+i; j<new_vect.size();j++){
//            if(new_vect[i] >= new_vect[j]){
//                
//                aux = new_vect[i];
//                new_vect[i] = new_vect[j];
//                new_vect[j] = aux;
//
//            }
//        }
//    }
//    
//}
//
//int main(void)
//{
//
//    std::vector <std::string> Vletras;
//    std::vector <uint32_t> vec2 (5,10); // 5 elementos con valor de 10
//    std::vector <float> vec3 (10);  //vector con 10 elementos vacios
//    std::vector <uint32_t> vec4 ={3,1,5}; //vector inicizalizado personalmente 
//    
//    for(uint32_t i:vec4){
//        std::cout<<i<<std::endl;
//    }
//
//    Mysort(vec4);   
//    std::cout<<"_________"<<std::endl;
//
//
//    
//    std::sort(vec4.begin(),vec4.end());//usando el metodo sort de libreria
//    
//    for(uint32_t i:vec4){
//        std::cout<<i<<std::endl;
//    }
//    
//    
//
//    vec4.swap(vec2);
//    
//    for(auto i:vec3){
//        std::cout<<i<<std::endl;
//    }
//    
//    for(uint32_t i:vec2){
//        std::cout<<i<<std::endl;
//    }
//    
//    Vletras.push_back("hola");
//        Vletras.push_back("mundo");
//
//    std::cout<<Vletras.size()<<std::endl;
//    
//    std::cout<<Vletras.at(0)<<std::endl;
//    std::cout<<Vletras[1]<<std::endl;
//    
//        Vletras.pop_back();
//        
//            std::cout<<Vletras.size()<<std::endl;
//    
//    std::cout<<Vletras.at(0)<<std::endl;
//    
//
//  
//	return 0;
//}


// #################################### Uso de * y & como y cuando usarlos ##########################
//void cadena(uint8_t* var){ //para cadenas de caracteres de numeros y demas es *
//    
//    for(uint8_t i =0; i<10; i++){
//        
//        var[i] = 1;
//    }
//    
//}
//
//void cadena(std::string & var){ //para string y para variables normales siempre es pasara el &
//    
//    for(uint8_t i =0; i<10; i++){
//        
//        var[i] = (char)'h';
//    }
//    
//}
//
//int main(void)
//{
//uint8_t cad0[10] = {4,4,4,4,4,4,4,4,4,4};
//
//std::string cad = "1234567890";    
//        
//        cadena(cad);
//        
//    for(char i:cad){
//        std::cout<<(char)i<<std::endl;
//    }
//  
//	return 0;
//}


//######################################### ejemplo clase ################################
class Actuador{
    protected:
        std::string Id;
        uint32_t valor;
        
        
        Actuador(std::string set_Id,uint32_t set_valor):Id(set_Id),valor(set_valor){
            
        }
        virtual ~Actuador() = default; //al no tener una rutina extra que se destrulla por default
        
        std::string get_Id(void)const;
        void set_params(std::string const &set_Id, uint32_t const set_valor); //este lleva virtual?
        

};

std::string Actuador::get_Id(void)const{
   return Id;
}

void Actuador::set_params(std::string const &set_Id, uint32_t const set_valor){
   this->Id = set_Id;
   this->valor = set_valor;
   std::cout<<"si"<<std::endl;
}



class Motor : private Actuador{
    protected:
        uint32_t rpm;
    public:
        using Actuador::set_params; //al tener set params en la clase padre pero con distintos parametros es un overload no un override

        Motor(std::string set_id,uint32_t set_valor,uint32_t set_rpm):Actuador(set_id,set_valor),rpm(set_rpm){
            
        }
        
        ~Motor() = default;
        
        void set_params(std::string const &new_name, uint32_t new_valor, uint32_t new_rpm); //para ser override
        //se tiene que tener el mismo nombre, mismo orden numero, tipo y orden de datos si no no se utiliza
        
        void get_data(void);
   
};

void Motor::set_params(std::string const &new_name, uint32_t new_valor, uint32_t new_rpm){
    Actuador::set_params(new_name, new_valor);
    this->rpm = new_rpm;
    std::cout<<"No"<<std::endl;
}

void Motor::get_data(void){
    std::cout<<"ID: "<<this->Id<<std::endl;
    std::cout<<"valor: "<<this->valor<<std::endl;
    std::cout<<"rpm: "<<this->rpm<<std::endl;
}


int main(void)
{

   Motor * my_moto = new Motor("sebas", 32, 1000);
   
   my_moto->get_data();
   my_moto->set_params("emily",443,2000);
   my_moto->get_data();
     
    delete my_moto;  
 
	return 0;
}



//##############################  factrorial de un numero ########################################3
//uint32_t dataaa(int a){
//    uint32_t resul =1;
//    
//    
//    for(uint32_t i = a; i>0;i--){
//        resul = i*resul;
//    }
//    
//    return resul;
//
//}

//int main(void)
//{
//uint32_t a=1,b = 2, cuenta =0;
//
//std::cout<<dataaa(6)<<std::endl;
//        
//  
//	return 0;
//}




//################################  intercambiar dos variables por referencia #######################3
// void cambio_de_valor(uint32_t &x,uint32_t &y){
//    uint32_t aux =0;
// //    aux = x;
// //    x = y;
// //    y = aux;
//    x = x^y;
//    y = x^y;
//    x = x^y;

// }

// int main(void)
// {
//     uint32_t d1=99,d2 = 34;
   
//    std::cout<<"d1: "<<d1<<std::endl;
//    std::cout<<"d2: "<<d2<<std::endl;

//     cambio_de_valor(d1,d2);  

//    std::cout<<"d1: "<<d1<<std::endl;
//    std::cout<<"d2: "<<d2<<std::endl;  
// 	return 0;
// }
