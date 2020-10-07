/**************************
 * Clare DuVal                             
 * CPSC2310 Spring 20 	   
 * Lab Section: 001 at 1:30 MW 
 * UserName: ckduval C17822756                             
 * Instructor:  Dr. Yvon Feaster  
*************************/

#ifndef FLOATFUNCTIONS_H
#define FLOATFUNCTIONS_H

#include <stdio.h>

typedef unsigned fbits;

/*
 * Parameters: fbits fnum: an unsigned 32 bit number representing a binary fractional number
 * Returns: an fbit number that is the positve sign of the input
 * 
 * Used to: Convert the input number to positive by overwriting the first bit (signed bit) with 0
*/
fbits fAbsVal(fbits fnum);

/*
 * Parameters: fbits fnum: an unsigned 32 bit number representing a binary fractional number
 * Returns: an fbit number that is the opposite sign of the input
 * 
 * Used to: Swap the signed bit of the input number to the opposite (0-->1 and 1-->0)
*/
fbits fNegate(fbits fnum);

/*
 * USED IN TESTING
 * Parameters: fbits result: result of what's calculated, fbits expected: expected result
 * Returns: NONE - prints to terminal
 * 
 * Used to: Test if the result of a function matches its expected outcome
*/
void print_result(fbits result, fbits expected);

#endif