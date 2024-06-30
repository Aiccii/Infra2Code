#include <stdio.h>
#include <led.h>
#include <display.h>
#include <button.h>
#include <potentio.h>
#include <buzzer.h>
#include <avr/interrupt.h>
#include <stdbool.h>


int playing = 0;

ISR( PCINT1_vect ) {

    

    

    if (buttonPushed(1) == 1 && playing == 0) {
        playing = 1;
        _delay_ms(200);
    }

    _delay_ms(10);

    

    if (buttonPushed(1) == 1 && playing == 1) {
       playing = 0;
    }
    
    /*
    
    */
    
    




}





int main() {


    enableAllButtons();
    


    while (1) {

        enableAllButtonInterrupts();


        
        
        
        
        int freq = potentioValue();
        disableBuzzer();
        potentiometerOnDisplay();


        if (playing == 1) {

        enableBuzzer();
        playTone(freq, 500);
        _delay_ms(1000);

        
        }

        

        
    }
    

        





}