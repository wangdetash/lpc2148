//program to interface 3*4 keypad numeric keypad
#include <LPC214X.H>

void transmit(char);
char keypad();

void main()
{	
	char a;
	PINSEL0=0X00000005;
	IODIR0=0X00000F01;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;
	a=keypad();
	transmit(a);
}

void transmit(char a)
{
	U0THR=a;
	while(!(U0LSR&0X20));
}

char keypad()
{
	IOCLR0=0XFFFF;
	IOSET0=0X0100;

	while(1)
	{
		if(IOSET0==0X0100)
		{
			if(	IOPIN0&(1<<12))
			{
				while(IOPIN0&(1<<12));return '1';
			}
			else if(IOPIN0&(1<<13))
			{
				while(IOPIN0&(1<<13));return '2';
			}
			else if(IOPIN0&(1<<14))
			{
				while(IOPIN0&(1<<14));return '3';
			}
			IOCLR0=0XFFFF;
			IOSET0=0X0200;
		}

		if(IOSET0==0X0200)
		{
			if(	IOPIN0&(1<<12))
			{
				while(IOPIN0&(1<<12));return '4';
			}
			else if(IOPIN0&(1<<13))
			{
				while(IOPIN0&(1<<13));return '5';
			}
			else if(IOPIN0&(1<<14))
			{
				while(IOPIN0&(1<<14));return '6';
			}
			IOCLR0=0XFFFF;
			IOSET0=0X0400;
		}

		if(IOSET0==0X0400)
		{
			if(	IOPIN0&(1<<12))
			{
				while(IOPIN0&(1<<12));return '7';
			}
			else if(IOPIN0&(1<<13))
			{
				while(IOPIN0&(1<<13));return '8';
			}
			else if(IOPIN0&(1<<14))
			{
				while(IOPIN0&(1<<14));return '9';
			}
			IOCLR0=0XFFFF;
			IOSET0=0X0800;
		}

		if(IOSET0==0X0800)
		{
			if(	IOPIN0&(1<<12))
			{
				while(IOPIN0&(1<<12));return '*';
			}
			else if(IOPIN0&(1<<13))
			{
				while(IOPIN0&(1<<13));return '0';
			}
			else if(IOPIN0&(1<<14))
			{
				while(IOPIN0&(1<<14));return '#';
			}
			
		}
	}
}

