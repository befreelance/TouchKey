/*****************************************************
//Program: touch key
//author:Befreelance
//modify date:2017.09.16
//describe:	this is a touch key program which is used 
//			for LinYi city.Key value is put to host 
//			by rs485.
//***************************************************/

#include "uart.h"

char *s="RS485 is OK!\r\n";
uchar KeyValue(void);
void putvalue(uchar keyvalue);
void main()
{
	//Begin
	//wait for MCU
	delay(100);
	//initialize IO interface
	P0=0xff;
	P1=0xff;
	P2=0xff;
	//initialize Uart
	UartInit();
	//only for wait
	delay(100);
	while(1)
	{
		//get keyvalue and put value to s
		putvalue(Keyvalue());
		//put s to host by RS485
		Tx_String485(s);
		//delay for host,the time value is set by host code
		Delay200ms();
				
	}

}

uchar KeyValue(void)
{
	uchar keyvalue;
	if(0xff!=P0)
	{
		//check P0's key
		if(0==P00)
		{
			keyvalue=1;
		}
		else if(0==P01)
		{
			keyvalue=2;
		}
		else if(0==P02)
		{
			keyvalue=3;
		}
		else if(0==P03)
		{
			keyvalue=4;
		}
		else if(0==P04)
		{
			keyvalue=5;
		}
		else if(0==P05)
		{
			keyvalue=6;
		}
		else if(0==P06)
		{
			keyvalue=7;
		}
		else if(0==P07)
		{
			keyvalue=8;
		}
		else
		{
			keyvalue=keyvalue;
		}
	}
	else if(0xff!=P1)
	{
		//check P1's key
		if(0==P10)
		{
			keyvalue=9;
		}
		else if(0==P11)
		{
			keyvalue=10;
		}
		else if(0==P12)
		{
			keyvalue=11;
		}
		else if(0==P13)
		{
			keyvalue=12;
		}
		else if(0==P14)
		{
			keyvalue=13;
		}
		else if(0==P15)
		{
			keyvalue=14;
		}
		else if(0==P16)
		{
			keyvalue=15;
		}
		else if(0==P17)
		{
			keyvalue=16;
		}
		else
		{
			keyvalue=keyvalue;
		}
	}
	else if(0xff!=P2)
	{
		//check P2's key
		if(0==P20)
		{
			keyvalue=17;
		}
		else if(0==P21)
		{
			keyvalue=18;
		}
		else if(0==P22)
		{
			keyvalue=19;
		}
		else if(0==P23)
		{
			keyvalue=20;
		}
		else if(0==P24)
		{
			keyvalue=21;
		}
		else if(0==P25)
		{
			keyvalue=22;
		}
		else if(0==P26)
		{
			keyvalue=23;
		}
		else if(0==P27)
		{
			keyvalue=24;
		}
		else
		{
			keyvalue=keyvalue;
		}
	}
	else
	{
		//no key
		keyvalue=0;
	}

	//return keyvalue
	return keyvalue;

}

void putvalue(uchar keyvalue)
{
	switch (keyvalue)
	{
		case 0:		s="V00\r\n";break;
		case 1:		s="V01\r\n";break;
		case 2:		s="V02\r\n";break;
		case 3:		s="V03\r\n";break;
		case 4:		s="V04\r\n";break;
		case 5:		s="V05\r\n";break;
		case 6:		s="V06\r\n";break;
		case 7:		s="V07\r\n";break;
		case 8:		s="V08\r\n";break;
		case 9:		s="V09\r\n";break;
		case 10:	s="V10\r\n";break;
		case 11:	s="V11\r\n";break;
		case 12:	s="V12\r\n";break;
		case 13:	s="V13\r\n";break;
		case 14:	s="V14\r\n";break;
		case 15:	s="V15\r\n";break;
		case 16:	s="V16\r\n";break;
		case 17:	s="V17\r\n";break;
		case 18:	s="V18\r\n";break;
		case 19:	s="V19\r\n";break;
		case 20:	s="V20\r\n";break;
		case 21:	s="V21\r\n";break;
		case 22:	s="V22\r\n";break;
		case 23:	s="V23\r\n";break;
		case 24:	s="V24\r\n";break;
		default:	s="E01\r\n";break;

	}
}