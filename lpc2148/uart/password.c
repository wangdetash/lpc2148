//program to password verification and reset
#include<LPC214X.H>
#include<string.h>
void transmit(char *);
void recieve(char *);
void main()
{
char x;
char a[10],b[10]="1234";
PINSEL0=0X00000005;
IODIR0=0X000000001;
U0LCR=0X83;
U0DLL=97;
U0LCR=0X03;
while(1)
{
  transmit("1.login\n2.password reset\n");
  while(!(U0LSR&(0X01)));
  x=U0RBR;
  switch(x)
  {
  case '1':
  transmit("password:\n");
  recieve(a);
  if(strcmp(a,b)==0)
  {
  transmit(" Access Granted\n");
  }
  else
  {
  transmit("Access Denied\n");
  }
  break;

  case '2':
  transmit("Enter old password:\n");
  recieve(a);
  if(strcmp(a,b)==0)
  {
  transmit("Enter new password:\n");
  recieve(b);
  }
  else
  {
  transmit("password dismatch\n");
  }
  }
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
 