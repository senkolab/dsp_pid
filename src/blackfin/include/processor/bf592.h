/*
 * BF592.h - register definitions for Analog Devices Blackfin BF592 processor
 *
 * Written by Rich Rademacher / IQC / University of Waterloo
 * March 2018
 */


#ifndef _BF592_H_
#define _BF592_H_

// 
// Processor-Specific Memory Registers
// 
#define DTEST_COMMAND    (0xFFE00300)  /* “Data Test Command Register” on page 2-5 */

// 
// Core Timer Registers
// 
#define TCNTL       (0xFFE03000)  /* “Core Timer Control Register (TCNTL)” on page 9-5 */
#define TPERIOD     (0xFFE03004)  /* “Core Timer Period Register (TPERIOD)” on page 9-6 */
#define TSCALE      (0xFFE03008)  /* “Core Timer Scale Register (TSCALE)” on page 9-7 */
#define TCOUNT      (0xFFE0300C)  /* “Core Timer Count Register (TCOUNT)” on page 9-5 */


// 
// System Reset and Interrupt Control Registers
// 
#define SYSCR       (0xFFC00104)  /* “System Reset Configuration (SYSCR) Register” on page 16-57 */
#define SIC_IMASK0  (0xFFC0010C)  /* “System Interrupt Mask (SIC_IMASK) Register” on page 4-12 */
#define SIC_IAR0    (0xFFC00110)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR1    (0xFFC00114)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR2    (0xFFC00118)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR3    (0xFFC0011C)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_ISR0    (0xFFC00120)  /* “System Interrupt Status (SIC_ISR) Register” on page 4-12 */
#define SIC_IWR0    (0xFFC00124)  /* “System Interrupt Wakeup-Enable (SIC_IWR) Register” on page 4-13 */


// 
// DMA/Memory DMA Control Registers
// 
#define DMA_TC_PER  (0xFFC00B0C)  /* “DMA_TC_PER Register” on page 5-93 */
#define DMA_TC_CNT  (0xFFC00B10)  /* “DMA_TC_CNT Register” on page 5-93 */

#define DMA0_BASE    (0xFFC00C00)
#define DMA1_BASE    (0xFFC00C40)
#define DMA2_BASE    (0xFFC00C80)
#define DMA3_BASE    (0xFFC00CC0)
#define DMA4_BASE    (0xFFC00D00)
#define DMA5_BASE    (0xFFC00D40)
#define DMA6_BASE    (0xFFC00D80)
#define DMA7_BASE    (0xFFC00DC0)
#define DMA8_BASE    (0xFFC00E00)
#define MDMA_D0_BASE    (0xFFC00F00)
#define MDMA_S0_BASE    (0xFFC00F40)
#define MDMA_D1_BASE    (0xFFC00F80)
#define MDMA_S1_BASE    (0xFFC00FC0)

