/**************************
 * Clare DuVal 
 * CPSC2310 Spring 20
 * Lab Section: 001 at 1:30 MW
 * UserName: ckduval C17822756
 * Instructor:  Dr. Yvon Feaster  
*************************/

#include "functions.h"

int main(int argc, char* argv[]) {

    // Initalize variables
    int M = record_multiplicand();
    int Q = record_multiplier();
    int orig_Q = Q;
    int C = 0, ACC = 0;

    printf("\n");

    // Print initial variables
    printf("M = multiplicand = %d (User specified)\n", M);
    printf("Q = multiplier = %d (User specified)\n", Q);
    printf("C = carry = %d\n", C);
    printf("ACC = accumulator = %d\n", ACC);

    // Step Zero
    initialize_register(C, ACC, M, Q);
    printf("\n");

    struct n_result result; 

    // Conduct Steps 1-8 and record new ACC and Q values with each step
    for (int i = 1; i <= 8; i++){
        result = step_n(i, C, ACC, M, Q);
        ACC = to_decimal(result.acc);
        Q = to_decimal(result.q);
    }

    // Check the binary multiplication matches the actual integer multiplication
    unsigned int real_ans = to_decimal_opt(result.acc) + to_decimal(result.q);
    check_product(real_ans, M, orig_Q);

    return 0;
}

