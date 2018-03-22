/*****************************************************************************
 * pid.asm
 *
 * Proportional-Integral-Derivative controller
 *
 * prototype: void pid(short* output, 
 *						const short* input, 
 *						const short* ref,
 *						int len, pid_state_t* state)
 *
 * structure: struct _state_t {
 								u32	accum_lower
 								u32 accum_upper
 								s16 kp
 								s16 ki
 								s16 kd
 								s16 err_last
 							}
 *****************************************************************************/

 
 /*
  * 	ref --->  (  ) --> | PID | ----\
  *				    ^					|
  *					|					|
  *					\------| SYSTEM |--/
  */
	.section program;
	.global _pid;
//#include "..\..\blackfin\include\algorithm\pid.h"
//.import "..\..\blackfin\include\algorithm\pid.h";


_pid:
    // set up stack
    link 20;
    [--sp] = (r7:4, p5:3);      // save all call-preserved registers
    [--sp] = l3;
    [--sp] = l2;
    [--sp] = l1;
    [--sp] = l0;

    // sanity check: N=0
    CC = r2 == 0;
    if CC jump pid_exit;
    
    // recast arguments as pointers
    p4 = [FP+24];	// p4 = &state
    p3 = [FP+20];	// p3 = lc0 = len
    i0 = r0;		// p0 = output
    i1 = r1;		// p1 = input
    i2 = r2;		// p2 = ref
    
    // import state
    r2 = [p4 + 0];		// OFFSETOF(_pid_state_t, accum_lower)
    r3 = [p4 + 4];		// OFFSETOF(_pid_state_t, accum_upper)
    r4 = [p4 + 8];		// OFFSETOF(_pid_state_t, kp), OFFSETOF(_pid_state_t, ki)
    r5 = [p4 + 12];		// OFFSETOF(_pid_state_t, kd), OFFSETOF(_pid_state_t, err_last)
    
    r6.l = -1.0r;		// use this fake -1 to simulate MAC addition a0 += 1.0 * x
    a0.x = r3;			// int_err upper 8 bits
    a0.w = r2;			// int_err lower 32 bits
    
    // main loop
    LSETUP(outer_t, outer_b) lc0=p3;
    outer_t:	r0.l = w[i1++];				// r0.l = in[n]
    			r0.h = w[i2++];				// r0.h = ref[n]
    			
    			r1.l = r0.h - r0.l (s);			// r1.l = err = ref - in
    			r5.h = r1.l - r5.h (s);			// deriv_err = err - err_last
    			r2.l = (a0 -= r6.l*r1.l);		// int_err = a0 += err <=> a0 -= -err
    			
    			
    			a1 = r4.l * r1.l;			// out = kp*err
    			a1 += r4.h* r2.l;			//     	+ ki*int_err
    			r6.h = (a1 += r5.l * r5.h);	//		+ kd*der_err
    			
				r5.h = r0.h - r0.l (s);				// last_err = err
				
    outer_b:	w[i0++] = r6.h;	// out[n] = r6
    
    
    // restore state
    r2 = a0.w;			// save lower 32 bit part of int_err
    r3 = a0.x;			// save upper 8 bit part of int_err
    [p4 + 12] = r5;		// OFFSETOF(_pid_state_t, kd), OFFSETOF(_pid_state_t, err_last)
    [p4 + 0] = r2;		// OFFSETOF(_pid_state_t, accum_lower)
    [p4 + 4] = r3;		// OFFSETOF(_pid_state_t, accum_upper)
    			
    
pid_exit:
    l0 = [sp++];
    l1 = [sp++];
    l2 = [sp++];
    l3 = [sp++];
    (r7:4,p5:3) = [sp++];
    unlink;
    rts;
_pid.END: