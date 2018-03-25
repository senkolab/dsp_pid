/*
 * BF592.h - register definitions for Analog Devices Blackfin BF592 processor
 *
 * Written by Rich Rademacher / IQC / University of Waterloo
 * March 2018
 */


#ifndef _BF592_H_
#define _BF592_H_


//
// core registers
//
#include <processor/blackfin_core.h>

// 
// Processor-Specific Memory Registers
// 
#define DTEST_COMMAND_ADDR    (0xFFE00300)  /* “Data Test Command Register” on page 2-5 */

// 
// Core Timer Registers
// 
#define TCNTL_ADDR       (0xFFE03000)  /* “Core Timer Control Register (TCNTL)” on page 9-5 */
#define TPERIOD_ADDR     (0xFFE03004)  /* “Core Timer Period Register (TPERIOD)” on page 9-6 */
#define TSCALE_ADDR      (0xFFE03008)  /* “Core Timer Scale Register (TSCALE)” on page 9-7 */
#define TCOUNT_ADDR      (0xFFE0300C)  /* “Core Timer Count Register (TCOUNT)” on page 9-5 */

typedef struct _bf592_coretimer_t {
  u8      start [ TCNTL_ADDR - BLACFIN_MMR_BASE ];
  u32     tcntl;       // 0xFFE03000
  u32     tperiod;     // 0xFFE03004
  u32     tscale;      // 0xFFE03008
  u32     tcount;      // 0xFFE0300C
} bf592_coretimer_t;

// 
// System Reset and Interrupt Control Registers
// 
#define SYSCR_ADDR       (0xFFC00104)  /* “System Reset Configuration (SYSCR) Register” on page 16-57 */
#define SIC_IMASK0_ADDR  (0xFFC0010C)  /* “System Interrupt Mask (SIC_IMASK) Register” on page 4-12 */
#define SIC_IAR0_ADDR    (0xFFC00110)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR1_ADDR    (0xFFC00114)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR2_ADDR    (0xFFC00118)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_IAR3_ADDR    (0xFFC0011C)  /* “System Interrupt Assignment (SIC_IAR) Register” on page 4-11 */
#define SIC_ISR0_ADDR    (0xFFC00120)  /* “System Interrupt Status (SIC_ISR) Register” on page 4-12 */
#define SIC_IWR0_ADDR    (0xFFC00124)  /* “System Interrupt Wakeup-Enable (SIC_IWR) Register” on page 4-13 */

typdef struct _bf592_sic_t {
  u8  start[ SYSCR_ADDR - BLACKFIN_MMR_BASE ];
  u16 SYSCR;       // 0xFFC00104
  u8  pad00[0x0c - 0x04 - 2];
  u16 SIC_IMASK0;  // 0xFFC0010C
  u32 SIC_IAR0;    // 0xFFC00110
  u32 SIC_IAR1;    // 0xFFC00114
  u32 SIC_IAR2;    // 0xFFC00118
  u32 SIC_IAR3;    // 0xFFC0011C
  u32 SIC_ISR0;    // 0xFFC00120
  u32 SIC_IWR0;    // 0xFFC00124
} bf592_sic_t;




// 
// DMA/Memory DMA Control Registers
// 
#define DMA_TC_PER_ADDR  (0xFFC00B0C)  /* “DMA_TC_PER Register” on page 5-93 */
#define DMA_TC_CNT_ADDR  (0xFFC00B10)  /* “DMA_TC_CNT Register” on page 5-93 */

#define DMA0_START_ADDR    (0xFFC00C00)
#define DMA1_START_ADDR    (0xFFC00C40)
#define DMA2_START_ADDR    (0xFFC00C80)
#define DMA3_START_ADDR    (0xFFC00CC0)
#define DMA4_START_ADDR    (0xFFC00D00)
#define DMA5_START_ADDR    (0xFFC00D40)
#define DMA6_START_ADDR    (0xFFC00D80)
#define DMA7_START_ADDR    (0xFFC00DC0)
#define DMA8_START_ADDR    (0xFFC00E00)
#define MDMA_D0_START_ADDR    (0xFFC00F00)
#define MDMA_S0_START_ADDR    (0xFFC00F40)
#define MDMA_D1_START_ADDR    (0xFFC00F80)
#define MDMA_S1_START_ADDR    (0xFFC00FC0)