#define DMA0_NEXT_DESC_PTR (DMA0_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA0_START_ADDR (DMA0_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA0_CONFIG (DMA0_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA0_X_COUNT (DMA0_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA0_X_MODIFY (DMA0_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA0_Y_COUNT (DMA0_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA0_Y_MODIFY (DMA0_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA0_CURR_DESC_PTR (DMA0_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA0_CURR_ADDR (DMA0_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA0_IRQ_STATUS (DMA0_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA0_PERIPHERAL_MAP (DMA0_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA0_CURR_X_COUNT (DMA0_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA0_CURR_Y_COUNT (DMA0_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA1_NEXT_DESC_PTR (DMA1_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA1_START_ADDR (DMA1_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA1_CONFIG (DMA1_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA1_X_COUNT (DMA1_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA1_X_MODIFY (DMA1_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA1_Y_COUNT (DMA1_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA1_Y_MODIFY (DMA1_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA1_CURR_DESC_PTR (DMA1_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA1_CURR_ADDR (DMA1_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA1_IRQ_STATUS (DMA1_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA1_PERIPHERAL_MAP (DMA1_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA1_CURR_X_COUNT (DMA1_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA1_CURR_Y_COUNT (DMA1_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA2_NEXT_DESC_PTR (DMA2_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA2_START_ADDR (DMA2_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA2_CONFIG (DMA2_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA2_X_COUNT (DMA2_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA2_X_MODIFY (DMA2_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA2_Y_COUNT (DMA2_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA2_Y_MODIFY (DMA2_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA2_CURR_DESC_PTR (DMA2_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA2_CURR_ADDR (DMA2_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA2_IRQ_STATUS (DMA2_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA2_PERIPHERAL_MAP (DMA2_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA2_CURR_X_COUNT (DMA2_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA2_CURR_Y_COUNT (DMA2_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA3_NEXT_DESC_PTR (DMA3_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA3_START_ADDR (DMA3_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA3_CONFIG (DMA3_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA3_X_COUNT (DMA3_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA3_X_MODIFY (DMA3_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA3_Y_COUNT (DMA3_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA3_Y_MODIFY (DMA3_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA3_CURR_DESC_PTR (DMA3_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA3_CURR_ADDR (DMA3_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA3_IRQ_STATUS (DMA3_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA3_PERIPHERAL_MAP (DMA3_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA3_CURR_X_COUNT (DMA3_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA3_CURR_Y_COUNT (DMA3_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA4_NEXT_DESC_PTR (DMA4_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA4_START_ADDR (DMA4_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA4_CONFIG (DMA4_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA4_X_COUNT (DMA4_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA4_X_MODIFY (DMA4_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA4_Y_COUNT (DMA4_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA4_Y_MODIFY (DMA4_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA4_CURR_DESC_PTR (DMA4_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA4_CURR_ADDR (DMA4_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA4_IRQ_STATUS (DMA4_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA4_PERIPHERAL_MAP (DMA4_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA4_CURR_X_COUNT (DMA4_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA4_CURR_Y_COUNT (DMA4_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA5_NEXT_DESC_PTR (DMA5_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA5_START_ADDR (DMA5_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA5_CONFIG (DMA5_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA5_X_COUNT (DMA5_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA5_X_MODIFY (DMA5_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA5_Y_COUNT (DMA5_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA5_Y_MODIFY (DMA5_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA5_CURR_DESC_PTR (DMA5_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA5_CURR_ADDR (DMA5_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA5_IRQ_STATUS (DMA5_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA5_PERIPHERAL_MAP (DMA5_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA5_CURR_X_COUNT (DMA5_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA5_CURR_Y_COUNT (DMA5_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA6_NEXT_DESC_PTR (DMA6_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA6_START_ADDR (DMA6_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA6_CONFIG (DMA6_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA6_X_COUNT (DMA6_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA6_X_MODIFY (DMA6_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA6_Y_COUNT (DMA6_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA6_Y_MODIFY (DMA6_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA6_CURR_DESC_PTR (DMA6_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA6_CURR_ADDR (DMA6_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA6_IRQ_STATUS (DMA6_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA6_PERIPHERAL_MAP (DMA6_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA6_CURR_X_COUNT (DMA6_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA6_CURR_Y_COUNT (DMA6_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA7_NEXT_DESC_PTR (DMA7_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA7_START_ADDR (DMA7_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA7_CONFIG (DMA7_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA7_X_COUNT (DMA7_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA7_X_MODIFY (DMA7_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA7_Y_COUNT (DMA7_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA7_Y_MODIFY (DMA7_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA7_CURR_DESC_PTR (DMA7_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA7_CURR_ADDR (DMA7_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA7_IRQ_STATUS (DMA7_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA7_PERIPHERAL_MAP (DMA7_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA7_CURR_X_COUNT (DMA7_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA7_CURR_Y_COUNT (DMA7_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA8_NEXT_DESC_PTR (DMA8_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA8_START_ADDR (DMA8_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA8_CONFIG (DMA8_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA8_X_COUNT (DMA8_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA8_X_MODIFY (DMA8_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA8_Y_COUNT (DMA8_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA8_Y_MODIFY (DMA8_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA8_CURR_DESC_PTR (DMA8_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA8_CURR_ADDR (DMA8_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA8_IRQ_STATUS (DMA8_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA8_PERIPHERAL_MAP (DMA8_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA8_CURR_X_COUNT (DMA8_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA8_CURR_Y_COUNT (DMA8_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_D0_NEXT_DESC_PTR (MDMA_D0_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_D0_START_ADDR (MDMA_D0_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_D0_CONFIG (MDMA_D0_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_D0_X_COUNT (MDMA_D0_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_D0_X_MODIFY (MDMA_D0_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_D0_Y_COUNT (MDMA_D0_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_D0_Y_MODIFY (MDMA_D0_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_D0_CURR_DESC_PTR (MDMA_D0_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_D0_CURR_ADDR (MDMA_D0_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_D0_IRQ_STATUS (MDMA_D0_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_D0_PERIPHERAL_MAP (MDMA_D0_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_D0_CURR_X_COUNT (MDMA_D0_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_D0_CURR_Y_COUNT (MDMA_D0_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_D1_NEXT_DESC_PTR (MDMA_D1_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_D1_START_ADDR (MDMA_D1_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_D1_CONFIG (MDMA_D1_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_D1_X_COUNT (MDMA_D1_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_D1_X_MODIFY (MDMA_D1_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_D1_Y_COUNT (MDMA_D1_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_D1_Y_MODIFY (MDMA_D1_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_D1_CURR_DESC_PTR (MDMA_D1_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_D1_CURR_ADDR (MDMA_D1_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_D1_IRQ_STATUS (MDMA_D1_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_D1_PERIPHERAL_MAP (MDMA_D1_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_D1_CURR_X_COUNT (MDMA_D1_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_D1_CURR_Y_COUNT (MDMA_D1_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_S0_NEXT_DESC_PTR (MDMA_S0_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_S0_START_ADDR (MDMA_S0_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_S0_CONFIG (MDMA_S0_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_S0_X_COUNT (MDMA_S0_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_S0_X_MODIFY (MDMA_S0_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_S0_Y_COUNT (MDMA_S0_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_S0_Y_MODIFY (MDMA_S0_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_S0_CURR_DESC_PTR (MDMA_S0_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_S0_CURR_ADDR (MDMA_S0_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_S0_IRQ_STATUS (MDMA_S0_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_S0_PERIPHERAL_MAP (MDMA_S0_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_S0_CURR_X_COUNT (MDMA_S0_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_S0_CURR_Y_COUNT (MDMA_S0_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_S1_NEXT_DESC_PTR (MDMA_S1_BASE + 0x00)   /*  “DMA Next Descriptor Pointer Registers (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_S1_START_ADDR (MDMA_S1_BASE + 0x04)   /*  “DMA Start Address Registers (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_S1_CONFIG (MDMA_S1_BASE + 0x08)   /*  “DMA Configuration Registers (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_S1_X_COUNT (MDMA_S1_BASE + 0x10)   /*  “DMA Inner Loop Count Registers (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_S1_X_MODIFY (MDMA_S1_BASE + 0x14)   /*  “DMA Inner Loop Address Increment Registers (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_S1_Y_COUNT (MDMA_S1_BASE + 0x18)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_S1_Y_MODIFY (MDMA_S1_BASE + 0x1)   /* C “DMA Outer Loop Address Increment Registers (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_S1_CURR_DESC_PTR (MDMA_S1_BASE + 0x20)   /*  “DMA Current Descriptor Pointer Registers (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_S1_CURR_ADDR (MDMA_S1_BASE + 0x24)   /*  “DMA Current Address Registers (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_S1_IRQ_STATUS (MDMA_S1_BASE + 0x28)   /*  “DMA Interrupt Status Registers (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_S1_PERIPHERAL_MAP (MDMA_S1_BASE + 0x2)   /* C “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_S1_CURR_X_COUNT (MDMA_S1_BASE + 0x30)   /*  “DMA Current Inner Loop Count Registers (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_S1_CURR_Y_COUNT (MDMA_S1_BASE + 0x38)   /*  “DMA Outer Loop Count Registers (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



