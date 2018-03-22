/*********************************************************
 *	pid.h - header file for PID.asm file
 *
 * Written by Rich Rademacher, UWaterloo/IQC
 *	March, 2018
 */
#ifndef _PID_H_
#define _PID_H_

typedef struct _pid_state_t {
	unsigned int 	accum_lower;
	unsigned int 	accum_upper;
	short		 	kp;
	short			ki;
	short			kd;
	short			err_last;
} _pid_state_t;

#endif /* _PID_H */