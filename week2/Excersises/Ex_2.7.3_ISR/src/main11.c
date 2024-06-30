

#include <avr/io.h>
#include <led.h>
#include <button.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_PORT PORTB
#define BUTTON_PORT PORTC

#define BUTTON_PIN PINC

#define LED_DDR DDRB
#define BUTTON_DDR DDRC

#define BUTTON1 PC1
#define BUTTON2 PC2

#define LED1 PB2
#define LED2 PB3
#define LED3 PB4
#define LED4 PB5


// PCINT1_vect is for changes in port C

ISR(PCINT2_vect) {

    LED_PORT &= _BV( LED4 );

   // button 1 is pressed (bit is set to 0)?
    if ( bit_is_clear( BUTTON_PIN, BUTTON1 ))
    {   

        LED_PORT &= ~_BV( LED3 );   // turn led1 on
        LED_PORT &= ~_BV( LED2 );
        _delay_ms( 1000 );
        LED_PORT |= _BV( LED3 );    // turn led1 off
        LED_PORT &= _BV( LED2 );
        _delay_ms( 1000 );
        
    }

}



int main11(){

    // we enable the wanted LED's
    LED_DDR |= _BV( LED3 ) | _BV( LED4 ) | _BV( LED2 );  
    LED_PORT |= _BV( LED3 ) | _BV( LED4 ) | _BV( LED2 );  

    // we enable the wanted buttons
    BUTTON_DDR &= ~_BV( BUTTON1 ) | ~_BV( BUTTON2 );          
    BUTTON_PORT |= _BV( BUTTON1 ) | _BV( BUTTON2 );          
    
    PCICR |= _BV( PCIE1 );  /* in Pin Change Interrupt Control Register: indicate
                             * which interrupt(s) you want to activate (PCIE0: port B,
                             * PCIE1: port C, PCIE2: port D) */
   
    PCMSK1 |= _BV( BUTTON1 ) | _BV( BUTTON2 );   /* In the corresponding Pin Change Mask Register: indicate
                                 * which pin(s) of that port activate the ISR. */
    
    sei();  // Set Enable Interrupts --> activate the interrupt system globally.
   
    while ( 1 )
    {
        LED_PORT &= ~_BV( LED3 );   // turn led1 on
        LED_PORT &= ~_BV( LED4 );
        _delay_ms( 2000 );
        LED_PORT |= _BV( LED3 );    // turn led1 off
        LED_PORT &= _BV( LED4 );
        _delay_ms( 2000 );
    }
    return 0;



}
