#include <stdio.h>
#include <usart.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>




void enableButton( int button );
int buttonPushed( int button );
int buttonReleased( int button );
void checkPressedButton();
void enableButtonInterrupt(int button);
void enableAllButtonInterrupts();
int returnPressedButton();
void trafficLight();
void enableAllButtons();
