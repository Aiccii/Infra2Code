#include <led.h>
#include <avr/io.h>
#include <util/delay.h>


void enableOneLed(int ledNumber) {
    DDRB |= (1 << (PB2 + ledNumber));
}

void enableMultipleLeds(uint8_t leds) {
    DDRB |= leds << PB2;
}

void enableAllLeds() {
    enableOneLed(0);
    enableOneLed(1);
    enableOneLed(2);
    enableOneLed(3);
}

void disableAllLeds() {
    DDRB &= ~0b00111100;
}

void lightUpOneLed(int ledNumber) {
    PORTB &= ~(1 << (PB2 + ledNumber));
}

void lightUpMultipleLeds(uint8_t leds) {
    PORTB &= ~(leds);
}

void lightUpAllLeds() {
    PORTB &= ~0b00111100;
}

void lightDownOneLed(int ledNumber) {
    PORTB |= (1 << (PB2 + ledNumber));
}

void lightDownMultipleLeds(uint8_t leds) {
    PORTB |= (leds);
}

void lightDownAllLeds() {
    PORTB |= 0b00111100;
}

void lightToggleOneLed(int ledNumber) {
    PORTB ^= (1 << (PB2 + ledNumber));
}

void dimLed(int ledNumber, int percentage, int duration) {
    int on_time = (percentage * duration) / 100;
    int off_time = duration - on_time;

    while (duration > 0) {
        PORTB |= (1 << ledNumber);
        _delay_ms(on_time);
        PORTB &= ~(1 << ledNumber);
        _delay_ms(off_time);
        duration -= (on_time + off_time);
    }
}

void fadeInLed(int ledNumber, int duration) {
    for (int i = 0; i <= 100; i++) {
        dimLed(ledNumber, i, duration / 100);
    }
}

void fadeOutLed(int ledNumber, int duration) {
    for (int i = 100; i >= 0; i--) {
        dimLed(ledNumber, i, duration / 100);
    }
}

void randomLEDDance(int duration) {
    for (int i = 0; i < duration * 10; i++) {  
        int led = rand() % 4;
        lightUpOneLed(led);
        _delay_ms(100);
        lightDownOneLed(led);
        _delay_ms(100);
    }
}

void countdownPattern(void) {
    for (int i = 0; i < 4; i++) {
        lightUpOneLed(i);
        _delay_ms(500);
    }
    for (int i = 3; i >= 0; i--) {
        lightDownOneLed(i);
        _delay_ms(500);
    }
}

void blinkLed(void) {
    enableOneLed(0);

    lightUpOneLed(0);
    _delay_ms(500);

    lightDownOneLed(0);
    _delay_ms(500);
}