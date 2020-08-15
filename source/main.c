/*	Author: dsale010@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:22
 *	Assignment: Lab #7 Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#define MAX 1023
#define MIN 48

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRB = 0xFF;    PORTB = 0x00;
    DDRD = 0xFF;    PORTD = 0X00;
    
    unsigned short adc;
    unsigned char outB, outD;
    
    ADC_init();

    /* Insert your solution below */
    while (1) {
        adc = ADC;
        if(adc >= MAX/2){
            outB = 0xFF;
            outD = 0x03;
        }
        else {
            outB = 0x00;
            outD = 0x00;
        }
        
        PORTB = outB;
        PORTD = outD;
    }
    return 1;
}
