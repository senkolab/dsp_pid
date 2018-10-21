////////////////////////////////////////////////////////////////////////////////
// vvprintf_test() - tests the vvprintf() function
//
// Written by Rich Rademacher, IQC/UWATERLOO
// October 2018
////////////////////////////////////////////////////////////////////////////////

#include <algorithm/vvprintf.h>
#include <types.h>


//
// globals
//
s8 putc_buf[256];

//
// prototypes
//

typedef struct _putc_state_t {
  u32 ntotal;
  s8* buf_ptr;
  s8* buf_start;
  u32 rem;
} putc_state_t;

#define PUTC_INIT(buf)  { sizeof(buf), buf, buf, sizeof(buf) }

/*
 * putc driver
 */
s32 putc( s8 c, void* vp_state)
{
  putc_state_t* state = vp_state;
  if(state->rem <= 0)
    return 0;
  
  *(state->buf_ptr++) = c;
  state->rem -= 1;

  return 1;
}


/*
 * main program
 */
s32 main(s32 argc, s8** argv)
{
  s32 result;
  putc_state_t putc_state = PUTC_INIT(putc_buf);
  void* state = &putc_state;

  result = vvprintf(putc, state, "test");

  result = vvprintf(putc, state, "%c", 'a');
  result = vvprintf(putc, state, "%c%c", 'a', 'b');
  

  result = vvprintf(putc, state, "%s", "hello world!");
  result = vvprintf(putc, state, "%12s", "hello world!");
  result = vvprintf(putc, state, "%2s", "hello world!");
  result = vvprintf(putc, state, "%15s", "hello world!");
  result = vvprintf(putc, state, "Test: %12s", "hello world!");


  result = vvprintf(putc, state, "%x", 0xaabb1234);
  result = vvprintf(putc, state, "%X", 0xaabb1234);
  result = vvprintf(putc, state, "%12x", 0x1234);
  result = vvprintf(putc, state, "%08x", 0x1234);
  result = vvprintf(putc, state, "% 8x", 0x1234);

  result = vvprintf(putc, state, "%i", 0);
  result = vvprintf(putc, state, "%3i", 0);
  result = vvprintf(putc, state, "%i", 1234);
  result = vvprintf(putc, state, "%i", -1234);
  result = vvprintf(putc, state, "%+i", 1234);
  result = vvprintf(putc, state, "%+13i", 1234);
  result = vvprintf(putc, state, "%+13i", 1234);



  while(1)
    asm("emuexcpt;");
}


