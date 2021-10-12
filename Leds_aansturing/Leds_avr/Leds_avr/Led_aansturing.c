#include <avr/io.h>

//Test Code aanpassingen voor jur

#define  Knop_Test_Open PF1
#define  Knop_Test_Dicht PF2



#define Knop_B_O PL1	//Knop Bediening Open
#define Knop_B_D PL2	//Knop Bediening Dicht
#define Knop_B_Nood PL3	//Noodschakelaar
#define Knop_D_O PL4	//Detectie schakelaar Brug Open
#define Knop_D_D PL5	//Detectie schakelaar Brug Dicht




#define Led_1 PB7
#define Led_2 PB6



void Delay()
{
	long counter = 0;
	while (counter++ < 50000)
		asm("nop");
}


int main()
{
	PINF &= ~(1 << Knop_Test_Open);	
	PINF &= ~(1 << Knop_Test_Dicht);
	
	PINF &= ~(1 << Knop_B_D);
	PINF &= ~(1 << Knop_B_O);
	PINF &= ~(1 << Knop_B_Nood);
	PINF &= ~(1 << Knop_D_O);
	PINF &= ~(1 << Knop_D_D);

DDRB |= (1 << Led_1);
	DDRB |= (1 << Led_2);

	while (1)
	{
				
		if (!(PINF&(1 << Knop_Test_Open)))
		{
			PORTB  &= ~(1 << Led_1);
			PORTB |= (1 << Led_2);
		}
		else if (!(PINF&(1 << Knop_Test_Dicht)))
		{
			PORTB |= (1 << Led_1);
			PORTB &= ~(1 << Led_2);
		}
		else
		{
			PORTB |= (1 << Led_1);
			PORTB |= (1 << Led_2);

		}
	}
}