/*
 * RC_SOFT.c
 *
 * Created: 2022-12-28 16:22:39
 * Author : albre
 */ 


#define F_CPU 16000000UL		//clockfrequence

//Libraries
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


int main(void)
{
    
    /* Replace with your application code */
    while (1) 
    {
		
		PORTB |= (1<<PB5);
		_delay_ms(500);
		PORTB &= ~(1<<PB5);
		_delay_ms(500);
    }
}