// 
// Ports Registers
// 
#define PORTFIO               (0xFFC00700)  /* “GPIO Data Registers” on page 7-23 */
#define PORTFIO_CLEAR         (0xFFC00704)  /* “GPIO Clear Registers” on page 7-24 */
#define PORTFIO_SET           (0xFFC00708)  /* “GPIO Set Registers” on page 7-24 */
#define PORTFIO_TOGGLE        (0xFFC0070C)  /* “GPIO Toggle Registers” on page 7-25 */
#define PORTFIO_MASKA         (0xFFC00710)  /* “GPIO Mask Interrupt A Registers” on page 7-27 */
#define PORTFIO_MASKA_CLEAR   (0xFFC00714)  /* “GPIO Mask Interrupt A Clear Registers” on page 7-30 */
#define PORTFIO_MASKA_SET     (0xFFC00718)  /* “GPIO Mask Interrupt A Set Registers” on page 7-28 */
#define PORTFIO_MASKA_TOGGLE  (0xFFC0071C)  /* “GPIO Mask Interrupt A Toggle Registers” on page 7-32 */
#define PORTFIO_MASKB         (0xFFC00720)  /* “GPIO Mask Interrupt B Registers” on page 7-27 */
#define PORTFIO_MASKB_CLEAR   (0xFFC00724)  /* “GPIO Mask Interrupt B Clear Registers” on page 7-31 */
#define PORTFIO_MASKB_SET     (0xFFC00728)  /* “GPIO Mask Interrupt B Set Registers” on page 7-29 */
#define PORTFIO_MASKB_TOGGLE  (0xFFC0072C)  /* “GPIO Mask Interrupt B Toggle Registers” on page 7-33 */
#define PORTFIO_DIR           (0xFFC00730)  /* “GPIO Direction Registers” on page 7-22 */
#define PORTFIO_POLAR         (0xFFC00734)  /* “GPIO Polarity Registers” on page 7-25 */
#define PORTFIO_EDGE          (0xFFC00738)  /* “Interrupt Sensitivity Registers” on page 7-26 */
#define PORTFIO_BOTH          (0xFFC0073C)  /* “GPIO Set on Both Edges Registers” on page 7-26 */
#define PORTFIO_INEN          (0xFFC00740)  /* “GPIO Input Enable Registers” on page 7-23 */
#define PORTGIO               (0xFFC01500)  /* “GPIO Data Registers” on page 7-23 */
#define PORTGIO_CLEAR         (0xFFC01504)  /* “GPIO Clear Registers” on page 7-24 */
#define PORTGIO_SET           (0xFFC01508)  /* “GPIO Set Registers” on page 7-24 */
#define PORTGIO_TOGGLE        (0xFFC0150C)  /* “GPIO Toggle Registers” on page 7-25 */
#define PORTGIO_MASKA         (0xFFC01510)  /* “GPIO Mask Interrupt A Registers” on page 7-27 */
#define PORTGIO_MASKA_CLEAR   (0xFFC01514)  /* “GPIO Mask Interrupt A Clear Registers” on page 7-30 */
#define PORTGIO_MASKA_SET     (0xFFC01518)  /* “GPIO Mask Interrupt A Set Registers” on page 7-28 */
#define PORTGIO_MASKA_TOGGLE  (0xFFC0151C)  /* “GPIO Mask Interrupt A Toggle Registers” on page 7-32 */
#define PORTGIO_MASKB         (0xFFC01520)  /* “GPIO Mask Interrupt B Registers” on page 7-27 */
#define PORTGIO_MASKB_CLEAR   (0xFFC01524)  /* “GPIO Mask Interrupt B Clear Registers” on page 7-31 */
#define PORTGIO_MASKB_SET     (0xFFC01528)  /* “GPIO Mask Interrupt B Set Registers” on page 7-29 */
#define PORTGIO_MASKB_TOGGLE  (0xFFC0152C)  /* “GPIO Mask Interrupt B Toggle Registers” on page 7-33 */
#define PORTGIO_DIR           (0xFFC01530)  /* “GPIO Direction Registers” on page 7-22 */
#define PORTGIO_POLAR         (0xFFC01534)  /* “GPIO Polarity Registers” on page 7-25 */
#define PORTGIO_EDGE          (0xFFC01538)  /* “Interrupt Sensitivity Registers” on page 7-26 */
#define PORTGIO_BOTH          (0xFFC0153C)  /* “GPIO Set on Both Edges Registers” on page 7-26 */
#define PORTGIO_INEN          (0xFFC01540)  /* “GPIO Input Enable Registers” on page 7-23 */
#define PORTF_FER            (0xFFC01100)  /* “Function Enable Registers” on page 7-22 */
#define PORTG_FER            (0xFFC01200)  /* “Function Enable Registers” on page 7-22 */
#define PORTF_MUX            (0xFFC01104)  /* “Port Multiplexer Control Register” on page 7-21 */
#define PORTG_MUX            (0xFFC01204)  /* “Port Multiplexer Control Register” on page 7-21 */

