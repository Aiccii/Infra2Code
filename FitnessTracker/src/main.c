#include <stdio.h>
#include <display.h>
#include <led.h>
#include <util/delay.h>
#include <button.h>
#include <avr/interrupt.h>
#include <adc.h>
#include <usart.h>
#include <Buzzer.h>





int repetitions = 0;

int totalRepetitions = 0;

int timer = 0;

int start = 0;

int roundCounter = 0;

int mainMenuStarter = 0;




ISR(PCINT1_vect) {

  // button 1 starts

  if (buttonPushed(1) == 1 && start == 0 && mainMenuStarter == 1) {
    start = 1;
    _delay_ms(100);
  }


  if (buttonPushed(1) == 1 && mainMenuStarter == 0) 
  {
    mainMenuStarter = 1;
    _delay_ms(200);
  }




  // button 2 pauses / stops
  if (buttonPushed(2) == 1 && start == 1 && mainMenuStarter == 1) {

    start = 0;
    _delay_ms(100);
 
  }
  



  // button 3 resets the timer
  if (buttonPushed(3) == 1 && start == 1 && mainMenuStarter == 1)  {

    timer = 0;
    _delay_ms(100);

  }
  



}




int main () {

  initDisplay();
  initUSART();
  enableAllButtons();
  enableAllButtonInterrupt();
  enableAllLeds();
  lightDownAllLeds();
  //enableBuzzer();

  int trainTime = 0;

  int restTime = 0;

  printf("\n************** ||  Welcome to the trainer  || *****************\n");

  printf("\nselect the amount of repetitions you want to train\n");
  repetitions = getNumber();

  printf("\nselect the amount of minutes you want to train");
  trainTime = getNumber();

  printf("\nselect the amount of time you want to rest");
  restTime = getNumber();


  printf("\nSummary\nRepetitions : %d\nTraining Time : %d\nRest Time : %d\n\nPlease Press Button 1 to start", repetitions, trainTime, restTime);
   

  
  while (mainMenuStarter == 0) {


    for (int i = 0; i < 20000; i++) {

      writeNumberToSegment(0, repetitions);
      writeNumberToSegment(2, 1);
      writeNumberToSegment(3, 0);

    }


    for (int i = 0; i < 20000; i++) {

      writeNumberToSegment(0, trainTime);
      writeNumberToSegment(2, (restTime / 10) % 10);
      writeNumberToSegment(3, restTime % 10);
      
    }


    
  }


  trainTime = trainTime * 60;

   playTone(300, 300);
   writeNumberAndWait(3, 1000);
   
   playTone(200, 600);
   writeNumberAndWait(2, 1000);

   playTone(100, 1200);
   writeNumberAndWait(1, 1000);

   start = 1;


   for (int i = 0; i < 10; i++)
   {
    lightUpAllLeds();
    _delay_ms(50);
    lightDownAllLeds(); 
    _delay_ms(50);
   }
   



  

int restTimeCopy = restTime;
int trainTimeCopy = trainTime;

  while (1) {

    int counter = 0;




      while (counter < repetitions && start == 1) {


      

        while (trainTimeCopy != 0 && start == 1) {

          for (int i = 0; i < 3000; i++) {
          writeNumber(trainTimeCopy);
          _delay_ms(0.1);
          }
          trainTimeCopy--;

        }


        
        writeStringAndWait("REST", 3000);
          
        
        



        while (restTimeCopy != 0 && start == 1) {

          for (int i = 0; i < 3000; i++) {
          writeNumber(restTimeCopy);
          _delay_ms(0.1);
          }
          restTimeCopy--;

          
        }

        writeStringAndWait("go", 3000);


        counter++;


        if (trainTimeCopy == 0 || timer == 0) 
        {
           trainTimeCopy = trainTime;
        }

        if (restTimeCopy == 0 || timer == 0) 
        {
           restTimeCopy = restTime;
        }
        
        
        
        



        
      }


      counter = 0;
      


      
    
    

  }
  





  return 0;
}