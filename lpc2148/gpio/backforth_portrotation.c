// program to rotate port0 back and forth using for loop as delay 
#include <LPC214X.H>
void main()
{
int i,k,b;
PINSEL0=0X00000000;
IODIR0=0XFFFFFFFF;
b=0X00000001;
while(1)
{
for(k=0;k<32;k++)
{
IOSET0=b<<k;
for(i=0;i<100000;i++);

IOCLR0=b<<k;
for(i=0;i<100000;i++);
}

for(k=32;k>=0;k--)
{
IOSET0=b<<k;
for(i=0;i<100000;i++);

IOCLR0=b<<k;
for(i=0;i<100000;i++);
}
}
}

