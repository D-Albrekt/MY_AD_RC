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

//Forward declarations
ADC_Init();

//Function implementation
ADC_Init() 
{
	ADMUX |= (1<<REFS0) | (1<<ADLAR) //REFS0 
	ADC	
}

int main(void)
{
    
    /* SETUP */
	DDRC &= ~(1<<PC0); //Analog input (A0) ska vara input -> DVS 0.
	DDRB |= 1; //FIXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX The three output registers.
	ADC_Init();
	
	/* Main program */
    while (1) 
    {
		
		PORTB |= (1<<PB5);
		_delay_ms(500);
		PORTB &= ~(1<<PB5);
		_delay_ms(500);
    }
}

