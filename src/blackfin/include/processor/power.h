#ifndef _POWER_H_
#define _POWER_H_
////////////////////////////////////////////////////////////////////////////////
// 
// power.h - header for  blackfin power and clocking
//
// Written by Rich Rademacher  UWaterloo/IQC
// March 2018
//
////////////////////////////////////////////////////////////////////////////////

#include <types.h>
#include <processor\power.h>
#include <pid_board.h>

// blackfin VCO synth frequency
#define VCO_FREQ    ( (XTAL_FREQ) * 6 )

// blackfin core frequency
#define CORE_FREQ   ( VCO_FREQ )

// system (peripheral bus) frequency
#define SYSCLK_FREQ ( VCO_FREQ / 4 )


//
// init_power() - set up power registers
//
extern void init_power(void);

#endif /* _POWER_H_ */
