#include <avr/io.h>

void Delay()
{
	long counter = 0;
	while (counter++ < 50000)
		asm("nop");
}


int main()
{
	DDRB |= (1 << PB7);
	DDRB |= (1 << PB6);


	while (1)
	{
		PORTB |= (1 << PB7);
		PORTB |= (1 << PB6);
		Delay();
		PORTB &= ~(1 << PB7);
		PORTB &= ~(1 << PB6);
		Delay();
	}
}
