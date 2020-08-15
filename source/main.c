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
#define INTERVAL ((MAX - MIN) / 8)

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;    PORTA = 0xFF;
    DDRB = 0xFF;    PORTB = 0x00;
    DDRD = 0xFF;    PORTD = 0X00;
    
    ADC_init();

    /* Insert your solution below */
    while (1) {
        unsigned short adc = ADC;
        unsigned char outtie = 1;
        
        adc = 47;
        
        while( adc >= MIN ){
            outtie = (outtie << 1) | 0x01;
            adc -= INTERVAL;
        }
        
        PORTB = outtie;
        
    }
    return 1;
}
