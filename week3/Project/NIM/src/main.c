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



int startNumeber = 21;

int minNumber = 1;

int maxNumeber = 3;

int player1Count = 0;

int player2Count = 0;

int matchesTaken = 0;

int matchesToTake = 0;

int potentioCount = 0;

int playerTurn = 0;

int startOfGame = 0;

int selectScene = 0;


ISR ( PCINT1_vect ) { 



  if (buttonPushed(BUTTON1) == 1 && startOfGame == 0) {

    startOfGame = 1;
    _delay_ms(200);

  }


  if (buttonPushed(BUTTON1) == 1) {

    _delay_ms(40);
    
    if (matchesToTake > 1)
    {
      matchesToTake--;
    }
    
  }
  

  if (buttonPushed(BUTTON2) == 1 && selectScene == 0) {

    selectScene = 1;
    
  }

  if (buttonPushed(BUTTON3) == 1) {

    if (matchesToTake <= 2) {

      matchesToTake++;

    }
    
    
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
  

  while (startOfGame == 0) {

    potentioCount = potentioValue();

    writeNumber(potentioCount);


  }

  srand(potentioCount);





 writeNumberToSegment(0, matchesToTake);

 playerTurn = rand() % 2;


for (int i = 0; i < 2000; i++)
{
  
 if (playerTurn == 0 ) {

    writeCharToSegment(1, 'C');
    _delay_ms(1);
    writeNumberToSegment(2, 2);
    _delay_ms(1);
    writeNumberToSegment(3, 1);
    _delay_ms(1);

 } else if (playerTurn == 1) {

    writeCharToSegment(1, 'P');  
    _delay_ms(1);
    writeNumberToSegment(2, 2);
    _delay_ms(1);
    writeNumberToSegment(3, 1);
    _delay_ms(1);
 }

}



while (startNumeber != 0)
{
  



if (playerTurn == 1)
{


while (selectScene == 0) {


  writeNumberToSegment(0, matchesToTake);
  writeCharToSegment(1, 'P'); 


}


startNumeber -= matchesToTake;

matchesToTake = 1;

playerTurn = 0;


}


for (int i = 0; i < 2000; i++)
{
  writeNumber(startNumeber);
  _delay_ms(1);
}



if (playerTurn == 0)
{


matchesToTake = rand() % 4 + 1;



for (int i = 0; i < 2000; i++)
{
  writeNumberToSegment(0, matchesToTake);
  _delay_ms(1);
  writeCharToSegment(1, 'C'); 
  _delay_ms(1);
}



startNumeber -= matchesToTake;

playerTurn = 1;
selectScene =0;

}


for (int i = 0; i < 2000; i++)
{
  writeNumber(startNumeber);
  _delay_ms(1);
}


}















  return 0;
}