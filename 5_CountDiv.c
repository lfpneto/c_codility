//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  CountDiv
//  O(1)
//
//

// LYB
#include <stdio.h>

// GLOBAL VARs

int solution(int A, int B, int K);




// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    
    outp = solution(0,11,2);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS

int solution(int A, int B, int K) {
    
    // write your code in C99
    if(A == 0) {
        printf("B/K = %d \n", B/K);
        return B/K + 1;
        // +1 ??
    } else {
        printf("B/K = %d \n", B/K);
        printf("(A - 1)/K = %d \n", (A - 1)/K);
        return B/K -(A - 1)/K;
        
    }
}
