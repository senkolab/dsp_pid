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

pid_state_t state = PID_INIT(30000, 0, 0);

//
// main routine
//
int main( int argc, char *argv[] )
{
	int n;

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
            input[n]= output[n-1];
            
        pid(output+n, input+n, ref+n, 1, &state);   
    }	
	
	
	/* Begin adding your custom code here */
	return 0;
}
