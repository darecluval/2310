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
 * Featues: int acc, int q
 * 
 * Used to: Keep track of changing ACC and Q values between each step of multiplication
*/
struct n_result ; 
typedef struct n_result {
   int acc, q; 
} n_result_ ;

/*
 * Parameters: NONE
 * Returns: An unsigned integer between 0 and 255
 * 
 * Used to: Record an integer between 0 and 255 to be used as the multiplicand
*/
unsigned int record_multiplicand();

/*
 * Parameters: NONE
 * Returns: An unsigned integer between 0 and 255
 * 
 * Used to: Record an integer between 0 and 255 to be used as the multiplier
*/
unsigned int record_multiplier();

/*
 * Parameters: An integer x
 * Returns: An unsigned integer between 0 and 255
 * 
 * Used to: Check that the input number is between 0 and 255 
 *          If not, request another number 
 *          When the number is within the limits, return it
*/
unsigned int check_num(int x);

/*
 * Parameters: Int C(Carry), Int ACC(Accumulator), 
 *             Int M(Multiplicand), Int Q(Multiplier)
 * Returns: NONE
 * 
 * Used to: Print the initilized parameter's and their values
*/
void initialize_register(int C, int ACC, int M, int Q);

/*
 * Parameters: An unsigned integer x
 * Returns: NONE
 * 
 * Used to: Print the binary representation of a decimal using bit manipulation
*/
void print_bin(unsigned int x);

/*
 * Parameters: An unsigned integer x
 * Returns: An integer 
 * 
 * Used to: Convert a decimal form integer x to the binary representation
*/
int to_bin_int(unsigned int x);

/*
 * Parameters: An integer x
 * Returns: NONE
 * 
 * Used to: Print the decimal and binary representation of an integer x
*/
void print_dec_bin(int x);

/*
 * Parameters: Int N(Step), Int C(Carry), Int ACC(Accumulator), 
 *             Int M(Multiplicand), Int Q(Multiplier)
 * Returns: struct n_result containing new ACC and Q values
 * 
 * Used to: Process the N-th step of the binary multiplication using the given params
*/
struct n_result step_n(int N, int C, int ACC, int M, int Q);

/*
 * Parameters: An integer x
 * Returns: An integer
 * 
 * Used to: Convert a binary-form integer to the decimal representation
*/
int to_decimal(int x);

/*
 * Parameters: An integer x
 * Returns: An integer
 * 
 * Used to: Convert a binary-form integer to the decimal representation
 *          Used to convert the final acc to the decimal keeping in mind the base is begins 
 *          At 256 instead of 1 since it gets added to the final Q.
*/
int to_decimal_opt(int x);

/*
 * Parameters: Int product(the decimal for of the final ACC&Q), 
 *             Int M(Muliplicand), Int Q(Original Multiplier),
 * Returns: NONE (Prints to the terminal)
 * 
 * Used to: Check that the final outcome of ACC&Q is the actual product of 
 *          the inital M * Q.
*/
void check_product(int product, int M, int Q);

#endif