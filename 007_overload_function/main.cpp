#include <iostream>
#include <stdint.h>


void print(int entero);

void print (double flot);

void print(std::string cadena);

int main(void)
{
    print(10);
    print(12.1);
    print("sebas");
    return 0;
}


void print(int entero){ //mismo nombre en funcion pero distintos parametros y numero de parametros hacen un overload
    std::cout<<"imprimirmos un entero "<<entero<<std::endl;

}

void print (double flot){
    std::cout<<"imprimirmos un flotante "<<flot<<std::endl;

}

void print(std::string cadena){
    std::cout<<"imprimirmos una cadena "<<cadena<<std::endl;

}