#include <stm32f103xb.h>
#include <Actividad_EstructuraDeTiposDeDatos1.h>
#include <stdbool.h>
void pinMode(int pin, bool inOut){
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    if(inOut){
        if(pin <= 7){
            GPIOA->CRL &= ~(0xF << (pin*4)); 
            GPIOA->CRL |= (0b0100 << (pin*4));
        }else if(pin > 7 && pin < 15){
            GPIOA->CRH &= ~(0xF << (pin*4)); 
            GPIOA->CRH |= (0b0100 << (pin*4));
        } 
    }else{
        if(pin <= 7){
            GPIOA->CRL |= (0b0010 << (pin*4));
            GPIOA->CRL &= ~(0xF << (pin*4)); 
        }else if(pin > 7 && pin < 15){
            GPIOA->CRH &= ~(0xF << (pin*4)); 
            GPIOA->CRH |= (0b0010 << (pin*4));
        } 
    }
}
void digitalWrite(int pin, bool estado){
    if(estado){
        GPIOA->BSRR|=(1 << pin);
    }else{
        GPIOA->BSRR|=(1 << (pin + 16));
    }
}
bool digitalRead(int pin){
    bool lectura = (GPIOA->IDR & (1 << pin));
    return lectura;
}