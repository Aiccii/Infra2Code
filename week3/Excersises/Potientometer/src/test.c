#include <stdio.h>


int main9()
{

    int* p;
    int a = 10;
    p = &a;

    int arr[3] = {11, 22, 33};

    int* parr;
    parr = arr;



    printf("a is %d\n", a);
    printf("p is %u\n", p);
    printf("&a is %u\n", &a);
    printf("&p is %u\n", &p);

    printf("\n\n");

    printf("arr is %u\n", arr);
    printf("parr is %u\n", parr);
    printf("*parr is %u\n", *parr);
    printf("parr is %u\n", parr + 1);
    printf("*parr + 1 is %u\n", *(parr + 1)); // to get the second value in the array
    printf("arr is %u\n", *arr);







    return 0;
}