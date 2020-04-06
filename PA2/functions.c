/**************************
 * Clare DuVal
 * CPSC2310 Spring 20
 * Lab Section: 001 at 1:30 MW
 * UserName: ckduval C17822756
 * Instructor:  Dr. Yvon Feaster
*************************/

#include "functions.h"

static int MIN = 0, MAX = 255;

// Record an integer between 0 and 255 to be used as the multiplicand
unsigned int record_multiplicand(){
    int x;
    printf("Please input a multiplicand: ");
    scanf("%d", &x);
    return check_num(x);
}

// Record an integer between 0 and 255 to be used as the multiplier
unsigned int record_multiplier(){
    int x;
    printf("Please input a multiplier: ");
    scanf("%d", &x);
    return check_num(x);
}

// Check that the input number is between 0 and 255 
// If not, request another number 
// When the number is within the limits, return it
unsigned int check_num(int x){
    while (x < MIN || MAX < x){
        printf("Your integer is outside the limits.");
        printf("Enter an integer between 0 and 255: ");
        scanf("%d", &x);
    }
    return x;
}

// Print the initilized parameter's and their values
void initialize_register(int C, int ACC, int M, int Q){
    printf("\n");
    printf("Initialize the data M = ");
    print_dec_bin(M);
    printf(" C = %d ACC = %d Q = ", C, ACC);
    print_dec_bin(Q);
    printf("\n");
}

// Print the binary representation of a decimal using bit manipulation
void print_bin(unsigned int x){
    unsigned int mask = 128;   //mask = [1000 0000] (8 bits = 128)
 
    //Go through each bit of the mask to use bit manipulation
    while(mask > 0) {
        if((x & mask) == 0 ){
            printf("0");
        } else {
            printf("1");
        }
        mask = mask >> 1 ;  // Right Shift
    }
}

// Print the decimal and binary representation of an integer x
int to_bin_int(unsigned int x){
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

// Print the decimal and binary representation of an integer x
void print_dec_bin(int x){
    print_bin(x);
    printf(" (%d)", x);
}

// Process the N-th step of the binary multiplication using the given params
struct n_result step_n(int N, int C, int ACC, int M, int Q){
    int add = 0;

    //Solve the last significant bit and depending on if it's one, change add 
    // M to the ACC
    int lsb = Q%2;
    char * lsbs = "lsb = 0 no add to ACC";
    if (lsb == 1) {
        add = M;
        lsbs = "lsb = 1 add M to the ACC";
    }

    printf("STEP %d:\n", N);

    //Line ONE
    printf("C   ACC        Q\n");

    //Line TWO
    printf("%d   ", C);
    print_bin(ACC);
    printf("   ");
    print_bin(Q);
    printf("\n");

    //Line THREE
    printf("+   ");
    print_bin(add);
    printf("             %s\n", lsbs);

    //Line FOUR
    printf("_______________________\n");

    //Add the ACC and (either M or 0), solve if the Carry is 1 if there is overflow
    int T = ACC + add;
    if (T > 255){
        T -= 255;
        C = 1;
    }

    //Line FIVE
    printf("%d   ", C);
    print_bin(T);
    printf("   ");
    print_bin(Q);
    printf("\n");

    //Line SIX
    printf("                         Shift >> 1\n");

    //Shift ACC and Q right by 1 (>>)
    int newT = to_bin_int(T)/10;
    if (T%2 == 1){
        add = 10000000;
    } else {
        add = 0;
    }
    int newQ = to_bin_int(Q)/10 + add;

    //Line SEVEN
    printf("%d   %08d   %08d\n", C, newT, newQ);

    printf("\n\n");

    //Create a struct that returns the two separate values of the new ACC and Q
    struct n_result result;
    result.acc = newT;
    result.q = newQ;
    return result;
}

// Convert a binary-form integer to the decimal representation
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

// Convert a binary-form integer to the decimal representation
// Used to convert the final acc to the decimal keeping in mind the base is begins 
// At 256 instead of 1 since it gets added to the final Q.
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

// Check that the final outcome of ACC&Q is the actual product of 
// the inital M * Q.
void check_product(int product, int M, int Q){
    printf("Checking... %d * %d = %d\n", M, Q, M*Q);
    if (M*Q == product) {
        printf("PASSED!\n");
    } else {
        printf("FAILED. %d != %d\n", product, M*Q);
    }
}
