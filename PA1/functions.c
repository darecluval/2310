/**************************
 *Clare DuVal - C17822756
 *CPSC 2310 Spring 2020
 *Due Date: Saturday, February 15, 2020 11:59PM
 *Instructor:  Dr. Yvon Feaster
 *Lab Time: 1:30PM MW
**************************/
#include "functions.h"

//Check the arguments meet the conditions to run the program
bool incorrect_args(int argc){
  if (argc != 3){
    printf("Incorrect amount of arguments. Please enter 2 integer arguments.\n");
    return false;
  }
  return true;
}

// Check that the argument integers are within the bounds of a uint8_t
unsigned int check_ab(int x){
  while (0 > x || x > 255){
    printf("Incorrect argument '%d'. Enter an integer between 0 and 255.\n", x);
    scanf("%d", &x);
  }
  return x;
}

//Swap values x and y
void inplace_swap(unsigned int *x, unsigned int *y)
{
  //Step 1
	*y = *x ^ *y;
  printf("Step 1:\n");
  print_step(*x, *y);

  //Step 2
	*x = *x ^ *y;
  printf("Step 2:\n");
  print_step(*x, *y);

  //Step 3
	*y = *x ^ *y;
  printf("Step 3:\n");
  print_step(*x, *y);
}

//Convert decimal to binary
int to_bin(unsigned int x){
  int i = 1;
  int ans = 0;

  //Evaluate while remainder is more than zero
  while (x != 0){
    ans += (i * (x%2));
    i *= 10;
    x /= 2;
  }
  return ans;
}

//Convert binary to hexidecimal
char * to_hex(unsigned int x){
  int i = 1;
  char * ans = (char *) malloc(sizeof(char) * 2);
  //Evaluate until each bit has been converted (fill backwards)
  while (i >= 0){
    int temp = x%16;
    //Convert to ascii
    if ( temp < 10) {
		           ans[i--] = temp + 48;
    } else {
		         ans[i--] = temp + 55;
    }
    x /= 16;
  }
  return ans;
}

//Print table of variables' current binary, hex, and dec values
void print_step(unsigned int x, unsigned int y){
  printf("    | Binary     | Hex       | Decimal \n");
  printf("_________________________________________\n"); //40
  printf(" *y | %08d   | 0x%s     | %d      \n", to_bin(y), to_hex(y), y);
  printf("_________________________________________\n");
  printf(" *x | %08d   | 0x%s     | %d      \n", to_bin(x), to_hex(x), x);
  printf("\n");

}
