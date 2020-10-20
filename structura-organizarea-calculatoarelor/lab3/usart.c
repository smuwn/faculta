#include "usart.h"
void USART_initialize(unsigned short int baud_rate)
{
  /* seteaz� baud rate */
  UBRRH = (unsigned char)(baud_rate >> 8);
  UBRRL = (unsigned char)(baud_rate & 0xFF);
  UCSRB = (1 << RXEN) | (1 << TXEN); /* activeaz� transmisia ?i
  recep?ia la ie?ire */
  /* seteaz� pinul TXD: ie?ire */
  DDRD |= (1 << PD1);
  /* seteaz� pinul RXD: intrare */
  DDRD &= ~(1 << PD0);
  /* activeaz� �ntreruperea */
  //UCSRB |= (1 << RXCIE);
}
void USART_transmit(unsigned char data)
{
  /* a?teapt� p�n� ce se termin� de transmis toate datele ?i dup� trece
  la urm�toarele informa?ii */
  static int i = 0;
  while (!( UCSRA & (1 << UDRE)))
  {
    ;
  }
  UDR = data;
  data_send[i++] = data;
}
unsigned char USART_Receive( void )
{
  /* A?teapt� recep?ionarea datelor */
  while ( !(UCSRA & (1<<RXC)) )
  {
    ;
  }
  /* Preia ?i returneaz� datele recep?ionate din buffer */
  return UDR;
}
