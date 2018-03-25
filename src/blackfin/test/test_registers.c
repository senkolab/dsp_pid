////////////////////////////////////////////////////////////////////////////////
// test_registers.c - test to ensure blackfin_core.h and bf592.h files are correct
//
// Written by Rich Rademacher, UWaterloo/IQC
// March 2018
////////////////////////////////////////////////////////////////////////////////

#include <processor/blackfin_core.h>
#include <processor/bf592.h>

void test_core(void);
void test_sys(void);

// force emulator stop
#define assert(x)   if( !(x) ) asm("emuexcpt;");

// create the base register
const bf592_t* blackfin = (bf592_t*) BLACKFIN_MMR_BASE;

int main(int argc, const char** argv)
{

  test_core();  
  test_sys();

  asm("emuexcpt;");
}

void test_core()
{


  //
  // L1 Data Memory Controller Registers
  //
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dmem_control) == DMEM_CONTROL_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_status) == DCPLB_STATUS_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_fault_addr) == DCPLB_FAULT_ADDR_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr0) == DCPLB_ADDR0_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr1) == DCPLB_ADDR1_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr2) == DCPLB_ADDR2_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr3) == DCPLB_ADDR3_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr4) == DCPLB_ADDR4_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr5) == DCPLB_ADDR5_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr6) == DCPLB_ADDR6_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr7) == DCPLB_ADDR7_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr8) == DCPLB_ADDR8_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr9) == DCPLB_ADDR9_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr10) == DCPLB_ADDR10_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr11) == DCPLB_ADDR11_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr12) == DCPLB_ADDR12_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr13) == DCPLB_ADDR13_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr14) == DCPLB_ADDR14_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_addr15) == DCPLB_ADDR15_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data0) == DCPLB_DATA0_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data1) == DCPLB_DATA1_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data2) == DCPLB_DATA2_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data3) == DCPLB_DATA3_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data4) == DCPLB_DATA4_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data5) == DCPLB_DATA5_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data6) == DCPLB_DATA6_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data7) == DCPLB_DATA7_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data8) == DCPLB_DATA8_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data9) == DCPLB_DATA9_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data10) == DCPLB_DATA10_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data11) == DCPLB_DATA11_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data12) == DCPLB_DATA12_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data13) == DCPLB_DATA13_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data14) == DCPLB_DATA14_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dcplb_data15) == DCPLB_DATA15_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dtest_command) == DTEST_COMMAND_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dtest_data0) == DTEST_DATA0_ADDR );
  assert( (int) &(blackfin->core.L1_dmem_ctrl.dtest_data1) == DTEST_DATA1_ADDR );


  // 
  // L1 Instruction Memory Controller Registers
  //
  assert( (int) &(blackfin->core.L1_imem_ctrl.imem_control) == IMEM_CONTROL_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_status) == ICPLB_STATUS_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_fault_addr) == ICPLB_FAULT_ADDR_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr0) == ICPLB_ADDR0_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr1) == ICPLB_ADDR1_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr2) == ICPLB_ADDR2_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr3) == ICPLB_ADDR3_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr4) == ICPLB_ADDR4_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr5) == ICPLB_ADDR5_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr6) == ICPLB_ADDR6_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr7) == ICPLB_ADDR7_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr8) == ICPLB_ADDR8_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr9) == ICPLB_ADDR9_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr10) == ICPLB_ADDR10_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr11) == ICPLB_ADDR11_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr12) == ICPLB_ADDR12_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr13) == ICPLB_ADDR13_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr14) == ICPLB_ADDR14_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_addr15) == ICPLB_ADDR15_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data0) == ICPLB_DATA0_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data1) == ICPLB_DATA1_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data2) == ICPLB_DATA2_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data3) == ICPLB_DATA3_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data4) == ICPLB_DATA4_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data5) == ICPLB_DATA5_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data6) == ICPLB_DATA6_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data7) == ICPLB_DATA7_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data8) == ICPLB_DATA8_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data9) == ICPLB_DATA9_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data10) == ICPLB_DATA10_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data11) == ICPLB_DATA11_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data12) == ICPLB_DATA12_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data13) == ICPLB_DATA13_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data14) == ICPLB_DATA14_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.icplb_data15) == ICPLB_DATA15_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.itest_command) == ITEST_COMMAND_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.itest_data0) == ITEST_DATA0_ADDR );
  assert( (int) &(blackfin->core.L1_imem_ctrl.itest_data1) == ITEST_DATA1_ADDR );


  // 
  // Interrupt Controller Registers
  //
  assert( (int) &(blackfin->core.evt.evt0) ==  EVT0_ADDR );
  assert( (int) &(blackfin->core.evt.evt1) ==  EVT1_ADDR );
  assert( (int) &(blackfin->core.evt.evt2) ==  EVT2_ADDR );
  assert( (int) &(blackfin->core.evt.evt3) ==  EVT3_ADDR );
  assert( (int) &(blackfin->core.evt.evt4) ==  EVT4_ADDR );
  assert( (int) &(blackfin->core.evt.evt5) ==  EVT5_ADDR );
  assert( (int) &(blackfin->core.evt.evt6) ==  EVT6_ADDR );
  assert( (int) &(blackfin->core.evt.evt7) ==  EVT7_ADDR );
  assert( (int) &(blackfin->core.evt.evt8) ==  EVT8_ADDR );
  assert( (int) &(blackfin->core.evt.evt9) ==  EVT9_ADDR );
  assert( (int) &(blackfin->core.evt.evt10) ==  EVT10_ADDR );
  assert( (int) &(blackfin->core.evt.evt11) ==  EVT11_ADDR );
  assert( (int) &(blackfin->core.evt.evt12) ==  EVT12_ADDR );
  assert( (int) &(blackfin->core.evt.evt13) ==  EVT13_ADDR );
  assert( (int) &(blackfin->core.evt.evt14) ==  EVT14_ADDR );
  assert( (int) &(blackfin->core.evt.evt15) ==  EVT15_ADDR );
  assert( (int) &(blackfin->core.evt.imask) ==  IMASK_ADDR );
  assert( (int) &(blackfin->core.evt.ipend) ==  IPEND_ADDR );
  assert( (int) &(blackfin->core.evt.ilat) ==  ILAT_ADDR );
  assert( (int) &(blackfin->core.evt.iprio) ==  IPRIO_ADDR );

  // 
  // Debug, MP, and Emulation Unit Registers
  //
  assert( (int) &(blackfin->core.dsp_id.dspid) == DSPID_ADDR );

  // 
  // Trace Unit Registers
  // 
  assert( (int) &(blackfin->core.trace.tbufctl) == TBUFCTL_ADDR );
  assert( (int) &(blackfin->core.trace.tbufstat) == TBUFSTAT_ADDR );
  assert( (int) &(blackfin->core.trace.tbuf) == TBUF_ADDR );

  // 
  // Watchpoint and Patch Registers
  // 
  assert( (int) &(blackfin->core.watchpoint.wpiactl) == WPIACTL_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia0) == WPIA0_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia1) == WPIA1_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia2) == WPIA2_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia3) == WPIA3_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia4) == WPIA4_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpia5) == WPIA5_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt0) == WPIACNT0_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt1) == WPIACNT1_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt2) == WPIACNT2_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt3) == WPIACNT3_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt4) == WPIACNT4_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpiacnt5) == WPIACNT5_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpdactl) == WPDACTL_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpda0) == WPDA0_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpda1) == WPDA1_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpdacnt0) == WPDACNT0_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpdacnt1) == WPDACNT1_ADDR );
  assert( (int) &(blackfin->core.watchpoint.wpstat) == WPSTAT_ADDR );



  // 
  // Performance Monitor Registers
  // 
  assert( (int) &(blackfin->core.perfmon.pfctl) == PFCTL_ADDR );
  assert( (int) &(blackfin->core.perfmon.pfcntr0) == PFCNTR0_ADDR );
  assert( (int) &(blackfin->core.perfmon.pfcntr1) == PFCNTR1_ADDR );

}