#define DMA0_NEXT_DESC_PTR_ADDR     (DMA0_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA0_START_ADDR_ADDR        (DMA0_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA0_CONFIG_ADDR            (DMA0_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA0_X_COUNT_ADDR           (DMA0_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA0_X_MODIFY_ADDR          (DMA0_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA0_Y_COUNT_ADDR           (DMA0_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA0_Y_MODIFY_ADDR          (DMA0_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA0_CURR_DESC_PTR_ADDR     (DMA0_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA0_CURR_ADDR_ADDR         (DMA0_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA0_IRQ_STATUS_ADDR        (DMA0_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA0_PERIPHERAL_MAP_ADDR    (DMA0_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA0_CURR_X_COUNT_ADDR      (DMA0_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA0_CURR_Y_COUNT_ADDR      (DMA0_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA1_NEXT_DESC_PTR_ADDR     (DMA1_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA1_START_ADDR_ADDR        (DMA1_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA1_CONFIG_ADDR            (DMA1_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA1_X_COUNT_ADDR           (DMA1_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA1_X_MODIFY_ADDR          (DMA1_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA1_Y_COUNT_ADDR           (DMA1_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA1_Y_MODIFY_ADDR          (DMA1_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA1_CURR_DESC_PTR_ADDR     (DMA1_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA1_CURR_ADDR_ADDR         (DMA1_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA1_IRQ_STATUS_ADDR        (DMA1_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA1_PERIPHERAL_MAP_ADDR    (DMA1_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA1_CURR_X_COUNT_ADDR      (DMA1_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA1_CURR_Y_COUNT_ADDR      (DMA1_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA2_NEXT_DESC_PTR_ADDR     (DMA2_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA2_START_ADDR_ADDR        (DMA2_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA2_CONFIG_ADDR            (DMA2_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA2_X_COUNT_ADDR           (DMA2_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA2_X_MODIFY_ADDR          (DMA2_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA2_Y_COUNT_ADDR           (DMA2_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA2_Y_MODIFY_ADDR          (DMA2_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA2_CURR_DESC_PTR_ADDR     (DMA2_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA2_CURR_ADDR_ADDR         (DMA2_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA2_IRQ_STATUS_ADDR        (DMA2_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA2_PERIPHERAL_MAP_ADDR    (DMA2_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA2_CURR_X_COUNT_ADDR      (DMA2_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA2_CURR_Y_COUNT_ADDR      (DMA2_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA3_NEXT_DESC_PTR_ADDR     (DMA3_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA3_START_ADDR_ADDR        (DMA3_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA3_CONFIG_ADDR            (DMA3_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA3_X_COUNT_ADDR           (DMA3_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA3_X_MODIFY_ADDR          (DMA3_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA3_Y_COUNT_ADDR           (DMA3_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA3_Y_MODIFY_ADDR          (DMA3_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA3_CURR_DESC_PTR_ADDR     (DMA3_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA3_CURR_ADDR_ADDR         (DMA3_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA3_IRQ_STATUS_ADDR        (DMA3_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA3_PERIPHERAL_MAP_ADDR    (DMA3_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA3_CURR_X_COUNT_ADDR      (DMA3_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA3_CURR_Y_COUNT_ADDR      (DMA3_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA4_NEXT_DESC_PTR_ADDR     (DMA4_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA4_START_ADDR_ADDR        (DMA4_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA4_CONFIG_ADDR            (DMA4_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA4_X_COUNT_ADDR           (DMA4_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA4_X_MODIFY_ADDR          (DMA4_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA4_Y_COUNT_ADDR           (DMA4_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA4_Y_MODIFY_ADDR          (DMA4_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA4_CURR_DESC_PTR_ADDR     (DMA4_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA4_CURR_ADDR_ADDR         (DMA4_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA4_IRQ_STATUS_ADDR        (DMA4_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA4_PERIPHERAL_MAP_ADDR    (DMA4_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA4_CURR_X_COUNT_ADDR      (DMA4_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA4_CURR_Y_COUNT_ADDR      (DMA4_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA5_NEXT_DESC_PTR_ADDR     (DMA5_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA5_START_ADDR_ADDR        (DMA5_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA5_CONFIG_ADDR            (DMA5_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA5_X_COUNT_ADDR           (DMA5_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA5_X_MODIFY_ADDR          (DMA5_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA5_Y_COUNT_ADDR           (DMA5_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA5_Y_MODIFY_ADDR          (DMA5_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA5_CURR_DESC_PTR_ADDR     (DMA5_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA5_CURR_ADDR_ADDR         (DMA5_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA5_IRQ_STATUS_ADDR        (DMA5_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA5_PERIPHERAL_MAP_ADDR    (DMA5_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA5_CURR_X_COUNT_ADDR      (DMA5_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA5_CURR_Y_COUNT_ADDR      (DMA5_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA6_NEXT_DESC_PTR_ADDR     (DMA6_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA6_START_ADDR_ADDR        (DMA6_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA6_CONFIG_ADDR            (DMA6_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA6_X_COUNT_ADDR           (DMA6_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA6_X_MODIFY_ADDR          (DMA6_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA6_Y_COUNT_ADDR           (DMA6_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA6_Y_MODIFY_ADDR          (DMA6_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA6_CURR_DESC_PTR_ADDR     (DMA6_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA6_CURR_ADDR_ADDR         (DMA6_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA6_IRQ_STATUS_ADDR        (DMA6_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA6_PERIPHERAL_MAP_ADDR    (DMA6_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA6_CURR_X_COUNT_ADDR      (DMA6_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA6_CURR_Y_COUNT_ADDR      (DMA6_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA7_NEXT_DESC_PTR_ADDR     (DMA7_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA7_START_ADDR_ADDR        (DMA7_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA7_CONFIG_ADDR            (DMA7_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA7_X_COUNT_ADDR           (DMA7_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA7_X_MODIFY_ADDR          (DMA7_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA7_Y_COUNT_ADDR           (DMA7_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA7_Y_MODIFY_ADDR          (DMA7_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA7_CURR_DESC_PTR_ADDR     (DMA7_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA7_CURR_ADDR_ADDR         (DMA7_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA7_IRQ_STATUS_ADDR        (DMA7_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA7_PERIPHERAL_MAP_ADDR    (DMA7_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA7_CURR_X_COUNT_ADDR      (DMA7_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA7_CURR_Y_COUNT_ADDR      (DMA7_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


#define DMA8_NEXT_DESC_PTR_ADDR     (DMA8_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define DMA8_START_ADDR_ADDR        (DMA8_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define DMA8_CONFIG_ADDR            (DMA8_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define DMA8_X_COUNT_ADDR           (DMA8_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define DMA8_X_MODIFY_ADDR          (DMA8_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define DMA8_Y_COUNT_ADDR           (DMA8_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define DMA8_Y_MODIFY_ADDR          (DMA8_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define DMA8_CURR_DESC_PTR_ADDR     (DMA8_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define DMA8_CURR_ADDR_ADDR         (DMA8_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define DMA8_IRQ_STATUS_ADDR        (DMA8_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define DMA8_PERIPHERAL_MAP_ADDR    (DMA8_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define DMA8_CURR_X_COUNT_ADDR      (DMA8_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define DMA8_CURR_Y_COUNT_ADDR      (DMA8_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_D0_NEXT_DESC_PTR_ADDR    (MDMA_D0_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_D0_START_ADDR_ADDR       (MDMA_D0_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_D0_CONFIG_ADDR           (MDMA_D0_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_D0_X_COUNT_ADDR          (MDMA_D0_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_D0_X_MODIFY_ADDR         (MDMA_D0_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_D0_Y_COUNT_ADDR          (MDMA_D0_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_D0_Y_MODIFY_ADDR         (MDMA_D0_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_D0_CURR_DESC_PTR_ADDR    (MDMA_D0_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_D0_CURR_ADDR_ADDR        (MDMA_D0_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_D0_IRQ_STATUS_ADDR       (MDMA_D0_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_D0_PERIPHERAL_MAP_ADDR   (MDMA_D0_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_D0_CURR_X_COUNT_ADDR     (MDMA_D0_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_D0_CURR_Y_COUNT_ADDR     (MDMA_D0_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_D1_NEXT_DESC_PTR_ADDR    (MDMA_D1_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_D1_START_ADDR_ADDR       (MDMA_D1_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_D1_CONFIG_ADDR           (MDMA_D1_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_D1_X_COUNT_ADDR          (MDMA_D1_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_D1_X_MODIFY_ADDR         (MDMA_D1_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_D1_Y_COUNT_ADDR          (MDMA_D1_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_D1_Y_MODIFY_ADDR         (MDMA_D1_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_D1_CURR_DESC_PTR_ADDR    (MDMA_D1_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_D1_CURR_ADDR_ADDR        (MDMA_D1_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_D1_IRQ_STATUS_ADDR       (MDMA_D1_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_D1_PERIPHERAL_MAP_ADDR   (MDMA_D1_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_D1_CURR_X_COUNT_ADDR     (MDMA_D1_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_D1_CURR_Y_COUNT_ADDR     (MDMA_D1_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_S0_NEXT_DESC_PTR_ADDR    (MDMA_S0_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_S0_START_ADDR_ADDR       (MDMA_S0_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_S0_CONFIG_ADDR           (MDMA_S0_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_S0_X_COUNT_ADDR          (MDMA_S0_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_S0_X_MODIFY_ADDR         (MDMA_S0_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_S0_Y_COUNT_ADDR          (MDMA_S0_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_S0_Y_MODIFY_ADDR         (MDMA_S0_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_S0_CURR_DESC_PTR_ADDR    (MDMA_S0_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_S0_CURR_ADDR_ADDR        (MDMA_S0_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_S0_IRQ_STATUS_ADDR       (MDMA_S0_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_S0_PERIPHERAL_MAP_ADDR   (MDMA_S0_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_S0_CURR_X_COUNT_ADDR     (MDMA_S0_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_S0_CURR_Y_COUNT_ADDR     (MDMA_S0_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */



