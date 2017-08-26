//program to recieve and retransmit a string using seperate functions for transmission and reception
#include <LPC214X.H>
void transmit(char *);
void recieve(char *);
void main()
{
char a[10];
PINSEL0=0X00000005;
IODIR0=0X000000001;
U0LCR=0X83;
U0DLL=97;
U0LCR=0X03;
while(1)
{
  recieve(a);
  transmit(a);
}
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


void recieve(char *q)
{
int i;
for(i=0;;i++)
{
while(!(U0LSR&(0X01)));
q[i]=U0RBR;
if(q[i]=='\r')
{
q[i]='\0';
break;
}
}
}
 