# include<lpc21xx.h>

# define rs (1<<25)
# define rw (1<<28)
# define en (1<<27) 

void delay(int j )
{
int i;
for(;j;j--)
for(i=6000;i;i--);
}

void data_lcd(char ch)
{
int i =0;
i = ch;
i = i<<16; 
IOPIN0 &=(0XFF00FFFF);
IOPIN0 |= i;

IOSET0 = rs;
IOCLR0 = rw;
IOSET0 = en;
delay(2);
IOCLR0 = en;
}
void cmd_lcd(char ch)
{
int i =0;
i = ch;
i = i<<16; 
IOPIN0 &=(0XFF00FFFF);

IOPIN0 |= i;
IOCLR0 = rs;
IOCLR0 = rw;
IOSET0 = en;
delay(2);
IOCLR0 = en;
}
void init_lcd()
{
cmd_lcd(0x38);
cmd_lcd(0x01);
cmd_lcd(0x06);
cmd_lcd(0x0c);
cmd_lcd(0x80);
}

void str_lcd(char *str)
{
while(*str)
data_lcd(*str++);
}

int main()
{
int i;
PINSEL1 = 0x00000000;
IODIR0 = 0XFFFF0000;
init_lcd();

while(1)
{
cmd_lcd(0x80);
cmd_lcd(0x01);

str_lcd("	   welcome");
cmd_lcd(0xc0);
str_lcd("	    smart");

for(i=0;i<16;i++)
{
cmd_lcd(0x1c);
delay(100);
}
}
}
