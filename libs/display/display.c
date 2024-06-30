#include "display.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <unistd.h> 
#include <time.h>

/* Segment byte maps for numbers 0 to 9 */
const uint8_t SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99,
                               0x92, 0x82, 0xF8, 0X80, 0X90};

/* Byte maps to select digit 1 to 4 */
const uint8_t SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};


const uint8_t ALPHABET_MAP[] = {0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0xC2,
                                0x89, 0xCF, 0xE1, 0x8A, 0xC7, 0xEA, 0xC8,
                                0xC0, 0x8C, 0x4A, 0xCC, 0x92, 0x87, 0xC1,
                                0xC1, 0xD5, 0x89, 0x91, 0xA4};

const uint8_t FLAPPY_MAP[] = {0xF7, 0xBF, 0xFE};





void initDisplay() {
  sbi(DDRD, LATCH_DIO);
  sbi(DDRD, CLK_DIO);
  sbi(DDRB, DATA_DIO);
}


// loop through seven segments of LED display and shift the correct bits in the
// data register
void shift(uint8_t val, uint8_t bitorder) {
  uint8_t bit;

  for (uint8_t i = 0; i < NUMBER_OF_SEGMENTS; i++) {
    if (bitorder == LSBFIRST) {
      bit = !!(val & (1 << i));
    } else {
      bit = !!(val & (1 << (7 - i)));
    }
    // write bit to register
    if (bit == HIGH)
      sbi(PORTB, DATA_DIO);
    else
      cbi(PORTB, DATA_DIO);

    // Trigger the clock pin so the display updates
    sbi(PORTD, CLK_DIO);
    cbi(PORTD, CLK_DIO);
  }
}

//Writes a digit to a certain segment. Segment 0 is the leftmost.
void writeNumberToSegment(uint8_t segment, uint8_t value) {
  cbi(PORTD, LATCH_DIO);
  shift(SEGMENT_MAP[value], MSBFIRST);
  shift(SEGMENT_SELECT[segment], MSBFIRST);
  sbi(PORTD, LATCH_DIO);
}



//Writes a nuber between 0 and 9999 to the display. To be used in a loop...
void writeNumber(int number) {
  if (number < 0 || number > 9999) return;
  writeNumberToSegment(0, number / 1000);
  writeNumberToSegment(1, (number / 100) % 10);
  writeNumberToSegment(2, (number / 10) % 10);
  writeNumberToSegment(3, number % 10);
}


//Writes a number between 0 and 9999 to the display and makes sure that it stays there a certain number of millisecs.
//Note: the timing is approximate; the amount of time writeNumberToSegment takes is not accounted for...
void writeNumberAndWait(int number, int delay) {
  // if the number is less than 0 or greater than 9999 do nothing
  if (number < 0 || number > 9999) return;

  // else
  for (int i = 0; i < delay / 20; i++) {
    writeNumberToSegment(0, number / 1000);
    _delay_ms(5);
    writeNumberToSegment(1, (number / 100) % 10);
    _delay_ms(5);
    writeNumberToSegment(2, (number / 10) % 10);
    _delay_ms(5);
    writeNumberToSegment(3, number % 10);
    _delay_ms(5);
  }
}



void writeFalppyToSegment(uint8_t segment, char index) {

  
       uint8_t value;

      //
        value = FLAPPY_MAP[index]; // Get the value from ALPHABET_MAP
        PORTD &= ~(1 << LATCH_DIO);
        shift(value, MSBFIRST); 
        shift(SEGMENT_SELECT[segment], MSBFIRST);
        PORTD |= (1 << LATCH_DIO);
  

}


void writeLevelForFloppy(int Level) {

    writeCharToSegment(0, 'l');
    _delay_ms(5);
    writeFalppyToSegment(1, 1);
    _delay_ms(5);
    writeNumberToSegment(2, (Level / 10) % 10);
    _delay_ms(5);
    writeNumberToSegment(3, Level % 10);
    _delay_ms(5);



}








void writeCharToSegment(uint8_t segment, char character) {

  if (character >= 'a' && character <= 'z') {
    character = character - 32;
  }
  

  uint8_t value;

      // Check if the character is a letter from A to Z
    if (character >= 'A' && character <= 'Z') {
        // Calculate the index in ALPHABET_MAP
        uint8_t index = character - 'A'; // get the index of the character
        value = ALPHABET_MAP[index]; // Get the value from ALPHABET_MAP
        PORTD &= ~(1 << LATCH_DIO);
        shift(value, MSBFIRST); 
        shift(SEGMENT_SELECT[segment], MSBFIRST);
        PORTD |= (1 << LATCH_DIO);
    } else {
        // For characters not in the alphabet, display an empty segment (space)
        value = SPACE;
    }

    

}




