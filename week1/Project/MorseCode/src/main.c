#include <avr/delay.h>
#include <stdio.h>
#include <usart.h>
#include <led.h>
#include <stdlib.h>
#include <ledChaos.h>
#include <time.h>




int main() {

  char *morseTable[36];
    

char a[] = "01";
char b[] = "1000";
char c[] = "1010";
char d[] = "100";
char e[] = "0";
char f[] = "0010";
char g[] = "110";
char h[] = "0000";
char i[] = "00";
char j[] = "0111";
char k[] = "101";
char l[] = "111";
char m[] = "11";
char n[] = "10";
char o[] = "111";
char p[] = "0110";
char q[] = "1101";
char r[] = "010";
char s[] = "000";
char t[] = "1";
char u[] = "001";
char v[] = "0001";
char w[] = "011";
char x[] = "1001";
char y[] = "1011";
char z[] = "1100";

char n0[] = "11111";
char n1[] = "01111";
char n2[] = "00111";
char n3[] = "00011";
char n4[] = "00001";
char n5[] = "00000";
char n6[] = "10000";
char n7[] = "11000";
char n8[] = "11100";
char n9[] = "11110";




  morseTable[0] = a;
  morseTable[1] = b;
  morseTable[2] = c;
  morseTable[3] = d;
  morseTable[4] = e;
  morseTable[5] = f;
  morseTable[6] = g;
  morseTable[7] = h;
  morseTable[8] = i;
  morseTable[9] = j;
  morseTable[10] = k;
  morseTable[11] = l;
  morseTable[12] = m;
  morseTable[13] = n;
  morseTable[14] = o;
  morseTable[15] = p;
  morseTable[16] = q;
  morseTable[17] = r;
  morseTable[18] = s;
  morseTable[19] = t;
  morseTable[20] = u;
  morseTable[21] = v;
  morseTable[22] = w;
  morseTable[23] = x;
  morseTable[24] = y;
  morseTable[25] = z;

  morseTable[26] = n0;
  morseTable[27] = n1;
  morseTable[28] = n2;
  morseTable[29] = n3;
  morseTable[30] = n4;
  morseTable[31] = n5;
  morseTable[32] = n6;
  morseTable[33] = n7;
  morseTable[34] = n8;
  morseTable[35] = n9;


  enableAllLeds(); 

  
    _delay_ms(1000);

    for (int i = 0; i < 4; i++) {
        lightDownLed(i);
        _delay_ms(250);
    }
    _delay_ms(1000);


      
      //dimLed(0, 1, 1000);

     // fadeInLed(1, 1000);    

         time_t timer;


    srand ( time(&timer));



    // Iterate through the morseTable array
    for (int i = 0; i < 5; i++) {

    int random = rand() % 36;

      _delay_ms(1000);
         


      

        // Get the pointer to the current letter array
        char *currentLetter = morseTable[random];
        
         
        // Iterate through the characters in the current letter array
        for (int j = 0; currentLetter[j]; j++) {

          _delay_ms(500);
            

            if (currentLetter[j] == '0') {
              lightUpAllLeds(); 
              _delay_ms(100);
              lightDownAllLeds();
            }
            else if (currentLetter[j] == '1' ) {
              lightUpAllLeds(); 
              _delay_ms(500);
              lightDownAllLeds();
            }

            


        }
        
  
    }

    




return 0;

}


