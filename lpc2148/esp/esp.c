//program to use esp8266
#include <LPC214X.H>
#include <stdio.h>
#include <string.h>

void transmit(char *);
void recieve(char *);

char SSID[]="quest";
char pass_word[]="quest123";
char apikey[]="5DET0BBI9UP99QDC";
char host_key[]="SMART HIGHWAY";
char password[]="JaNisa";

char data1[100],data2[100];
int gas_level=50;
int string_length;

void main()
{   
	PINSEL0=0X00000005;
	IODIR0=0X000000001;
	U0LCR=0X83;
	U0DLL=97;
	U0LCR=0X03;

	sprintf(data1,"AT+CWMODE=3\n");
	transmit(data1);
	recieve(data1);

	sprintf(data1,"AT+CWJAP=\"%s\", \"%s\"\n",SSID,pass_word);
	transmit(data1);
	recieve(data1);
	while(1)
	{	
		sprintf(data1,"AT+CIPSTART=\"TCP\",\"192.168.3.116\", 8080\n");
		transmit(data1);
		recieve(data1);

		sprintf(data2,"Get /update?api_key=%s&field1=%d\n",apikey,gas_level);
		string_length=strlen(data2);
		sprintf(data1,"AT+CIPSEND=%d\n",string_length);
		transmit(data1);
		transmit(data2);

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
