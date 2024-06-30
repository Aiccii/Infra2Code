#include "Buzzer.h"

void enableBuzzer() {
    DDRD |= (1 << PD3); // Set PD3 as an output pin
}

void disableBuzzer() {
    DDRD &= ~(1 << PD3); // Set PD3 as an input pin (effectively disabling it)
}

void playTone( float frequency, uint32_t duration )
{
    enableBuzzer();
   uint32_t periodInMicro = ( uint32_t ) ( 1000000 / frequency ); //Calculate the period in microsecs from the freq
   uint32_t durationInMicro = duration * 1000; //We express duration in microsecs
   for ( uint32_t time = 0; time < durationInMicro; time += periodInMicro ) //See tutorial on Music for more info!
    {
    PORTD &= ~( 1 << PD3 ); //turn the buzzer on
    _delay_us( periodInMicro / 2 ); //Wait for the half of the period
    PORTD |= ( 1 << PD3 ); //Turn the buzzer off
    _delay_us( periodInMicro / 2 ); //Wait again for half of the period
    }
}

