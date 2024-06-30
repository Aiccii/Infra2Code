#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>



void enableOneLed(int led);

void enableMultipleLeds(uint8_t led); 

void enableAllLeds ();

void lightUpOneLed(int led); 

void lightUpMultipleLeds (uint8_t led);

void lightUpAllLeds (); 

void lightDownOneLed(int led); 

void lightDownMultipleLeds (uint8_t led);

void lightDownAllLeds (); 

void lightToggleOneLed(int led);

void lightDownLed ( int lednumber );

void lightUpLed ( int lednumber );

void enableLed ( int lednumber );

void ledChaos();


void dimLed(int lednumber, int percentage, int duration);   

void fadeInLed(int lednumber, int duration);   


void fadeOutLed(int lednumber, int duration); 
