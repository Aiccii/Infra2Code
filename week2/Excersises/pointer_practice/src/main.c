#include <stdio.h>
#include <button.h>


#define MAX 8
#define SEVENFOLD 7


void printArray(int arr[]) {

  printf("Contents of array\n");

  for (int i = 0; i < MAX; i++) {

    

    printf("Address : %x has value : %d\n\n", (arr + i), *(arr + i));
    
  }
  

}


void makeArray(int arr[]) {

  for (int i = 0; i < MAX; i++) {

    *(arr + i) = i * SEVENFOLD;
  
  }

}



int	main() {
  
  int arr[MAX] = {0};

  makeArray(arr);

  printArray(arr);
  




  return 0;
}
