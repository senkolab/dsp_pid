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

//
// L1 Data Memory Controller Registers
//
#define DMEM_CONTROL    (0xFFE00004)  /* “DMEM_CONTROL Register” on page 6-28 */
#define DCPLB_STATUS    (0xFFE00008)  /* “DCPLB_STATUS and ICPLB_STATUS Registers” on page 6-67 */
#define DCPLB_FAULT_ADDR    (0xFFE0000C)  /* “DCPLB_FAULT_ADDR and ICPLB_FAULT_ADDR Registers” on page 6-69 */
#define DCPLB_ADDR0    (0xFFE00100)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR1    (0xFFE00104)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR2    (0xFFE00108)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR3    (0xFFE0010C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR4    (0xFFE00110)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR5    (0xFFE00114)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR6    (0xFFE00118)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR7    (0xFFE0011C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR8    (0xFFE00120)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR9    (0xFFE00124)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR10    (0xFFE00128)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR11    (0xFFE0012C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR12    (0xFFE00130)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR13    (0xFFE00134)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR14    (0xFFE00138)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_ADDR15    (0xFFE0013C)  /* “DCPLB_ADDRx Registers” on page 6-65 */
#define DCPLB_DATA0    (0xFFE00200)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA1    (0xFFE00204)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA2    (0xFFE00208)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA3    (0xFFE0020C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA4    (0xFFE00210)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA5    (0xFFE00214)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA6    (0xFFE00218)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA7    (0xFFE0021C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA8    (0xFFE00220)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA9    (0xFFE00224)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA10    (0xFFE00228)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA11    (0xFFE0022C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA12    (0xFFE00230)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA13    (0xFFE00234)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA14    (0xFFE00238)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DCPLB_DATA15    (0xFFE0023C)  /* “DCPLB_DATAx Registers” on page 6-62 */
#define DTEST_COMMAND    (0xFFE00300)  /* “DTEST_COMMAND Register” on page 6-45 */
#define DTEST_DATA0    (0xFFE00400)  /* “DTEST_DATA0 Register” on page 6-48 */
#define DTEST_DATA1    (0xFFE00404)  /* “DTEST_DATA1 Register” on page 6-47 */



// 
// L1 Instruction Memory Controller Registers
//
#define IMEM_CONTROL    (0xFFE01004)  /* “IMEM_CONTROL Register” on page 6-6 */
#define ICPLB_STATUS    (0xFFE01008)  /* “DCPLB_STATUS and ICPLB_STATUS Registers” on page 6-67 */
#define ICPLB_FAULT_ADDR    (0xFFE0100C)  /* “DCPLB_FAULT_ADDR and ICPLB_FAULT_ADDR Registers” on page 6-69 */
#define ICPLB_ADDR0    (0xFFE01100)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR1    (0xFFE01104)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR2    (0xFFE01108)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR3    (0xFFE0110C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR4    (0xFFE01110)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR5    (0xFFE01114)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR6    (0xFFE01118)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR7    (0xFFE0111C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR8    (0xFFE01120)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR9    (0xFFE01124)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR10    (0xFFE01128)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR11    (0xFFE0112C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR12    (0xFFE01130)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR13    (0xFFE01134)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR14    (0xFFE01138)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_ADDR15    (0xFFE0113C)  /* “ICPLB_ADDRx Registers” on page 6-66 */
#define ICPLB_DATA0    (0xFFE01200)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA1    (0xFFE01204)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA2    (0xFFE01208)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA3    (0xFFE0120C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA4    (0xFFE01210)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA5    (0xFFE01214)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA6    (0xFFE01218)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA7    (0xFFE0121C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA8    (0xFFE01220)  /* “ICPLB_DATAx Registers” on page 6-61  */
#define ICPLB_DATA9    (0xFFE01224)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA10    (0xFFE01228)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA11    (0xFFE0122C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA12    (0xFFE01230)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA13    (0xFFE01234)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA14    (0xFFE01238)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ICPLB_DATA15    (0xFFE0123C)  /* “ICPLB_DATAx Registers” on page 6-61 */
#define ITEST_COMMAND    (0xFFE01300)  /* “ITEST_COMMAND Register” on page 6-24 */
#define ITEST_DATA0    (0xFFE01400)  /* “ITEST_DATA0 Register” on page 6-27 */
#define ITEST_DATA1    (0xFFE01404)  /* “ITEST_DATA1 Register” on page 6-26 */


