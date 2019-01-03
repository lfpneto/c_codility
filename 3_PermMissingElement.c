//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 05/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  PermMissingElem
//





// LYB
#include <stdio.h>

// GLOBAL VARs

int solution(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    int A[] = {2,3,1,5};
    int N =  4;
    
    
    outp = solution(A,N);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    //  The main challenge of this question is the XOR operations: X^X=0, and 0^X=X.
    //  Logically, the addition and subtraction operations also are able to do this work.
    //  But taking the overflow in computer into consideration, they become a very bad choice.
    //
    //  xor_sum = axor_sum ^ A[i] ^ (i + 1)
    //
    //  0 = 1 ^ 2 ^ ... (N+1) ^ 1 ^ 2 ^ ... (N+1) <=>
    //  0 = 1 ^ 1 ^ 2 ^ 2 ^ ... ^ (N+1) ^ (N+1)
    //
    //  A[0] ^... ^ A[N] ^ M = 1 ^ ... ^ (N+1)
    
    //  S = 1 ^ 2 ^ … ^ N ^ (N +1) ^ 1 ^ 2 ^ … ^ N ^ (N +1)
    //  = A[1] ^ A[2] ^ … ^ A[N] ^ M ^ 1 ^ 2 ^ … ^ N ^ (N +1)
    //  = (A[1] ^ A[2] ^ … ^ A[N] ^ 1 ^ 2 ^ … ^ N) ^ M ^(N +1)
    //  = (A[1] ^ 1 ^ A[2] ^ 2 ^ … ^ A[N] ^ N) ^ M ^ (N + 1).
    //
    //  Since S = 0, we can get M as
    //  M = S ^ (A[1] ^ 1 ^ A[2] ^ 2 ^ … ^ A[N] ^ N) ^ (N + 1)
    //  = (A[1] ^ 1 ^ A[2] ^ 2 ^ … ^ A[N] ^ N) ^ (N + 1).
    
    
    
    int ret = 0;
    int s = 0;
    for (int i = 0; i<N; i++) {
        s = s ^ A[i] ^ (i+1);
    }
    ret = s ^ (N+1);
    return ret;
}