// 
// Timer Registers
// 
#define TIMER0_CONFIG    (0xFFC00600)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER0_COUNTER    (0xFFC00604)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER0_PERIOD    (0xFFC00608)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER0_WIDTH    (0xFFC0060C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER1_CONFIG    (0xFFC00610)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER1_COUNTER    (0xFFC00614)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER1_PERIOD    (0xFFC00618)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER1_WIDTH    (0xFFC0061C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER2_CONFIG    (0xFFC00620)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER2_COUNTER    (0xFFC00624)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER2_PERIOD    (0xFFC00628)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER2_WIDTH    (0xFFC0062C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER_ENABLE    (0xFFC00640)  /* “Timer Enable Register (TIMER_ENABLE)” on page 8-35 */
#define TIMER_DISABLE    (0xFFC00644)  /* “Timer Disable Register (TIMER_DISABLE)” on page 8-36 */
#define TIMER_STATUS    (0xFFC00648)  /* “Timer Status Register (TIMER_STATUS)” on page 8-38 */

// 
// Watchdog Timer Registers
// 
#define WDOG_CTL    (0xFFC00200)  /* “Watchdog Control (WDOG_CTL) Register” on page 10-8 */
#define WDOG_CNT    (0xFFC00204)  /* “Watchdog Count (WDOG_CNT) Register” on page 10-6 */
#define WDOG_STAT    (0xFFC00208)  /* “Watchdog Status (WDOG_STAT) Register” on page 10-7 */

