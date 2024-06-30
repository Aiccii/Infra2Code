#include <led.h>
#include <display.h>
#include <button.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <potentio.h>
#include <buzzer.h>
#include <usart.h>

#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3



typedef struct {
    int time;
    int jumps;
    int lives;
} stats;


void initTimer0()
{
    TCCR0A |= _BV( WGM00 ) | _BV( WGM01 );
    TCCR0B |= (1 << CS02) | (1 << CS00); // sets prescaler 1024, (1024 / 16,000,000) seconds,a 16 MHz clock frequency.
    TIMSK0 |= (1 << TOIE0); // enable overflow interrupt
    sei();
}
 


// global variables

int flappyPos = 0; // the position of the bird

//int buttonPressed = 0; // returns which button has been pressed

int delayObstacles = 0; // makes the obstacles move faster or slower

int randomObstacles = 0; // the obstacles value stored in here

int beforeGameStart = 0; // just a checker for before the game starts

int levelChoosen = 0; // just a checker for before the levels are selected

int potentio = 0; // to store the potentiometer value

int pause = 0; // the value of the pause

int play = 0;

int holaNum = 0;  // sets the hola screen to false

int lose = 0; // sets the loose boolean flag to false

int flappyTime = 0; // time in air for flappy

int speedOfMovement = 0;

int newGame = 0;

stats playerStats;


ISR(TIMER0_OVF_vect) {

    playerStats.time++;

}

// coded the logic for the buttons using interrupts
ISR ( PCINT1_vect ) {

  // the jump function
  if (buttonPushed(BUTTON1) == 1 && play == 1 && pause == 0) {

    playerStats.jumps++;
    
    // the jump function for less than 2
    if (flappyPos < 2)
    {
      flappyPos++;
      flappyTime = 0;
    }

    // keeps the flappy a float on the top
    if (flappyPos == 2 ) {
      flappyPos = 2;
      flappyTime = 0;
    }
    
    
  }

  // the pause function
  if (buttonPushed(BUTTON2) == 1 && pause == 0 && play == 1 ){
    pause = 1;
    _delay_ms(150);
  }

  // the continue logic
  if (buttonPushed(BUTTON2) == 1 && pause == 1 && play == 1){
    pause = 0;
    _delay_ms(150);
  }


  // makes the random dance disappear when any button is pressed
  if ((buttonPushed(BUTTON1) == 1 || buttonPushed(BUTTON2) == 1 || buttonPushed(BUTTON3) == 1 ) && beforeGameStart == 0){
    beforeGameStart = 1;
    _delay_ms( 250);
  }

   // makes the hola disappear when any button is pressed
  if ((buttonPushed(BUTTON1) == 1 || buttonPushed(BUTTON2) == 1 || buttonPushed(BUTTON3) == 1 ) && beforeGameStart == 1){
    holaNum = 1;
    _delay_ms( 250);
  }


  // makes the game start from the level screen
  if ((buttonPushed(BUTTON1) == 1 || buttonPushed(BUTTON2) == 1 || buttonPushed(BUTTON3) == 1 ) && holaNum == 1){
    play = 1;
    _delay_ms(150);
    
  }



}





