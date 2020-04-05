/**************************
 * Clare DuVal 
 * CPSC2310 Spring 20
 * Lab Section: 001 at 1:30 MW
 * UserName: ckduval C17822756
 * Instructor:  Dr. Yvon Feaster  
*************************/

#include "functions.h"

static int MIN = 0, MAX = 255;

unsigned int record_multiplicand(){
    int x;
    printf("Please input a multiplicand: ");
    scanf("%d", &x);
    return check_num(x);
}

unsigned int record_multiplier(){
    int x;
    printf("Please input a multiplier: ");
    scanf("%d", &x);
    return check_num(x);
}

unsigned int check_num(int x){
    while (x < MIN || MAX < x){
        printf("Your integer is outside the limits. Enter an integer between 0 and 255: ");
        scanf("%d", &x);
    }
    return x;
}