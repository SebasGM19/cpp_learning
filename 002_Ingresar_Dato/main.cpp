#include <iostream>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits

#include <stdint.h>
#include <string.h>
#include "example_header.h"

//el std se usa para indicar que son funciones o clases propias del lenguaje

//#define car_lenght (2)// NO USAR ESTO, MEJOR USAR EL CONST

int car_lengh =2;

int main(void)
{
    int32_t mi_number {0};
    std::string nombre = "";
    float valor_dec = {0};
    char caracter_individual;
    char caracter_limitado[car_lengh];
    uint8_t lengh = sizeof(caracter_limitado)/sizeof(caracter_limitado[0]);
    uint32_t prueba_numero {0};
    holaMundo();
    
//    fflush(stdin);
    std::cout << "dime tu numeor favorito: ";
    std::cin >> mi_number;
	std::cin.ignore(); //este tanto el fflush vacian el bufer del salto de linea
    //lo que lo hace que pueda avanzar, colocarlo despues de cada ingreso de datos
    std::cout<< "tu numero fue: "<<mi_number<<std::endl; //el endl es para limpiar el buffer y hace un salto de linea


//    fflush(stdin);
    std::cout<<"ahora dime tu nombre: ";
    //std::cin>>nombre; // de esta manera solo lee hasta un espcaio
   std::getline(std::cin, nombre); //aqui lee todo hasta el salto de linea
//    std::getline(std::cin, nombre,'x'); //lee todo y solo captura hasta que encuentre una x
    std::cout<<"mucho gusto: "<<nombre<<"."<<std::endl;
    fflush(stdin); //este si usarlo para ingresar letras, cadenas
    
    
    std::cout<<"ahora dime un numero decimal: ";
    std::cin>>valor_dec;
    std::cin.ignore();
    std::cout<<"tu numero decimal es: "<<valor_dec<<std::endl;
    
    
//    fflush(stdin);
    std::cout<<"Por ultimo dime una letra: ";
    std::cin>>caracter_individual;
    std::cin.ignore();
    std::cout<<"la letra quue elegiste es: "<<caracter_individual<<std::endl;
    fflush(stdin); //usado para caracteres
    
    
    std::cout<<"ahora limitaremos a solo poder ingresar 2 carcteres"<<std::endl;
    std::cout<<"dime una palabra y tomare solo dos caracteres: ";
    std::cin.get(caracter_limitado,(lengh+1));
    std::cin.ignore(); //bueno cuando se limitan los caracteres o tambien fflush(stdin)
    std::cout<<"los caracteres fueron: "<<caracter_limitado<<std::endl;
    
    
    std::cout<<"por ultimo ya un numero: ";
    std::cin>>prueba_numero;
    std::cin.ignore();
    std::cout<<"tu numero fue: "<<prueba_numero<<std::endl;
    
    
    return 0;
}