#define MDMA_S1_NEXT_DESC_PTR_ADDR    (MDMA_S1_START_ADDR + 0x00)   /*  “DMA Next Descriptor Pointer Registers    (DMAx_NEXT_DESC_PTR/ MDMA_yy_NEXT_DESC_PTR)” on page 5-84 */
#define MDMA_S1_START_ADDR_ADDR       (MDMA_S1_START_ADDR + 0x04)   /*  “DMA Start Address Registers    (DMAx_START_ADDR/MDMA_yy_START_ADDR)” on page 5-77 */
#define MDMA_S1_CONFIG_ADDR           (MDMA_S1_START_ADDR + 0x08)   /*  “DMA Configuration Registers    (DMAx_CONFIG/MDMA_yy_CONFIG)” on page 5-70 */
#define MDMA_S1_X_COUNT_ADDR          (MDMA_S1_START_ADDR + 0x10)   /*  “DMA Inner Loop Count Registers    (DMAx_X_COUNT/MDMA_yy_X_COUNT)” on page 5-78 */
#define MDMA_S1_X_MODIFY_ADDR         (MDMA_S1_START_ADDR + 0x14)   /*  “DMA Inner Loop Address Increment Registers    (DMAx_X_MODIFY/MDMA_yy_X_MODIFY)” on page 5-80 */
#define MDMA_S1_Y_COUNT_ADDR          (MDMA_S1_START_ADDR + 0x18)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */
#define MDMA_S1_Y_MODIFY_ADDR         (MDMA_S1_START_ADDR + 0x1c)   /*  “DMA Outer Loop Address Increment Registers    (DMAx_Y_MODIFY/MDMA_yy_Y_MODIFY)” on page 5-83 */
#define MDMA_S1_CURR_DESC_PTR_ADDR    (MDMA_S1_START_ADDR + 0x20)   /*  “DMA Current Descriptor Pointer Registers    (DMAx_CURR_DESC_PTR/ MDMA_yy_CURR_DESC_PTR)” on page 5-85 */
#define MDMA_S1_CURR_ADDR_ADDR        (MDMA_S1_START_ADDR + 0x24)   /*  “DMA Current Address Registers    (DMAx_CURR_ADDR/MDMA_yy_CURR_ADDR)” on page 5-77 */
#define MDMA_S1_IRQ_STATUS_ADDR       (MDMA_S1_START_ADDR + 0x28)   /*  “DMA Interrupt Status Registers    (DMAx_IRQ_STATUS/MDMA_yy_IRQ_STATUS)” on page 5-74 */
#define MDMA_S1_PERIPHERAL_MAP_ADDR   (MDMA_S1_START_ADDR + 0x2c)   /*  “DMA Peripheral Map Registers DMAx_PERIPHERAL_MAP/ MDMA_yy_PERIPHERAL_MAP)” on page 5-69 */
#define MDMA_S1_CURR_X_COUNT_ADDR     (MDMA_S1_START_ADDR + 0x30)   /*  “DMA Current Inner Loop Count Registers    (DMAx_CURR_X_COUNT /MDMA_yy_CURR_X_COUNT)” on page 5-79 */
#define MDMA_S1_CURR_Y_COUNT_ADDR     (MDMA_S1_START_ADDR + 0x38)   /*  “DMA Outer Loop Count Registers    (DMAx_Y_COUNT/MDMA_yy_Y_COUNT)” on page 5-81 */


typedef struct _bf592_dma_desc_t {
  void*   next_desc_ptr;     // 0x00
  void*   start_addr;        // 0x04
  u16     config;            // 0x08
  u16     pad00
  u16     x_count;           // 0x10
  u16     pad01;
  u16     x_modify;          // 0x14
  u16     pad02;        
  u16     y_count;           // 0x18
  u16     pad03;
  u16     y_modify;          // 0x1c
  u16     pad04;
  void*   curr_desc_ptr;     // 0x20
  void*   curr_addr;         // 0x24
  u16     irq_status;        // 0x28
  u16     pad05;
  u16     peripheral_map;    // 0x2c
  u16     pad06;
  u16     curr_x_count;      // 0x30
  u16     pad07;
  u16     curr_y_count;      // 0x38
  u8      pad08[ DMA1_NEXT_DESC_PTR_ADDR - DMA0_CURR_Y_COUNT - 2];  // inter-descriptor padding

#define MDMA_D0_START_ADDR    (0xFFC00F00)
#define MDMA_S0_START_ADDR    (0xFFC00F40)
#define MDMA_D1_START_ADDR    (0xFFC00F80)
#define MDMA_S1_START_ADDR    (0xFFC00FC0)

} bf592_dma_desc_t;


typedef struct _bf592_dma_t {
  u8 start[ DMA_TC_PER_ADDR - BLACKFIN_MMR_BASE ];
  u16 dma_tc_per;  // 0xFFC00B0C
  u16 dma_tc_cnt;  // 0xFFC00B10

  u8  pad00[ DMA0_START_ADDR - DMA_TC_CNT_ADDR];
  bf592_dma_desc_t dma[9];

  u8  pad01[ MDMA_NEXT_DESC_PTR - DMA8_CURR_Y_COUNT - 0x40];
  bf592_dma_desc_t mdma_d0;
  bf592_dma_desc_t mdma_s0;
  bf592_dma_desc_t mdma_d1;
  bf592_dma_desc_t mdma_s1;
} bf592_dma_t;

