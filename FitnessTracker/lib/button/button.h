#include <stdio.h>
#include <usart.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>

void enableButton( int button );
int buttonPushed( int button );
int buttonReleased( int button );
void enableAllButtonInterrupt();
void enableAllButtons();
int readButton();