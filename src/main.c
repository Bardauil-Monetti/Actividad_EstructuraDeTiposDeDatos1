#include <stm32f103xb.h>
#include <Actividad_EstructuraDeTiposDeDatos1.h>
#include <stdbool.h>
int selM, selL;
int main(void){
    for(int i = 1; i < 6; i++){
        pinMode(i, true);
    }
    //4 y 5 selectoras
    pinMode(7, false);
    while(1){
        selM = digitalRead(4);
        selL = digitalRead(5);
        if(!selM && !selL){
            digitalWrite(5, digitalRead(1));
        }else if(!selM && selL){
            digitalWrite(5, digitalRead(2));
        }else if(selM && !selL){
            digitalWrite(5, digitalRead(3));
        }
    }
}