// 
// Ports Registers
// 
#define PORTFIO_ADDR                  (0xFFC00700)  /* “GPIO Data Registers” on page 7-23 */
#define PORTFIO_CLEAR_ADDR            (0xFFC00704)  /* “GPIO Clear Registers” on page 7-24 */
#define PORTFIO_SET_ADDR              (0xFFC00708)  /* “GPIO Set Registers” on page 7-24 */
#define PORTFIO_TOGGLE_ADDR           (0xFFC0070C)  /* “GPIO Toggle Registers” on page 7-25 */
#define PORTFIO_MASKA_ADDR            (0xFFC00710)  /* “GPIO Mask Interrupt A Registers” on page 7-27 */
#define PORTFIO_MASKA_CLEAR_ADDR      (0xFFC00714)  /* “GPIO Mask Interrupt A Clear Registers” on page 7-30 */
#define PORTFIO_MASKA_SET_ADDR        (0xFFC00718)  /* “GPIO Mask Interrupt A Set Registers” on page 7-28 */
#define PORTFIO_MASKA_TOGGLE_ADDR     (0xFFC0071C)  /* “GPIO Mask Interrupt A Toggle Registers” on page 7-32 */
#define PORTFIO_MASKB_ADDR            (0xFFC00720)  /* “GPIO Mask Interrupt B Registers” on page 7-27 */
#define PORTFIO_MASKB_CLEAR_ADDR      (0xFFC00724)  /* “GPIO Mask Interrupt B Clear Registers” on page 7-31 */
#define PORTFIO_MASKB_SET_ADDR        (0xFFC00728)  /* “GPIO Mask Interrupt B Set Registers” on page 7-29 */
#define PORTFIO_MASKB_TOGGLE_ADDR     (0xFFC0072C)  /* “GPIO Mask Interrupt B Toggle Registers” on page 7-33 */
#define PORTFIO_DIR_ADDR              (0xFFC00730)  /* “GPIO Direction Registers” on page 7-22 */
#define PORTFIO_POLAR_ADDR            (0xFFC00734)  /* “GPIO Polarity Registers” on page 7-25 */
#define PORTFIO_EDGE_ADDR             (0xFFC00738)  /* “Interrupt Sensitivity Registers” on page 7-26 */
#define PORTFIO_BOTH_ADDR             (0xFFC0073C)  /* “GPIO Set on Both Edges Registers” on page 7-26 */
#define PORTFIO_INEN_ADDR             (0xFFC00740)  /* “GPIO Input Enable Registers” on page 7-23 */
#define PORTGIO_ADDR                  (0xFFC01500)  /* “GPIO Data Registers” on page 7-23 */
#define PORTGIO_CLEAR_ADDR            (0xFFC01504)  /* “GPIO Clear Registers” on page 7-24 */
#define PORTGIO_SET_ADDR              (0xFFC01508)  /* “GPIO Set Registers” on page 7-24 */
#define PORTGIO_TOGGLE_ADDR           (0xFFC0150C)  /* “GPIO Toggle Registers” on page 7-25 */
#define PORTGIO_MASKA_ADDR            (0xFFC01510)  /* “GPIO Mask Interrupt A Registers” on page 7-27 */
#define PORTGIO_MASKA_CLEAR_ADDR      (0xFFC01514)  /* “GPIO Mask Interrupt A Clear Registers” on page 7-30 */
#define PORTGIO_MASKA_SET_ADDR        (0xFFC01518)  /* “GPIO Mask Interrupt A Set Registers” on page 7-28 */
#define PORTGIO_MASKA_TOGGLE_ADDR     (0xFFC0151C)  /* “GPIO Mask Interrupt A Toggle Registers” on page 7-32 */
#define PORTGIO_MASKB_ADDR            (0xFFC01520)  /* “GPIO Mask Interrupt B Registers” on page 7-27 */
#define PORTGIO_MASKB_CLEAR_ADDR      (0xFFC01524)  /* “GPIO Mask Interrupt B Clear Registers” on page 7-31 */
#define PORTGIO_MASKB_SET_ADDR        (0xFFC01528)  /* “GPIO Mask Interrupt B Set Registers” on page 7-29 */
#define PORTGIO_MASKB_TOGGLE_ADDR     (0xFFC0152C)  /* “GPIO Mask Interrupt B Toggle Registers” on page 7-33 */
#define PORTGIO_DIR_ADDR              (0xFFC01530)  /* “GPIO Direction Registers” on page 7-22 */
#define PORTGIO_POLAR_ADDR            (0xFFC01534)  /* “GPIO Polarity Registers” on page 7-25 */
#define PORTGIO_EDGE_ADDR             (0xFFC01538)  /* “Interrupt Sensitivity Registers” on page 7-26 */
#define PORTGIO_BOTH_ADDR             (0xFFC0153C)  /* “GPIO Set on Both Edges Registers” on page 7-26 */
#define PORTGIO_INEN_ADDR             (0xFFC01540)  /* “GPIO Input Enable Registers” on page 7-23 */
#define PORTF_FER_ADDR                (0xFFC01100)  /* “Function Enable Registers” on page 7-22 */
#define PORTG_FER_ADDR                (0xFFC01200)  /* “Function Enable Registers” on page 7-22 */
#define PORTF_MUX_ADDR                (0xFFC01104)  /* “Port Multiplexer Control Register” on page 7-21 */
#define PORTG_MUX_ADDR                (0xFFC01204)  /* “Port Multiplexer Control Register” on page 7-21 */

