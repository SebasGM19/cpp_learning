#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>


/*              Instrucciones

->Descripción del ejercicio

    1. Clase CircularBuffer<T>

        Plantilla genérica que almacena hasta capacity elementos de tipo T.

        Internamente usa un std::vector<T> de tamaño fijo.

        Mantiene dos índices: head (dónde se escribe la siguiente lectura) y size (número actual de lecturas almacenadas).

    2. Clase Sensor

        Simula un sensor que genera un valor entero (int read() devuelve un número pseudoaleatorio).

    3. Clase SensorManager

        Contiene un CircularBuffer<int> para cada sensor registrado.

        Métodos:

            void addSensor(int id, size_t capacity);

            void capture(int id); // Lee del sensor y guarda en el buffer

            double average(int id) const; // Calcula el promedio de las lecturas actuales


->Requisitos y pasos

    1. Definir CircularBuffer<T>

        Constructor que recibe capacity.

        Método void push(const T& value): inserta el valor en la posición head, actualiza head (con wrap-around) y, si está lleno, sobrescribe el más antiguo.

        Métodos de consulta como size(), capacity() y un método para iterar las lecturas.

    2. Implementar Sensor

        Constructor recibe un ID.

        int read(): retorna un valor simulado (por ejemplo, rand() % 100).

    3. Implementar SensorManager

        Internamente un std::map<int, CircularBuffer<int>> buffers; (o, si prefieres concentrarte en std::vector, puedes usar un std::vector<std::pair<int, CircularBuffer<int>>>).

        Al registrar un sensor, creas su buffer.

        capture(id): invoca read() y lo inserta.

        average(id): recorre el buffer y retorna el promedio de las lecturas.

    4. Programa principal

        Crea el SensorManager.

        Registra 2–3 sensores con diferentes capacities.

        En un bucle, cada 100 ms captura lecturas y, cada 1 s, imprime (por printf/UART) el promedio de cada sensor.

->Extensiones opcionales

    Usar std::list para mantener un histórico ilimitado de eventos de alarma si el valor supera un umbral.

    Emplear std::map<std::string, float> para almacenar parámetros de calibración por nombre de sensor.

    Añadir métodos para vaciar buffers o cambiar capacidad en tiempo de ejecución.


*/


class CirculaBuff{
    private:
        int capacity;
        int actual;
        int size;
        std::vector <int> miVector;

    public:

    CirculaBuff(int set_capacity) : capacity(set_capacity), miVector(set_capacity,0){
        
    }


};


class Sensor{

};

class SensorManager : private CirculaBuff{


};

int main(void){
    std::cout<<"hola mundo"<<std::endl;
    
    return 0;
}