#include <iostream>
#include <stdint.h>


//#define car_lenght (2)// NO USAR ESTO, MEJOR USAR EL CONST

int const car_lengh {2}; //las const en ningun lugar se pueden modificar incluso locales como en C
int main(void)
{
int const entero {20}; //de esta manera se inicializaran ahora en adelante

float flotante {2.322f};
long double mucho {2.7e10};

double multi {entero*flotante};

bool istrue {true};

    std::cout<<"tamano"<<sizeof(uint32_t)<<std::endl;
    

	return 0;
}