typedef struct _bf592_port_t {
  u8          start[ PLL_CTL_ADDR - BLACKFIN_MMR_BASE ];
  u16         portfio;                  // 0xFFC00700
  u8          pad01[ 0x704 - 0x700 + 2 ];
  u16         portfio_clear;            // 0xFFC00704
  u8          pad02[ 0x708 - 0x704 + 2 ];
  u16         portfio_set;              // 0xFFC00708
  u8          pad03[ 0x70c - 0x708 + 2 ];
  u16         portfio_toggle;           // 0xFFC0070C
  u8          pad04[ 0x710 - 0x70c + 2 ];
  u16         portfio_maska;            // 0xFFC00710
  u8          pad05[ 0x714 - 0x710 + 2 ];
  u16         portfio_maska_clear;      // 0xFFC00714
  u8          pad06[ 0x718 - 0x714 + 2 ];
  u16         portfio_maska_set;        // 0xFFC00718
  u8          pad07[ 0x71c - 0x718 + 2 ];
  u16         portfio_maska_toggle;     // 0xFFC0071C
  u8          pad08[ 0x720 - 0x71c + 2 ];
  u16         portfio_maskb;            // 0xFFC00720
  u8          pad09[ 0x724 - 0x720 + 2 ];
  u16         portfio_maskb_clear;      // 0xFFC00724
  u8          pad10[ 0x728 - 0x724 + 2 ];
  u16         portfio_maskb_set;        // 0xFFC00728
  u8          pad11[ 0x72c - 0x728 + 2 ];
  u16         portfio_maskb_toggle;     // 0xFFC0072C
  u8          pad12[ 0x730 - 0x72c + 2 ];
  u16         portfio_dir;              // 0xFFC00730
  u8          pad13[ 0x734 - 0x730 + 2 ];
  u16         portfio_polar;            // 0xFFC00734
  u8          pad14[ 0x738 - 0x734 + 2 ];
  u16         portfio_edge;             // 0xFFC00738
  u8          pad15[ 0x73c - 0x738 + 2 ];
  u16         portfio_both;             // 0xFFC0073C
  u8          pad16[ 0x740 - 0x73c + 2 ];
  u16         portfio_inen;             // 0xFFC00740

  u8          pad34[ 0x1100 - 0x0740 + 2 ];
  u16         portf_fer;                // 0xFFC01100
  u8          pad36[ 0x1104 - 0x1100 + 2 ];
  u16         portf_mux;                // 0xFFC01104
  u8          pad35[ 0x1200 - 0x1104 + 2 ];
  u16         portg_fer;                // 0xFFC01200
  u8          pad37[ 0x1204 - 0x1200 + 2 ];
  u16         portg_mux;                // 0xFFC01204

  u8          pad17[ 0x1500 - 0x1204 + 2 ];
  u16         portgio;                  // 0xFFC01500
  u8          pad18[ 0x1504 - 0x1500 + 2 ];
  u16         portgio_clear;            // 0xFFC01504
  u8          pad19[ 0x1508 - 0x1504 + 2 ];
  u16         portgio_set;              // 0xFFC01508
  u8          pad20[ 0x150c - 0x1508 + 2 ];
  u16         portgio_toggle;           // 0xFFC0150C
  u8          pad21[ 0x1510 - 0x150c + 2 ];
  u16         portgio_maska;            // 0xFFC01510
  u8          pad22[ 0x1514 - 0x1510 + 2 ];
  u16         portgio_maska_clear;      // 0xFFC01514
  u8          pad23[ 0x1518 - 0x1514 + 2 ];
  u16         portgio_maska_set;        // 0xFFC01518
  u8          pad24[ 0x151c - 0x1518 + 2 ];
  u16         portgio_maska_toggle;     // 0xFFC0151C
  u8          pad25[ 0x1520 - 0x151c + 2 ];
  u16         portgio_maskb;            // 0xFFC01520
  u8          pad26[ 0x1524 - 0x1520 + 2 ];
  u16         portgio_maskb_clear;      // 0xFFC01524
  u8          pad27[ 0x1528 - 0x1524 + 2 ];
  u16         portgio_maskb_set;        // 0xFFC01528
  u8          pad28[ 0x152c - 0x1528 + 2 ];
  u16         portgio_maskb_toggle;     // 0xFFC0152C
  u8          pad29[ 0x1530 - 0x152c + 2 ];
  u16         portgio_dir;              // 0xFFC01530
  u8          pad30[ 0x1534 - 0x1530 + 2 ];
  u16         portgio_polar;            // 0xFFC01534
  u8          pad31[ 0x1538 - 0x1534 + 2 ];
  u16         portgio_edge;             // 0xFFC01538
  u8          pad32[ 0x153c - 0x1538 + 2 ];
  u16         portgio_both;             // 0xFFC0153C
  u8          pad33[ 0x1540 - 0x153c + 2 ];
  u16         portgio_inen;             // 0xFFC01540
} bf592_port_t;

// 
// Timer Registers
// 
#define TIMER0_CONFIG_ADDR      (0xFFC00600)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER0_COUNTER_ADDR     (0xFFC00604)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER0_PERIOD_ADDR      (0xFFC00608)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER0_WIDTH_ADDR       (0xFFC0060C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER1_CONFIG_ADDR      (0xFFC00610)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER1_COUNTER_ADDR     (0xFFC00614)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER1_PERIOD_ADDR      (0xFFC00618)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER1_WIDTH_ADDR       (0xFFC0061C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER2_CONFIG_ADDR      (0xFFC00620)  /* “Timer Configuration Register (TIMER_CONFIG)” on page 8-40 */
#define TIMER2_COUNTER_ADDR     (0xFFC00624)  /* “Timer Counter Register (TIMER_COUNTER)” on page 8-41 */
#define TIMER2_PERIOD_ADDR      (0xFFC00628)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER2_WIDTH_ADDR       (0xFFC0062C)  /* “Timer Period (TIMER_PERIOD) and Timer Width (TIMER_WIDTH) Registers” on page 8-42 */
#define TIMER_ENABLE_ADDR       (0xFFC00640)  /* “Timer Enable Register (TIMER_ENABLE)” on page 8-35 */
#define TIMER_DISABLE_ADDR      (0xFFC00644)  /* “Timer Disable Register (TIMER_DISABLE)” on page 8-36 */
#define TIMER_STATUS_ADDR       (0xFFC00648)  /* “Timer Status Register (TIMER_STATUS)” on page 8-38 */

// 
// Watchdog Timer Registers
// 
#define WDOG_CTL_ADDR           (0xFFC00200)  /* “Watchdog Control (WDOG_CTL) Register” on page 10-8 */
#define WDOG_CNT_ADDR           (0xFFC00204)  /* “Watchdog Count (WDOG_CNT) Register” on page 10-6 */
#define WDOG_STAT_ADDR          (0xFFC00208)  /* “Watchdog Status (WDOG_STAT) Register” on page 10-7 */

// 
// Dynamic Power Management Registers
// 
#define PLL_CTL_ADDR            (0xFFC00000)  /* “PLL_CTL Register” on page 6-21 */
#define PLL_DIV_ADDR            (0xFFC00004)  /* “PLL_DIV Register” on page 6-20 */
#define VR_CTL_ADDR             (0xFFC00008)  /* “VR_CTL Register” on page 6-23 */
#define PLL_STAT_ADDR           (0xFFC0000C)  /* “PLL_STAT Register” on page 6-22 */
#define PLL_LOCKCNT_ADDR        (0xFFC00010)  /* “PLL_LOCKCNT Register” on page 6-22 */

typedef struct _bf592_vr_ctl_t {
  u16   polarity      :     1;
  u16   extclk_oe     :     1;
  u16   extclk_sel    :     1;
  u16   hibernateb    :     1;
  u16   wake_en3      :     1;
  u16   wake_en2      :     1;
  u16   wake_en1      :     1;
  u16   wake_en0      :     1;
  u16                 :     8;
} bf592_vr_ctl_t;


typedef struct _bf592_power_t {
  u8          start[ PLL_CTL_ADDR - BLACKFIN_MMR_BASE ];
  u16         pll_ctl;
  u8          pad00[2];
  u16         pll_div;
  u8          pad01[2];
  vr_ctl_t    vr_ctl;
  u8          pad02[2];
  u16         pll_stat;
  u8          pad03[2];
  u16         pll_lockcnt;
} bf592_power_t;
// 
// PPI Registers
// 
#define PPI_CONTROL_ADDR        (0xFFC01000)  /* “PPI Control Register (PPI_CONTROL)” on page 15-26 */
#define PPI_STATUS_ADDR         (0xFFC01004)  /* “PPI Status Register (PPI_STATUS)” on page 15-30 */
#define PPI_COUNT_ADDR          (0xFFC01008)  /* “PPI Transfer Count Register (PPI_COUNT)” on page 15-34 */
#define PPI_DELAY_ADDR          (0xFFC0100C)  /* “PPI Delay Count Register (PPI_DELAY)” on page 15-33 */
#define PPI_FRAME_ADDR          (0xFFC01010)  /* “PPI Lines Per Frame Register (PPI_FRAME)” on page 15-34 */

