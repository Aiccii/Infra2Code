#include <button.h>

#define BUTTON_PIN PINC
#define BUTTON_DDR DDRC
#define BUTTON_PORT PORTC
#define BUTTON1 PC1
#define BUTTON2 PC2
#define BUTTON3 PC3



void enableButton(int button){
    // Assuming VMA209 shield button is connected to pin PC1
    // Initialize the button as input
    BUTTON_DDR &= ~(1 << BUTTON_PIN); // Set data direction register for the button pin as input
    BUTTON_PORT |= (1 << BUTTON_PIN); // Enable pull-up resistor for the button pin
}

int buttonPushed(int button){
   
   enableButton(button);

    // Check if the button is pushed
    if (bit_is_clear(PINC, button)){
        return 1; // Button is pushed
    } else {
        return 0; // Button is not pushed
    }
}

int buttonReleased(int button){
    // Initialize the button as input
    BUTTON_DDR &= ~(1 << BUTTON_PIN); // Set data direction register for the button pin as input
    BUTTON_PORT |= (1 << BUTTON_PIN); // Enable pull-up resistor for the button pin

    // Check if the button is released
    if ((BUTTON_PORT & (1 << BUTTON_PIN)) != 0){
        return 1; // Button is released
    } else {
        return 0; // Button is not released
    }
}

void enableButtonInterrupt() {
    // Set BUTTON1 (PC1) as input and enable pull-up resistor
    DDRC &= ~(1 << BUTTON1);
    PORTC |= (1 << BUTTON1);

    // Enable external interrupt on PCINT1 (Pin Change Interrupt 1)
    PCICR |= (1 << PCIE1);     // Enable pin change interrupt for PCINT[14:8]
    PCMSK1 |= (1 << PCINT9);   // Enable interrupt for PC1 (PCINT9)

    // Enable global interrupts
    sei();
}

void enableAllButtonInterrupt() {
    DDRC &= ~((1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3));
    PORTC |= (1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3);

   PCICR |= (1 << PCIE1);
   PCMSK1 |= _BV(PC1);
   PCMSK1 |= _BV(PC2);
   PCMSK1 |= _BV(PC3);

    sei();

}

int readButton(void) {
    // Basic debounce logic
    if (buttonPushed(BUTTON1 == 1)) {
    } 
    if (buttonPushed(BUTTON2 == 2)) {
    } 
    if (buttonPushed(BUTTON3 == 3)) {
    }
    return 0;
}

void enableAllButtons() {
    enableButton(BUTTON1);
    enableButton(BUTTON2);
    enableButton(BUTTON3);
}

