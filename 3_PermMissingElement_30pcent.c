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
    int A[] = {2,3};
    int N =  2;
    
    
    outp = solution(A,N);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ret = 0;
    if ( N==1 ) {
        ret = A[0];
    } else if ( N != 0) {
        for (int i=1 ; i<(N+1); i++) {
            // i é o numero que vai procurar
            //printf("iteração i=%d \n",i);
            
            for (int j=0 ; j<=(N); j++) {
                if (i==A[j]) {
                    //printf("encontrou %d na posição A[%d] \n", i,j);
                    break;
                } else if (j==N){
                    ret = i;
                    //printf("o numero em falta é %d \n", i);
                    i = N+1;
                }
            }
        }
        
    }
    
    
    return ret;
}

