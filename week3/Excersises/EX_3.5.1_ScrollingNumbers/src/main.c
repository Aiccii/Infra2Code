#include <display.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <usart.h>



int main() {

  initDisplay();
  initUSART();

  int sequence = 1234;
  int seqArr[10] = {1234, 2345, 3456,4567,}


  while (1)
  
  {
    writeNumberAndWait(sequence, 1000);
           // Extract the current sequence
        int current_sequence = sequence;

        // Extract the first digit (leftmost digit)
        int first_digit = current_sequence / 1000;
        
        // Remove the first digit by taking modulus of 1000
        current_sequence = current_sequence - (first_digit * 1000);

        // Shift left by multiplying current sequence by 10
        current_sequence *= 10;

        // Append the first digit as the new last digit

        
          current_sequence += first_digit + 4;

        

        // Update sequence with the shifted sequence
        sequence = current_sequence;

  }
  

     

     

    


}



