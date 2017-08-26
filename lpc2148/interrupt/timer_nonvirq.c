//program to set port0 when timer witth non vectored interrupt
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
T0TCR=0X00;
T0PR=15000000;
T0MR0=1;
T0TCR=0X01;
T0MCR=( 1<<1)|( 1<<0);
VICIntEnable=1<<4;
VICVDefVectAddr=(unsigned)timer;
while(1);
}