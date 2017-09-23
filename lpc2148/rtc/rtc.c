//program to use inbuilt rtc
#include<LPC214X.H>
#include<stdio.h>

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
	int i;
	char a[30];
	int date,month,year,hour,min,sec;
	PINSEL0=0X00000005;
	IODIR0=0X000000001;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;

	
    CCR =0X11;
	DOM=23;
	MONTH=10;
	YEAR=2107;
	HOUR=22;
	MIN=10;
	SEC=40;

	while(1)
	{
        hour = HOUR;
        min  = MIN; 
        sec  = SEC; 
        date  = DOM;   
        month = MONTH;  
        year  = YEAR; 
        sprintf(a,"%d:%d:%d:%d\n",hour,min,sec),
        transmit(a);
        for(i=0;i<100000;i++);

	}
}