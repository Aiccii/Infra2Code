#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>


// this function enables one led
void enableOneLed (int led) { 
  if (led < 0 || led > 3)
  {
    return;
  }else {

    DDRB |= (1 << (PB2 + led));


  }

}





void enableMultipleLeds (uint8_t led) {

  DDRB |= led;


}





void enableAllLeds () {
  
  DDRB |= (1 << (PB2 + 0));
  DDRB |= (1 << (PB2 + 1));
  DDRB |= (1 << (PB2 + 2));
  DDRB |= (1 << (PB2 + 3));
  
}




void lightUpOneLed (int led) {

  if (led < 0 || led > 3)
  {
    return;
  }else {

    PORTB &= ~( 1 << ( PB2 + led ));


  }


}




void lightUpMultipleLeds (uint8_t led) {
  enableMultipleLeds(led);

  PORTB &= ~(led);

}




void lightUpAllLeds () {
  enableAllLeds();
  PORTB &= ~( 1 << ( PB2 + 0 ));
  PORTB &= ~( 1 << ( PB2 + 1 ));
  PORTB &= ~( 1 << ( PB2 + 2 ));
  PORTB &= ~( 1 << ( PB2 + 3 ));

}




void lightDownOneLed (int led) {
  if (led < 0 || led > 3)
  {
    return;
  }else {

    PORTB |= ( 1 << ( PB2 + led ));


  }
}





void lightDownMultipleLeds (uint8_t led) {

  PORTB |= led;


}




void lightDownAllLeds () {
  PORTB |= ( 1 << ( PB2 + 0 ));
  PORTB |= ( 1 << ( PB2 + 1));
  PORTB |= ( 1 << ( PB2 + 2 ));
  PORTB |= ( 1 << ( PB2 + 3 ));
}





void lightToggleOneLed (int led) {

}






int	main() {
  
  

  lightUpMultipleLeds(0b00000110);




}



