#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

int main(void) {
    DDRD |= (1 << PD5);
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2); 
    while (1) {
	if(!(PIND &(1<<PD2)))
	    PORTD |=  (1 << PD5);
	else
	    PORTD &= ~(1 << PD5);
    }
    return 0;
}