// 
// Dynamic Power Management Registers
// 
#define PLL_CTL    (0xFFC00000)  /* “PLL_CTL Register” on page 6-21 */
#define PLL_DIV    (0xFFC00004)  /* “PLL_DIV Register” on page 6-20 */
#define VR_CTL    (0xFFC00008)  /* “VR_CTL Register” on page 6-23 */
#define PLL_STAT    (0xFFC0000C)  /* “PLL_STAT Register” on page 6-22 */
#define PLL_LOCKCNT    (0xFFC00010)  /* “PLL_LOCKCNT Register” on page 6-22 */


// 
// PPI Registers
// 
#define PPI_CONTROL    (0xFFC01000)  /* “PPI Control Register (PPI_CONTROL)” on page 15-26 */
#define PPI_STATUS    (0xFFC01004)  /* “PPI Status Register (PPI_STATUS)” on page 15-30 */
#define PPI_COUNT    (0xFFC01008)  /* “PPI Transfer Count Register (PPI_COUNT)” on page 15-34 */
#define PPI_DELAY    (0xFFC0100C)  /* “PPI Delay Count Register (PPI_DELAY)” on page 15-33 */
#define PPI_FRAME    (0xFFC01010)  /* “PPI Lines Per Frame Register (PPI_FRAME)” on page 15-34 */

