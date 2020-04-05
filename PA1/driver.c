/**************************
 *Clare DuVal - C17822756
 *CPSC 2310 Spring 2020
 *Due Date: Saturday, February 15, 2020 11:59PM
 *Instructor:  Dr. Yvon Feaster
 *Lab Time: 1:30PM MW
**************************/
#include "functions.h"

int main(int argc, char* argv[]) {

  //Check Arguments Preconditions
  if (!incorrect_args(argc)) {
      return 0;
  }

  unsigned int a = check_ab(atoi(argv[1]));
  unsigned int b = check_ab(atoi(argv[2]));

  inplace_swap(&a, &b);

  return 0;
}
