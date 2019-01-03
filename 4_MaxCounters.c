//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  MaxCounters
//  O(M+N)
//
//

// LYB
#include <stdio.h>
#include <stdlib.h> // para incluir ABS

// GLOBAL VARs

struct Results {
    int * C;
    int L; // Length of the array
};
struct Results solution(int N, int A[], int M);

// MAIN
int main(void){
    //LOCAL VARs
    struct Results outp;
    //BODY MAIN
    int N =  5; // Numero de counters
    int A[] = {3,4,4,6,1};
    int X = 5;
    
    outp = solution(N,A,X);
    // print solução
    printf("OUTPUT \n");
    for(int i = 0; i < N; i++) {printf("%d ", outp.C[i]);} printf("\n");
    
}



// FUNCTIONS


struct Results solution(int N, int A[], int M) {
    struct Results result;
    
    int *B;
    B = (int *)calloc(N, sizeof *B);
    
    int max = 0;
    // lastIncrease regista o numero max
    // sempre que sai um increase(X), func. vê se o valor do registo é menor que lastIncrease
    // se for: resgito = lastIncrease; registo++
    // no final percorre array, todos os registos < que lastIncrease tomam o valor de max increase
    int lastIncrease = 0;
    
    for (int i = 0; i < M; i ++) {
        if(A[i] > 0 && A[i] < N + 1) {
            if (B[A[i] - 1] < lastIncrease) {
                B[A[i] - 1] = lastIncrease;
            }
            B[A[i] - 1] ++;
            
            // Actualiza o valor max
            if(max < B[A[i] - 1]) {
                max = B[A[i] - 1];
            }
        }
        if (A[i] == N + 1) {
            lastIncrease = max;
        }
    }
    
    for(int i = 0; i < N ; i ++) {
        if(B[i] < lastIncrease) {
            B[i] = lastIncrease;
        }
    }
    
    result.C = B;
    result.L = N;
    return result;
}


