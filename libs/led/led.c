#include "led.h"

#define NUMBER_OF_LEDS 4








// this function enables one led
void enableOneLed (int led) { 
  if (led < 0 || led > 3)
  {
    return;
  }else {

    DDRB |= ( 1 << ( PB2 + led ));
    
    

  }

}





void enableMultipleLeds (uint8_t led) {

  DDRB |= (led << 2);

}





void enableAllLeds () {
  
  DDRB |= (1 << (PB2 + 0));
  DDRB |= (1 << (PB2 + 1));
  DDRB |= (1 << (PB2 + 2));
  DDRB |= (1 << (PB2 + 3));
  
}





void lightUpOneLed (int led) {
  enableOneLed(led);

  if (led < 0 || led > 3)
  {
    return;
  }else {

    PORTB &= ~( 1 <<  (PB2 + led)  );
    

  }


}




void lightUpMultipleLeds (uint8_t led) {
  enableMultipleLeds(led);

  PORTB &= ~(led << 2);

}




void lightUpAllLeds () {
  enableAllLeds();
  PORTB &= ~( 1 << ( PB2 + 0 ));
  PORTB &= ~( 1 << ( PB2 + 1 ));
  PORTB &= ~( 1 << ( PB2 + 2 ));
  PORTB &= ~( 1 << ( PB2 + 3 ));

}

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



void lightDownOneLed (int led) {
  if (led < 0 || led > 3)
  {
    return;
  }else {

    PORTB |= ( 1 << ( PB2 + led ));
    


  }
}


void lightDownAllLeds () {

  PORTB |= ( 1 << ( PB2 + 0 ));
  PORTB |= ( 1 << ( PB2 + 1 ));
  PORTB |= ( 1 << ( PB2 + 2 ));
  PORTB |= ( 1 << ( PB2 + 3 ));

}




void lightDownMultipleLeds (uint8_t led) {

  PORTB |= (led << 2);

}









void lightToggleOneLed (int led) {
  
  if (led < 0 || led > 3)
  {
    return;
  }else {
    enableOneLed(led);
    while (1) {
      PORTB &= ~( 1 << ( PB2 + led ));
      _delay_ms(1000);
      PORTB |= ( 1 << ( PB2 + led ));
      _delay_ms(1000);

    }
    
    

  }


}


void dimLed(int lednumber, int percentage, int duration) {

  int onPercentage = 100 - percentage;
  int currDuration = 0;

  enableLed(lednumber);
  lightDownLed(lednumber);

  while (duration > currDuration) {

    lightUpLed(lednumber);
    _delay_ms(onPercentage);
    lightDownLed(lednumber);
    _delay_ms(percentage);


  }
  _delay_ms(1);
    currDuration = currDuration + 1;
  


}   
   



void fadeInLed(int lednumber, int duration) {



}
  

void fadeOutLed(int lednumber, int duration) {



} 




/*

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


// function to light up the LEDs
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


// function to light down the LEDs
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

*/
