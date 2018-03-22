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

//
// main routine
//
int main( int argc, char *argv[] )
{
	int n;
	
	// preparation
	for(n=0; n<BUF_LEN; n++)
	{
		input[n] = 1000;
		output[n] = 0;
	}
	
	
	
	/* Begin adding your custom code here */
	return 0;
}
