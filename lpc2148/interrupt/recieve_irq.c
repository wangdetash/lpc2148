//program to recieve charecter with vectored interrupt
#include <LPC214X.H>
void recieve()__irq
{
U0THR=U0RBR;
while(!(U0LSR&0X20));
VICVectAddr=0;
}
void main()
{
PINSEL0=0X00000005;
IODIR0=0X00000001;
U0LCR=0X83;
U0DLL=97;
U0LCR=0X03;
U0IER=0X01;
VICIntEnable=1<<6;
VICVectCntl0=(1<<5)|6;
VICVectAddr0=(unsigned)recieve;
while(1);
}