typedef struct _bf592_ppi_t {
  u8          start[ PPI_CONTROL_ADDR - BLACKFIN_MMR_BASE ];
  u16         ppi_control;        // 0xFFC01000
  u8          pad00[2];
  u16         ppi_status;         // 0xFFC01004
  u8          pad01[2];
  u16         ppi_count;          // 0xFFC01008
  u8          pad02[2];
  u16         ppi_delay;          // 0xFFC0100C
  u8          pad03[2];
  u16         ppi_frame;          // 0xFFC01010
} bf592_ppi_t;

// 
// SPI Controller Registers
// 
#define SPI0_CTL_ADDR           (0xFFC00500)  /* “SPI Control (SPI_CTL) Register” on page 13-37 */
#define SPI0_FLG_ADDR           (0xFFC00504)  /* “SPI Flag (SPI_FLG) Register” on page 13-39 */
#define SPI0_STAT_ADDR          (0xFFC00508)  /* “SPI Status (SPI_STAT) Register” on page 13-41  */
#define SPI0_TDBR_ADDR          (0xFFC0050C)  /* “SPI Transmit Data Buffer (SPI_TDBR) Register” on page 13-44 */
#define SPI0_RDBR_ADDR          (0xFFC00510)  /* “SPI Receive Data Buffer (SPI_RDBR) Register” on page 13-45 */
#define SPI0_BAUD_ADDR          (0xFFC00514)  /* “SPI Baud Rate (SPI_BAUD) Register” on page 13-36 */
#define SPI0_SHADOW_ADDR        (0xFFC00518)  /* “SPI RDBR Shadow (SPI_SHADOW) Register” on page 13-45 */
#define SPI1_CTL_ADDR           (0xFFC01300)  /* “SPI Control (SPI_CTL) Register” on page 13-37 */
#define SPI1_FLG_ADDR           (0xFFC01304)  /* “SPI Flag (SPI_FLG) Register” on page 13-39 */
#define SPI1_STAT_ADDR          (0xFFC01308)  /* “SPI Status (SPI_STAT) Register” on page 13-41 */
#define SPI1_TDBR_ADDR          (0xFFC0130C)  /* “SPI Transmit Data Buffer (SPI_TDBR) Register” on page 13-44 */
#define SPI1_RDBR_ADDR          (0xFFC01310)  /* “SPI Receive Data Buffer (SPI_RDBR) Register” on page 13-45 */
#define SPI1_BAUD_ADDR          (0xFFC01314)  /* “SPI Baud Rate (SPI_BAUD) Register” on page 13-36 */
#define SPI1_SHADOW_ADDR        (0xFFC01318)  /* “SPI RDBR Shadow (SPI_SHADOW) Register” on page 13-45 */

typedef struct _bf592_spi_t {
  u8          start[ PPI_CONTROL_ADDR - BLACKFIN_MMR_BASE ];
  u16         spi0_ctl;           // 0xFFC00500
  u8          pad01[2];
  u16         spi0_flg;           // 0xFFC00504
  u8          pad02[2];
  u16         spi0_stat;          // 0xFFC00508
  u8          pad03[2];
  u16         spi0_tdbr;          // 0xFFC0050C
  u8          pad04[2];
  u16         spi0_rdbr;          // 0xFFC00510
  u8          pad05[2];
  u16         spi0_baud;          // 0xFFC00514
  u8          pad06[2];
  u16         spi0_shadow;        // 0xFFC00518
  u8          pad07[2];
  u16         spi1_ctl;           // 0xFFC01300
  u8          pad08[2];
  u16         spi1_flg;           // 0xFFC01304
  u8          pad09[2];
  u16         spi1_stat;          // 0xFFC01308
  u8          pad10[2];
  u16         spi1_tdbr;          // 0xFFC0130C
  u8          pad11[2];
  u16         spi1_rdbr;          // 0xFFC01310
  u8          pad12[2];
  u16         spi1_baud;          // 0xFFC01314
  u8          pad13[2];
  u16         spi1_shadow;        // 0xFFC01318
} bf592_spi_t;

// 
// SPORT Controller Registers
// 
#define SPORT0_TCR1_ADDR          (0xFFC00800)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT0_TCR2_ADDR          (0xFFC00804)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT0_TCLKDIV_ADDR       (0xFFC00808)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT0_TFSDIV_ADDR        (0xFFC0080C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT0_TX_ADDR            (0xFFC00810)  /* “SPORT Transmit Data (SPORT_TX) Register” on page 14-59 */
#define SPORT0_RX_ADDR            (0xFFC00818)  /* “SPORT Receive Data (SPORT_RX) Register” on page 14-61 */
#define SPORT0_RCR1_ADDR          (0xFFC00820)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT0_RCR2_ADDR          (0xFFC00824)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT0_RCLKDIV_ADDR       (0xFFC00828)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT0_RFSDIV_ADDR        (0xFFC0082C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT0_STAT_ADDR          (0xFFC00830)  /* “SPORT Status (SPORT_STAT) Register” on page 14-64 */
#define SPORT0_CHNL_ADDR          (0xFFC00834)  /* “SPORT Current Channel (SPORT_CHNL) Register” on page 14-69 */
#define SPORT0_MCMC1_ADDR         (0xFFC00838)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT0_MCMC2_ADDR         (0xFFC0083C)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT0_MTCS0_ADDR         (0xFFC00840)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS1_ADDR         (0xFFC00844)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS2_ADDR         (0xFFC00848)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MTCS3_ADDR         (0xFFC0084C)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT0_MRCS0_ADDR         (0xFFC00850)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS1_ADDR         (0xFFC00854)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS2_ADDR         (0xFFC00858)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT0_MRCS3_ADDR         (0xFFC0085C)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_TCR1_ADDR          (0xFFC00900)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT1_TCR2_ADDR          (0xFFC00904)  /* “SPORT Transmit Configuration (SPORT_TCR1 and SPORT_TCR2) Registers” on page 14-49 */
#define SPORT1_TCLKDIV_ADDR       (0xFFC00908)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT1_TFSDIV_ADDR        (0xFFC0090C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT1_TX_ADDR            (0xFFC00910)  /* “SPORT Transmit Data (SPORT_TX) Register” on page 14-59 */
#define SPORT1_RX_ADDR            (0xFFC00918)  /* “SPORT Receive Data (SPORT_RX) Register” on page 14-61 */
#define SPORT1_RCR1_ADDR          (0xFFC00920)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT1_RCR2_ADDR          (0xFFC00924)  /* “SPORT Receive Configuration (SPORT_RCR1 and SPORT_RCR2) Registers” on page 14-55 */
#define SPORT1_RCLKDIV_ADDR       (0xFFC00928)  /* “SPORT Transmit and Receive Serial Clock Divider (SPORT_TCLKDIV and SPORT_RCLKDIV) Registers” on page 14-66 */
#define SPORT1_RFSDIV_ADDR        (0xFFC0092C)  /* “SPORT Transmit and Receive Frame Sync Divider (SPORT_TFSDIV and SPORT_RFSDIV) Registers” on page 14-67 */
#define SPORT1_STAT_ADDR          (0xFFC00930)  /* “SPORT Status (SPORT_STAT) Register” on page 14-64 */
#define SPORT1_CHNL_ADDR          (0xFFC00934)  /* “SPORT Current Channel (SPORT_CHNL) Register” on page 14-69 */
#define SPORT1_MCMC1_ADDR         (0xFFC00938)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT1_MCMC2_ADDR         (0xFFC0093C)  /* “SPORT Multichannel Configuration (SPORT_MCMC1 and SPORT_MCMC2) Registers” on page 14-68 */
#define SPORT1_MTCS0_ADDR         (0xFFC00940)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS1_ADDR         (0xFFC00944)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS2_ADDR         (0xFFC00948)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MTCS3_ADDR         (0xFFC0094C)  /* “SPORT Multichannel Transmit Selection (SPORT_MTCSn) Registers” on page 14-71 */
#define SPORT1_MRCS0_ADDR         (0xFFC00950)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS1_ADDR         (0xFFC00954)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS2_ADDR         (0xFFC00958)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT1_MRCS3_ADDR         (0xFFC0095C)  /* “SPORT Multichannel Receive Selection (SPORT_MRCSn) Registers” on page 14-69 */
#define SPORT_CLKGATE_ADDR        (0xFFC0120C)  /* “SPORT Clock Gating Register” on page 14-81 */

