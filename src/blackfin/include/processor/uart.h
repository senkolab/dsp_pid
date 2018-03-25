#ifndef _UART_H_
#define _UART_C_
////////////////////////////////////////////////////////////////////////////////
// uart.h - header file for UART driver
//
// Written by Rich Rademacher, UWaterloo/IQC
// March 2018
////////////////////////////////////////////////////////////////////////////////

#include <types.h>

// Maximum number of charachters in the UART ringbuffer
#define UART_BUFFSIZE 128

// Output baud rate
#define UART_BAUD     19200


// function prototypes
extern void uart_init(void);
extern void uart_putc(u8 c);
extern void uart_getc(u8* c);

#endif /* _UART_C_ */

