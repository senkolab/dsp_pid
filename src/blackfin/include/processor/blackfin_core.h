/*
 * blackfin_core.h - Core register definitions for Analog Devices Blackfin processors
 *
 * Ref: Blackfin Processor Programming Reference
 *
 * Written by Rich Rademacher / IQC / University of Waterloo
 * March 2018
 */

#ifndef _BLACKFIN_CORE_H_
#define _BLACKFIN_CORE_H_

#include <types.h>

//
// this sets up the base pointer
//
#define BLACKFIN_MMR_BASE         (0xFFE00000)


//
// L1 Data Memory Controller Registers
//
#define DMEM_CONTROL_ADDR            (0xFFE00004)  /* “DMEM_CONTROL Register” on page 6-28 */
#define DCPLB_STATUS_ADDR            (0xFFE00008)  /* “DCPLB_STATUS and ICPLB_STATUS Registers” on page 6-67 */
#define DCPLB_FAULT_ADDR_ADDR        (0xFFE0000C)  /* “DCPLB_FAULT_ADDR and ICPLB_FAULT_ADDR Registers” on page 6-69 */
#define DCPLB_ADDR0_ADDR             (0xFFE00100)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR1_ADDR             (0xFFE00104)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR2_ADDR             (0xFFE00108)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR3_ADDR             (0xFFE0010C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR4_ADDR             (0xFFE00110)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR5_ADDR             (0xFFE00114)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR6_ADDR             (0xFFE00118)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR7_ADDR             (0xFFE0011C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR8_ADDR             (0xFFE00120)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR9_ADDR             (0xFFE00124)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR10_ADDR            (0xFFE00128)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR11_ADDR            (0xFFE0012C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR12_ADDR            (0xFFE00130)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR13_ADDR            (0xFFE00134)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR14_ADDR            (0xFFE00138)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR15_ADDR            (0xFFE0013C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_DATA0_ADDR             (0xFFE00200)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA1_ADDR             (0xFFE00204)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA2_ADDR             (0xFFE00208)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA3_ADDR             (0xFFE0020C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA4_ADDR             (0xFFE00210)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA5_ADDR             (0xFFE00214)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA6_ADDR             (0xFFE00218)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA7_ADDR             (0xFFE0021C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA8_ADDR             (0xFFE00220)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA9_ADDR             (0xFFE00224)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA10_ADDR            (0xFFE00228)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA11_ADDR            (0xFFE0022C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA12_ADDR            (0xFFE00230)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA13_ADDR            (0xFFE00234)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA14_ADDR            (0xFFE00238)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA15_ADDR            (0xFFE0023C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DTEST_COMMAND_ADDR           (0xFFE00300)  /* “DTEST_COMMAND Register” on page 6-45 */
#define DTEST_DATA0_ADDR             (0xFFE00400)  /* “DTEST_DATA0 Register” on page 6-48 */
#define DTEST_DATA1_ADDR             (0xFFE00404)  /* “DTEST_DATA1 Register” on page 6-47 */

