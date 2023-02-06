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


//Variables and contants
const char FORWARD = PB0;
const char REVERSE = PD7;	
uint8_t Input_volt;

//Forward declarations
void ADC_Init();
uint8_t ADC_read();
void forward();
void reverse();
void gas(uint8_t speed);

//Function implementation
void ADC_Init() 
{
	ADMUX |= (1<<REFS0) | (1<<ADLAR); //REFS1:REFS0 = 01 => external reference voltage on AREF, ADLAR leftshifts the result.
	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);	//ADEN = AD ENable; 
	/*
	BELOW YOU SEE THE CALCULATION FOR THE ADPSx.
	ADPSX division factor between the system clock frequency and the input clock
	to the ADC. Since the CPU clock = 16MHz and sample cycle = 13 => 
	16 000 000 / 13 = 1 230 769 > 15 000 SPS => 1 230 769 /15 000 = 82. =>
	ADPS > 82 => ADPS = 128 => ADPS0 = ADPS1 = ADPS2 = 1.
	*/
}
uint8_t ADC_read()
{
	ADCSRA |= (1<<ADSC);
	while ((ADCSRA & (1<<ADSC)) != 0)
	{
	}
	return ADCH;
}

void forward()
{
	PORTB |= (1<<FORWARD);
	PORTD &= ~(1<<REVERSE);
}
void reverse()
{
	PORTB &= ~(1<<FORWARD);
	PORTD |= (1<<REVERSE);
}
void gas(uint8_t speed)
{	
	//speed *= 10;
	for (speed; speed > 0; speed--)
	{
		 PORTB |= (1<<PB3);
	}
	  PORTB &= ~(1<<PB3);
}

int main(void)
{
    
    /* SETUP */
	DDRC &= ~(1<<PC0); //Analog input (A0) ska vara input -> DVS 0.
	DDRB |= (1<<PB3) | (1<<PB0); //PB 3 = Arduinopin 11 (PWM), PB0 = Arduino pin 8.
	DDRD |= (1<<PD7); //PD7 = Arduinopin 7
	ADC_Init();
	PORTB = (1<<PB3) | (1<<PB0);
	PORTD = (1<<PD7);
	/* Main program */
    while (1) 
    {
		
		Input_volt = ADC_read();	//Value 0-255. (8 bit number)
		reverse();
		//forward();
		PORTB |= (1<<PB3);
		//gas(Input_volt);
		//_delay_ms(1000);
		//reverse();
		//gas(Input_volt);
		//_delay_ms(1000);
		
		
		
    }
}
