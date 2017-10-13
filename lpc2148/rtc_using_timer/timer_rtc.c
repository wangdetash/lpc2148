//program to implement realtime clock using internal timer
#include <LPC214X.H>
#include <stdio.h>


char a[20];
char hr=0,min=0,sec=0;


void rtc()
{
 	if(sec<59)
 	{
 		sec=sec+1;
 		
 	}
 	else if(min<59)
 		{
 			sec=0;
 			min=min+1;
 			
 		}
 	else if(hr<23)
 		{
 			sec=0;
 			min=0;
 			hr=hr+1;
 		}
}

void timer()__irq
{
	
	rtc();
	T0IR=1;
	VICVectAddr=0;

}


void rtc_init()
{
	T0CTCR=0X00;
	T0PR=12000;    
	T0TCR=0X02;
	T0MCR=3;
	T0MR0=1;
	T0IR=(1<<0);
	T0TCR=0X02;
	T0TCR=0X01;
	VICVectCntl0=(1<<5)|4;
	VICIntEnable=1<<4;
	VICVectAddr0=(unsigned)timer;
}

void transmit(char *p)
{
int i;
for(i=0;p[i]!='\0';i++)
{
U0THR=p[i];
while(!(U0LSR&0X20));
}
}																														  




void main()
{
	

	PINSEL0 =0X00008005;
	IODIR0=0X00000001;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;


	
	rtc_init();
	while(1)
	{
		sprintf(a,"%d:%d:%d \r",hr,min,sec);
		transmit(a);
	}
}