typedef struct _bf592_sport01_t {
  u16         sport0_tcr1;                  // 0xFFC00800      0xFFC00900 
  u8          pad00[ 0x804 - 0x800 - 2];
  u16         sport0_tcr2;                  // 0xFFC00804      0xFFC00904
  u8          pad01[ 0x808 - 0x804 - 2];
  u16         sport0_tclkdiv;               // 0xFFC00808      0xFFC00908
  u8          pad02[ 0x80c - 0x808 - 2];
  u16         sport0_tfsdiv;                // 0xFFC0080C      0xFFC0090C
  u8          pad03[ 0x810 - 0x80c - 2];
  u32         sport0_tx;                    // 0xFFC00810      0xFFC00910
  u8          pad04[ 0x818 - 0x810 - 4];
  u32         sport0_rx;                    // 0xFFC00818      0xFFC00918
  u8          pad05[ 0x820 - 0x818 - 4];
  u16         sport0_rcr1;                  // 0xFFC00820      0xFFC00920
  u8          pad06[ 0x824 - 0x820 - 2];
  u16         sport0_rcr2;                  // 0xFFC00824      0xFFC00924
  u8          pad07[ 0x828 - 0x824 - 2];
  u16         sport0_rclkdiv;               // 0xFFC00828      0xFFC00928
  u8          pad08[ 0x82c - 0x828 - 2];
  u16         sport0_rfsdiv;                // 0xFFC0082C      0xFFC0092C
  u8          pad09[ 0x830 - 0x82c - 2];
  u16         sport0_stat;                  // 0xFFC00830      0xFFC00930
  u8          pad10[ 0x834 - 0x830 - 2];
  u16         sport0_chnl;                  // 0xFFC00834      0xFFC00934
  u8          pad11[ 0x838 - 0x834 - 2];
  u16         sport0_mcmc1;                 // 0xFFC00838      0xFFC00938
  u8          pad12[ 0x83c - 0x828 - 2];
  u16         sport0_mcmc2;                 // 0xFFC0083C      0xFFC0093C
  u8          pad13[ 0x840 - 0x83c - 2];
  u32         sport0_mtcs0;                 // 0xFFC00840      0xFFC00940
  u8          pad14[ 0x844 - 0x840 - 4];
  u32         sport0_mtcs1;                 // 0xFFC00844      0xFFC00944
  u8          pad15[ 0x848 - 0x844 - 4];
  u32         sport0_mtcs2;                 // 0xFFC00848      0xFFC00948
  u8          pad16[ 0x84c - 0x848 - 4];
  u32         sport0_mtcs3;                 // 0xFFC0084C      0xFFC0094C
  u8          pad17[ 0x850 - 0x84c - 4];
  u32         sport0_mrcs0;                 // 0xFFC00850      0xFFC00950
  u8          pad18[ 0x854 - 0x850 - 4];
  u32         sport0_mrcs1;                 // 0xFFC00854      0xFFC00954
  u8          pad19[ 0x858 - 0x854 - 4];
  u32         sport0_mrcs2;                 // 0xFFC00858      0xFFC00958
  u8          pad20[ 0x85c - 0x858 - 4];
  u32         sport0_mrcs3;                 // 0xFFC0085C      0xFFC0095C
  u8          pad21[ 0x900 - 0x85c - 4];

} bf592_sport01_t;

typedef struct _bf592_sport01_t {
  u8          start [ SPORT0_TCR1 - BLACKFIN_MMR_BASE ];
  bf592_sport01_t sport[2];                 // FFC00800 FFC00900
  u8          pad00[ 0x120c - 0xa00];
  u16         sport_clkgate;                // 0xFFC0120C

} bf592_sport01_t;
// 
// UART Controller Registers
// 
#define UART_THR_ADDR            (0xFFC00400)  /* “UART Transmit Holding (UART_THR) Register” on page 11-26 */
#define UART_RBR_ADDR            (0xFFC00400)  /* “UART Receive Buffer (UART_RBR) Register” on page 11-27 */
#define UART_DLL_ADDR            (0xFFC00400)  /* “UART Divisor Latch (UART_DLL and UART_DLH) Registers” on page 11-31 */
#define UART_DLH_ADDR            (0xFFC00404)  /* “UART Divisor Latch (UART_DLL and UART_DLH) Registers” on page 11-31 */
#define UART_IER_ADDR            (0xFFC00404)  /* “UART Interrupt Enable (UART_IER) Register” on page 11-27 */
#define UART_IIR_ADDR            (0xFFC00408)  /* “UART Interrupt Identification (UART_IIR) Register” on page 11-29 */
#define UART_LCR_ADDR            (0xFFC0040C)  /* “UART Line Control (UART_LCR) Register” on page 11-22 */
#define UART_MCR_ADDR            (0xFFC00410)  /* “UART Modem Control (UART_MCR) Register” on page 11-24 */
#define UART_LSR_ADDR            (0xFFC00414)  /* “UART Line Status (UART_LSR) Register” on page 11-25 */
#define UART_SCR_ADDR            (0xFFC0041C)  /* “UART Scratch (UART_SCR) Register” on page 11-32 */
#define UART_GCTL_ADDR           (0xFFC00424)  /* “UART Global Control (UART_GCTL) Register” on page 11-32 */

