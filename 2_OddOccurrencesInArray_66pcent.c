//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 05/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  OddOccurrencesInArray
//
//  Solução original, score 66%, falhou a time complexity

// LYB
#include <stdio.h>

// GLOBAL VARs
int A[] = {9,3,9,3,9,7,9};
int N;
int solution(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int C = 0;
    //BODY MAIN
    N = sizeof(A)/sizeof(int);
    printf(" N = %d \n", N);
    
    C = solution(A,N);
}



// FUNCTIONS
int solution(int A[], int N) {
    //returns the value of the unpaired element
    
    //  crio um array a[N] onde vou guardar os numeros que têm
    //  comparo os valores de A[i] com A[j]
    //  se os valores forem iguais, as suas posições no array a[] ficam iguais a zero
    
    int array[N];
    for ( int i = 0 ; i < N ; i++){
        array[i] = i+1;
    };
    
    for (int i=0; i<N-1; i++) {
        if (array[i] != 0) {
            for (int j=1+i; j<N; j++) {
                if (A[i] == A[j]) {
                    printf(" A[%d] == A[%d] \n", i,j);
                    array[i] = 0;
                    array[j] = 0;
                    break;
                }
            }
        }
    }
    
    // procuro em array[] qual é que não é zero
    // devolvo o seu valor -1 como sendo a posição no vecto A[]
    
    int B = 0;
    for (int i=0; i<N; i++) {
        if (array[i] != 0) {
            B = i;
            //printf("B = %d \n",B);
        }
    }
    
    //printf("A[B] = %d \n",A[B]);
    return A[B];
};