int main() {


  initUSART();
  


  while(1) {

  initDisplay();

  enableAllButtons();
  enableAllButtonInterrupts();

    
    
    playerStats.time = 0;
    playerStats.jumps = 0;
    playerStats.lives = 3;


    int *array = malloc(300 * sizeof(int));
  
    if (array == NULL) {
 
      printf("Memory allocation failed\n");

    }
    else {

      printf("ok\n");

    }

    int *ptrPotentio = &potentio;

    // before the game starts it gets the potentiometer value and uses it as a seed to initialize the array
    *ptrPotentio = potentioValue();

    srand(*ptrPotentio);
    // Fill the array with random numbers, generated from the seed from potentio
    for (int i = 0; i < 300; i++) {
        array[i] = rand() % 3;
    }

     for (int i = 0; i < 300; i++) {
        printf("%d ", array[i]);
      }


  // just some random led blinking stuff before the game starts
  while (beforeGameStart != 1) {

      writeFlappyBird();

    


    for (int i = 0; i < 30; i++)
    {
      int randomGame = rand() % 3;
      int randomSegment = rand() % 4;

    writeFalppyToSegment(randomSegment, randomGame);
    _delay_ms(7);
    writeFalppyToSegment(randomSegment, randomGame);
    _delay_ms(7);
    writeFalppyToSegment(randomSegment, randomGame);
    _delay_ms(7);
    writeFalppyToSegment(randomSegment, randomGame); 
    _delay_ms(7);
    }
    
    



    
  }

     // game start music 
      enableBuzzer();
      playTone(200, 100);
      _delay_ms(200);
      playTone(400, 200);
      _delay_ms(200);
      playTone(1400, 800);
      _delay_ms(200);
      
      


    // just to display the HOLA, idk i just found it nice
     while (holaNum != 1){

      writeCharToSegment(0, 'H');
      _delay_ms(3);
      writeCharToSegment(1, 'O');
      _delay_ms(3);
      writeCharToSegment(2, 'L');
      _delay_ms(3);
      writeCharToSegment(3, 'A');
      _delay_ms(3);
    

    
    }
  


  // to choose the level
  while (play != 1) {

    *ptrPotentio = potentioValue(); // write by reference
    writeLevelForFloppy(*ptrPotentio); // readby reference

    speedOfMovement = *ptrPotentio * 140;
    pause = 0;

    

  }
  
  

while (1)
{
  

  initTimer0();
      // the following 4 lines are the core of the flappy movement, and the pieces movement
    writeFalppyToSegment(0, flappyPos);
    _delay_ms(1);
    writeFalppyToSegment(1, *(array + randomObstacles));
    writeFalppyToSegment(2, *(array + 1 + randomObstacles));
    writeFalppyToSegment(3, *(array + 2 + randomObstacles));  
  while (playerStats.lives != 0 && pause != 1) {
    
  
  
  // makes the obstacles move, it's based on the speed selected using the potentiometer value
  if (delayObstacles == (2000 - speedOfMovement)) {
    randomObstacles++;

      if ((*(array + randomObstacles - 1) == flappyPos))
    {
      printf("speed : %d\n", speedOfMovement);
      playerStats.lives--;
    }


     delayObstacles = 0;  
     
     }



// makes the bird go down
if (flappyTime == 500) {


  if (flappyPos > 0 ) {

    flappyPos--;

  }


  flappyTime = 0;

    
}







    // the following 4 lines are the core of the flappy movement, and the pieces movement
    writeFalppyToSegment(0, flappyPos);
    _delay_ms(1);
    writeFalppyToSegment(1, *(array + randomObstacles));
    writeFalppyToSegment(2, *(array + 1 + randomObstacles));
    writeFalppyToSegment(3, *(array + 2 + randomObstacles));  


    
    
    // lives left unsigned bit for the LEDs
    uint8_t lives_3 = 0b00000111;
    uint8_t lives_2 = 0b00000011;
    uint8_t lives_1 = 0b00000001;


  // enables all the leds initially
  enableMultipleLeds(lives_3);



  switch (playerStats.lives) {
    
    case  3 :
    lightDownAllLeds();
    lightUpMultipleLeds(lives_3);
    
    break;

    case  2 :

    lightDownAllLeds();
    lightUpMultipleLeds(lives_2);
    
    break;

    case  1 :

    lightDownAllLeds();
    lightUpMultipleLeds(lives_1);

    break;
    
    default:
    lightDownAllLeds();
    break;
  }



  if (playerStats.lives == 0 ) {

    lose = 1;

    while (newGame != 2) {

      for (int i = 0; i < 1000; i++)
      {
       writeCharToSegment(0, 'L');
      _delay_ms(1);
      writeCharToSegment(1, 'O');
      _delay_ms(1);
      writeCharToSegment(2, 'S');
      _delay_ms(1);
      writeCharToSegment(3, 'E');
      _delay_ms(1);
      }
      
      
      newGame++;

     
      printf("\n**********************   Game End, You Lost   **********************\n");
      printf("Total Jumps: %d\n", playerStats.jumps);
      printf("Total Seconds Stayed Alive: %d\n", (playerStats.time / 60));
    
      
      playTone(1400, 250);
      _delay_ms(200);
      playTone(400, 350);
      _delay_ms(200);
      playTone(200, 450);
      _delay_ms(200);

      _delay_ms(4000);


        // after the game ends, it waits 5 seconds before doing a new game loop
        if (newGame >= 1) {
          
          flappyPos = 0;
       
          //buttonPressed = 0;
       
          delayObstacles = 0;
       
          randomObstacles = 0;
       
          beforeGameStart = 0;
       
          levelChoosen = 0;
       
          *ptrPotentio = 0;
       
          play = 0;
       
          holaNum = 0;
       
          lose = 0;
       
          flappyTime = 0;
       
          speedOfMovement = 0;
       

          free(array);
          
          break;
       
        }
      
    
    }


    
    
    
    
    
  }

  
  

  //_delay_ms(1);
  delayObstacles++;
  flappyTime++;

  }


      if (newGame >= 1) {
          
          newGame = 0;

         // pause = 0;

          
          break;
       
        }


}

  

}


}


   