void test_sys() {

  // 
  // Processor-Specific Memory Registers
  // 
#define DTEST_COMMAND_ADDR    (0xFFE00300)  /* “Data Test Command Register” on page 2-5 */

  // 
  // Core Timer Registers
  // 
  assert( (int) &(blackfin->coretimer.tcntl) == TCNTL_ADDR );
  assert( (int) &(blackfin->coretimer.tperiod) == TPERIOD_ADDR );
  assert( (int) &(blackfin->coretimer.tscale) == TSCALE_ADDR );
  assert( (int) &(blackfin->coretimer.tcount) == TCOUNT_ADDR );

  // 
  // System Reset and Interrupt Control Registers
  // 
  assert( (int) &(blackfin->sic.syscr) == SYSCR_ADDR );
  assert( (int) &(blackfin->sic.sic_imask0) == SIC_IMASK0_ADDR );
  assert( (int) &(blackfin->sic.sic_iar0) == SIC_IAR0_ADDR );
  assert( (int) &(blackfin->sic.sic_iar1) == SIC_IAR1_ADDR );
  assert( (int) &(blackfin->sic.sic_iar2) == SIC_IAR2_ADDR );
  assert( (int) &(blackfin->sic.sic_iar3) == SIC_IAR3_ADDR );
  assert( (int) &(blackfin->sic.sic_isr0) == SIC_ISR0_ADDR );
  assert( (int) &(blackfin->sic.sic_iwr0) == SIC_IWR0_ADDR );




  // 
  // DMA/Memory DMA Control Registers
  // 
  assert( (int) &(blackfin->dma.dma_tc_per) == DMA_TC_PER_ADDR );
  assert( (int) &(blackfin->dma.dma_tc_cnt) == DMA_TC_CNT_ADDR );


  assert( (int) &(blackfin->dma.dma[0].next_desc_ptr) ==  DMA0_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[0].start_addr) ==  DMA0_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[0].config) == DMA0_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[0].x_count) == DMA0_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[0].x_modify) == DMA0_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[0].y_count) == DMA0_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[0].y_modify) == DMA0_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[0].curr_desc_ptr) ==  DMA0_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[0].curr_addr) ==  DMA0_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[0].irq_status) == DMA0_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[0].peripheral_map) == DMA0_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[0].curr_x_count) == DMA0_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[0].curr_y_count) == DMA0_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[1].next_desc_ptr) ==  DMA1_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[1].start_addr) ==  DMA1_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[1].config) == DMA1_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[1].x_count) == DMA1_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[1].x_modify) == DMA1_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[1].y_count) == DMA1_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[1].y_modify) == DMA1_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[1].curr_desc_ptr) ==  DMA1_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[1].curr_addr) ==  DMA1_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[1].irq_status) == DMA1_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[1].peripheral_map) == DMA1_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[1].curr_x_count) == DMA1_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[1].curr_y_count) == DMA1_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[2].next_desc_ptr) ==  DMA2_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[2].start_addr) ==  DMA2_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[2].config) == DMA2_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[2].x_count) == DMA2_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[2].x_modify) == DMA2_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[2].y_count) == DMA2_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[2].y_modify) == DMA2_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[2].curr_desc_ptr) ==  DMA2_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[2].curr_addr) ==  DMA2_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[2].irq_status) == DMA2_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[2].peripheral_map) == DMA2_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[2].curr_x_count) == DMA2_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[2].curr_y_count) == DMA2_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[3].next_desc_ptr) ==  DMA3_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[3].start_addr) ==  DMA3_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[3].config) == DMA3_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[3].x_count) == DMA3_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[3].x_modify) == DMA3_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[3].y_count) == DMA3_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[3].y_modify) == DMA3_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[3].curr_desc_ptr) ==  DMA3_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[3].curr_addr) ==  DMA3_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[3].irq_status) == DMA3_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[3].peripheral_map) == DMA3_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[3].curr_x_count) == DMA3_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[3].curr_y_count) == DMA3_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[4].next_desc_ptr) ==  DMA4_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[4].start_addr) ==  DMA4_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[4].config) == DMA4_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[4].x_count) == DMA4_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[4].x_modify) == DMA4_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[4].y_count) == DMA4_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[4].y_modify) == DMA4_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[4].curr_desc_ptr) ==  DMA4_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[4].curr_addr) ==  DMA4_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[4].irq_status) == DMA4_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[4].peripheral_map) == DMA4_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[4].curr_x_count) == DMA4_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[4].curr_y_count) == DMA4_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[5].next_desc_ptr) ==  DMA5_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[5].start_addr) ==  DMA5_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[5].config) == DMA5_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[5].x_count) == DMA5_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[5].x_modify) == DMA5_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[5].y_count) == DMA5_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[5].y_modify) == DMA5_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[5].curr_desc_ptr) ==  DMA5_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[5].curr_addr) ==  DMA5_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[5].irq_status) == DMA5_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[5].peripheral_map) == DMA5_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[5].curr_x_count) == DMA5_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[5].curr_y_count) == DMA5_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[6].next_desc_ptr) ==  DMA6_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[6].start_addr) ==  DMA6_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[6].config) == DMA6_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[6].x_count) == DMA6_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[6].x_modify) == DMA6_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[6].y_count) == DMA6_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[6].y_modify) == DMA6_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[6].curr_desc_ptr) ==  DMA6_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[6].curr_addr) ==  DMA6_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[6].irq_status) == DMA6_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[6].peripheral_map) == DMA6_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[6].curr_x_count) == DMA6_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[6].curr_y_count) == DMA6_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[7].next_desc_ptr) ==  DMA7_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[7].start_addr) ==  DMA7_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[7].config) == DMA7_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[7].x_count) == DMA7_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[7].x_modify) == DMA7_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[7].y_count) == DMA7_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[7].y_modify) == DMA7_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[7].curr_desc_ptr) ==  DMA7_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[7].curr_addr) ==  DMA7_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[7].irq_status) == DMA7_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[7].peripheral_map) == DMA7_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[7].curr_x_count) == DMA7_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[7].curr_y_count) == DMA7_CURR_Y_COUNT_ADDR );



  assert( (int) &(blackfin->dma.dma[8].next_desc_ptr) ==  DMA8_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[8].start_addr) ==  DMA8_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[8].config) == DMA8_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.dma[8].x_count) == DMA8_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[8].x_modify) == DMA8_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[8].y_count) == DMA8_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[8].y_modify) == DMA8_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.dma[8].curr_desc_ptr) ==  DMA8_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.dma[8].curr_addr) ==  DMA8_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.dma[8].irq_status) == DMA8_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.dma[8].peripheral_map) == DMA8_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.dma[8].curr_x_count) == DMA8_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.dma[8].curr_y_count) == DMA8_CURR_Y_COUNT_ADDR );


  assert( (int) &(blackfin->dma.mdma_d0.next_desc_ptr) ==  MDMA_D0_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.start_addr) ==  MDMA_D0_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.config) == MDMA_D0_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.x_count) == MDMA_D0_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.x_modify) == MDMA_D0_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.y_count) == MDMA_D0_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.y_modify) == MDMA_D0_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.curr_desc_ptr) ==  MDMA_D0_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.curr_addr) ==  MDMA_D0_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.irq_status) == MDMA_D0_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.peripheral_map) == MDMA_D0_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.curr_x_count) == MDMA_D0_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d0.curr_y_count) == MDMA_D0_CURR_Y_COUNT_ADDR );

  assert( (int) &(blackfin->dma.mdma_d1.next_desc_ptr) ==  MDMA_D1_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.start_addr) ==  MDMA_D1_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.config) == MDMA_D1_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.x_count) == MDMA_D1_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.x_modify) == MDMA_D1_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.y_count) == MDMA_D1_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.y_modify) == MDMA_D1_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.curr_desc_ptr) ==  MDMA_D1_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.curr_addr) ==  MDMA_D1_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.irq_status) == MDMA_D1_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.peripheral_map) == MDMA_D1_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.curr_x_count) == MDMA_D1_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_d1.curr_y_count) == MDMA_D1_CURR_Y_COUNT_ADDR );

  assert( (int) &(blackfin->dma.mdma_s0.next_desc_ptr) ==  MDMA_S0_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.start_addr) ==  MDMA_S0_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.config) == MDMA_S0_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.x_count) == MDMA_S0_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.x_modify) == MDMA_S0_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.y_count) == MDMA_S0_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.y_modify) == MDMA_S0_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.curr_desc_ptr) ==  MDMA_S0_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.curr_addr) ==  MDMA_S0_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.irq_status) == MDMA_S0_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.peripheral_map) == MDMA_S0_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.curr_x_count) == MDMA_S0_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s0.curr_y_count) == MDMA_S0_CURR_Y_COUNT_ADDR );

  assert( (int) &(blackfin->dma.mdma_s1.next_desc_ptr) ==  MDMA_S1_NEXT_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.start_addr) ==  MDMA_S1_START_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.config) == MDMA_S1_CONFIG_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.x_count) == MDMA_S1_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.x_modify) == MDMA_S1_X_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.y_count) == MDMA_S1_Y_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.y_modify) == MDMA_S1_Y_MODIFY_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.curr_desc_ptr) ==  MDMA_S1_CURR_DESC_PTR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.curr_addr) ==  MDMA_S1_CURR_ADDR_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.irq_status) == MDMA_S1_IRQ_STATUS_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.peripheral_map) == MDMA_S1_PERIPHERAL_MAP_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.curr_x_count) == MDMA_S1_CURR_X_COUNT_ADDR );
  assert( (int) &(blackfin->dma.mdma_s1.curr_y_count) == MDMA_S1_CURR_Y_COUNT_ADDR );



  // 
  // Ports Registers
  // 
  assert( (int) &(blackfin->port.portfio) == PORTFIO_ADDR );
  assert( (int) &(blackfin->port.portfio_clear) == PORTFIO_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portfio_set) == PORTFIO_SET_ADDR );
  assert( (int) &(blackfin->port.portfio_toggle) == PORTFIO_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portfio_maska) == PORTFIO_MASKA_ADDR );
  assert( (int) &(blackfin->port.portfio_maska_clear) == PORTFIO_MASKA_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portfio_maska_set) == PORTFIO_MASKA_SET_ADDR );
  assert( (int) &(blackfin->port.portfio_maska_toggle) == PORTFIO_MASKA_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portfio_maskb) == PORTFIO_MASKB_ADDR );
  assert( (int) &(blackfin->port.portfio_maskb_clear) == PORTFIO_MASKB_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portfio_maskb_set) == PORTFIO_MASKB_SET_ADDR );
  assert( (int) &(blackfin->port.portfio_maskb_toggle) == PORTFIO_MASKB_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portfio_dir) == PORTFIO_DIR_ADDR );
  assert( (int) &(blackfin->port.portfio_polar) == PORTFIO_POLAR_ADDR );
  assert( (int) &(blackfin->port.portfio_edge) == PORTFIO_EDGE_ADDR );
  assert( (int) &(blackfin->port.portfio_both) == PORTFIO_BOTH_ADDR );
  assert( (int) &(blackfin->port.portfio_inen) == PORTFIO_INEN_ADDR );

  assert( (int) &(blackfin->port.portf_fer) == PORTF_FER_ADDR );
  assert( (int) &(blackfin->port.portf_mux) == PORTF_MUX_ADDR );
  assert( (int) &(blackfin->port.portg_fer) == PORTG_FER_ADDR );
  assert( (int) &(blackfin->port.portg_mux) == PORTG_MUX_ADDR );

  assert( (int) &(blackfin->port.portgio) == PORTGIO_ADDR );
  assert( (int) &(blackfin->port.portgio_clear) == PORTGIO_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portgio_set) == PORTGIO_SET_ADDR );
  assert( (int) &(blackfin->port.portgio_toggle) == PORTGIO_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portgio_maska) == PORTGIO_MASKA_ADDR );
  assert( (int) &(blackfin->port.portgio_maska_clear) == PORTGIO_MASKA_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portgio_maska_set) == PORTGIO_MASKA_SET_ADDR );
  assert( (int) &(blackfin->port.portgio_maska_toggle) == PORTGIO_MASKA_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portgio_maskb) == PORTGIO_MASKB_ADDR );
  assert( (int) &(blackfin->port.portgio_maskb_clear) == PORTGIO_MASKB_CLEAR_ADDR );
  assert( (int) &(blackfin->port.portgio_maskb_set) == PORTGIO_MASKB_SET_ADDR );
  assert( (int) &(blackfin->port.portgio_maskb_toggle) == PORTGIO_MASKB_TOGGLE_ADDR );
  assert( (int) &(blackfin->port.portgio_dir) == PORTGIO_DIR_ADDR );
  assert( (int) &(blackfin->port.portgio_polar) == PORTGIO_POLAR_ADDR );
  assert( (int) &(blackfin->port.portgio_edge) == PORTGIO_EDGE_ADDR );
  assert( (int) &(blackfin->port.portgio_both) == PORTGIO_BOTH_ADDR );
  assert( (int) &(blackfin->port.portgio_inen) == PORTGIO_INEN_ADDR );

  // 
  // Timer Registers
  // 
  assert( (int) &(blackfin->timer.timer0_config) == TIMER0_CONFIG_ADDR );
  assert( (int) &(blackfin->timer.timer0_counter) == TIMER0_COUNTER_ADDR );
  assert( (int) &(blackfin->timer.timer0_period) == TIMER0_PERIOD_ADDR );
  assert( (int) &(blackfin->timer.timer0_width) == TIMER0_WIDTH_ADDR );
  assert( (int) &(blackfin->timer.timer1_config) == TIMER1_CONFIG_ADDR );
  assert( (int) &(blackfin->timer.timer1_counter) == TIMER1_COUNTER_ADDR );
  assert( (int) &(blackfin->timer.timer1_period) == TIMER1_PERIOD_ADDR );
  assert( (int) &(blackfin->timer.timer1_width) == TIMER1_WIDTH_ADDR );
  assert( (int) &(blackfin->timer.timer2_config) == TIMER2_CONFIG_ADDR );
  assert( (int) &(blackfin->timer.timer2_counter) == TIMER2_COUNTER_ADDR );
  assert( (int) &(blackfin->timer.timer2_period) == TIMER2_PERIOD_ADDR );
  assert( (int) &(blackfin->timer.timer2_width) == TIMER2_WIDTH_ADDR );
  assert( (int) &(blackfin->timer.timer_enable) == TIMER_ENABLE_ADDR );
  assert( (int) &(blackfin->timer.timer_disable) == TIMER_DISABLE_ADDR );
  assert( (int) &(blackfin->timer.timer_status) == TIMER_STATUS_ADDR );

  // 
  // Watchdog Timer Registers
  // 
  assert( (int) &(blackfin->watchdog.wdog_ctl) == WDOG_CTL_ADDR );
  assert( (int) &(blackfin->watchdog.wdog_cnt) == WDOG_CNT_ADDR );
  assert( (int) &(blackfin->watchdog.wdog_stat) == WDOG_STAT_ADDR );

  // 
  // Dynamic Power Management Registers
  // 

  assert( (int) &(blackfin->power.pll_ctl) == PLL_CTL_ADDR );
  assert( (int) &(blackfin->power.pll_div) == PLL_DIV_ADDR );
  assert( (int) &(blackfin->power.vr_ctl) == VR_CTL_ADDR );
  assert( (int) &(blackfin->power.pll_stat) == PLL_STAT_ADDR );
  assert( (int) &(blackfin->power.pll_lockcnt) == PLL_LOCKCNT_ADDR );
  // 
  // PPI Registers
  // 
  assert( (int) &(blackfin->ppi.ppi_control) == PPI_CONTROL_ADDR );
  assert( (int) &(blackfin->ppi.ppi_status) == PPI_STATUS_ADDR );
  assert( (int) &(blackfin->ppi.ppi_count) == PPI_COUNT_ADDR );
  assert( (int) &(blackfin->ppi.ppi_delay) == PPI_DELAY_ADDR );
  assert( (int) &(blackfin->ppi.ppi_frame) == PPI_FRAME_ADDR );

  // 
  // SPI Controller Registers
  // 
  assert( (int) &(blackfin->spi.spi0_ctl) == SPI0_CTL_ADDR );
  assert( (int) &(blackfin->spi.spi0_flg) == SPI0_FLG_ADDR );
  assert( (int) &(blackfin->spi.spi0_stat) == SPI0_STAT_ADDR );
  assert( (int) &(blackfin->spi.spi0_tdbr) == SPI0_TDBR_ADDR );
  assert( (int) &(blackfin->spi.spi0_rdbr) == SPI0_RDBR_ADDR );
  assert( (int) &(blackfin->spi.spi0_baud) == SPI0_BAUD_ADDR );
  assert( (int) &(blackfin->spi.spi0_shadow) == SPI0_SHADOW_ADDR );
  assert( (int) &(blackfin->spi.spi1_ctl) == SPI1_CTL_ADDR );
  assert( (int) &(blackfin->spi.spi1_flg) == SPI1_FLG_ADDR );
  assert( (int) &(blackfin->spi.spi1_stat) == SPI1_STAT_ADDR );
  assert( (int) &(blackfin->spi.spi1_tdbr) == SPI1_TDBR_ADDR );
  assert( (int) &(blackfin->spi.spi1_rdbr) == SPI1_RDBR_ADDR );
  assert( (int) &(blackfin->spi.spi1_baud) == SPI1_BAUD_ADDR );
  assert( (int) &(blackfin->spi.spi1_shadow) == SPI1_SHADOW_ADDR );

  // 
  // SPORT Controller Registers
  // 
  assert( (int) &(blackfin->sport.sport[0].tcr1) == SPORT0_TCR1_ADDR );
  assert( (int) &(blackfin->sport.sport[0].tcr2) == SPORT0_TCR2_ADDR );
  assert( (int) &(blackfin->sport.sport[0].tclkdiv) == SPORT0_TCLKDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[0].tfsdiv) == SPORT0_TFSDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[0].tx) == SPORT0_TX_ADDR );
  assert( (int) &(blackfin->sport.sport[0].rx) == SPORT0_RX_ADDR );
  assert( (int) &(blackfin->sport.sport[0].rcr1) == SPORT0_RCR1_ADDR );
  assert( (int) &(blackfin->sport.sport[0].rcr2) == SPORT0_RCR2_ADDR );
  assert( (int) &(blackfin->sport.sport[0].rclkdiv) == SPORT0_RCLKDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[0].rfsdiv) == SPORT0_RFSDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[0].stat) == SPORT0_STAT_ADDR );
  assert( (int) &(blackfin->sport.sport[0].chnl) == SPORT0_CHNL_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mcmc1) == SPORT0_MCMC1_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mcmc2) == SPORT0_MCMC2_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mtcs0) == SPORT0_MTCS0_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mtcs1) == SPORT0_MTCS1_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mtcs2) == SPORT0_MTCS2_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mtcs3) == SPORT0_MTCS3_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mrcs0) == SPORT0_MRCS0_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mrcs1) == SPORT0_MRCS1_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mrcs2) == SPORT0_MRCS2_ADDR );
  assert( (int) &(blackfin->sport.sport[0].mrcs3) == SPORT0_MRCS3_ADDR );

  assert( (int) &(blackfin->sport.sport[1].tcr1) == SPORT1_TCR1_ADDR );
  assert( (int) &(blackfin->sport.sport[1].tcr2) == SPORT1_TCR2_ADDR );
  assert( (int) &(blackfin->sport.sport[1].tclkdiv) == SPORT1_TCLKDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[1].tfsdiv) == SPORT1_TFSDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[1].tx) == SPORT1_TX_ADDR );
  assert( (int) &(blackfin->sport.sport[1].rx) == SPORT1_RX_ADDR );
  assert( (int) &(blackfin->sport.sport[1].rcr1) == SPORT1_RCR1_ADDR );
  assert( (int) &(blackfin->sport.sport[1].rcr2) == SPORT1_RCR2_ADDR );
  assert( (int) &(blackfin->sport.sport[1].rclkdiv) == SPORT1_RCLKDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[1].rfsdiv) == SPORT1_RFSDIV_ADDR );
  assert( (int) &(blackfin->sport.sport[1].stat) == SPORT1_STAT_ADDR );
  assert( (int) &(blackfin->sport.sport[1].chnl) == SPORT1_CHNL_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mcmc1) == SPORT1_MCMC1_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mcmc2) == SPORT1_MCMC2_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mtcs0) == SPORT1_MTCS0_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mtcs1) == SPORT1_MTCS1_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mtcs2) == SPORT1_MTCS2_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mtcs3) == SPORT1_MTCS3_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mrcs0) == SPORT1_MRCS0_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mrcs1) == SPORT1_MRCS1_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mrcs2) == SPORT1_MRCS2_ADDR );
  assert( (int) &(blackfin->sport.sport[1].mrcs3) == SPORT1_MRCS3_ADDR );

  assert( (int) &(blackfin->sport.sport_clkgate) == SPORT_CLKGATE_ADDR );


  // 
  // UART Controller Registers
  // 
  assert( (int) &(blackfin->uart.uart_thr_rbr_dll) == UART_DLL_ADDR );
  assert( (int) &(blackfin->uart.uart_thr_rbr_dll) == UART_THR_ADDR );
  assert( (int) &(blackfin->uart.uart_thr_rbr_dll) == UART_RBR_ADDR );
  assert( (int) &(blackfin->uart.uart_dlh_ier) == UART_IER_ADDR );
  assert( (int) &(blackfin->uart.uart_dlh_ier) == UART_DLH_ADDR );
  assert( (int) &(blackfin->uart.uart_iir) == UART_IIR_ADDR );
  assert( (int) &(blackfin->uart.uart_lcr) == UART_LCR_ADDR );
  assert( (int) &(blackfin->uart.uart_mcr) == UART_MCR_ADDR );
  assert( (int) &(blackfin->uart.uart_lsr) == UART_LSR_ADDR );
  assert( (int) &(blackfin->uart.uart_scr) == UART_SCR_ADDR );
  assert( (int) &(blackfin->uart.uart_gctl) == UART_GCTL_ADDR );

  // 
  // TWI Registers
  // 
  assert( (int) &(blackfin->twi.twi_clkdiv) == TWI_CLKDIV_ADDR );
  assert( (int) &(blackfin->twi.twi_control) == TWI_CONTROL_ADDR );
  assert( (int) &(blackfin->twi.twi_slave_ctl) == TWI_SLAVE_CTL_ADDR );
  assert( (int) &(blackfin->twi.twi_slave_stat) == TWI_SLAVE_STAT_ADDR );
  assert( (int) &(blackfin->twi.twi_slave_addr) == TWI_SLAVE_ADDR_ADDR );
  assert( (int) &(blackfin->twi.twi_master_ctl) == TWI_MASTER_CTL_ADDR );
  assert( (int) &(blackfin->twi.twi_master_stat) == TWI_MASTER_STAT_ADDR );
  assert( (int) &(blackfin->twi.twi_master_addr) == TWI_MASTER_ADDR_ADDR );
  assert( (int) &(blackfin->twi.twi_int_stat) == TWI_INT_STAT_ADDR );
  assert( (int) &(blackfin->twi.twi_int_mask) == TWI_INT_MASK_ADDR );
  assert( (int) &(blackfin->twi.twi_fifo_ctl) == TWI_FIFO_CTL_ADDR );
  assert( (int) &(blackfin->twi.twi_fifo_stat) == TWI_FIFO_STAT_ADDR );
  assert( (int) &(blackfin->twi.twi_xmt_data8) == TWI_XMT_DATA8_ADDR );
  assert( (int) &(blackfin->twi.twi_xmt_data16) == TWI_XMT_DATA16_ADDR );
  assert( (int) &(blackfin->twi.twi_rcv_data8) == TWI_RCV_DATA8_ADDR );
  assert( (int) &(blackfin->twi.twi_rcv_data16) == TWI_RCV_DATA16_ADDR );




}
