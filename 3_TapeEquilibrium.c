//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  TapeEquilibrium
//
//  The variable of head stores the sum of the heading part of the tape.
//  And the variable of tail stores the sum of tailing part.
//  Then, we move the index from 2nd position to the last 2nd position.
//  Every time we move the index, we adjust both head and tail, compute and compare the difference.

// LYB
#include <stdio.h>
#include <stdlib.h> // para incluir ABS

// GLOBAL VARs

int solution(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    int A[] = {3000,1000};
    int N =  2;
    
    
    outp = solution(A,N);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS
int solution(int A[], int N) {
    int ret;
    int head = A[0];
    int tail = 0;
    for ( int i = 1 ; i<N ; i++) {
        tail = tail + A[i];
    }
    ret = abs(head-tail);
    for ( int i = 1 ; i<(N-1) ; i++) {
        head = head + A[i];
        tail = tail - A[i];
        if (ret > abs(head-tail)) {
            ret = abs(head-tail);
        }
    }
    return ret;
}
