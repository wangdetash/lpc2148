// program to blink port zero when 1st pin of port 1 is set
#include <LPC214X.H>
void main()
{
int i;
PINSEL0=0X00000000;
IODIR0=0XFFFFFFFF;
while(1)
{
if(IOPIN1&(1<<16))
{
IOSET0=~IOSET0;
for(i=0;i<10000;i++);
IOCLR0=~IOCLR0;
for(i=0;i<10000;i++);
}
}
}