// 
// Interrupt Controller Registers
//
#define EVT0    (0xFFE02000)  /* (EMU) “Core Event Vector Table” on page 4-45 */
#define EVT1    (0xFFE02004)  /* (RST) “Core Event Vector Table” on page 4-45 */
#define EVT2    (0xFFE02008)  /* (NMI) “Core Event Vector Table” on page 4-45 */
#define EVT3    (0xFFE0200C)  /* (EVX) “Core Event Vector Table” on page 4-45 */
#define EVT4    (0xFFE02010)  /* “Core Event Vector Table” on page 4-45 */
#define EVT5    (0xFFE02014)  /* (IVHW) “Core Event Vector Table” on page 4-45 */
#define EVT6    (0xFFE02018)  /* (TMR) “Core Event Vector Table” on page 4-45 */
#define EVT7    (0xFFE0201C)  /* (IVG7) “Core Event Vector Table” on page 4-45 */
#define EVT8    (0xFFE02020)  /* (IVG8) “Core Event Vector Table” on page 4-45 */
#define EVT9    (0xFFE02024)  /* (IVG9) “Core Event Vector Table” on page 4-45 */
#define EVT10    (0xFFE02028)  /* (IVG10) “Core Event Vector Table” on page 4-45 */
#define EVT11    (0xFFE0202C)  /* (IVG11) “Core Event Vector Table” on page 4-45 */
#define EVT12    (0xFFE02030)  /* (IVG12) “Core Event Vector Table” on page 4-45 */
#define EVT13    (0xFFE02034)  /* (IVG13) “Core Event Vector Table” on page 4-45 */
#define EVT14    (0xFFE02038)  /* (IVG14) “Core Event Vector Table” on page 4-45 */
#define EVT15    (0xFFE0203C)  /* (IVG15) “Core Event Vector Table” on page 4-45 */
#define IMASK    (0xFFE02104)  /* “IMASK Register” on page 4-40 */
#define IPEND    (0xFFE02108)  /* “IPEND Register” on page 4-42 */
#define ILAT    (0xFFE0210C)  /* “ILAT Register” on page 4-40 */
#define IPRIO    (0xFFE02110)  /* “IPRIO Register and Write Buffer Depth” on page 6-40 */


// 
// Debug, MP, and Emulation Unit Registers
//
#define DSPID    (0xFFE05000)  /* “DSPID Register” on page 21-32 */

// 
// Trace Unit Registers
// 
#define TBUFCTL    (0xFFE06000)  /* “TBUFCTL Register” on page 21-16 */
#define TBUFSTAT    (0xFFE06004)  /* “TBUFSTAT Register” on page 21-17 */
#define TBUF    (0xFFE06100)  /* “TBUF Register” on page 21-18 */


// 
// Watchpoint and Patch Registers
// 
#define WPIACTL    (0xFFE07000)  /* “WPIACTL Register” on page 21-8 */
#define WPIA0    (0xFFE07040)  /* “WPIAx Registers” on page 21-5 */
#define WPIA1    (0xFFE07044)  /* “WPIAx Registers” on page 21-5 */
#define WPIA2    (0xFFE07048)  /* “WPIAx Registers” on page 21-5 */
#define WPIA3    (0xFFE0704C)  /* “WPIAx Registers” on page 21-5 */
#define WPIA4    (0xFFE07050)  /* “WPIAx Registers” on page 21-5 */
#define WPIA5    (0xFFE07054)  /* “WPIAx Registers” on page 21-5 */
#define WPIACNT0    (0xFFE07080)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT1    (0xFFE07084)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT2    (0xFFE07088)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT3    (0xFFE0708C)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT4    (0xFFE07090)  /* “WPIACNTx Registers” on page 21-7 */
#define WPIACNT5    (0xFFE07094)  /* “WPIACNTx Registers” on page 21-7 */
#define WPDACTL    (0xFFE07100)  /* “WPDACTL Register” on page 21-12 */
#define WPDA0    (0xFFE07140)  /* “WPDAx Registers” on page 21-11 */
#define WPDA1    (0xFFE07144)  /* “WPDAx Registers” on page 21-11 */
#define WPDACNT0    (0xFFE07180)  /* “WPDACNTx Registers” on page 21-12 */
#define WPDACNT1    (0xFFE07184)  /* “WPDACNTx Registers” on page 21-12 */
#define WPSTAT    (0xFFE07200)  /* “WPSTAT Register” on page 21-14 */

// 
// Performance Monitor Registers
// 
#define PFCTL    (0xFFE08000)  /* “PFCTL Register” on page 21-22 */
#define PFCNTR0    (0xFFE08100)  /* “PFCNTRx Registers” on page 21-21 */
#define PFCNTR1    (0xFFE08104)  /* “PFCNTRx Registers” on page 21-21 */

#endif /* _BLACKFIN_CORE_H_ */
