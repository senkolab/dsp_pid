#ifndef _PID_BOARD_H_
#define _PID_BOARD_H_
////////////////////////////////////////////////////////////////////////////////
// pid_board.h - board definitions for the Senko Lab PID DSP board
//
// Written by Rich Rademacher  UWaterloo/IQC
// March 2018
////////////////////////////////////////////////////////////////////////////////

#define XTAL_FREQ   24000000  // processor clock crystal frequency


// blackfin VCO synth frequency
#define VCO_FREQ    ( (XTAL_FREQ) * 6 )

// blackfin core frequency
#define CORE_FREQ   ( VCO_FREQ )

// system (peripheral bus) frequency
#define SYSCLK_FREQ ( VCO_FREQ / 6 )


#endif /* _PID_BOARD_H_ */
