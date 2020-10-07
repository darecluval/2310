/**************************
 * Clare DuVal                             
 * CPSC2310 Spring 20 	   
 * Lab Section: 001 at 1:30 MW 
 * UserName: ckduval C17822756                             
 * Instructor:  Dr. Yvon Feaster  
*************************/

#include "floatFunctions.h"

int main(void){

    //Test Positive Number, positive since the first bit is 0
    printf("Testing Positive Number...\n");
    fbits test = 0x0FACD851;
    print_result(fNegate(test), 0x8FACD851);
    print_result(fAbsVal(test), 0x0FACD851);

    printf("\n");

    //Test Negative Number, negative since the first bit is 1
    printf("Testing Negative Number...\n");
    test = 0x8FACD851;
    print_result(fNegate(test), 0x0FACD851);
    print_result(fAbsVal(test), 0x0FACD851);
    
    return 0;
}