////////////////////////////////////////////////////////////////////////////////
//
// uart.c - driver for Blackfin BF592 UART subsystem
//
////////////////////////////////////////////////////////////////////////////////

#include <processor/bf592.h>
#include <processor/uart.h>
#include <types.h>

// 
// ring buffers for UART0
//
static u8 uart0_txbuf[UART_BUFSIZE];
static u8 uart0_rxbuf[UART_BUFSIZE];

//
// length of unread bytes in buffer
//
static s32 uart0_tx_len;
static s32 uart0_rx_len;

//
// index position within the ringbuffer
//
static s32 uart0_tx_idx;
static s32 uart0_rx_idx;

////////////////////////////////////////////////////////////////////////////////
// uart0_init() - initialize the UART subsystem
//
////////////////////////////////////////////////////////////////////////////////
void uart0_init() {
  uart0_rx_idx = 0;
  uart0_tx_idx = 0;
  uart0_rx_len = 0;
  uart0_tx_len = 0;


}


