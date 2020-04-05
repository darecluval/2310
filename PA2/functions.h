/**************************
 * Clare DuVal 
 * CPSC2310 Spring 20
 * Lab Section: 001 at 1:30 MW
 * UserName: ckduval C17822756
 * Instructor:  Dr. Yvon Feaster  
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <limits.h>

/*
 * Parameters: NONE
 * Returns: An integer between 0 and 255
 * 
 * Used to: Record an integer between 0 and 255 to be used as the multiplicand.
*/
unsigned int record_multiplicand();

/*
 * Parameters: NONE
 * Returns: An integer between 0 and 255
 * 
 * Used to: Record an integer between 0 and 255 to be used as the multiplier.
*/
unsigned int record_multiplier();

/*
 * Parameters: An integer
 * Returns: An integer between 0 and 255
 * 
 * Used to: Check that the input number is between 0 and 255. If not, request another number. 
 *          When the number is within the limits, return it
*/
unsigned int check_num(int x);

#endif