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
 * compare
 */
s32 _strcmp(s8* expected, putc_state_t* state)
{
  s32 n;
  s8* p = state->buf_start;
  s32 result = 0;


  while(*p && *expected )
  {
    if(*p++ != *expected++)
      return 0; 
  }
  if(p != state->buf_ptr)
    return 0;


  // ersae old data on success
  for(; state->buf_ptr > state->buf_start; state->rem++)
    *(--(state->buf_ptr)) = 0;
  return 1;
}

#define ASSERT(x)   { if( 0 == _strcmp(x, &putc_state) )  {asm("emuexcpt;");} }

/*
 * main program
 */
s32 main(s32 argc, s8** argv)
{
  s32 result;
  putc_state_t putc_state = PUTC_INIT(putc_buf);
  void* state = &putc_state;

  result = vvprintf(putc, state, "test");                   ASSERT("test");

  result = vvprintf(putc, state, "%c", 'a');                ASSERT("a");
  result = vvprintf(putc, state, "%c%c", 'a', 'b');         ASSERT("ab");
  

  result = vvprintf(putc, state, "%s", "hello world!");     ASSERT("hello world!");
  result = vvprintf(putc, state, "%12s", "hello world!");   ASSERT("hello world!");
  result = vvprintf(putc, state, "%2s", "hello world!");    ASSERT("hello world!");
  result = vvprintf(putc, state, "%15s", "hello world!");   ASSERT("   hello world!");
  result = vvprintf(putc, state, "Test: %12s", "hello world!"); ASSERT("Test: hello world!");


  result = vvprintf(putc, state, "%x", 0xaabb1234);         ASSERT("aabb1234");
  result = vvprintf(putc, state, "%X", 0xaabb1234);         ASSERT("AABB1234");
  result = vvprintf(putc, state, "%12x", 0x1234);           ASSERT("        1234");
  result = vvprintf(putc, state, "%08x", 0x1234);           ASSERT("00001234");
  result = vvprintf(putc, state, "% 8x", 0x1234);           ASSERT("    1234");

  result = vvprintf(putc, state, "%i", 0);                  ASSERT("0");
  result = vvprintf(putc, state, "%3i", 0);                 ASSERT("  0");
  result = vvprintf(putc, state, "%i", 1234);               ASSERT("1234");
  result = vvprintf(putc, state, "%i", -1234);              ASSERT("-1234");
  result = vvprintf(putc, state, "%+i", 1234);              ASSERT("+1234");
  result = vvprintf(putc, state, "%+13i", 1234);            ASSERT("+        1234");

  result = vvprintf(putc, state, "%e", 0.0);
  result = vvprintf(putc, state, "%e", 1.0);
  result = vvprintf(putc, state, "%e", -1.0);
  result = vvprintf(putc, state, "%e", 2.0);
  result = vvprintf(putc, state, "%e", 0.5);
  result = vvprintf(putc, state, "%e", 10);
  result = vvprintf(putc, state, "%e", 0.10);

  while(1)
    asm("emuexcpt;");
}


