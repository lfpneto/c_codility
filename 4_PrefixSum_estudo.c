//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  suffixSum
//  estudo

// LYB
#include <stdio.h>

// GLOBAL VARs

int suffixSum(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    int N = 8;
    int A[] = {3,4,-2,-1,7,-5,6,4};
    
    outp = suffixSum(A,N);
    // print solução
    
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
}



// FUNCTIONS

int suffixSum(int A[], int N) {
    int ret = 0;
    int *P;
    P = calloc(N+1,sizeof *P);
    
    for (int i = 1; i < N+1 ; i++) {
        P[i] = P[i-1] + A[i-1];
    };
    ret = P[N];
    // P[0] == 0 sempre
    // P[1] == A[0]             >> A[0] primeiro elemento
    // P[2] == P[1] + A[1]
    // P[3] == P[2] + A[2]
    // ...
    // P[N] == P[N-1] + A[N-1]  >> A[N-1] ultimo elemento
    
    return ret;
}

