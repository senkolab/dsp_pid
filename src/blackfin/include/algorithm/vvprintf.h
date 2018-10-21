#ifndef _VVPRINTF_H_
#define _VVPRINTF_H_
////////////////////////////////////////////////////////////////////////////////
// vvprintf.h - header file for vvprintf.c
////////////////////////////////////////////////////////////////////////////////

#include <types.h>

extern s32 vvprintf( s32 (*vputc)(s8 c, void* state), void* vp_state, s8* fmt, ...);

extern s32 vvitoh( s32 (*vputc)(s8, void*), void* vp_state, u32 value, s32 leading_pad, s8 leading_char, s32 trailing_pad, const s8* table);
extern s32 vvputs( s32 (*vputs)(s8, void*), void* vp_state, s8* str, s32 leading_pad );

#endif /* _VVPRINTF_H_ */
