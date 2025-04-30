#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <memory>  // <- para std::unique_ptr

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
        size_t capacity;
        int pos_actual {0};
        int datos_acumulados {0};
        std::vector <int> miVector;

    public:

    CirculaBuff(size_t set_capacity) : capacity(set_capacity), miVector(set_capacity,0){}

    ~CirculaBuff() = default;

    void Insertar(size_t valor){
        this->datos_acumulados++;

        if(static_cast<size_t>(this->datos_acumulados) > capacity){
            this->pos_actual = 0;
            this->datos_acumulados = 1;
        }

        this->miVector[this->pos_actual] = valor;
        this->pos_actual++;
    }

    int posicion_actual(){
        return pos_actual;
    }

    int averange(void){
        int suma =0;
        for(auto data: miVector){
            suma+=data;
        }
        return suma/miVector.size();
    }

    void print_vector_data(){
        for(auto data: miVector){
            std::cout<<data<<", ";
        }
        std::cout<<std::endl;
    }

    size_t get_capacity(void){
        return capacity;
    }

};


class Sensor{
    private:
        std::string ID;
        CirculaBuff mi_buffer;

    public:
        Sensor(std::string set_id, size_t set_capacity):ID(set_id),mi_buffer(set_capacity){}

        ~Sensor() = default; 

        uint32_t read(void){
            srand(time(NULL));
            int valor = rand()/10;
            std::cout<<"valor optenido y guardado: "<<valor<<std::endl; 
            mi_buffer.Insertar(valor);
            return valor;
        }

        int get_averange(){
            return mi_buffer.averange();
        }

        void print_data(){
            mi_buffer.print_vector_data();
        }

        uint32_t get_capacity(){
            return static_cast<uint32_t>(mi_buffer.get_capacity());
        }

};

class SensorManager{

    private:
    std::map<std::string, std::unique_ptr<Sensor>> Mapa_de_sensores; //cuando usemos una clase como valor de map
                                                                    //poner que sea unique_ptr para que se pueda liiberar la memoria cuando no se use mas

    public:

        SensorManager(){};

        ~SensorManager() = default;

        void addSensor(std::string ID, size_t capacity){

            Mapa_de_sensores[ID] = std::make_unique<Sensor>(ID,capacity);
        
        }

        uint32_t ReadSensor(std::string ID){

            if (Mapa_de_sensores.find(ID) != Mapa_de_sensores.end()) { //el .end es el carater null despues del ultimo elemento, 
                                                                        //si .find(ID) no encuenta el valor retorn ese caracter null .end
                return Mapa_de_sensores[ID]->read();

            } else {
                std::cout << "Sensor con ID " << ID << " no encontrado." << std::endl;
            }

            return 0;
        }

        void print_data(std::string ID){
            if (Mapa_de_sensores.find(ID) != Mapa_de_sensores.end()) { //el .end es el carater null despues del ultimo elemento, 
                //si .find(ID) no encuenta el valor retorn ese caracter null .end
                Mapa_de_sensores[ID]->print_data();

            } else {
                std::cout << "Sensor con ID " << ID << " no encontrado." << std::endl;
            }
        }

        void print_all_sensor(void){
            for(const auto &one_sensor : Mapa_de_sensores){ //en este tipo de for se usa el & para el iterador
                std::cout<<one_sensor.first<<std::endl;
            }
        }


};

int main(void){
    SensorManager * manager = new SensorManager();
    
    manager->addSensor("sht20",3);
    manager->addSensor("NPK",5);

    manager->print_all_sensor();
    
    manager->ReadSensor("sht20");
    manager->ReadSensor("sht20");
    manager->ReadSensor("sht20");
    manager->ReadSensor("sht20");

    manager->print_data("sht20");

    delete manager;

    return 0;

}