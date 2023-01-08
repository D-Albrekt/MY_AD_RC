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
	ADMUX |= (1<<REFS0) | (1<<ADLAR) //REFS1:REFS0 = 01 => external reference voltage on AREF, ADLAR leftshifts the result.
	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2)	//ADEN = AD ENable; 
	/*
	BELOW YOU SEE THE CALCULATION FOR THE ADPSx.
	ADPSX division factor between the system clock frequency and the input clock
	to the ADC. Since the CPU clock = 16MHz and sample cycle = 13 => 
	16 000 000 / 13 = 1 230 769 > 15 000 SPS => 1 230 769 /15 000 = 82. =>
	ADPS > 82 => ADPS = 128 => ADPS0 = ADPS1 = ADPS2 = 1.
	*/
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

