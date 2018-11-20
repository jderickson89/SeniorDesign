#include <atmel_start.h>
#include <avr/io.h>

// -------- Stepper Motor Definitions -------- //

#define FORWARD		 1		
#define	BACKWARD	-1
#define TURN		 200	// Steps per rotation. Dependent on motor.

#define MAX_DELAY	 255	// startup speed
#define MIN_DELAY	 8		// max cruise speed
#define ACCELERATION 16		// lower =  smoother but slower

#define RAMP_STEPS	 ((MAX_DELAY - MIN_DELAY)/ACCELERATION)

// -------- Stepper Motor Global Variables -------- //
const uint8_t motorPhases[] = {
	(1 << PB0)|(1 << PB2 ),
	()|(),
	()|(),
	()|(),
	};

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
	}
}