// 
// SPI Controller Registers
// 
#define SPI0_CTL    (0xFFC00500)  /* “SPI Control (SPI_CTL) Register” on page 13-37 */
#define SPI0_FLG    (0xFFC00504)  /* “SPI Flag (SPI_FLG) Register” on page 13-39 */
#define SPI0_STAT    (0xFFC00508)  /* “SPI Status (SPI_STAT) Register” on page 13-41  */
#define SPI0_TDBR    (0xFFC0050C)  /* “SPI Transmit Data Buffer (SPI_TDBR) Register” on page 13-44 */
#define SPI0_RDBR    (0xFFC00510)  /* “SPI Receive Data Buffer (SPI_RDBR) Register” on page 13-45 */
#define SPI0_BAUD    (0xFFC00514)  /* “SPI Baud Rate (SPI_BAUD) Register” on page 13-36 */
#define SPI0_SHADOW    (0xFFC00518)  /* “SPI RDBR Shadow (SPI_SHADOW) Register” on page 13-45 */
#define SPI1_CTL    (0xFFC01300)  /* “SPI Control (SPI_CTL) Register” on page 13-37 */
#define SPI1_FLG    (0xFFC01304)  /* “SPI Flag (SPI_FLG) Register” on page 13-39 */
#define SPI1_STAT    (0xFFC01308)  /* “SPI Status (SPI_STAT) Register” on page 13-41 */
#define SPI1_TDBR    (0xFFC0130C)  /* “SPI Transmit Data Buffer (SPI_TDBR) Register” on page 13-44 */
#define SPI1_RDBR    (0xFFC01310)  /* “SPI Receive Data Buffer (SPI_RDBR) Register” on page 13-45 */
#define SPI1_BAUD    (0xFFC01314)  /* “SPI Baud Rate (SPI_BAUD) Register” on page 13-36 */
#define SPI1_SHADOW    (0xFFC01318)  /* “SPI RDBR Shadow (SPI_SHADOW) Register” on page 13-45 */


// 
// SPORT Controller Registers
// 
#define SPORT0_TCR1    (0xFFC00800)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT0_TCR2    (0xFFC00804)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT0_TCLKDIV    (0xFFC00808)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT0_TFSDIV    (0xFFC0080C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT0_TX    (0xFFC00810)  /* “SPORT Transmit Data (SPORT_TX) Register” on page 14-59 */
#define SPORT0_RX    (0xFFC00818)  /* “SPORT Receive Data (SPORT_RX) Register” on page 14-61 */
#define SPORT0_RCR1    (0xFFC00820)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT0_RCR2    (0xFFC00824)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT0_RCLKDIV    (0xFFC00828)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT0_RFSDIV    (0xFFC0082C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT0_STAT    (0xFFC00830)  /* “SPORT Status (SPORT_STAT) Register” on page 14-64 */
#define SPORT0_CHNL    (0xFFC00834)  /* “SPORT Current Channel (SPORT_CHNL) Register” on page 14-69 */
#define SPORT0_MCMC1    (0xFFC00838)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT0_MCMC2    (0xFFC0083C)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT0_MTCS0    (0xFFC00840)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS1    (0xFFC00844)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS2    (0xFFC00848)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS3    (0xFFC0084C)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MRCS0    (0xFFC00850)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS1    (0xFFC00854)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS2    (0xFFC00858)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS3    (0xFFC0085C)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_TCR1    (0xFFC00900)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT1_TCR2    (0xFFC00904)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT1_TCLKDIV    (0xFFC00908)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT1_TFSDIV    (0xFFC0090C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT1_TX    (0xFFC00910)  /* “SPORT Transmit Data (SPORT_TX) Register” on page 14-59 */
#define SPORT1_RX    (0xFFC00918)  /* “SPORT Receive Data (SPORT_RX) Register” on page 14-61 */
#define SPORT1_RCR1    (0xFFC00920)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT1_RCR2    (0xFFC00924)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT1_RCLKDIV    (0xFFC00928)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT1_RFSDIV    (0xFFC0092C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT1_STAT    (0xFFC00930)  /* “SPORT Status (SPORT_STAT) Register” on page 14-64 */
#define SPORT1_CHNL    (0xFFC00934)  /* “SPORT Current Channel (SPORT_CHNL) Register” on page 14-69 */
#define SPORT1_MCMC1    (0xFFC00938)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT1_MCMC2    (0xFFC0093C)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT1_MTCS0    (0xFFC00940)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS1    (0xFFC00944)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS2    (0xFFC00948)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS3    (0xFFC0094C)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MRCS0    (0xFFC00950)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS1    (0xFFC00954)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS2    (0xFFC00958)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS3    (0xFFC0095C)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT_CLKGATE    (0xFFC0120C)  /* “SPORT Clock Gating Register” on page 14-81 */


