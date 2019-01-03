//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  TapeEquilibrium
//
// Detected time complexity:O(N * N)
//

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
    int ret = 0;
    int c = 0;
    for ( int P=1 ; P <= N-1 ; P++) {
        printf("A testar P = %d \n", P);
        int a = 0, b = 0;
        
        for (int i = 0 ; i <= P-1; i++) {
            a = a+A[i];
        }
        for (int i = P ; i < N; i++) {
            b = b+A[i];
        }
        printf("   a = %d \n", a);
        printf("   b = %d \n", b);
        
        if ( P==1 ) {
            c = abs(a-b);
        } else if (abs(a-b) < c) {
            c = abs(a-b);
            printf("* mudou c = %d \n", c);
        }
    }
    return ret = c ;
}

