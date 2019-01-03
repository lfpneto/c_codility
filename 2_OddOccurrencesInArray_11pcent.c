//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 05/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  OddOccurrencesInArray
//

//Solving Process
//The array will be iterated by the unit of two elements. After sorting an array, Checking the paired element and if it is not paired, then the element’s value is the element the method returns.
//
//It is like sorting rocks that have several height levels and spotting the only unpaired rock.

// LYB
#include <stdio.h>

// GLOBAL VARs
int A[] = {9,3,9,3,9,7,9};
int NA;
int B[] = {24};
int NB;
int C[] = {1,4,1,2,2,4,7,8,3,3,8};
int NC;

int solution(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp = 0; //solução
    
    //BODY MAIN
    NA = sizeof(A)/sizeof(int);
    //printf(" N = %d \n", N);
    outp = solution(A,NA);
    printf(" arrayA outp = %d \n", outp);
    
    NB = sizeof(B)/sizeof(int);
    outp = solution(B,NB);
    printf(" arrayB outp = %d \n", outp);
    
    NC = sizeof(C)/sizeof(int);
    outp = solution(C,NC);
    printf(" arrayC outp = %d \n", outp);
    
}



// FUNCTIONS
int solution(int A[], int N) {
    //    //print array para testar o sort
    //    for (int i = 0; i < N ; ++i){
    //        printf("%d ,", A[i]);
    //    }
    
    int out;
    
    if (N==1) {
        out = A[0];
        
    } else {
        // fazer um sort
        
        for ( int i=0 ; i<(N-1) ; i++) {
            for ( int j=i ; j<N ; j++) {
                if ( A[i] > A[j] ) {
                    int a = A[i];
                    A[i] = A[j];
                    A[j] = a;
                }
            }
        }
        
        //        //print array para testar o sort
        //        printf("\n");
        //        for (int i = 0; i < N ; ++i){
        //            printf("%d ,", A[i]);
        //        }
        
        
        // ver os pares, out = numero que não tiver par
        out = A[N];
        for ( int i=0 ;  i<N-1  ; i++) {
            if ( A[i+1] != A[i] ) {
                out = A[i];
            }
        }
    }
    return out;
};