// 
// UART Controller Registers
// 
#define UART_THR    (0xFFC00400)  /* “UART Transmit Holding (UART_THR) Register” on page 11-26 */
#define UART_RBR    (0xFFC00400)  /* “UART Receive Buffer (UART_RBR) Register” on page 11-27 */
#define UART_DLL    (0xFFC00400)  /* “UART Divisor Latch (UART_DLL and UART_DLH) Registers” on page 11-31 */
#define UART_DLH    (0xFFC00404)  /* “UART Divisor Latch (UART_DLL and UART_DLH) Registers” on page 11-31 */
#define UART_IER    (0xFFC00404)  /* “UART Interrupt Enable (UART_IER) Register” on page 11-27 */
#define UART_IIR    (0xFFC00408)  /* “UART Interrupt Identification (UART_IIR) Register” on page 11-29 */
#define UART_LCR    (0xFFC0040C)  /* “UART Line Control (UART_LCR) Register” on page 11-22 */
#define UART_MCR    (0xFFC00410)  /* “UART Modem Control (UART_MCR) Register” on page 11-24 */
#define UART_LSR    (0xFFC00414)  /* “UART Line Status (UART_LSR) Register” on page 11-25 */
#define UART_SCR    (0xFFC0041C)  /* “UART Scratch (UART_SCR) Register” on page 11-32 */
#define UART_GCTL    (0xFFC00424)  /* “UART Global Control (UART_GCTL) Register” on page 11-32 */


// 
// TWI Registers
// 
#define TWI_CLKDIV    (0xFFC01400)  /* “SCL Clock Divider Register (TWI_CLKDIV)” on page 12-26 */
#define TWI_CONTROL    (0xFFC01404)  /* “TWI CONTROL Register (TWI_CONTROL)” on page 12-25 */
#define TWI_SLAVE_CTL    (0xFFC01408)  /* “TWI Slave Mode Control Register (TWI_SLAVE_CTL)” on page 12-27 */
#define TWI_SLAVE_STAT    (0xFFC0140C)  /* “TWI Slave Mode Status Register (TWI_SLAVE_STAT)” on page 12-29 */
#define TWI_SLAVE_ADDR    (0xFFC01410)  /* “TWI Slave Mode Address Register (TWI_SLAVE_ADDR)” on page 12-29 */
#define TWI_MASTER_CTL    (0xFFC01414)  /* “TWI Master Mode Control Register (TWI_MASTER_CTL)” on page 12-31 */
#define TWI_MASTER_STAT    (0xFFC01418)  /* “TWI Master Mode Status Register (TWI_MASTER_STAT)” on page 12-35 */
#define TWI_MASTER_ADDR    (0xFFC0141C)  /* “TWI Master Mode Address Register (TWI_MASTER_ADDR)” on page 12-34 */
#define TWI_INT_STAT    (0xFFC01420)  /* “TWI Interrupt Status Register (TWI_INT_STAT)” on page 12-43 */
#define TWI_INT_MASK    (0xFFC01424)  /* “TWI Interrupt Mask Register (TWI_INT_MASK)” on page 12-42 */
#define TWI_FIFO_CTL    (0xFFC01428)  /* “TWI FIFO Control Register (TWI_FIFO_CTL)” on page 12-38 */
#define TWI_FIFO_STAT    (0xFFC0142C)  /* “TWI FIFO Status Register (TWI_FIFO_STAT)” on page 12-40 */
#define TWI_XMT_DATA8    (0xFFC01480)  /* “TWI FIFO Transmit Data Single Byte Register (TWI_XMT_DATA8)” on page 12-46 */
#define TWI_XMT_DATA16    (0xFFC01484)  /* “TWI FIFO Transmit Data Double Byte Register (TWI_XMT_DATA16)” on page 12-47 */
#define TWI_RCV_DATA8    (0xFFC01488)  /* “TWI FIFO Receive Data Single Byte Register (TWI_RCV_DATA8)” on page 12-48 */
#define TWI_RCV_DATA16    (0xFFC0148C)  /* “TWI FIFO Receive Data Double Byte Register (TWI_RCV_DATA16)” on page 12-49 */


#endif /* _BF592_H_ */

