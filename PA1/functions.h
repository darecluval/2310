/**************************
 *Clare DuVal - C17822756
 *CPSC 2310 Spring 2020
 *Due Date: Saturday, February 15, 2020 11:59PM
 *Instructor:  Dr. Yvon Feaster
 *Lab Time: 1:30PM MW
**************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool incorrect_args(int argc);
unsigned int check_ab(int x);
void inplace_swap(unsigned int *x, unsigned int *y);
int to_bin(unsigned int x);
char * to_hex(unsigned int x);
void print_step(unsigned int x, unsigned int y);

#endif
