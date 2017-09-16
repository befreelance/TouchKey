#include "delay.h"

void UartInit();
void Tx_Data(uchar txData);
void Tx_String(char *s);

void Tx_Data485(uchar txData);
void Tx_String485(char *s);