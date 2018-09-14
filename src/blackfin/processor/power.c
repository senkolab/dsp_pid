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
// init_power() - set up power registers
//
void init_power()
{
    blackfin->pll_ctl.pll_div.ssel = SYSCLK_FREQ
}


static void prog_pll_ctl()
{
    u8 msel;
    
    // DF is used if the VCO/XTAL ratio is not an integer
    u8 df =  ((2*VCO_FREQ) / XTAL_FREQ) & 1 ;

    
    // MSEL defines the divider ratio integer part
    if( df == 1 )
        msel = (2*VCO_FREQ) / XTAL_FREQ;
     else
        msel = VCO_FREQ / XTAL_FREQ;
        
     
    
}