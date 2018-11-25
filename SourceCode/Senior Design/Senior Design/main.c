/*
 * Senior Design.c
 * Single Motor Test Code
 *
 * Created: 11/18/2018 1:29:49 PM
 * Author : Derickson
 */ 

// ------- Preamble -------- //

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ENA 128;
#define ENB 128;

// -------- Functions -------- //
static inline void motorInit(){
	// ---- L298 INPUT Set Up ---- //
		DDRB |= 0b00111001;				// Set PB0,PB3,PB4,PB5 as output
		
	// ---- L298 ENABLE Set Up --- //
		DDRB |= 0b00000110;				//Set pins PB1 and PB2 as OUTPUT
		TCCR1A = 0b11110001;			//Configure timer 1 for fast PWM
		TCCR1B = 0b00000010;
		TCCR1C = 0b00000000;
		OCR1A = 0;
		OCR1B = 0;

}
static inline void setBridgeState(uint8_t INPUT1,uint8_t INPUT2, uint8_t INPUT3, uint8_t INPUT4,uint8_t ENABLEA, uint8_t ENABLEB){

	if(INPUT1){ PORTB |=  (1 << PINB0); }
		  else{	PORTB &= ~(1 << PINB0); }
			  
	if(INPUT2){ PORTB |=  (1 << PINB3); }
		  else{	PORTB &= ~(1 << PINB3); }
			  
	if(INPUT3){ PORTB |=  (1 << PINB4); }
		  else{	PORTB &= ~(1 << PINB4); }
			  
	if(INPUT4){ PORTB |=  (1 << PINB5); }
		  else{	PORTB &= ~(1 << PINB5); }
			  
	OCR1A = ENABLEA;
	OCR1B = ENABLEB; 


}

int main(void){
	
	motorInit();
				
	while(1){
		for(int i = 0; i < 25 ; i++){
			setBridgeState(1,0,1,0,32,32);
			_delay_ms(25);
			setBridgeState(0,1,1,0,32,32);
			_delay_ms(25);
			setBridgeState(0,1,0,1,32,32);
			_delay_ms(25);		
			setBridgeState(1,0,0,1,32,32);
			_delay_ms(25);
		}
		
		for(int i = 0; i < 25 ; i++){
			setBridgeState(0,1,0,1,32,32);
			_delay_ms(25);
			setBridgeState(0,1,1,0,32,32);
			_delay_ms(25);
			setBridgeState(1,0,1,0,32,32);
			_delay_ms(25);
			setBridgeState(1,0,0,1,32,32);
			_delay_ms(25);
		}
	}
	return(0);
}

