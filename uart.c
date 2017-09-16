#include "uart.h"

void UartInit()
{

	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��1ʱ��ΪFosc/12,��12T
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFD;		//�趨��ʱ��ֵ
	TH1 = 0xFD;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	ES=1;
	TR1 = 1;		//������ʱ��1
}
void Tx_Data(uchar txData)
{
	
	SBUF=txData;			// write data x to SBUF
	while(0==TI);
	TI=0;
	
}

void Tx_String(char *s)
{
	while(*s)
	{
		Tx_Data(*s++);
	}
}

void Tx_Data485(uchar txData)
{
	P36=1;
	P37=1;
//	Delay1ms();
	SBUF=txData;			// write data x to SBUF
	while(!TI);
	TI=0;
//	Delay1ms();
//
	P36=0;
	P37=0;
}

void Tx_String485(char *s)
{


	while(*s)
	{
		Tx_Data485(*s++);
		Delay1ms();
	}

	Delay50us();

}
