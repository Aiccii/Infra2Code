#include <avr/io.h>
#include "dim.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

void dimLed(int lednumber, int percentage, int duration) {
    int on_time = (percentage * duration) / 100;
    int off_time = duration - on_time;

    while (duration > 0) {
        // Turn on LED
        PORTB |= (1 << lednumber);
        _delay_ms(on_time);

        // Turn off LED
        PORTB &= ~(1 << lednumber);
        _delay_ms(off_time);

        // Decrement duration
        duration -= (on_time + off_time);
    }
}

void fadeInLed(int lednumber, int duration) {
    // Fade in from 0% to 100% in steps
    for (int i = 0; i <= 100; i++) {
        dimLed(lednumber, i, duration / 100);
    }
}

void fadeOutLed(int lednumber, int duration) {
    // Fade out from 100% to 0% in steps
    for (int i = 100; i >= 0; i--) {
        dimLed(lednumber, i, duration / 100);
    }
}
