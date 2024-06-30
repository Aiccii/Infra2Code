

#include <led.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <button.h>

#define BUTTON1 PC1
#define BUTTON2 PC2
#define BUTTON3 PC3
#define BUTTON_PORT PORTC
#define BUTTON_DDR DDRC 
#define BUTTON_PIN PINC


#define LED1 PB2
#define LED2 PB3
#define LED3 PB4
#define LED4 PB5

#define LED_PORT PORTB
#define LED_DDR DDRB




ISR(PCINT1_vect) {

    

    // button 1 is pressed (bit is set to 0)?
    if ( bit_is_clear( BUTTON_PIN, BUTTON1 ))
    {  
      
      while(1){
        
        LED_PORT &= ~_BV( LED1 ) ; // turn the LED on
        _delay_ms(500);
        LED_PORT |= _BV( LED1 ); // turn the LED off
        _delay_ms(500);

        if (bit_is_clear( BUTTON_PIN, BUTTON1 )) {
            break;
        }

      }

        

    }


    if ( bit_is_clear( BUTTON_PIN, BUTTON2 ))
    {  

        while(1) {
        
     
        LED_PORT &= ~_BV( LED2 ) ; // turn the LED on
        _delay_ms(500);
        LED_PORT |= _BV( LED2 ); // turn the LED off
        _delay_ms(500);

        if (bit_is_clear( BUTTON_PIN, BUTTON2 )) {
            break;
        }

        }


    }







    if ( bit_is_clear( BUTTON_PIN, BUTTON3 ))
    {  

        while (1)
        {
            
        LED_PORT &= ~_BV( LED3 ) ; // turn the LED on
        _delay_ms(500);
        LED_PORT |= _BV( LED3 ); // turn the LED off
        _delay_ms(500);

        if ( bit_is_clear( BUTTON_PIN, BUTTON2 )) {  

        while(1) {


        
        LED_PORT &= ~_BV( LED3 ) ; // turn the LED on
        LED_PORT &= ~_BV( LED2 ) ; // turn the LED on
        _delay_ms(500);
        LED_PORT |= _BV( LED2 ); // turn the LED off
        LED_PORT |= _BV( LED3 ); // turn the LED off
        _delay_ms(500);


        // button 1 is pressed (bit is set to 0)?
    if ( bit_is_clear( BUTTON_PIN, BUTTON1 ))
    {  
      
      while(1){


        LED_PORT &= ~_BV( LED3 ) ; // turn the LED on
        LED_PORT &= ~_BV( LED2 ) ; // turn the LED on
        LED_PORT &= ~_BV( LED1 ) ; // turn the LED on
        _delay_ms(500);
        LED_PORT |= _BV( LED2 ); // turn the LED off
        LED_PORT |= _BV( LED3 ); // turn the LED off
         LED_PORT |= _BV( LED1 ); // turn the LED off
        _delay_ms(500);
        

        if (bit_is_clear( BUTTON_PIN, BUTTON1 )) {
            break;
        }

      }

        

    }



    
        if (bit_is_clear( BUTTON_PIN, BUTTON2 )) {
            break;
        }

        }


    }

        if (bit_is_clear( BUTTON_PIN, BUTTON3 )) {
            break;
        }

        }

    }

    }






int main() {


    LED_DDR |= _BV( LED3 ) | _BV( LED1 ) | _BV( LED2 ) | _BV( LED4 );  // enable the wanted LEDs
    LED_PORT |= _BV( LED3 ) | _BV( LED1 ) | _BV( LED2 ) | _BV( LED4 );  // turn the wanted LEDs off

    BUTTON_DDR &= ~_BV( BUTTON1 ) | ~_BV( BUTTON2 ) | ~_BV( BUTTON3 ) ;  // enable the wanted buttons
    BUTTON_PORT |= _BV( BUTTON1 ) | _BV( BUTTON2 ) | _BV( BUTTON3 );   // enable pull-up aka the reading from the buttons


    PCICR |= _BV( PCIE1 );  /* in Pin Change Interrupt Control Register: indicate
                             * which interrupt(s) you want to activate (PCIE0: port B,
                             * PCIE1: port C, PCIE2: port D) */

    PCMSK1 |= _BV( BUTTON1 ) | _BV( BUTTON2 ) | _BV( BUTTON3 );   /* In the corresponding Pin Change Mask Register: indicate
                                 * which pin(s) of that port activate the ISR. */

    sei();  // Set Enable Interrupts --> activate the interrupt system globally.
    

    while (1)
    {
        /* code */
    }
    

    





    return 0;

}