/*
// this function writes a string in the board, used for 4 letter words
void writeString(char* str) {

uint8_t value;

while (1)
{

    // Iterate through the first 4 characters of the string
    for (uint8_t i = 0; i < 4; i++) {
      
        uint8_t index = str[i] - 'A';
        value = ALPHABET_MAP[index]; // Get the value from ALPHABET_MAP
        PORTD &= ~(1 << LATCH_DIO);
        shift(value, MSBFIRST);
        shift(SEGMENT_SELECT[i], MSBFIRST);
        PORTD |= (1 << LATCH_DIO);

    }
    
    }

}


*/



// this function writes a string in the board, used for 4 letter words
void writeString(char* str) {


  writeCharToSegment(0, str[0]);
  _delay_ms(5);
  writeCharToSegment(1, str[1]);
  _delay_ms(5);
  writeCharToSegment(2, str[2]);
  _delay_ms(5);
  writeCharToSegment(3, str[3]);
  _delay_ms(5);


}

// ahh yes the best one to write multiple chars that loop
void writeStringAndWait(char* str, int delay) {

    
    int elapsedTime = 0;
    
    // Iterate through the string
    
    for (int i = 0; i < delay / 20 ; i++) {
    
        // Write the character at position i
        writeCharToSegment(0, str[0]);
        _delay_ms(5);
        writeCharToSegment(1, str[1]);
        _delay_ms(5);
        writeCharToSegment(2, str[2]);
        _delay_ms(5);
        writeCharToSegment(3, str[3]);
        _delay_ms(5);
        
        // Shift the string and update the display

        
    
    }

    

}

    

    void writeFlappyBird() {

    
      for (int i = 0; i < 60; i++)
      {
       writeCharToSegment(0, 'f');
       _delay_ms(5);
      writeCharToSegment(1, 'l');
      _delay_ms(5);
      writeCharToSegment(2, 'a');
      _delay_ms(5);
      writeCharToSegment(3, 'p');
      _delay_ms(5);

      }
      
      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, 'l');
        _delay_ms(5);
      writeCharToSegment(1, 'a');
      _delay_ms(5);
      writeCharToSegment(2, 'p');
      _delay_ms(5);
      writeCharToSegment(3, 'p');
      _delay_ms(5);
      }


      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, 'a');
        _delay_ms(5);
      writeCharToSegment(1, 'p');
      _delay_ms(5);
      writeCharToSegment(2, 'p');
      _delay_ms(5);
      writeCharToSegment(3, 'y');
      _delay_ms(5);
        
      }

      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, 'p');
        _delay_ms(5);
      writeCharToSegment(1, 'p');
      _delay_ms(5);
      writeCharToSegment(2, 'y');
      _delay_ms(5);
      writeCharToSegment(3, ' ');
      _delay_ms(5);
        
      }

      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, 'p');
        _delay_ms(5);
      writeCharToSegment(1, 'y');
      _delay_ms(5);
      writeCharToSegment(2, ' ');
      _delay_ms(5);
      writeCharToSegment(3, 'b');
      _delay_ms(5);
        
      }

      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, 'y');
        _delay_ms(5);
      writeCharToSegment(1, ' ');
      _delay_ms(5);
      writeCharToSegment(2, 'b');
      _delay_ms(5);
      writeCharToSegment(3, 'i');
      _delay_ms(5);
        
      }


      for (int i = 0; i < 20; i++)
      {
        writeCharToSegment(0, ' ');
        _delay_ms(5);
      writeCharToSegment(1, 'b');
      _delay_ms(5);
      writeCharToSegment(2, 'i');
      _delay_ms(5);
      writeCharToSegment(3, 'r');
      _delay_ms(5);
        
      }


      for (int i = 0; i < 60; i++)
      {
        writeCharToSegment(0, 'b');
        _delay_ms(5);
      writeCharToSegment(1, 'i');
      _delay_ms(5);
      writeCharToSegment(2, 'r');
      _delay_ms(5);
      writeCharToSegment(3, 'd');
      _delay_ms(5);
        
      }


      

    


    
  }





  
    




