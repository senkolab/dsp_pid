/*****************************************************************************
 * TestProject.c
 * Tests the DSP-PID loop
 *****************************************************************************/

/* Place program arguments in the following string, or delete the definition
   if arguments will be passed from the command line. */
#pragma symbolic_ref
const char __argv_string[] = "-abc -xyz";

#define BUF_LEN 1000
short input[BUF_LEN];
short output[BUF_LEN]; 
short ref[BUF_LEN]; 


#include <algorithm\pid.h>
#include <processor\bf592.h>

pid_state_t state = PID_INIT(0, 16000, 500);

//
// main routine
//
int main( int argc, char *argv[] )
{
	int n;

	volatile u16* vr_ctl = (volatile u16*) VR_CTL_ADDR;
	
	*vr_ctl = (1 << 14) | (1 << 13);
	
	// preparation
	for(n=0; n<BUF_LEN; n++)
	{
		ref[n] = 1000;
		output[n] = 0;
		
	}
	
    // operation
    for(n=0; n<BUF_LEN; n++)
    {
        if(n != 0)
            input[n]= output[n-1]; //output[n-1];
            
        pid(output+n, input+n, ref+n, 1, &state);   
    }	
	
	
	asm("EMUEXCPT;");
	return 0;
}
