#include <iostream>
#include <stdint.h>
#include <string.h>


typedef enum{
    
    pin_0,
    pin_1,
    pin_2,
    pin_3,
    pin_4,
    pin_5,
    pin_6,
}gpios_t;

class I2C{
    
    protected: //un driver debera tener protect y que sus herencias solo puedan ser aceddidas por medio de metodos
    gpios_t SCL_pin;
    gpios_t SDA_pin;
    uint32_t baudrate;
    std::string name;
    //public: 
   
    //constructores, el primero es el default cuando no se le pasen argumentos
    I2C():SCL_pin(pin_2),SDA_pin(pin_3),baudrate(100000),name("default"){
        
    } 

    //constructor cuando se le pasen argumentos
    I2C(gpios_t set_scl_pin,gpios_t set_sda_pin, uint32_t set_baudrate,std::string set_name):
    SCL_pin(set_scl_pin),SDA_pin(set_sda_pin), baudrate(set_baudrate),name(set_name){
        
    }
     
    
    //destructor
    virtual ~I2C() = default;

    virtual void configure_params(gpios_t set_scl_pin,gpios_t set_sda_pin, uint32_t set_baudrate,std::string set_name);
    void get_params(void);
    uint32_t write(uint8_t addres, const uint8_t *data, uint32_t data_size);
    uint32_t read(uint8_t addres, uint8_t *data,  uint32_t data_get);
    
};




void I2C::configure_params(gpios_t set_scl_pin,gpios_t set_sda_pin, uint32_t set_baudrate,std::string set_name){
    this -> SCL_pin = set_scl_pin;
    this -> SDA_pin = set_sda_pin;
    this -> baudrate = set_baudrate;
    this -> name = set_name;
}

void I2C::get_params(void){
    std::cout<<"SCL pin: "<<SCL_pin<<std::endl;
    std::cout<<"SDA pin: "<<SDA_pin<<std::endl;
    std::cout<<"baudRate: "<<baudrate<<std::endl;
    std::cout<<"nombre "<<name<<std::endl;
}

uint32_t I2C::write(uint8_t addres, const uint8_t *data, uint32_t data_size){
    
    for(uint8_t i = 0; i<data_size;i++){
        std::cout<<"numero "<<i+1<<": "<<std::hex<<(int)data[i]<<std::endl;
        
    }
    
    return 0;
}


uint32_t I2C::read(uint8_t addres,uint8_t*data,uint32_t data_get){
    
    uint8_t dummy_data[10]={0x10,0xAA,0x56,0x78,0x12,0x01,0x80,0x00,0xFF,0xAB};

    for(uint8_t i =0; i<data_get;i++){
        data[i] = dummy_data[i];
    }
    
    return 0;
}



//////////////////////////class SHT20/////////////////////////
class SHT20 : private I2C{

    protected: //los atributos si se quiere que nomas se accedan por metodos
        int daaa {0};
    public: //pero en la clase final, los metodos deben ser publicos
    
        //constructor 
            SHT20(gpios_t set_scl_pin,gpios_t set_sda_pin, uint32_t set_baudrate,std::string set_name):
                    I2C(set_scl_pin,set_sda_pin,set_baudrate,set_name){
                        
                    }

                   //si tuviera mas atributos esta clase seria:
        //    SHT20(gpios_t set_scl_pin,gpios_t set_sda_pin, uint32_t set_baudrate,std::string set_name, int set_otro, int set_mas):
        //            I2C(set_scl_pin,set_sda_pin,set_baudrate,set_name),
        //            otro(set_otro),mas(set_mas){
                       
        //            }
            
            
            void SHT20_init(gpios_t sht20_SCL_pin, gpios_t sht20_SDA_pin, uint32_t sht20_baudrate, std::string sht20_name);
            void configure_params(gpios_t sht20_SCL_pin, gpios_t sht20_SDA_pin, uint32_t sht20_baudrate, std::string sht20_name)override;
            uint32_t read_temperature(uint32_t &tempe);
            uint32_t read_humidity(uint32_t &hum);
            
            void get_params(void);
            
            ~SHT20() = default;
        
            void get_daa(void);
//la clase hija debe tener un constructo hacia la clase padre y a la clase mism
        
};


void SHT20::SHT20_init(gpios_t sht20_SCL_pin, gpios_t sht20_SDA_pin, uint32_t sht20_baudrate, std::string sht20_name){
    
    I2C::configure_params(sht20_SCL_pin,sht20_SDA_pin,sht20_baudrate,sht20_name);
}

void SHT20::configure_params(gpios_t sht20_SCL_pin, gpios_t sht20_SDA_pin, uint32_t sht20_baudrate, std::string sht20_name){
    I2C::configure_params(sht20_SCL_pin,sht20_SDA_pin,sht20_baudrate,sht20_name);
}

uint32_t SHT20::read_temperature(uint32_t &tempe){
    uint8_t const data[2] = {0xF3,0xAA};
    uint8_t rec_data[3] = {0};
    I2C::write(0xFA,data,sizeof(data)/sizeof(data[0]));
    I2C::read(0xFA,rec_data,3);
    
    tempe = ((rec_data[2]<<16) + (rec_data[1]<<8)) | rec_data[0]; 
    
    return 0;
}

uint32_t SHT20::read_humidity(uint32_t &hum){
    uint8_t const data[2] = {0xDD,0x01};
    uint8_t rec_data[3] = {0};
    I2C::write(0xE5,data,sizeof(data)/sizeof(data[0]));
    I2C::read(0xE5,rec_data,3);
    
    hum = ((rec_data[2]<<16) + (rec_data[1]<<8)) | rec_data[0]; 
    
    return 0;
}

void SHT20::get_daa(void){
    std::cout<<this->daaa<<std::endl;
}

void SHT20::get_params(void){
    this->daaa+=5;
    I2C::get_params();
    get_daa();
}





//hacer el constructor de la clase hija referenciando al constructor d ela clase base
//jugar con las herencias public, portect y private

int main(void)
{
    uint8_t data[4] = {0x12,0x45,0x32,0x55};
    uint8_t data_get[4] = {0};
  
    SHT20 *sensor = new SHT20(pin_4,pin_6,200,"slot");
    
    uint32_t value {0};

    //sensor->read_humidity(value);
    sensor->get_params();

    std::cout <<std::dec<<value<<std::endl;
    
    delete sensor;
	return 0;
}
