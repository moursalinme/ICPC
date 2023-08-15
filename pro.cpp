// Interface a Blinking LED using AVR Microcontroller.
#include <util/delay.h>
#include <xc.h>

#define F_CPU 16000000UL //crystal oscillator 16mhZ (I set it to)  

int main(void) {
	
	DDRC = 0XFF;
	
	while(1) {
		PORTC = 0XFF;
		_delay_ms(1000);
		PORTC = 0X00;
		_delay_ms(1000);
	}
}


// Interface a stepper motor and control its direction using AVR Microcontroller
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{

	unsigned int x = 100;
	DDRA &= ~(1 << 1);
	PORTA = 0x02;
	DDRC = 0xFF;

	while (1) {

		if((PINA & (1 << 1)) == 0) {

			PORTC = 0x66; _delay_ms(x);
			PORTC = 0xCC; _delay_ms(x);
			PORTC = 0x99; _delay_ms(x);
			PORTC = 0x33; _delay_ms(x);
		}
		else {
			PORTC = 0x66; _delay_ms(x);
			PORTC = 0x33; _delay_ms(x);
			PORTC = 0x99; _delay_ms(x);
			PORTC = 0xCC; _delay_ms(x);
		}
	}
	return 0;
}



// Interface a stepper motor and control its speed using Arduino.
#include <Stepper.h>

#define STEPS 30
Stepper stepper(STEPS, 8, 9, 10, 11);

const int button = 13;
const int pot = A0;

void setup() {

	pinMode(button, INPUT_PULLUP);
}

int direction = 1, speed = 0;

void loop() {

	if ( digitalRead(button) == 0 && debounce() ) {
		direction *= - 1;
		while (debounce());
	}

	int val = analogRead(pot);

	if ( speed != map(val, 0, 1023, 5, 100) ) {

		speed = map(val, 0, 1023, 5, 100);
		stepper.setSpeed(speed);
	}

	stepper.step(direction);
}

bool debounce() {

	byte count = 0;
	
	for (byte i = 0; i < 5; i++) {
		if ( digitalRead(button) == 0 ) count++;
		delay(10);
	}

	if (count > 2) return 1;
	return 0;
}




// Interface a stepper motor and control its direction using Arduino.

#include <Stepper.h>
#define STEPS 30

Stepper stepper(STEPS, 8, 9, 10, 11);

const int button = 13;
const int pot = A0;

void setup() {

	pinMode(button, INPUT_PULLUP);
}

int direction = 1, speed = 0;

void loop()
{

	if ( digitalRead(button) == 0 &&  debounce() ) {
		direction *= - 1;
		while ( debounce() );
	}

	int val = analogRead(pot);
	
	if ( speed != map(val, 0, 1023, 5, 100) ) {

		speed = map(val, 0, 1023, 5, 100);
		stepper.setSpeed(speed);
	}
	stepper.step(direction);
}


bool debounce() {

	byte count = 0;
	for (byte i = 0; i < 5; i++) {
		if ( digitalRead(button) == 0 ) count++;
		delay(10);
	}

	if (count > 2) return 1;
	return 0;
}
