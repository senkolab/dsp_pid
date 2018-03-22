/*********************************************************
 *	pid.h - header file for PID.asm file
 *
 * Written by Rich Rademacher, UWaterloo/IQC
 *	March, 2018
 */
#ifndef _PID_H_
#define _PID_H_

/**
 * this register layout is special...do not move or optimize without changing pid.asm file
 */
typedef struct _pid_state_t {
	unsigned int 	accum_lower;
	unsigned int 	accum_upper;
	short		 	kp;
	short			ki;
	short			kd;
	short			err_last;
} pid_state_t;

extern void pid(short* output, 
					const short* input, 
					const short* ref,
					int len, pid_state_t* state);
					
/**
 * use this to initialize state
 */
#define PID_INIT(kp, ki, kd)    { 0, 0, kp, ki, kd, 0 }

#endif /* _PID_H */
