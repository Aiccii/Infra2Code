#define __DELAY_BACKWARD_COMPATIBLE__ 
#include <stdlib.h>
#include <led.h>
#include <usart.h>
#include <avr/io.h>
#include <util/delay.h>





void ledChaos() {

    int time = rand() % 500;
    
    int led = rand() % 4;

    if (time < 50)
    {
        time = 50;
    }


    enableLed(led);
    lightUpLed(led);
    _delay_ms(time);
    lightDownLed(led);
    




}






void dimLed(int ledNumber, int percentage, int duration) {

    
    double lightUp =  percentage / 100;
    double lightDown = 1 - lightUp;

    enableLed(ledNumber);


    while (duration > 0) {

    lightUpLed(ledNumber);
    _delay_ms(lightUp);
    lightDownLed(ledNumber);
    _delay_ms(lightDown);

    _delay_ms(1);
    duration -= 1;

    }
    


}



void fadeInLed(int lednumber, int duration) 
{
    for (int i = 1; i <= 100; i++) {
        dimLed(lednumber, i, duration );
        _delay_ms(1);
    }
}

   

void fadeOutLed(int ledNum, int duration) {






}
  


