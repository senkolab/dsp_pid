////////////////////////////////////////////////////////////////////////////////
// vvprintf.c - printf-like backend
//
// Written by Rich Rademacher, UWaterloo/IQC
// October 2018
////////////////////////////////////////////////////////////////////////////////

#include <types.h>
#include <algorithm/vvprintf.h>
#include <stdarg.h>

/*
 * Lowercase hex table
 */
const s8 lower_hex_tab[] = "0123456789abcdef";

/*
 * uppercase hex table
 */
const s8 upper_hex_tab[] = "0123456789ABCDEF";

/*
 * decimal table
 */
const s8 dec_tab[] = "0123456789";

/*
 * power-of-tens table
 */
const s32 dec_pwr_table[] = {
  1,
  10,
  100,
  1000,
  10000,
  100000,
  1000000,
  10000000,
  100000000,
  1000000000
};
#define LAST_DEC_PWR_IDX (sizeof(dec_pwr_table)/sizeof(dec_pwr_table[0]) - 1)


/*
 * vvprintf() - printf backend
 *
 * vputc - handle to function that puts a single character
 * vp_state - state variable for vputc
 * fmt - null-termintated format specifier
 * ... - variable arg list
 */
s32 vvprintf( s32 (*vputc)(s8 c, void* state), void* vp_state, s8* fmt, ...)
{
  s8 c;
  s32 result = 0;
  enum {IDLE, ESCAPE_1, ESCAPE_N} state = IDLE;
  s8 pad_char;
  s32 leading_pad, trailing_pad;
  s32 has_dot;
  s32 has_plus; 
  s8* pvalue; 
  s32 value;
  double dvalue;

  va_list ap;
  

  // start the variable argument list
  va_start(ap, fmt);
  


  while(1)
  {
    // get next format character
    c = *fmt++;
    
    // null termination
    if( 0 == c )
      break;
 
    // not in escaped state?  look for start of token
    if( IDLE == state )
    {
      if('%' == c)
      {
        pad_char = ' ';
        leading_pad = 0;
        trailing_pad = 0;
        has_dot = 0;
        has_plus = 0;

        state = ESCAPE_1;
      }
      else
      { 
        result += (*vputc)(c, vp_state);
      }
    }

    // first character of escape code
    else if( ESCAPE_1 == state )
    {
      switch(c)
      {
        case ' ':
          pad_char = ' ';
          state = ESCAPE_N;
          break;
        case '0':
          pad_char = '0';
          state = ESCAPE_N;
          break;
        case '.':
          has_dot = 1;
          state = ESCAPE_N;
          break;
        case '+':
          has_plus = 1;
          state = ESCAPE_N;
          break;
        case 'c': 
          value = va_arg(ap, s8);
          result += (*vputc)((s8) value, vp_state);
          state = IDLE;
          break;
        case 's':
          pvalue = va_arg(ap, s8*);
          result += vvputs(vputc, vp_state, pvalue, leading_pad);
          state = IDLE;
          break;
        case 'x':
          value = va_arg(ap, s32);
          result += vvitoh(vputc, vp_state, value, leading_pad, pad_char, trailing_pad, lower_hex_tab);
          state = IDLE;
          break;
        case 'X':
          value = va_arg(ap, s32);
          result += vvitoh(vputc, vp_state, value, leading_pad, pad_char, trailing_pad, upper_hex_tab);
          state = IDLE;
          break;
        case 'i':
          value = va_arg(ap, s32);
          result += vvitoa(vputc, vp_state, value, has_plus, leading_pad, pad_char);
          state = IDLE;
          break;
        case 'e':
          dvalue = va_arg(ap, double);
          result += vvdtoa_e(vputc, vp_state, dvalue);
          state = IDLE;
          break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          leading_pad = leading_pad*10 + (c - '0');
          state = ESCAPE_N;
          break;
        default:
          state = IDLE;

      }
    }
    // first character of escape code
    else if( ESCAPE_N == state )
    {
      switch(c)
      {
        case 'c': 
          value = va_arg(ap, s8);
          result += (*vputc)((s8) value, vp_state);
          state = IDLE;
          break;
        case 's':
          pvalue = va_arg(ap, s8*);
          result += vvputs(vputc, vp_state, pvalue, leading_pad);
          state = IDLE;
          break;
        case 'x':
          value = va_arg(ap, s32);
          result += vvitoh(vputc, vp_state, value, leading_pad, pad_char, trailing_pad, lower_hex_tab);
          state = IDLE;
          break;
        case 'X':
          value = va_arg(ap, s32);
          result += vvitoh(vputc, vp_state, value, leading_pad, pad_char, trailing_pad, upper_hex_tab);
          state = IDLE;
          break;
        case 'i':
          value = va_arg(ap, s32);
          result += vvitoa(vputc, vp_state, value, has_plus, leading_pad, pad_char);
          state = IDLE;
          break;
        case 'e':
          dvalue = va_arg(ap, double);
          result += vvdtoa_e(vputc, vp_state, dvalue);
          state = IDLE;
          break;
         case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          leading_pad = leading_pad*10 + (c - '0');
          state = ESCAPE_N;
          break;
        default:
          state = IDLE;

      }
    }
  }
  return result;
}