typedef struct _bf592_uart_t {
  u8          start [ UART_THR_ADDR - BLACKFIN_MMR_BASE ];
  u16         uart_thr_rbr_dll;    // 0xFFC00400
  u8          pad00[ 0x004 - 0x00 + 2 ];
  u16         uart_dlh_ier;        // 0xFFC00404
  u8          pad01[ 0x008 - 0x04 + 2 ];
  u16         uart_iir;            // 0xFFC00408
  u8          pad02[ 0x00c - 0x08 + 2 ];
  u16         uart_lcr;            // 0xFFC0040C
  u8          pad03[ 0x010 - 0x0c + 2 ];
  u16         uart_mcr;            // 0xFFC00410
  u8          pad04[ 0x014 - 0x10 + 2 ];
  u16         uart_lsr;            // 0xFFC00414
  u8          pad05[ 0x01c - 0x14 + 2 ];
  u16         uart_scr;            // 0xFFC0041C
  u8          pad06[ 0x024 - 0x1c + 2 ];
  u16         uart_gctl;           // 0xFFC00424
} bf592_uart_t;

// 
// TWI Registers
// 
#define TWI_CLKDIV_ADDR             (0xFFC01400)  /* “SCL Clock Divider Register (TWI_CLKDIV)” on page 12-26 */
#define TWI_CONTROL_ADDR            (0xFFC01404)  /* “TWI CONTROL Register (TWI_CONTROL)” on page 12-25 */
#define TWI_SLAVE_CTL_ADDR          (0xFFC01408)  /* “TWI Slave Mode Control Register (TWI_SLAVE_CTL)” on page 12-27 */
#define TWI_SLAVE_STAT_ADDR         (0xFFC0140C)  /* “TWI Slave Mode Status Register (TWI_SLAVE_STAT)” on page 12-29 */
#define TWI_SLAVE_ADDR_ADDR         (0xFFC01410)  /* “TWI Slave Mode Address Register (TWI_SLAVE_ADDR)” on page 12-29 */
#define TWI_MASTER_CTL_ADDR         (0xFFC01414)  /* “TWI Master Mode Control Register (TWI_MASTER_CTL)” on page 12-31 */
#define TWI_MASTER_STAT_ADDR        (0xFFC01418)  /* “TWI Master Mode Status Register (TWI_MASTER_STAT)” on page 12-35 */
#define TWI_MASTER_ADDR_ADDR        (0xFFC0141C)  /* “TWI Master Mode Address Register (TWI_MASTER_ADDR)” on page 12-34 */
#define TWI_INT_STAT_ADDR           (0xFFC01420)  /* “TWI Interrupt Status Register (TWI_INT_STAT)” on page 12-43 */
#define TWI_INT_MASK_ADDR           (0xFFC01424)  /* “TWI Interrupt Mask Register (TWI_INT_MASK)” on page 12-42 */
#define TWI_FIFO_CTL_ADDR           (0xFFC01428)  /* “TWI FIFO Control Register (TWI_FIFO_CTL)” on page 12-38 */
#define TWI_FIFO_STAT_ADDR          (0xFFC0142C)  /* “TWI FIFO Status Register (TWI_FIFO_STAT)” on page 12-40 */
#define TWI_XMT_DATA8_ADDR          (0xFFC01480)  /* “TWI FIFO Transmit Data Single Byte Register (TWI_XMT_DATA8)” on page 12-46 */
#define TWI_XMT_DATA16_ADDR         (0xFFC01484)  /* “TWI FIFO Transmit Data Double Byte Register (TWI_XMT_DATA16)” on page 12-47 */
#define TWI_RCV_DATA8_ADDR          (0xFFC01488)  /* “TWI FIFO Receive Data Single Byte Register (TWI_RCV_DATA8)” on page 12-48 */
#define TWI_RCV_DATA16_ADDR         (0xFFC0148C)  /* “TWI FIFO Receive Data Double Byte Register (TWI_RCV_DATA16)” on page 12-49 */

typedef _bf592_twi_t {
  u8          start [ UART_THR_ADDR - BLACKFIN_MMR_BASE ];
  u16         twi_clkdiv;             // 0xFFC01400
  u8          pad00[ 0x004 - 0x00 + 2 ];
  u16         twi_control;            // 0xFFC01404
  u8          pad01[ 0x008 - 0x04 + 2 ];
  u16         twi_slave_ctl;          // 0xFFC01408
  u8          pad02[ 0x00c - 0x08 + 2 ];
  u16         twi_slave_stat;         // 0xFFC0140C
  u8          pad03[ 0x010 - 0x0c + 2 ];
  u16         twi_slave_addr;         // 0xFFC01410
  u8          pad04[ 0x014 - 0x10 + 2 ];
  u16         twi_master_ctl;         // 0xFFC01414
  u8          pad05[ 0x018 - 0x14 + 2 ];
  u16         twi_master_stat;        // 0xFFC01418
  u8          pad06[ 0x01c - 0x18 + 2 ];
  u16         twi_master_addr;        // 0xFFC0141C
  u8          pad07[ 0x020 - 0x1c + 2 ];
  u16         twi_int_stat;           // 0xFFC01420
  u8          pad08[ 0x024 - 0x20 + 2 ];
  u16         twi_int_mask;           // 0xFFC01424
  u8          pad09[ 0x028 - 0x24 + 2 ];
  u16         twi_fifo_ctl;           // 0xFFC01428
  u8          pad10[ 0x02c - 0x28 + 2 ];
  u16         twi_fifo_stat;          // 0xFFC0142C
  u8          pad11[ 0x080 - 0x2c + 2 ];
  u16         twi_xmt_data8;          // 0xFFC01480
  u8          pad12[ 0x084 - 0x80 + 2 ];
  u16         twi_xmt_data16;         // 0xFFC01484
  u8          pad13[ 0x088 - 0x84 + 2 ];
  u16         twi_rcv_data8;          // 0xFFC01488
  u8          pad14[ 0x08c - 0x88 + 2 ];
  u16         twi_rcv_data16;         // 0xFFC0148C
} bf592_twi_t;



//
// master MMR structure
//
typedef union _bf592_t {
  blackfin_core_t   core;
  bf592_coretimer_t coretimer;
  bf592_sic_t       sic;
  bf592_dma_t       dma;
  bf592_port_t      port;
  bf592_power_t     power;
  bf592_ppi_t       ppi;
  bf592_spi_t       spi;
  bf592_sport_t     sport;
  bf592_uart_t      uart;
  bf592_twi_t       twi;
} bf592_t;


#endif /* _BF592_H_ */

