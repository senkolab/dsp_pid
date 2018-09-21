////////////////////////////////////////////////////////////////////////////////
// 
// power.c - set blackfin power and clocking
//
// Written by Rich Rademacher  UWaterloo/IQC
// March 2018
//
////////////////////////////////////////////////////////////////////////////////

#include <types.h>
#include <processor\power.h>
#include <processor\bf592.h>


//
// prototypes
//
static void prog_pll_ctl(void);

//
// init_power() - set up power registers
//
void init_power()
{
    prog_pll_ctl();
}


//
// program the PLL control registers
//
static void prog_pll_ctl(void)
{
    u8 msel;
    u8 df;
    u8 csel; 
    u8 ssel;
    
    // DF is used if the VCO/XTAL ratio is not an integer
    df =  ((2*VCO_FREQ) / XTAL_FREQ) & 1 ;

    
    // MSEL defines the VCO/XTAL divider ratio integer part
    if( df == 1 )
        msel = (2*VCO_FREQ) / XTAL_FREQ;
    else
        msel = VCO_FREQ / XTAL_FREQ;
        
    
    // CSEL sets the ratio of core freq to VCO
    csel = VCO_FREQ / CORE_FREQ;
    
    // SSEL sets the system bus clock frequency
    ssel = VCO_FREQ / SYSCLK_FREQ;
        
        
    blackfin->power.pll_div.ssel = ssel;      // VCO:SCLK ratio
    blackfin->power.pll_div.csel = csel;      // VCO:CCLK ratio
    
    blackfin->power.pll_ctl.df = df;          // Divide flag
    blackfin->power.pll_ctl.pll_off = 0;      // enable PLL power
    blackfin->power.pll_ctl.stopck = 0;       // cclk on
    blackfin->power.pll_ctl.pdwn = 0;         // enable pll power
    blackfin->power.pll_ctl.bypass = 0;       // do not bypass
    blackfin->power.pll_ctl.msel = msel;      // CLKIN*MSEL = VCO Freq

    // restart processor to program PLL
    asm( "[--SP] = R0; CLI R0; IDLE; STI R0; R0 = [SP++]; // PLL PROGRAMMING SEQUENCE" );
    
    SSYNC();
      
}