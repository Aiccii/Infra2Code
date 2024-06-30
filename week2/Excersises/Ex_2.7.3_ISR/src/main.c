#include <util/delay.h>
#include <avr/io.h>
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

/* First, review the code in the main function!
 * This ISR is called when Pin Change Interrupt 1 is triggered (PCINT1_vect)
 * This is the interrupt for PORTC, where the switches/buttons are connected... */
ISR( PCINT1_vect )
{
    // button 1 is pressed (bit is set to 0)?
    while ( bit_is_clear( BUTTON_PIN, BUTTON1 ))
    {  
      LED_PORT |= _BV( LED4 ); // turn the LED off

      for (int i = 0; i < 5; i++) // i made it 5 times because why not?
      {
        
        LED_PORT &= ~_BV( LED2 ) ; // turn the LED on
        LED_PORT &= ~_BV( LED3 ) ;   // turn the LED on
        _delay_ms( 5000 );
        LED_PORT |= _BV( LED2 ); // turn the LED off
        LED_PORT |= _BV( LED3 );  // turn the LED off
        _delay_ms( 5000 );

      }
    }


    while ( bit_is_clear( BUTTON_PIN, BUTTON2 ))
    {  
      LED_PORT |= _BV( LED4 ); // turn the LED off
      LED_PORT |= _BV( LED3 ); // turn the LED off
      _delay_ms(500); // delay before starting

      for (int i = 0; i < 7; i++)
      {
    
        LED_PORT &= ~_BV( LED3 ) ;   // turn led on
        _delay_ms( 500 );
        LED_PORT |= _BV( LED3 );   // turn led off
        _delay_ms( 500 );

      }
    }


}

int main()
{
    // we enable the wanted LED's
    LED_DDR |= _BV( LED3 ) | _BV( LED4 ) | _BV( LED2 );  // enable the wanted LEDs
    LED_PORT |= _BV( LED3 ) | _BV( LED4 ) | _BV( LED2 );  // turn the wanted LEDs off

    BUTTON_DDR &= ~_BV( BUTTON1 ) | ~_BV( BUTTON2 );  // enable the wanted buttons
    BUTTON_PORT |= _BV( BUTTON1 ) | _BV( BUTTON2 );   // enable pull-up aka the reading from the buttons


    PCICR |= _BV( PCIE1 );  /* in Pin Change Interrupt Control Register: indicate
                             * which interrupt(s) you want to activate (PCIE0: port B,
                             * PCIE1: port C, PCIE2: port D) */

    PCMSK1 |= _BV( BUTTON1 ) | _BV( BUTTON2 ) ;   /* In the corresponding Pin Change Mask Register: indicate
                                 * which pin(s) of that port activate the ISR. */

    sei();  // Set Enable Interrupts --> activate the interrupt system globally.
    
    while ( 1 )
    {
        LED_PORT &= ~_BV( LED4 ) ;  // turn the LED on
        LED_PORT &= ~_BV( LED3 ) ;   // turn the LED on
        _delay_ms( 2000 );
        LED_PORT |= _BV( LED4 ); // turn the LED off
        LED_PORT |= _BV( LED3 );  // turn the LED off
        _delay_ms( 2000 );
    }
    
    return 0;
}