/*
 * vvitoh() virtual ascii to hex converter
 *
 * vputc - putc function driver
 * vp_state - putc state variable
 * value - value to convert
 * leading_pad - minium number of digits leading
 * leading_char - character to pad leading with
 * trailing_pad - minimum number of digits to trail
 * table - encoding table to use (upper or lower case)
 *
 */
s32 vvitoh( s32 (*vputc)(s8, void*), void* vp_state, u32 value, s32 leading_pad, s8 leading_char, s32 trailing_pad, const s8* table)
{
  s32 n;
  s8 c;
  s32 result = 0;
  s32 n_digits = 0;
  u32 p16 = 0x10000000;

  // get expected number of digits (special case for zero)
  if(0 == value)
  {
    n_digits = 1;
  }
  else
  {
    for(n_digits = 8; n_digits > 0; n_digits--)
    {
      if(value >= p16)
        break;
      p16 >>= 4;
    }
  }
  

  // do leading pad
  for(n=leading_pad; n > n_digits; n--)
  {
    result += (*vputc)( leading_char, vp_state );
  }
  
  // do digits
  for(n=n_digits-1; n >= 0; n--)
  {
    c = table[ (value >> (n*4)) & 0xf ];  // get digits
    result += (*vputc)( c, vp_state );  // call putc()
  }

  // do trailing pad
  for(; result < trailing_pad; )
  {
    result += (*vputc)(' ', vp_state);
  }

  return result;
}



/*
 * vvputs() - virtualizes the puts() function
 *
 * vputc - putc() driver
 * vp_state - state variable for putc()
 * str - string to put
 */
s32 vvputs( s32 (*vputc)(s8, void*), void* vp_state, s8* str, s32 leading_pad )
{
  s8 c;
  s32 result = 0;
  s32 len;
  s8* p = str;

  // pad leading
  if(leading_pad != 0)
  {
    // find string length
    for(p=str, len=leading_pad; '\0' != *p; p++)
      len--;

    // apply padding character (space)
    for(; len > 0; len--)
      result += (*vputc)(' ', vp_state);
  }


  // copy string
  p = str;
  while(1)
  {
    // get new character
    c = *p++;
    
    // null termination ends function
    if('\0' == c)
      return result;

    // place character
    result += (*vputc)(c, vp_state);
  }
}


/*
 * vvitoa() - integer to ascii
 *
 * vputc - putc() driver
 * vp_state - putc() state variable
 * value - value
 * plus_sign - mandatory plus sign
 * leading_pad - number of pad characters
 * pad_char - pad characters
 *
 */
s32 vvitoa(s32 (*vputc)(s8, void*), void* vp_state, s32 value, s32 plus_sign, s32 leading_pad, s8 pad_char)
{
  s32 radix = LAST_DEC_PWR_IDX;
  s32 m;
  s32 result = 0;
  s32 n; 
  s32 n_digits = 0;



  // pos/neg logic
  if( value < 0 )
  {
    result += (*vputc)('-', vp_state);
    value = 0-value;
    n_digits++;
  }
  else if( plus_sign )
  {
    result += (*vputc)('+', vp_state);
    n_digits++;
  }



  // calculate number of digits
  if( 0 == value )
  {
    n_digits++;
  }
  else
  {
    for(radix=LAST_DEC_PWR_IDX; radix >=0; radix--)
    {
      if( value >= dec_pwr_table[ radix ] )
      {
        n_digits += radix;
        break;
      }
    }
  }



  // do pad character
  for( ; leading_pad > n_digits; leading_pad-- )
  {
    result += (*vputc)(pad_char, vp_state);
  }




  // print each power-of-10 digit
  if( 0 == value )
  {
    result += (*vputc)('0', vp_state);
  }
  else
  {
    for( ; radix >= 0; radix-- )
    {
      // find multiplicand at this radix
      m = value / dec_pwr_table[ radix ];

      // printt multiplicand as ascii digit
      result += (*vputc)( dec_tab[m], vp_state );

      // remainder is result of multiplication
      value -= m * dec_pwr_table[ radix ];
    }
  }


  return result;
}




/*
 * vvdtoa_e() - double-precision to ascii in "e" format
 *
 */
s32 vvdtoa_e( s32 (*vputc)(s8, void*), void* vp_state, double value )
{
  union {
    double d;
    u32 u;
    struct {
      u32 mant: 23;
      s32 exp:  8;
      u32 sign: 1;
    } ieee;
  } dvalue;

  s32 result = 0;
  s8 exp;
  s32 mant;
  s32 n;
  s32 ipart;
  s32 fpart;
  s8  c;



  // decode ieee764 value
  dvalue.d = value;
  exp = dvalue.ieee.exp - 127;            // normalize the signed mantissa
  if( 0 == dvalue.ieee.exp )
    mant = dvalue.ieee.mant;              // denormalized numbers have
  else 
    mant = (1 << 24) + dvalue.ieee.mant;  // add implicit "1" from IEEE standard


  // do sign
  if(dvalue.ieee.sign)
    result += (*vputc)('-', vp_state);



  // do integer portion
  ipart = (mant << exp ) >> 24;
  c = dec_tab[ ipart ];
  result += (*vputc)( c, vp_state );
  result += (*vputc)( '.', vp_state );
  

  // do fractional part
  fpart = mant - ((c - '0') << 24);
  for(n=exp-24; n>0; n++)
  {
  }
  


  return result;
}
