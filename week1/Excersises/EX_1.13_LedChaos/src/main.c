#define __DELAY_BACKWARD_COMPATIBLE__  
#include <util/delay.h> 
#include <stdlib.h>
#include <led.h>




int main () {
  

  while (1)
  {
    ledChaos(); // i just created the function in the led library
  }
  
  



}