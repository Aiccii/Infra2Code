#define __DELAY_BACKWARD_COMPATIBLE__  
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>





void enableBuzzer(); // enables the buzzer
void playTone( float frequency, uint32_t duration ); // plays a tone
void disableBuzzer(); // disables the buzzer

//void playMusic(**notes); // optional