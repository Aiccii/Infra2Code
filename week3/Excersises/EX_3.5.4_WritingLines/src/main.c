#include <avr/io.h>
#include <button.h>
#include <led.h>
#include <usart.h>
#include <string.h>
#include <stdlib.h>


void writeLinesOnHeap(char sentence []) {

    // allocate memory for the sentence on heap
    char *heap_sentence = calloc((strlen(sentence) + 1), sizeof(char));
    
    if (!heap_sentence) {
        printf("Memory allocation failed\n");
        return 1;

    }else{

      // copy the sentence into allocated memory
    strcpy(heap_sentence, sentence);
    
    
    printf("%s is on heap\n", heap_sentence);
    
    // freeing the memory seems to fix the problem of no allocation after line 44?
    free(heap_sentence);

    }
    
    

}


int main() {

  char sentence[] = "I am not allowed to speak in class.";
  

  if (returnPressedButton() == 1) {

    
    for ( int i = 0; i <= 100; i++ )  {

      printf("%d : %s\n", i, sentence);
      writeLinesOnHeap(sentence);

        
    }
    
  }

}

  
  
