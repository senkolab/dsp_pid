/*****************************************************************************
 * test_uart.c
 *
 * Tests local UART subsystem
 * Written by Rich Rademacher, UWaterloo/IQC
 * March 2018
 *****************************************************************************/

#pragma symbolic_ref
const char __argv_string[] = "-abc -xyz";

#include <types.h>
//#include <processor/uart.h>
#include <processor/bf592.h>
#include <processor/power.h>

#define UART_BAUD   9600

//
// base MMR
//
bf592_t* blackfin = (bf592_t*) BLACKFIN_MMR_BASE;


int main( int argc, char *argv[] )
{
  u16 div = (SYSCLK_FREQ) / ((UART_BAUD) * 16);
  u32 sclk = SYSCLK_FREQ;
  u16 rx_byte;
  
  blackfin->uart.uart_gctl.ucen = 0;
  blackfin->uart.uart_lcr.dlab = 1;
  blackfin->uart.uart_thr_rbr_dll = (div & 0xff);
  blackfin->uart.uart_dlh_ier.dlh = (div >> 8);
  blackfin->uart.uart_lcr.stb = 0;    // 1 stop bit
  blackfin->uart.uart_lcr.wls = UART_LCR_WLS_8BIT;
  blackfin->uart.uart_lcr.pen = 0;
  blackfin->uart.uart_lcr.dlab = 0;
  blackfin->uart.uart_gctl.ucen = 1;

  //
  // set port multiplexor to use UART
  //
  blackfin->port.portf_mux &= ~BIT(11) | ~BIT(12);
  blackfin->port.portf_fer |= BIT(11) | BIT(12);
  
    // loop forever
    while(1)
    {
        // when transmit buffer is empty, write 'A'
        if( blackfin->uart.uart_lsr.tempt == 1 )
            blackfin->uart.uart_thr_rbr_dll = 'a';
            
        // halt processor when received byte
        if( blackfin->uart.uart_lsr.dr == 1 )
        {
            rx_byte = blackfin->uart.uart_thr_rbr_dll;
            asm("emuexcpt;");
        }   
        SSYNC();
    }	
    
    // force stop to IDE
    asm("emuexcpt;");
	return 0;
}
