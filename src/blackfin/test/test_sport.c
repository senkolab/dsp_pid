/*****************************************************************************
 * test_sport.c
 *
 * Tests the DSP-PID SPORT port
 *
 * Written by Rich Rademacher, UWaterloo/IQC
 * March 2018
 *****************************************************************************/


#include <processor/bf592.h>
#include <processor/uart.h>
#include <types.h>
#include <processor/power.h>

extern void sport0_isr();

bf592_t* blackfin = (bf592_t*) BLACKFIN_MMR_BASE;

int main( void )
{
    
    //
    // enable SCLK output on CLKOUT pin
    //
    blackfin->power.vr_ctl.extclk_sel = 1;
    blackfin->power.vr_ctl.extclk_oe = 1;
    
    //
    // set port multiplexor to use UART
    //
    blackfin->port.portg_mux = ~( nDR0PRI_PORTG_BIT | nRSCLK0_PORTG_BIT   \
                                    | nRFS0_PORTG_BIT |  nDT0PRI_PORTG_BIT   \
                                    | nTSCLK0_PORTG_BIT | nTFS0_PORTG_BIT );

    blackfin->port.portg_fer =  nDR0PRI_PORTG_BIT | nRSCLK0_PORTG_BIT   \
                                | nRFS0_PORTG_BIT | nDT0PRI_PORTG_BIT   \
                                | nTSCLK0_PORTG_BIT | nTFS0_PORTG_BIT;

                                
    //
    // sport interrupt enable
    //
    blackfin->sic.sic_iar1.sport0_tx = 2;   
    blackfin->sic.sic_imask0 |= SIC_ID_SPORT0_RX;
    blackfin->sic.sic_imask0 |= SIC_ID_SPORT0_TX;
    blackfin->core.evt.evt9 = sport0_isr;    // defined in ASM file
    blackfin->core.evt.imask.ivg9 = 1;       
    
    
    //
    // SPORT 0 config
    //	
    blackfin->sport.sport[0].rcr1.rspen     = 0;
    blackfin->sport.sport[0].rcr1.irclk     = 0;
    blackfin->sport.sport[0].rcr1.rdtype    = 0;
    blackfin->sport.sport[0].rcr1.rlsbit    = 0;
    blackfin->sport.sport[0].rcr1.irfs      = 0;
    blackfin->sport.sport[0].rcr1.rfsr      = 1;
    blackfin->sport.sport[0].rcr1.lrfs      = 1;
    blackfin->sport.sport[0].rcr1.larfs     = 0;
    blackfin->sport.sport[0].rcr1.rckfe     = 1;

    blackfin->sport.sport[0].rcr2.slen      = 15;
    blackfin->sport.sport[0].rcr2.rxse      = 0;
    blackfin->sport.sport[0].rcr2.rsfse     = 1;
    blackfin->sport.sport[0].rcr2.rrfst     = 0;

    blackfin->sport.sport[0].rcr1.rspen     = 1;


    blackfin->sport.sport[0].tcr1.tspen   = 0;
    blackfin->sport.sport[0].tcr1.itclk   = 0;
    blackfin->sport.sport[0].tcr1.tdtype  = 0;
    blackfin->sport.sport[0].tcr1.tlsbit  = 0;
    blackfin->sport.sport[0].tcr1.itfs    = 0;
    blackfin->sport.sport[0].tcr1.tfsr    = 1;
    blackfin->sport.sport[0].tcr1.ditfs   = 0;
    blackfin->sport.sport[0].tcr1.ltfs    = 0;
    blackfin->sport.sport[0].tcr1.latfs   = 0;
    blackfin->sport.sport[0].tcr1.tckfe   = 0;

    blackfin->sport.sport[0].tcr2.slen    = 15;
    blackfin->sport.sport[0].tcr2.txse    = 0;
    blackfin->sport.sport[0].tcr2.tsfse   = 1;
    blackfin->sport.sport[0].tcr2.trfst   = 0;
    
    blackfin->sport.sport[0].tfsdiv = 1;
    blackfin->sport.sport[0].tclkdiv = 1;
    
    blackfin->sport.sport[0].tcr1.tspen   = 1;

    blackfin->sport.sport[0].mcmc2.mcmen = 0;
    
    
    while(1)
    {
        SSYNC();
    }
    
    
    // halt the debugger
    asm("emuexcpt;");
	return 0;
}


//
// TX interrupt handler (vectored from Assembly Code)
//
void sport0_tx_handler() 
{
    
    SSYNC();    
    if(blackfin->sport.sport[0].tcr1.tspen == 0)
        return;

    // is TX holding register empty?6
    if(blackfin->sport.sport[0].stat.txhre == 1)
        blackfin->sport.sport[0].tx.half = 0x100;
}

//
// RX interrupt handler (vectored from Assembly Code)
//
void sport0_rx_handler() 
{
    u32 inbyte;
    
    
    SSYNC();    
    if(blackfin->sport.sport[0].rcr1.rspen == 0)
        return;

    // is RX not empty? -- generates interrupt
    if(blackfin->sport.sport[0].stat.rxne == 0)
        inbyte = blackfin->sport.sport[0].rx.half;   
}
