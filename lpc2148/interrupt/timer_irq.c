//program to set port0 on timer interrupt
#include <LPC214X.H>

void timer()__irq
{
IOSET0=0XFFFFFFFF;
VICVectAddr=0;
}

void main()
{
PINSEL0=0X00000000;
IODIR0=0XFFFFFFFF;
T0CTCR=0X00;
T0PR=12000000;
T0MR0=1;
T0TCR=0X01;
T0MCR=(1<<1)|(1<<0);
VICIntEnable=1<<4;
VICVectCntl0=(1<<5)|4;
VICVectAddr0=(unsigned)timer;
while(1);
}

