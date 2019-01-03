//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  suffixPrefixSliceSums
//  estudo

// LYB
#include <stdio.h>

// GLOBAL VARs

int suffixSum(int A[], int N, int X);
// array A, numero de elementos N, até onde é que conta X (a começar no inicio)
int prefixSum(int A[], int N, int Y);
// array A, numero de elementos N, até onde é que conta Y (a começar no fim)
int sliceSum(int A[], int N, int Y, int X);
// array A, numero de elementos N, de onde até onde é que conta X a Y



// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    
    int A[] = {3,4,-2,-1,7,-5,6,4};
    int N = 8;
    
    outp = suffixSum(A,N,8);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
    
    outp = prefixSum(A,N,0);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
    
    outp = sliceSum(A,N,0,8);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
}



// FUNCTIONS

int suffixSum(int A[], int N, int X) {
    int ret = 0;
    // X = 8; // assim faz a soma por completo
    int *P;
    P = calloc(N+1,sizeof *P);
    
    for (int i = 1; i < X+1 ; i++) {
        P[i] = P[i-1] + A[i-1];
    };
    
    ret = P[X];
    
    // P[0] == 0 sempre
    // P[1] == A[0]             >> A[0] primeiro elemento
    // P[2] == P[1] + A[1]
    // P[3] == P[2] + A[2]
    // ...
    // P[N] == P[N-1] + A[N-1]  >> A[N-1] ultimo elemento
    
    return ret;
}

int prefixSum(int A[], int N, int Y) {
    int ret = 0;
    // Y = 0; // assim faz a soma por completo
    int *P;
    P = calloc(N+1,sizeof *P);
    P[N] = 0;
    for (int i = N-1; i >= Y ; i--) {
        P[i] = P[i+1] + A[i];
    };
    
    ret = P[Y];
    
    // P[N] == 0 sempre
    // P[N-1] == A[N]
    // P[N-2] == P[N-1] + A[N-1]
    // P[N-3] == P[N-2] + A[N-2]
    // ...
    // P[0] == P[1] + A[1]
    
    return ret;
}

int sliceSum(int A[], int N, int Y, int X) {
    int ret = 0;
    // X = 8;
    // Y = 0; // assim faz a soma por completo
    int *P;
    P = calloc(N+1,sizeof *P);
    
    
    for (int i = Y+1 ; i < X+1 ; i++) {
        P[i] = P[i-1] + A[i-1];
    };
    
    ret = P[X];
    
    return ret;
}


