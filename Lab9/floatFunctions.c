/**************************
 * Clare DuVal                             
 * CPSC2310 Spring 20 	   
 * Lab Section: 001 at 1:30 MW 
 * UserName: ckduval C17822756                             
 * Instructor:  Dr. Yvon Feaster  
*************************/

#include "floatFunctions.h"

// Convert the input number to positive by overwriting the first bit (signed bit)
// with 0
fbits fAbsVal(fbits fnum) {

    //If the number is denormalized, return itself
    unsigned exp = fnum >> 23  &  0xFF; 
    if (exp == 0) {
        return fnum;
    } 

    //Only return those numbers fnum has in common with a mask with a 0 followed 
    //by all 1s
    return (fnum & 0x7FFFFFFF);

}

// Swap the signed bit of the input number to the opposite (0-->1 and 1-->0)
fbits fNegate(fbits fnum) {

    //If the number is denormalized, return itself
    unsigned exp = fnum >> 23  &  0xFF; 
    if (exp == 0) {
        return fnum;
    } 

    //Create a mask with a 0 followed by all 1s to be used as the signed bit
    int sign = 0x7FFFFFFF;

    //Check sign bit of fnum
    if ( (fnum >> 31) == 0){
        //Replace sign bit with 1, so sign becomes 0x80000000
        return fnum | ~sign; 
    } else {
        // Else, Replace sign bit with 0, sign remains 0x7FFFFFFF
        return fnum & sign;
    }
}

void print_result(fbits result, fbits expected){

    //Print if the result of the function is what's expected
    if (result == expected){
        printf("Works!\n");
    } else {
        printf("Doesn't work.\n");
    }
}
