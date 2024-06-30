#include <util/delay.h>
#include <avr/io.h>

#define NUMBER_OF_LEDS 4 //Define is a "preprocessor directive". It ensures that every NUMBER_OF_LEDS will be replaced by 4 in the following code
// the above code will replace NUMBER_OF_LEDS with the number 4



// function to enable the LED
void enableLed ( int lednumber ) //C has no classes; functions can be included directly in the .c file.
{
    // if the led number is less than 0 OR the led number is greater than NUMBER_OF_LEDS - 1 = (4), then do nothing 
    if ( lednumber < 0 || lednumber > NUMBER_OF_LEDS - 1 ) {
       return; // return; aka do nothing
       }
       else {
        // else enable the LED associated with the entered number
        DDRB |= ( 1 << ( PB2 + lednumber ));    //Check the tutorial "Writing to a Pin". We know from the documentation on
                                            //the multifunctional shield that the LEDs start at PB2
       }
}


void lightUpLed ( int lednumber )    //Note: enabled LEDs light up immediately ( 0 = on )
{
  // if the led number is less than 0 or greater than number of LEDs - 1, aka 3 it does nothing
     if ( lednumber < 0 || lednumber > NUMBER_OF_LEDS - 1 ) {
      return; // return; aka do nothing at all
      }
       else {
        // else light up the led associated with the entered number
         PORTB &= ~( 1 << ( PB2 + lednumber ));  //Check the tutorial on "Bit Operations" to know what happens in this line.

       }
}



void lightDownLed ( int lednumber )
{
    // if the led number is less than 0 or greater than 3 do nothing aka return;
    if ( lednumber < 0 || lednumber > 3 ) {
      return; // do nothing aka return;

      }
       else {
        // else light up the entered led number that is entered by the user using this function
        PORTB |= ( 1 << ( PB2 + lednumber ));   //Make sure you understand this line as well!

       }
}



int main()
{
    for ( int i = 0; i < 4; i++ )
    {
      // the for loops number enables the LEDS, associated with
        enableLed(i);
    }
    while (1)
    {
        for ( int i = 0; i < 4; i++ )
        {
            lightUpLed(i);
            _delay_ms( 100 );
        }
        for ( int i = 0; i < 4; i++ )
        {
            lightDownLed(i);
            _delay_ms( 100 );
        }
    }
    return 0;
}