typedef struct _bf_L1_dmem_ctrl_t { {
  u8  start[ DMEM_CONTROL_ADDR - BLACKFIN_MMR_BASE ];
  u32 dmem_control;            // 0xFFE00004
  u32 dcplb_status;            // 0xFFE00008
  u32 dcplb_fault_addr;        // 0xFFE0000C
  u8  pad00[0x100-0x0C + 4];
  u32 dcplb_addr0;             // 0xFFE00100
  u32 dcplb_addr1;             // 0xFFE00104
  u32 dcplb_addr2;             // 0xFFE00108
  u32 dcplb_addr3;             // 0xFFE0010C
  u32 dcplb_addr4;             // 0xFFE00110
  u32 dcplb_addr5;             // 0xFFE00114
  u32 dcplb_addr6;             // 0xFFE00118
  u32 dcplb_addr7;             // 0xFFE0011C
  u32 dcplb_addr8;             // 0xFFE00120
  u32 dcplb_addr9;             // 0xFFE00124
  u32 dcplb_addr10;            // 0xFFE00128
  u32 dcplb_addr11;            // 0xFFE0012C
  u32 dcplb_addr12;            // 0xFFE00130
  u32 dcplb_addr13;            // 0xFFE00134
  u32 dcplb_addr14;            // 0xFFE00138
  u32 dcplb_addr15;            // 0xFFE0013C
  u8  pad01[0x200-0x140 + 4];
  u32 dcplb_data0;             // 0xFFE00200
  u32 dcplb_data1;             // 0xFFE00204
  u32 dcplb_data2;             // 0xFFE00208
  u32 dcplb_data3;             // 0xFFE0020C
  u32 dcplb_data4;             // 0xFFE00210
  u32 dcplb_data5;             // 0xFFE00214
  u32 dcplb_data6;             // 0xFFE00218
  u32 dcplb_data7;             // 0xFFE0021C
  u32 dcplb_data8;             // 0xFFE00220
  u32 dcplb_data9;             // 0xFFE00224
  u32 dcplb_data10;            // 0xFFE00228
  u32 dcplb_data11;            // 0xFFE0022C
  u32 dcplb_data12;            // 0xFFE00230
  u32 dcplb_data13;            // 0xFFE00234
  u32 dcplb_data14;            // 0xFFE00238
  u32 dcplb_data15;            // 0xFFE0023C
  u8  pad02[0x300-0x240 + 4];
  u32 dtest_command;           // 0xFFE00300
  u8  pad03[0x400-0x300 + 4];
  u32 dtest_data0;             // 0xFFE00400
  u32 dtest_data1;             // 0xFFE00404
} bf_L1_dmem_ctrl_t;


// 
// L1 Instruction Memory Controller Registers
//
#define IMEM_CONTROL_ADDR       (0xFFE01004)  /* “IMEM_CONTROL Register” on page 6-6 */
#define ICPLB_STATUS_ADDR       (0xFFE01008)  /* “DCPLB_STATUS and ICPLB_STATUS Registers” on page 6-67 */
#define ICPLB_FAULT_ADDR_ADDR   (0xFFE0100C)  /* “DCPLB_FAULT_ADDR and ICPLB_FAULT_ADDR Registers” on page 6-69 */
#define ICPLB_ADDR0_ADDR        (0xFFE01100)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR1_ADDR        (0xFFE01104)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR2_ADDR        (0xFFE01108)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR3_ADDR        (0xFFE0110C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR4_ADDR        (0xFFE01110)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR5_ADDR        (0xFFE01114)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR6_ADDR        (0xFFE01118)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR7_ADDR        (0xFFE0111C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR8_ADDR        (0xFFE01120)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR9_ADDR        (0xFFE01124)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR10_ADDR       (0xFFE01128)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR11_ADDR       (0xFFE0112C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR12_ADDR       (0xFFE01130)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR13_ADDR       (0xFFE01134)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR14_ADDR       (0xFFE01138)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR15_ADDR       (0xFFE0113C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_DATA0_ADDR        (0xFFE01200)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA1_ADDR        (0xFFE01204)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA2_ADDR        (0xFFE01208)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA3_ADDR        (0xFFE0120C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA4_ADDR        (0xFFE01210)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA5_ADDR        (0xFFE01214)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA6_ADDR        (0xFFE01218)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA7_ADDR        (0xFFE0121C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA8_ADDR        (0xFFE01220)  /* “ICPLB_DATAx Registers” on page 6-61  */
#define ICPLB_DATA9_ADDR        (0xFFE01224)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA10_ADDR       (0xFFE01228)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA11_ADDR       (0xFFE0122C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA12_ADDR       (0xFFE01230)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA13_ADDR       (0xFFE01234)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA14_ADDR       (0xFFE01238)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA15_ADDR       (0xFFE0123C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ITEST_COMMAND_ADDR      (0xFFE01300)  /* “ITEST_COMMAND Register” on page 6-24 */
#define ITEST_DATA0_ADDR        (0xFFE01400)  /* “ITEST_DATA0 Register” on page 6-27 */
#define ITEST_DATA1_ADDR        (0xFFE01404)  /* “ITEST_DATA1 Register” on page 6-26 */

typedef struct _bf_L1_imem_ctrl_t { {
  u8  start[ IMEM_CONTROL_ADDR - BLACKFIN_MMR_BASE ];
  u32 imem_control;       // 0xFFE01004
  u32 icplb_status;       // 0xFFE01008
  u32 icplb_fault_addr;   // 0xFFE0100C
  u8  pad00[0x100-0x0C + 4];
  u32 icplb_addr0;        // 0xFFE01100
  u32 icplb_addr1;        // 0xFFE01104
  u32 icplb_addr2;        // 0xFFE01108
  u32 icplb_addr3;        // 0xFFE0110C
  u32 icplb_addr4;        // 0xFFE01110
  u32 icplb_addr5;        // 0xFFE01114
  u32 icplb_addr6;        // 0xFFE01118
  u32 icplb_addr7;        // 0xFFE0111C
  u32 icplb_addr8;        // 0xFFE01120
  u32 icplb_addr9;        // 0xFFE01124
  u32 icplb_addr10;       // 0xFFE01128
  u32 icplb_addr11;       // 0xFFE0112C
  u32 icplb_addr12;       // 0xFFE01130
  u32 icplb_addr13;       // 0xFFE01134
  u32 icplb_addr14;       // 0xFFE01138
  u32 icplb_addr15;       // 0xFFE0113C
  u8  pad01[0x200-0x140 + 4];
  u32 icplb_data0;        // 0xFFE01200
  u32 icplb_data1;        // 0xFFE01204
  u32 icplb_data2;        // 0xFFE01208
  u32 icplb_data3;        // 0xFFE0120C
  u32 icplb_data4;        // 0xFFE01210
  u32 icplb_data5;        // 0xFFE01214
  u32 icplb_data6;        // 0xFFE01218
  u32 icplb_data7;        // 0xFFE0121C
  u32 icplb_data8;        // 0xFFE01220
  u32 icplb_data9;        // 0xFFE01224
  u32 icplb_data10;       // 0xFFE01228
  u32 icplb_data11;       // 0xFFE0122C
  u32 icplb_data12;       // 0xFFE01230
  u32 icplb_data13;       // 0xFFE01234
  u32 icplb_data14;       // 0xFFE01238
  u32 icplb_data15;       // 0xFFE0123C
  u8  pad02[0x300-0x240 + 4];
  u32 itest_command;      // 0xFFE01300
  u8  pad03[0x400-0x300 + 4];
  u32 itest_data0;        // 0xFFE01400
  u32 itest_data1;        // 0xFFE01404
} bf_L1_imem_ctrl_t;


// 
// Interrupt Controller Registers
//
#define EVT0_ADDR                (0xFFE02000)  /* (EMU) “Core Event Vector Table” on page 4-45 */
#define EVT1_ADDR                (0xFFE02004)  /* (RST) “Core Event Vector Table” on page 4-45 */
#define EVT2_ADDR                (0xFFE02008)  /* (NMI) “Core Event Vector Table” on page 4-45 */
#define EVT3_ADDR                (0xFFE0200C)  /* (EVX) “Core Event Vector Table” on page 4-45 */
#define EVT4_ADDR                (0xFFE02010)  /* “Core Event Vector Table” on page 4-45 */
#define EVT5_ADDR                (0xFFE02014)  /* (IVHW) “Core Event Vector Table” on page 4-45 */
#define EVT6_ADDR                (0xFFE02018)  /* (TMR) “Core Event Vector Table” on page 4-45 */
#define EVT7_ADDR                (0xFFE0201C)  /* (IVG7) “Core Event Vector Table” on page 4-45 */
#define EVT8_ADDR                (0xFFE02020)  /* (IVG8) “Core Event Vector Table” on page 4-45 */
#define EVT9_ADDR                (0xFFE02024)  /* (IVG9) “Core Event Vector Table” on page 4-45 */
#define EVT10_ADDR               (0xFFE02028)  /* (IVG10) “Core Event Vector Table” on page 4-45 */
#define EVT11_ADDR               (0xFFE0202C)  /* (IVG11) “Core Event Vector Table” on page 4-45 */
#define EVT12_ADDR               (0xFFE02030)  /* (IVG12) “Core Event Vector Table” on page 4-45 */
#define EVT13_ADDR               (0xFFE02034)  /* (IVG13) “Core Event Vector Table” on page 4-45 */
#define EVT14_ADDR               (0xFFE02038)  /* (IVG14) “Core Event Vector Table” on page 4-45 */
#define EVT15_ADDR               (0xFFE0203C)  /* (IVG15) “Core Event Vector Table” on page 4-45 */
#define IMASK_ADDR               (0xFFE02104)  /* “IMASK Register” on page 4-40 */
#define IPEND_ADDR               (0xFFE02108)  /* “IPEND Register” on page 4-42 */
#define ILAT_ADDR                (0xFFE0210C)  /* “ILAT Register” on page 4-40 */
#define IPRIO_ADDR               (0xFFE02110)  /* “IPRIO Register and Write Buffer Depth” on page 6-40 */

typedef struct _bf_evt_t { {
  u8      start[ EVT0_ADDR - BLACKFIN_MMR_BASE ];
  void*   evt0;                // 0xFFE02000
  void*   evt1;                // 0xFFE02004
  void*   evt2;                // 0xFFE02008
  void*   evt3;                // 0xFFE0200C
  void*   evt4;                // 0xFFE02010
  void*   evt5;                // 0xFFE02014
  void*   evt6;                // 0xFFE02018
  void*   evt7;                // 0xFFE0201C
  void*   evt8;                // 0xFFE02020
  void*   evt9;                // 0xFFE02024
  void*   evt10;               // 0xFFE02028
  void*   evt11;               // 0xFFE0202C
  void*   evt12;               // 0xFFE02030
  void*   evt13;               // 0xFFE02034
  void*   evt14;               // 0xFFE02038
  void*   evt15;               // 0xFFE0203C
  u8      pad00[ 0x104 - 0x3c + 4 ];
  void*   imask;               // 0xFFE02104
  void*   ipend;               // 0xFFE02108
  void*   ilat;                // 0xFFE0210C
  void*   iprio;               // 0xFFE02110
} bf_evt_t;

// 
// Debug, MP, and Emulation Unit Registers
//
#define DSPID_ADDR              (0xFFE05000)  /* “DSPID Register” on page 21-32 */
typedef struct _bf_dsp_id_t { {
  u8  start[ DSPID_ADDR - BLACKFIN_MMR_BASE ];
  u32 dspid;              // 0xFFE05000
} bf_dsp_id_t;

// 
// Trace Unit Registers
// 
#define TBUFCTL_ADDR            (0xFFE06000)  /* “TBUFCTL Register” on page 21-16 */
#define TBUFSTAT_ADDR           (0xFFE06004)  /* “TBUFSTAT Register” on page 21-17 */
#define TBUF_ADDR               (0xFFE06100)  /* “TBUF Register” on page 21-18 */

typedef struct _bf_trace_t { {
  u8      start[ TBUFCTL_ADDR - BLACKFIN_MMR_BASE ];
  u32     tbufctl;            // 0xFFE06000
  u32     tbufstat;           // 0xFFE06004
  u8      pad00[0x100 - 0x004 + 4];
  u32     tbuf;               // 0xFFE06100
} bf_trace_t;

// 
// Watchpoint and Patch Registers
// 
#define WPIACTL_ADDR          (0xFFE07000)  /* “WPIACTL Register” on page 21-8 */
#define WPIA0_ADDR            (0xFFE07040)  /* “WPIAx Registers” on page 21-5 */
#define WPIA1_ADDR            (0xFFE07044)  /* “WPIAx Registers” on page 21-5 */
#define WPIA2_ADDR            (0xFFE07048)  /* “WPIAx Registers” on page 21-5 */
#define WPIA3_ADDR            (0xFFE0704C)  /* “WPIAx Registers” on page 21-5 */
#define WPIA4_ADDR            (0xFFE07050)  /* “WPIAx Registers” on page 21-5 */
#define WPIA5_ADDR            (0xFFE07054)  /* “WPIAx Registers” on page 21-5 */
#define WPIACNT0_ADDR         (0xFFE07080)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT1_ADDR         (0xFFE07084)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT2_ADDR         (0xFFE07088)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT3_ADDR         (0xFFE0708C)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT4_ADDR         (0xFFE07090)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT5_ADDR         (0xFFE07094)  /* “WPIACNTx Registers” on page 21-7 */
#define WPDACTL_ADDR          (0xFFE07100)  /* “WPDACTL Register” on page 21-12 */
#define WPDA0_ADDR            (0xFFE07140)  /* “WPDAx Registers” on page 21-11 */
#define WPDA1_ADDR            (0xFFE07144)  /* “WPDAx Registers” on page 21-11 */
#define WPDACNT0_ADDR         (0xFFE07180)  /* “WPDACNTx Registers” on page 21-12 */
#define WPDACNT1_ADDR         (0xFFE07184)  /* “WPDACNTx Registers” on page 21-12 */
#define WPSTAT_ADDR           (0xFFE07200)  /* “WPSTAT Register” on page 21-14 */

typedef struct _bf_watchpoint_t { {
  u8      start[ TBUFCTL_ADDR - BLACKFIN_MMR_BASE ];
  u32     wpiactl;          // 0xFFE07000
  u8      pad00[ 0x040 - 0x000 + 4 ];
  u32     wpia0;            // 0xFFE07040
  u32     wpia1;            // 0xFFE07044
  u32     wpia2;            // 0xFFE07048
  u32     wpia3;            // 0xFFE0704C
  u32     wpia4;            // 0xFFE07050
  u32     wpia5;            // 0xFFE07054
  u8      pad01[ 0x080 - 0x054 + 4 ];
  u32     wpiacnt0;         // 0xFFE07080
  u32     wpiacnt1;         // 0xFFE07084
  u32     wpiacnt2;         // 0xFFE07088
  u32     wpiacnt3;         // 0xFFE0708C
  u32     wpiacnt4;         // 0xFFE07090
  u32     wpiacnt5;         // 0xFFE07094
  u8      pad02[ 0x100 - 0x094 + 4 ];
  u32     wpdactl;          // 0xFFE07100
  u8      pad03[ 0x140 - 0x100 + 4 ];
  u32     wpda0;            // 0xFFE07140
  u32     wpda1;            // 0xFFE07144
  u8      pad04[ 0x180 - 0x144 + 4 ];
  u32     wpdacnt0;         // 0xFFE07180
  u32     wpdacnt1;         // 0xFFE07184
  u8      pad05[ 0x200 - 0x184 + 4 ];
  u32     wpstat;           // 0xFFE07200
} bf_watchpoint_t;



// 
// Performance Monitor Registers
// 
#define PFCTL_ADDR            (0xFFE08000)  /* “PFCTL Register” on page 21-22 */
#define PFCNTR0_ADDR          (0xFFE08100)  /* “PFCNTRx Registers” on page 21-21 */
#define PFCNTR1_ADDR          (0xFFE08104)  /* “PFCNTRx Registers” on page 21-21 */

typedef struct _bf_perfmon_t { {
  u8      start[ PFCTL_ADDR - BLACKFIN_MMR_BASE ];
  u32     pfctl;            // 0xffe08000
  u32     pfcntr0;          // 0xffe08100
  u32     pfcntr1;          // 0xffe08104
} bf_perfmon_t;


//
// master core mmr
//
typedef union _blackfin_core_t {
  bf_L1_dmem_ctrl_t     L1_dmem_ctrl;
  bf_L1_imem_ctrl_t     L1_imem_ctrl;
  bf_evt_t              evt;
  bf_dsp_id_t           dsp_id;
  bf_trace_t            trace;
  bf_watchpoint_t       watchpoint;
  bf_perfmon_t          perfmon;
} blackfin_core_t;

#endif /* _BLACKFIN_CORE_H_ */
