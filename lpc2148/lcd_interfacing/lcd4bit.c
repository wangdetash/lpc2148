//program to use lcd in 4 bit mode
#include <LPC214X.H>
#define bit(x) (1<<x)
#define RS bit(24) 
#define RW bit(23) 
#define EN bit(22) 
#define CNTL (RS|RW|EN)
#define DATA (bit(10)|bit(11)|bit(12)|bit(13))
void delay(int x)
{int i;
for(i=0;i<x;i++);
}

void cmd(char a)
{
char b;
IOCLR1=CNTL;
IOCLR0=DATA;
IOCLR1=RS;
b=a&0XF0;
IOSET0=b<<6;
IOSET1=EN;
delay(1000);
IOCLR1=EN;
IOCLR0=DATA;
b=a&0X0F;
IOSET0=b<<10;
IOSET1=EN;
delay(1000);
IOCLR1=EN;
}
void data(char a)
{
char b;

IOCLR0=DATA;
IOSET1=RS;
b=a&0XF0;
IOSET0=b<<6;
IOSET1=EN;
delay(1000);
IOCLR1=EN;
IOCLR0=DATA;
b=a&0X0F;
IOSET0=b<<10;
IOSET1=EN;
delay(1000);
IOCLR1=EN;
}
void string(char *s)
{  int j;
for(j=0;s[j]!='\0';j++)
{
data(s[j]);
}
}
int main()
{

PINSEL0=0X00000000;
PINSEL2=0X00000000;
IODIR1=CNTL;
IODIR0=DATA;
cmd(0x02);
  cmd(0x28);
cmd(0x01);
cmd(0x0C);  




while(1)
{
 
 cmd(0x80);
 string("LCD ON");
 delay(1000000);
 cmd(0xc0);
 string("WELCOME");
 delay(1000000);
 cmd(0x01);
 
 
 
 }
 }



