#include <stdio.h>
#include <display.h>
#include <led.h>
#include <util/delay.h>
#include <potentio.h>
#include <button.h>
#include <avr/interrupt.h>


int potentioMeterValue = 0;

// the dices 
int dice1 = 0;
int dice2 = 0;
int dice3 = 0;


ISR(PCINT1_vect) {


  if (buttonPushed(1)) { 

    _delay_ms(1000);
    srand(potentioMeterValue + dice3 + 41); 
    dice1 = (rand() % 6) + 1;
     writePointToPlace(0);

  }


  if (buttonPushed(2)) {

    _delay_ms(1000);
    srand(103 + potentioMeterValue); 
    dice2 = (rand() % 6) + 1;
    writePointToPlace(1);
  }
  

  if (buttonPushed(3))
  {
   _delay_ms(1000);
    srand(potentioMeterValue + dice1 + 42); 
    dice3 = (rand() % 6) + 1;
    writePointToPlace(2);
  }
  


}



int throwCount = 2; // the amount of throws available


// the count of the scores
int ones = -1;

int twos = -1;

int threes = -1;

int fours = -1;

int fives = -1;

int sixes = -1;

int street = -1;

int yahtzee = -1;






uint8_t intValue = 0;





int main() {

  initDisplay();
  initUSART();
  initADC();
  enableAllButtonInterrupts(); 
  enableAllLeds();
  lightDownAllLeds(); 

  
  printf("\nWelcome to mini-yahtzee!!!\n");
  printf("Press a button to start the game...\n\n");

  int potentioMeterValue = potentioValue(); // this returns the value of the potentiometer
  srand(potentioMeterValue); // this puts the seed of the random as the potentiometer value

  dice1 = (rand() % 6) + 1;
  srand(potentioMeterValue + dice1);
  dice2 = (rand() % 6) + 1;
  srand(potentioMeterValue * dice2); 
  dice3 = (rand() % 6) + 1;


  while (1)
  {


    while (throwCount >= 0 ) {

      for (int i = 0; i < 3; i++) {

        lightUpAllLeds();
        _delay_ms(100);
        lightDownAllLeds(); 
        _delay_ms(100);

      }
      
      printf("PotentioMeter Val : %d\n\n", potentioMeterValue);
      printf("dice 1 : %d\n", dice1);
      printf("dice 2 : %d\n", dice2);
      printf("dice 3 : %d\n", dice3);
      
      for (int i = 0; i < 500; i++) {
        writeNumberToSegment(0, dice1);
        _delay_ms(5);
        writeNumberToSegment(1, dice2);
        _delay_ms(5);
        writeNumberToSegment(2, dice3);
        _delay_ms(5);

      }

      throwCount--;
      
      
      printf("The dice are rolled.  Look at the display and fix or release dice with the buttons....\n");

      printf("Remaining throws: %d\n", throwCount);
      
      if (throwCount <= 0) {
        break;
      }

      printf("Type 9 if you want to select and skip the remaining throws\n\n");
      printf("Type 0 if you want to use remaining throws\n\n");
      
      //printf("Free dice were rolled again. Look at the display.\n");

       intValue = 0;

             

       intValue = getNumber();

       if (intValue == 9) {
        intValue = 0;
        break;
       }
       

      

    }
    


  printf("\nWhich score do you want to adjust?\n");


  if (ones == -1)
  {
    printf("1 = ones\n");
  }

  if (twos == -1)
  {
    printf("2 = twos\n");
  }

  if (threes == -1)
  {
    printf("3 = threes\n");
  }

  if (fours == -1)
  {
    printf("4 = fours\n");
  }

  if (fives == -1)
  {
    printf("5 = fives\n");
  }

  if (sixes == -1)
  {
    printf("6 = sixes\n");
  }

  if (street == -1)
  {
    printf("7 = street\n");
  }

  if (yahtzee == -1)
  {
    printf("8 = yahtzee\n");
  }

  
  

  printf("\n\nGive your choice: ");

  intValue = 0;
  
  intValue = getNumber(); // write the value as this 001, 002, 003, 004, and so on, writing 1 will result in 1335 for some reason

  printf("\n\nEntered Value : %d\n", intValue);


  int vals[] = {dice1, dice2, dice3};


  if (intValue == 1 && ones == -1) {
    

    for (int i = 0; i < 3; i++) {
      
      if (vals[i] == 1) {

        ones = ones + 1;



      }
      
    }
  srand(787 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(643 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(57 + dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;
    
    throwCount = 2;

  }



    if (intValue == 2 && twos == -1) {

      

    for (int i = 0; i < 3; i++) {

      if (vals[i] == 2) {

        twos = twos + 2;

      }
      
    }
 srand(634 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(342 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(20 + dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;

  throwCount = 2;
    
  }

    if (intValue == 3 && threes == -1) {
      
      for (int i = 0; i < 3; i++) {
        
        if (vals[i] == 3) {

        threes = threes + 3;

        }
      
      }

 srand(908 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(309 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(82 + dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;

  throwCount = 2;
    
    }


    if (intValue == 4 && fours == -1) {

    for (int i = 0; i < 3; i++) {
      if (vals[i] == 4)
      {
        fours = fours + 4;
      }
      
    }
    srand(447 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
    srand(143 + dice1 + potentioMeterValue);
    dice2 = (rand() % 6) + 1;
    srand(86 + dice2 + potentioMeterValue); 
    dice3 = (rand() % 6) + 1;
    throwCount = 2;

  }


  if (intValue == 5 && fives == -1) {

    for (int i = 0; i < 3; i++) {

      if (vals[i] == 5)
      {
        fives = fives + 5;
      }

    }
    srand(205 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
    srand(926 + dice1 + potentioMeterValue);
    dice2 = (rand() % 6) + 1;
    srand(33 + dice2 + potentioMeterValue); 
    dice3 = (rand() % 6) + 1;
    throwCount = 2;
    
    
  }


  if (intValue == 6 && sixes == -1) {

    for (int i = 0; i < 3; i++)
    {
      if (vals[i] == 6)
      {
        sixes = sixes + 6;
      }
    }
    
 srand(911 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(523 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(125 + dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;
  throwCount = 2;
    
  }


  if (intValue == 7 && street == -1) {

    
      if ((vals[0] == 1 && vals[1] == 2 && vals[2] == 3) || 
      (vals[0] == 2 && vals[1] == 3 && vals[2] == 4) || 
      (vals[0] == 3 && vals[1] == 4 && vals[2] == 5) || 
      (vals[0] == 4 && vals[1] == 5 && vals[2] == 6) )
      {
        street = street + 25;
      }


 srand(931 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(803 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(189 * dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;
  throwCount = 2;
    
    
    
  }


  if (intValue == 8 && yahtzee == -1) {

    
      if (vals[0] == vals[1] && vals[1] == vals[2])
      {
        yahtzee = yahtzee + 50;
      }


  srand(787 + dice3 + potentioMeterValue);
    dice1 = (rand() % 6) + 1;
  srand(643 + dice1 + potentioMeterValue);
  dice2 = (rand() % 6) + 1;
  srand(57 * dice2 + potentioMeterValue); 
  dice3 = (rand() % 6) + 1;
  throwCount = 2;
    
    
    
  }


 // printf("ones = %d\ntwos = %d\nthrees = %d\nfours = %d\nfives = %d\nsixes = %d\nstreet = %d\nyahtzee = %d\n\n", ones, twos,threes,fours,fives, sixes, street, yahtzee);

  if (ones == -1)
  {
    printf("ones = -\n");
  }else {
    printf("ones = %d\n", ones);
  }

  if (twos == -1)
  {
    printf("twos = -\n");
  }else {
    printf("twos = %d\n", twos);
  }

  if (threes == -1)
  {
    printf("threes = -\n");

  }else {
     printf("threes = %d\n", threes);
  }


  if (fours == -1)
  {
    printf("fours = -\n");
  } else {
    printf("fours = %d\n", fours);
  }


  if (fives == -1)
  {
    printf("5 = fives\n");
  }else {
    printf("5 = fives = %d\n", fives);
  }


  if (sixes == -1)
  {
    printf("sixes = -\n");

  }else {
    printf("6 = sixes\n", sixes);
  }


  if (street == -1)
  {
    printf("street = -\n");
  }else {

    printf("street = %d\n", street);
    
  }


  if (yahtzee == -1)
  {
    printf("yahtzee = -\n");
  }else {
    printf("yahtzee = %d\n", yahtzee);
  }



  int counterScore = 0;
  int scores[] = {ones, twos, threes, fours, fives, sixes, street, yahtzee};

  for (int i = 0; i < 8; i++)
  {
    if (scores[i] != -1)
    {
      counterScore++;
    }
    
  }


  if (counterScore == 8)
  {
    break;
  }
  
  
  


  

}


printf("Game over");





  return 0;
}
