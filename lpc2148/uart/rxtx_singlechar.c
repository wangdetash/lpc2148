//program to recieve and retransmit a single charecter
#include <LPC214X.H>
void main()
{
PINSEL0=0X00000005;
IODIR0=0X00000001;
U0LCR=0X83;
U0DLL=97;
U0LCR=0X03;
while(1)
{
while(!(U0LSR&(1<<0)));
U0THR=U0RBR;
while(!(U0LSR&(1<<6)));
}
}