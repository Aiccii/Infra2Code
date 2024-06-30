#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>
#include <button.h>
#include <display.h>
#include <potentio.h>
#include <led.h>


#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3




int potentioCount = 0;

int playerTurn = 0;

int startOfGame = 0;

int selectScene = 0;

int stage1 = 0;

int stage2 = 0;

int stage3 = 0;




ISR ( PCINT1_vect ) { 



  if (buttonPushed(BUTTON1) == 1 && startOfGame == 0) {

    startOfGame = 1;
    _delay_ms(200);

  }

  if (buttonPushed(BUTTON1) == 1 && stage1 == 0) {

    stage1 = 1;
    _delay_ms(200);

  }


  if (buttonPushed(BUTTON1) == 1 && buttonPushed(BUTTON2) == 1 && stage2 == 0) {

    stage2 = 1;
    _delay_ms(200);

  }

  if (buttonPushed(BUTTON1) == 1 && buttonPushed(BUTTON2) == 1 && buttonPushed(BUTTON3) == 1 && stage3 == 0) {

    stage3 = 1;
    _delay_ms(200);

  }


  if (buttonPushed(BUTTON1) == 1) {

    _delay_ms(40);
    
  
    
  }
  

  if (buttonPushed(BUTTON2) == 1 && selectScene == 0) {

    selectScene = 1;
    
  }

  if (buttonPushed(BUTTON3) == 1) {


     
  }




}




int main() {

  initUSART();
  initADC();
  initDisplay();
  enableAllButtons();
  enableAllButtonInterrupts();
  enableAllLeds();
  lightDownAllLeds(); 


potentioCount = potentioValue();


  

while (1)
{
  while (startOfGame != 1) {

    lightUpOneLed(3);
    _delay_ms(1000);
    lightDownOneLed(3);
    _delay_ms(1000);

  }



  lightDownAllLeds(); 



  while (stage1 != 1)
  {

    lightUpOneLed(0);
    _delay_ms(1000);
    lightDownOneLed(0);
    _delay_ms(1000);

    
  }


  for (int i = 0; i < 15; i++)
  {
    lightUpOneLed(3);
    _delay_ms(50);
    lightDownOneLed(3);
    _delay_ms(50);
  }
  

  while (stage2 != 1)
  {

    lightUpOneLed(0);
    lightUpOneLed(2);
    _delay_ms(1000);
    lightDownOneLed(0);
    lightDownOneLed(2);
    _delay_ms(1000);

    
  }


    while (stage3 != 1)
  {

    lightUpOneLed(0);
    lightUpOneLed(2);
    _delay_ms(1000);
    lightDownOneLed(0);
    lightDownOneLed(2);
    _delay_ms(1000);

    
  }


  
  

}



  





  return 0;
}