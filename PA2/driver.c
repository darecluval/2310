/**************************
 * Clare DuVal 
 * CPSC2310 Spring 20
 * Lab Section: 001 at 1:30 MW
 * UserName: ckduval C17822756
 * Instructor:  Dr. Yvon Feaster  
*************************/

#include "functions.h"

int main(int argc, char* argv[]) {

  int multiplicand = record_multiplicand();
  int multiplier = record_multiplier();

  printf("%d %d\n", multiplicand, multiplier);

  return 0;
}
