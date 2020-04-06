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

// register initialize_register(){

// }


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

void print_dec_bin(int x){
    printf("%08d (%d)", to_bin(x), x);
}

void step_zero(int C, int ACC, int M, int Q){
    printf("\n");
    printf("Initialize the data M = ");
    print_dec_bin(M);
    printf(" C = %d ACC = %d Q = ", C, ACC);
    print_dec_bin(Q);
    printf("\n\n");
}

struct one_two step_n(int N, int C, int ACC, int M, int Q){
    int add = 0;
    int lsb = Q%2;
    char * lsbs = "lsb = 0 no add to ACC";

    printf("STEP %d:\n", N);

    if (lsb == 1) {
        add = M;
        lsbs = "lsb = 1 add M to the ACC";
    } 

    printf("C   ACC        Q\n");
    printf("%d   %08d   %08d\n", C, to_bin(ACC), to_bin(Q));
    printf("+   %08d             %s\n", to_bin(add), lsbs);
    printf("_______________________\n");
   
    int T = ACC + add;
    if (T > 255){
        T -= 255;
        C = 1;
    }

    printf("%d   %08d   %08d\n", C, to_bin(T), to_bin(Q));
    printf("                         Shift >> 1\n");

    int newT = to_bin(T)/10;

    if (T%2 == 1){
        add = 10000000;
    } else {
        add = 0;
    }

    int newQ = to_bin(Q)/10 + add;

    printf("%d   %08d   %08d\n", C, newT, newQ);
    printf("\n\n");

    struct one_two result;
    result.acc = newT;
    result.q = newQ;
    return result;
}

int to_decimal(int x){

    int T = 0, base = 1, rem;
    while (x > 0)
    {
        rem = x % 10;
        T = T + rem * base;
        x = x / 10 ;
        base = base * 2;
    }
    return T;

}

int to_decimal_opt(int x){

    int T = 0, base = 256, rem;
    while (x > 0)
    {
        rem = x % 10;
        T = T + rem * base;
        x = x / 10 ;
        base = base * 2;
    }
    return T;

}

void check_product(product, M, Q){
    printf("Checking... %d * %d = %d\n", M, Q, M*Q);
    if (M*Q == product) {
        printf("PASSED!\n");
    } else {
        printf("FAILED. %d != %d\n", product, M*Q);
    }
}