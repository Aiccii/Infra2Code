#include "morse.h"
#include <util/delay.h>





void morseTrainer() 
{

    enableLeds(LEDS);

    Morse table[TABLE_LENGTH];
    
    
    countDownPattern();

    printf("\n==== MORSE TRAINER ====\n");

    for (int i = 0; i < 10; i++) {
        Morse *random = &table[getRandomIndex(table)];
        blinkCode(random->code);
        _delay_ms(1000);
        printf("[%d] Solution: %c (%s)\n", i + 1, random->ch, random->code);
        _delay_ms(1000);
    }

    printf("\n==== END OF MORSE TRAINER ====");
    
}





// lights down enabled led's
void countDownLed() 
{
    _delay_ms(1000);

    for (int i = 0; i < 4; i++) {
        lightDownLed(i);
        _delay_ms(1000);
    }
    _delay_ms(1000);
}




void blinkCode(char *code) 
{
    for (int i = 0; i < strlen(code); i++) {

        lightUpAllLeds();

        if (code[i] == '0') {
            _delay_ms(SHORT_BLINK);
        } else {
            _delay_ms(LONG_BLINK);
        }

        lightDownAllLeds(); 
        _delay_ms(500);
    }
}




int returnRandom() {

    return rand() % 36;

}




char *getValue(char character) 
{

    switch(character) {

        case 'a': return "01";
        case 'b': return "1000";
        case 'c': return "1010";
        case 'd': return "100";
        case 'e': return "1";
        case 'f': return "0010";
        case 'g': return "110";
        case 'h': return "0000";
        case 'i': return "00";
        case 'j': return "0111";
        case 'k': return "101";
        case 'l': return "0100";
        case 'm': return "11";
        case 'n': return "10";
        case 'o': return "111";
        case 'p': return "0110";
        case 'q': return "1101";
        case 'r': return "010";
        case 's': return "000";
        case 't': return "1";
        case 'u': return "001";
        case 'v': return "0001";
        case 'w': return "011";
        case 'x': return "1001";
        case 'y': return "1011";
        case 'z': return "1100";
        case '0': return "11111";
        case '1': return "01111";
        case '2': return "00111";
        case '3': return "00011";
        case '4': return "00001";
        case '5': return "00000";
        case '6': return "10000";
        case '7': return "11000";
        case '8': return "11100";
        case '9': return "11110";
        default: return "1111111"; 
    }



}