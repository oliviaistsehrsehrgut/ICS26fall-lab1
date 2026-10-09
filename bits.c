/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 李悠然 oliviaistsehrsehrgut
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return (~(x&y)&(~(~x&~y)));
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (~((x>>31)&x))+1;
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  
  return ((x>>(src<<3)&0x000000FF)<<(dst<<3))|(x&(~(0x000000FF<<(dst<<3))));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int logicalShift(int x, int n) {
  return (x >> n) & ~(((1 << 31) >> n) << 1);
}
//int logicalShift(int x, int n) {
// return (x>>n)&(~((1<<31)>>n)<<1);
//}


// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
// P6
int swapNibblePairs(int x) {
  int m1 = 0x0F | (0x0F << 8);
  m1 = m1 | (m1 << 16);
  int m2 = 0xF0 | (0xF0 << 8);
  m2 = m2 | (m2 << 16);
  int mask = ~(0xF0 << 24);
  int odd = (x & m1) << 4;
  int even = ((x & m2) >> 4) & mask;
  return odd | even;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int x_new= ((~x)&(x+1))+x;
  return (~x_new)&(x_new+1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
// P8
int oddParity(int x) {
  int m = 0xFF | (0xFF << 8);
  int pack8 = (x & m) ^ ((x >> 16) & m);
  int pack4 = (pack8 >> 8) ^ (pack8 & 0xFF);
  int pack2 = (pack4 >> 4) ^ (pack4 & 0xF);
  int pack1 = (pack2 >> 2) ^ (pack2 & 0x3);
  int pack0 = (pack1 >> 1) ^ (pack1 & 0x1);
  return !pack0;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  n = n & 31;
  int logical_right = (x >> n) & ~(((1 << 31) >> n) << 1);
  int left = x << ((32 - n) & 31);
  return logical_right | left;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int d = 1 << n;
  int q = x >> n;
  int r = x & (d + ~0);              
  int half = 1 << (n + ~0);          
  int gt = (half + (~r + 1)) >> 31;  
  int eq_odd = (!(r ^ half)) & (q & 1);
  int cond = (gt & 1) | eq_odd;
  return (q + cond) << n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int avg = (x & y) + ((x ^ y) >> 1);
  int half = (x ^ y) & 1;
  int sx = x >> 31;
  int sy = y >> 31;
  int same = ~(sx ^ sy);
  int diff = x + (~y + 1);
  int x_gt_y = (~sx & sy) | (same & ~(diff >> 31));
  return avg + (half & x_gt_y & 1);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
// P12
int isBetweenEitherOrder(int x, int a, int b) {
  int ua = a + (1 << 31);
  int ub = b + (1 << 31);
  int ux = x + (1 << 31);
  int a_le_b = !((ua + (~ub + 1)) >> 31);
  int b_le_a = !((ub + (~ua + 1)) >> 31);
  int x_ge_a = !((ua + (~ux + 1)) >> 31);
  int x_le_b = !((ux + (~ub + 1)) >> 31);
  int x_ge_b = !((ub + (~ux + 1)) >> 31);
  int x_le_a = !((ux + (~ua + 1)) >> 31);
  int cond1 = a_le_b & x_ge_a & x_le_b;
  int cond2 = b_le_a & x_ge_b & x_le_a;
  return cond1 | cond2;
}
// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int sign = x >> 31;
  int t = 0x19;
  t = (t << 8) | 0x99;
  t = (t << 8) | 0x99;
  t = (t << 8) | 0x99;        
  int pos_ov = (t + (~x + 1)) >> 31; 
  int neg_th = t + 1;           
  int neg_ov = (x + neg_th) >> 31;  
  int overflow = (sign & neg_ov) | (~sign & pos_ov);
  int max_val = ~(1 << 31);
  int min_val = 1 << 31;
  int sat = (sign & min_val) | (~sign & max_val);
  return (overflow & sat) | (~overflow & ((x << 2) + x));
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
// P14
int classifyAdd3(int x, int y, int z) {
  int s1 = x + y;
  int s2 = s1 + z;
  int high = (x>>31) + (y>>31) + (z>>31) + 
             (((x & y) | ((x | y) & ~s1)) >> 31 & 1) + 
             (((s1 & z) | ((s1 | z) & ~s2)) >> 31 & 1);
  int pos_ov = (~(high>>31)) & !!high;
  int is_int_min = !(s2 ^ (1 << 31));
  int neg_ov = (high >> 31) & (is_int_min + ~0);
  return (pos_ov & 1) | neg_ov;
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned s = uf & 0x80000000;
  unsigned e = (uf >> 23) & 0xFF;
  unsigned f = uf & 0x7FFFFF;
  if (e == 0xFF) return uf;
  if (e == 0 && f == 0) return uf;
  
  unsigned M;
  int exp;
  if (e == 0) {
    M = f;
    exp = -126;
  } else {
    M = (1 << 23) | f;
    exp = e - 127;
  }
  
  unsigned M3 = M * 3;
  unsigned rem = M3 & 1;
  M3 >>= 1;
  if (rem && (M3 & 1)) M3++;
  
  if (M3 >= (1 << 24)) {
    unsigned rem2 = M3 & 1;
    M3 >>= 1;
    if (rem2 && (M3 & 1)) M3++;
    exp++;
  }
  
  if (M3 < (1 << 23)) {
    if (exp < -126) {
      int shift = -126 - exp;
      if (shift >= 24) return s;
      unsigned sub_f = M3 >> shift;
      unsigned sub_rem = M3 & ((1 << shift) - 1);
      unsigned half = 1 << (shift - 1);
      if (sub_rem > half || (sub_rem == half && (sub_f & 1))) sub_f++;
      return s | sub_f;
    } else {
      while (M3 < (1 << 23)) {
        M3 <<= 1;
        exp--;
      }
    }
  }
  
  int ne = exp + 127;
  if (ne <= 0) {
    int shift = 1 - ne;
    if (shift >= 24) return s;
    unsigned sub_f = M3 >> shift;
    unsigned sub_rem = M3 & ((1 << shift) - 1);
    unsigned half = 1 << (shift - 1);
    if (sub_rem > half || (sub_rem == half && (sub_f & 1))) sub_f++;
    return s | sub_f;
  }
  if (ne >= 0xFF) return s | 0x7F800000;
  unsigned new_f = M3 & 0x7FFFFF;
  return s | (ne << 23) | new_f;
}
// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned s = uf & 0x80000000;
  unsigned e = (uf >> 23) & 0xFF;
  unsigned f = uf & 0x7FFFFF;
  if (e == 0xFF) return uf;
  if (e == 0 && f == 0) return uf;
  int exp = e - 127;
  if (exp >= 23) return uf;
  if (exp < 0) {
    if (exp < -1) return s;
    if (f == 0) return s;
    return s | 0x3F800000;
  }
  unsigned M = (1 << 23) | f;
  int shift = 23 - exp;
  unsigned rounded = M >> shift;
  unsigned rem = M & ((1 << shift) - 1);
  unsigned half = 1 << (shift - 1);
  if (rem > half || (rem == half && (rounded & 1))) rounded++;
  if (rounded == 0) return s;
  int k = 31;
  while (!(rounded & (1 << k))) k--;
  int ne = 127 + k;
  unsigned new_f = (rounded << (23 - k)) & 0x7FFFFF;
  return s | (ne << 23) | new_f;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  if (x == 0) return 0;
  unsigned s, ux;
  if (x < 0) {
    s = 0x80000000;
    ux = ~x + 1;
    if (x == (1 << 31)) ux = 1 << 31;
  } else {
    s = 0;
    ux = x;
  }
  
  int exp = 31;
  while (!(ux & (1 << exp))) exp--;
  
  if (exp <= 23) {
    unsigned f = ux << (23 - exp);
    return s | ((exp + 127) << 23) | (f & 0x7FFFFF);
  }
  
  int shift = exp - 23;
  unsigned M = ux >> shift;
  unsigned rem = ux & ((1 << shift) - 1);
  unsigned half = 1 << (shift - 1);
  if (rem > half || (rem == half && (M & 1))) M++;
  if (M >= (1 << 24)) { M >>= 1; exp++; }
  return s | ((exp + 127) << 23) | (M & 0x7FFFFF);
}


// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int m1 = 0x55 | (0x55 << 8);
  m1 = m1 | (m1 << 16);           
  int m2 = 0x33 | (0x33 << 8);
  m2 = m2 | (m2 << 16);          
  int m3 = 0x0F | (0x0F << 8);
  m3 = m3 | (m3 << 16);       
  int m4 = 0xFF | (0xFF << 16);   
  int m5 = 0xFF | (0xFF << 8);   

  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m3) + ((x >> 4) & m3);
  x = (x & m4) + ((x >> 8) & m4);
  x = (x & m5) + ((x >> 16) & m5);
  return x;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x) {
  int m1 = 0x55 | (0x55 << 8);
  m1 = m1 | (m1 << 16);           
  int m2 = 0x33 | (0x33 << 8);
  m2 = m2 | (m2 << 16);           
  int m3 = 0x0F | (0x0F << 8);
  m3 = m3 | (m3 << 16);          
  int m4 = 0xFF | (0xFF << 16);   

  x = ((x >> 1) & m1) | ((x & m1) << 1);
  x = ((x >> 2) & m2) | ((x & m2) << 2);
  x = ((x >> 4) & m3) | ((x & m3) << 4);
  x = ((x >> 8) & m4) | ((x & m4) << 8);
  x = (x >> 16) | (x << 16);
  return x;
}
