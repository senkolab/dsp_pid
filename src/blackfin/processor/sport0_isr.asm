////////////////////////////////////////////////////////////////////////////////
//  sport0_isr.asm - interrupt service routines for TX and RX for BF592 processor
//
//
//  Written by Rich Rademacher,  UWaterloo/IQC
//  March 2018
////////////////////////////////////////////////////////////////////////////////

.section program;
.global _sport0_isr;
.extern _sport0_tx_handler;
.extern _sport0_rx_handler;


//
// save all registers for processing in C code
//
_sport0_isr:
  [--SP] = ASTAT;
  [--SP] = RETS;
  [--SP] = (R7:0,P5:0);
  [--SP] = FP;

  [--SP] = LC0;
  [--SP] = LT0;
  [--SP] = LB0;

  [--SP] = LC1;
  [--SP] = LT1;
  [--SP] = LB1;

  [--SP] = L0;
  [--SP] = L1;
  [--SP] = L2;
  [--SP] = L3;

  [--SP] = B0;
  [--SP] = B1;
  [--SP] = B2;
  [--SP] = B3;

  [--SP] = M0;
  [--SP] = M1;
  [--SP] = M2;
  [--SP] = M3;

  [--SP] = I0;
  [--SP] = I1;
  [--SP] = I2;
  [--SP] = I3;

  [--SP] = A0.W;
  [--SP] = A0.X;

  [--SP] = A1.W;
  [--SP] = A1.X;

  [--SP] = RETI;
      SP +=  -12;
      
      // all work is done in handlers in C code
      CALL _sport0_rx_handler;
      CALL _sport0_tx_handler;

      SP +=  12;
  RETI = [SP++];

  A1.X = [SP++];
  A1.W = [SP++];

  A0.X = [SP++];
  A0.W = [SP++];

  I3 = [SP++];
  I2 = [SP++];
  I1 = [SP++];
  I0 = [SP++];

  M3 = [SP++];
  M2 = [SP++];
  M1 = [SP++];
  M0 = [SP++];

  B3 = [SP++];
  B2 = [SP++];
  B1 = [SP++];
  B0 = [SP++];

  L3 = [SP++];
  L2 = [SP++];
  L1 = [SP++];
  L0 = [SP++];

  LB1 = [SP++];
  LT1 = [SP++];
  LC1 = [SP++];

  LB0 = [SP++];
  LT0 = [SP++];
  LC0 = [SP++];

  FP = [SP++];
  (R7:0,P5:0) = [SP++];
  RETS = [SP++];
  ASTAT = [SP++];

  RTI;
_sport0_isr.END:

