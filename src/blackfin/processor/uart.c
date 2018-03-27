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
u8 uart_txbuf[UART_BUFSIZE];
u8 uart_rxbuf[UART_BUFSIZE];

//
// length of unread bytes in buffer
//
s32 uart_tx_count;
s32 uart_rx_count;

//
// index position within the ringbuffer
//
s32 uart_tx_idx;
s32 uart_rx_idx;

////////////////////////////////////////////////////////////////////////////////
// uart_init() - initialize the UART subsystem
//
////////////////////////////////////////////////////////////////////////////////
void uart_init() {
  uart_rx_idx = 0;
  uart_tx_idx = 0;
  uart_rx_count = 0;
  uart_tx_count = 0;

  uart_set_baud();
  
}

////////////////////////////////////////////////////////////////////////////////
//  uart_set_baud()
//  
// sets the baud rate, see Blackfin HRM section 11-33
//
////////////////////////////////////////////////////////////////////////////////
static void uart_set_baud()
{
  u16 div = (SYSCLK_FREQ) / ((UART_BAUD) * 16);
  
  blackfin->uart.uart_gctl.ucen = 1;
  blackfin->uart.uart_lcr.dlab = 1;
  blackfin->uart.uart_dll = (div & 0xff);
  blackfin->uart.uart_dlh_ier = (div >> 8);
  blackfin->uart.uart_lcr.stb = 0;    // 1 stop bit
  blackfin->uart.uart_lcr.wls = UART_LCR_WLS_8BIT;
  blackfin->uart.uart_lcr.pen = 0;
  blackfin->uart.uart_lcr.dlab = 0;

}

////////////////////////////////////////////////////////////////////////////////
// uart_tx_handler()
//
// transmit interrup handler
////////////////////////////////////////////////////////////////////////////////
void uart_tx_handler()
{
  u8  status;

  status = blackfin->uart.uart_iir.status;
  SSYNC();

  if( (status & 1) != 0 )   // TX buffer empty interrupt
  {
    // there are bytes available to send
    if(uart_tx_count >= 0u)
    {
      // send next byte out
      blackfin->uart.uart_thr = uart_tx_buf[ uart_tx_idx++ ];

      // circular increment position
      if( uart_tx_idx >= UART_BUFSIZE )
        uart_tx_idx = 0;

      // decrement counter
      uart_tx_count -= 1;
    }

    else
    {
      // wait for both THR and TSR to be empty before disabling
      while( blackfin->uart.uart_lsr.tempt != 1 )
        SSYNC();

      // disable tx interrupt becuase there is no more
      blackfin->uart.uart_ier.etbei = 0;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
// uart_rx_handler()
//
// receive interrup handler
////////////////////////////////////////////////////////////////////////////////
void uart_rx_handler()
{
  u8  status;
  u8  newchar;

  status = blackfin->uart.uart_iir.status;
  SSYNC();

  // read the character 
  newchar = blackfin->uart.uart_rbr;

  if( (status & 2) != 0 )   // Rx data ready buffer empty interrupt
  {
    // check for room
    if( uart_rx_count < UART_BUFSIZE)
    {
      uart_rx_buf[ uart_rx_idx++ ] = newchar;
      uart_rx_count++;

      // circular append
      if( uart_rx_idx >= UART_BUFSIZE )
        uart_rx_idx = 0;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
// uart_putc()
//
//
////////////////////////////////////////////////////////////////////////////////
s32 uart_putc(u8 c)
{
  
}
