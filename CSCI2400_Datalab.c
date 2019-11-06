/*
 * CS:APP Data Lab
 *
 * <#Team members: Alex_Garcia,104288519;Tanner_Lillich,830313967>
 *
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
// 01010101 01010101 01010101 01010101

//          01010101 // n
// 01010101 00000000 // n << 8
//                   01010101 01010101 // n | (n<<8)
// 01010101 01010101
//m=01010101 even position at 1
//shift by 2 bytes and add to get 32 bits long
//You get 0 which gets flipped by the bang to 1

    int Bi = 0x55;
    int WD =  Bi+ (Bi << 8);
    int Pond = WD + (WD <<16);
    return Pond;

}
/* e
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
//0 is flipped by a complement gives us
	//1111111 which in a 2 complement system is -1
  return ~1 + 1;
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {

  int varA;
  int varB;
  //and operation between input x and 1 so that we can identify the
  //least significant bit. Because if lsb is 1, we
  //and it with one and it stays the same. if lsb is 0, we and it with
  //one and it stays the same. all the other bits than the lsb are and-ed
  //with 0 and thus stay the same
  varA=x & 1;
  //new variable that is the complement of varA
  varB=~varA;
  //do another and operation with 1 which is 00000001 in binary
  varB=varB+1;
  //the two and operations w 1 result in the lsb being copied into all
  //bit locations
  return varB;


}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {

    	//if we just do a right shift of x by n, because keep in mind
    	//each digit in binary increases by one power of two as we move
    	//from the least significant bit to the right

    // Something is needed to account for x >> n if positive and x >> n + 1 if negative // Subtract 1 from 2^n // This accounts for the need to + 1
    int mask = (1 << n) + ~0; // Use & operator on mask and sign bit of x
    int equalizer = (x >> 31) & mask; // Adds 1 if x was originally negative // Adds 0 if x was originally positive
    return (x + equalizer) >> n;

}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {

	//do a right shift of x by 8*n, then and it with the binary number
	//that has ones in all of the first eight bit locations, which is 255
	return (0xFF & (x >> (n << 3)));
}
/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
	//make a variable where the 0 and ones alternate in binary, which is
	//170 in decimal

	//or operation with a, and itself with a left shift of 8

	//or operation with a, and itself with a left shift of 16

	//return the "not-not" or "bang-bang of the input x anded with the
	//variable a that we did the two shifts on
  int YAM = 0xAA;
  int WD = YAM + (YAM << 8);
  int ODD = WD + (WD << 16);
  return !!(x & ODD);




}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
	//declare new variable which is input x with a right shift by 31
    int temp=x>>31;
    //do an and operation with that variable and 1 (hex value of 1 is Ox1)
    //and return that
	return (temp&0x1);
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
//returns 0 for [0xc0, 0cv7]
//returns 0 for [0xc8, 0xc9]
  return !((x >> 3) ^ 0x6) | !((x >> 1) ^ 0x1C);



}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int fitsBits(int x, int n) {
    int Number;
    int Drake;
    Number = x;
    //left shift by (32, (plus the complement of n, plus one))
    Number = Number << (32+(~n+1));
    //right shift of (32, (plus the complement of n, plus one))
    Number = Number >> (32+(~n+1));
    //xor: if exactly one bit is one, it returns one
    Drake = x^Number;
    //add one
    Drake = Drake + 1;
    //right shift by 1
    Drake = Drake >> 1;
    //return the bang of that: if anything is a 1, it returns all 0s,
    //if all 0s, returns a 1 in binary
    return!(Drake);
}
/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
//applied ! to bit shifted results if x and x+y have same result
  int M = 0x1; //one bit.
  int mx = (x>>31)&M;
  int my = (y>>31)&M;
  int ten = my^mx;
  int s = (x+(~y+1))>>31;
  int ss = (s&M)^mx;
  return !(ss&ten);


}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
//Two options 0x0 for 0xfffff in case of x=1 or x=-s 0
    int OPTION = ~0 + !x;
    return (y & OPTION) | (z & ~OPTION);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {

int variable, solution, six, eight, four, two, one, pointbit;
//binary search used to check number and check the first  16 bits for bit result
    one = 0x2;
    two = 0xC;
    four = 0xF0;
    eight = 0xFF<<8;
    six = (eight | 0xFF) << 16;
    solution = 1;
    variable = x^(x>>31);
    pointbit = (!!(variable & six)) << 4;
    solution += pointbit;
    variable = variable >> pointbit;
    pointbit = (!!(variable & eight)) << 3;
    solution += pointbit;
    variable = variable >> pointbit;
    pointbit = (!!(variable & four)) << 2;
    solution += pointbit;
    variable = variable >> pointbit;
    pointbit = (!!(variable & two)) << 1;
    solution += pointbit;
    variable = variable >> pointbit;
    pointbit = !!(variable & one);  //0 or 1
    solution += pointbit;
    variable = variable >> pointbit;
    return solution + (variable&1);

}


/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {

//checking 0 sign bits againts 1 to see if either has sign bit
    int n = ~x + 1;
    return ((n >> 31) | (x >> 31)) & 1;


}
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  //do a right shift w 31(0b000001)
  //exclusive or of input x with variable sign_x:if exactly one bit is
  //one, one is returned, and then add that to one plus the complement
  //of the variable, because the complement will flip all bits, bit by bit
  int sign_x = x >> 31;
  return((x ^ (sign_x)) + (1 + ( ~(sign_x))));
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int isPower2(int x) {

    //negate to check return for zero and due to diffren bit pattren result in non zero
    int mask = ~0;
    return (!(mask ^ (~x + 1)));

}


