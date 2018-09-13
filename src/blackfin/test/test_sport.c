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

volatile bf592_t* blackfin = (bf592_t*) BLACKFIN_MMR_BASE;

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
    blackfin->sport.sport[0].rcr1.larfs     = 1;
    blackfin->sport.sport[0].rcr1.rckfe     = 0;

    blackfin->sport.sport[0].rcr2.slen      = 23;
    blackfin->sport.sport[0].rcr2.rxse      = 0;
    blackfin->sport.sport[0].rcr2.rsfse     = 1;
    blackfin->sport.sport[0].rcr2.rrfst     = 0;

    blackfin->sport.sport[0].rfsdiv = 511 ;
    blackfin->sport.sport[0].rclkdiv = 0;


    blackfin->sport.sport[0].tcr1.tspen   = 0;  // not enabled yet...to be done below
    blackfin->sport.sport[0].tcr1.itclk   = 1;  // internal tx clock ???
    blackfin->sport.sport[0].tcr1.tdtype  = 0;  // type=normal (no companding)
    blackfin->sport.sport[0].tcr1.tlsbit  = 0;  // MSB first bit order
    blackfin->sport.sport[0].tcr1.itfs    = 1;  // internal tx frame sync
    blackfin->sport.sport[0].tcr1.tfsr    = 1;  // TX Frame sync required = yes
    blackfin->sport.sport[0].tcr1.ditfs   = 0;  // disable data independent of frame sync
    blackfin->sport.sport[0].tcr1.ltfs    = 1;  // Active low transmit frame sync
    blackfin->sport.sport[0].tcr1.latfs   = 0;  // Late frame sync disabled
    blackfin->sport.sport[0].tcr1.tckfe   = 0;  // clk falling edge select = disabled

    blackfin->sport.sport[0].tcr2.slen    = 23; // serial length = 32 bits - 1  (2 channens 16 bit)
    blackfin->sport.sport[0].tcr2.txse    = 0;  // tx secondary enable = false
    blackfin->sport.sport[0].tcr2.tsfse   = 1;  // stereo frame sync enable
    blackfin->sport.sport[0].tcr2.trfst   = 0;  // right stereo cchannel first
    
    blackfin->sport.sport[0].tfsdiv = 511 ;     // fsdiv = 512 == 62khz @ 32 MHz mclk
    blackfin->sport.sport[0].tclkdiv = 0;       //  tx clock = mclk
    

    blackfin->sport.sport[0].tcr1.tspen   = 1;      // enable TX sport
    blackfin->sport.sport[0].rcr1.rspen     = 1;    // enable RX sport

    blackfin->sport.sport[0].mcmc2.mcmen = 0;
    
    
    while(1)
    {
        SSYNC();
    }
    
    
    // halt the debugger
    asm("emuexcpt;");
	return 0;
}

//static const s16 tx_buffer[] = {-32767, -32767, -23170, -23170, 0, 0, 23170, 23170, 32767, 32767, 23170, 23170, 0, 0, -23170, -23170};
//static const s16 tx_buffer[] = {-32767, -32767, -32767, -32767, -16384, -16384, 32767, 32767, 32767, 32767, 16384, 16384};
static const s16 tx_buffer[] = {-32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, -32767, 
                                32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767 };
//static const s16 tx_buffer[] = { 16384, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static const s32 tx_size = sizeof(tx_buffer)/sizeof(tx_buffer[0]);
static u32 tx_idx;

//
// TX interrupt handler (vectored from Assembly Code)
//
void sport0_tx_handler() 
{
    s32 sample;
    
    // sync the system to check the latest "enable"/"disable" register status.
    // do nothing if the SPORT is disabled
    SSYNC();    
    if(blackfin->sport.sport[0].tcr1.tspen == 0)
        return;

    
    
    // is TX holding register empty?6
    if(blackfin->sport.sport[0].stat.txhre == 1)
    {
        // get the next sample, and imcrement the addres until at end
        sample = tx_buffer[tx_idx++] << 8;
        
        // at end of buffer? put zeros forever
        if(tx_idx >= tx_size)
            tx_idx = 0;
            
        // write the sample to the SPORT output
        blackfin->sport.sport[0].tx.word = sample;
    }
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
        inbyte = blackfin->sport.sport[0].rx.word;   
}
