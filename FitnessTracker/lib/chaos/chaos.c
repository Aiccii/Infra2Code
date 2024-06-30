#include <chaos.h>
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__  
#include <util/delay.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flashLed(int led){
    PORTB |= (1<<led);
    _delay_ms(rand() % 100+ 900);
    PORTB &= ~(1 <<led);
}
void enablePins(){
    DDRB= 0b00111100;
    }
