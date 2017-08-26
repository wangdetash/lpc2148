//program to see timer increment on port0
#include <LPC214X.H>
int main()
{
int i;
PINSEL0=0X00000000;
IODIR0=0XFFFFFFFF;
T0CTCR=0X00;
T0PR=12000000;
T0TCR=0X01;
while(1)
{
IOSET0=T0TC;
for(i=0;i<10000;i++);
IOCLR0=0XFFFFFFFF;
for(i=0;i<10000;i++);
}
}
