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

// struct one_two { 
//     int one, two; 
// }; 
  
// typedef struct one_two Struct; 

struct one_two ; /* Forward declaration */

typedef struct one_two
{
   int acc, q; 
} one_two_ ;

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

/*
 * Parameters: An integer
 * Returns: An integer between 0 and 255
 * 
 * Used to: Check that the input number is between 0 and 255. If not, request another number. 
 *          When the number is within the limits, return it
*/
//register initialize_register();

/*
 * Parameters: An unsigned integer
 * Returns: An integer 
 * 
 * Used to: Convert an integer to the binary representation.
*/
int to_bin(unsigned int x);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to therterminal)
 * 
 * Used to: Print the decimal and binary representation of an integer.
*/
void print_dec_bin(int x);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: 
*/
void step_zero(int C, int ACC, int M, int Q);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: 
*/
struct one_two step_n(int N, int C, int ACC, int M, int Q);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: 
*/
int to_decimal(int x);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: 
*/
int to_decimal_opt(int x);

/*
 * Parameters: An integer
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: 
*/
void check_product(int product, int M, int Q);

#endif