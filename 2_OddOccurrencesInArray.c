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
int B[] = {1};
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
    printf("\n");
    
    NB = sizeof(B)/sizeof(int);
    outp = solution(B,NB);
    printf(" arrayB outp = %d \n", outp);
    printf("\n");
    
    NC = sizeof(C)/sizeof(int);
    outp = solution(C,NC);
    printf(" arrayC outp = %d \n", outp);
    printf("\n");
    
}



// FUNCTIONS
int solution(int A[], int N) {
    printf("---INICIO FUNÇÃO--- \n");
    int ret = 0;
    
    for (int i = 0 ; i<N ; i++) {
        
        ret = ret ^ A[i];
        printf("Na it.%d, A[i] = %d e ret = %d \n",i,A[i], ret);
        
        //    ^ Binary XOR Operator
        //    copies the bit if it is set in one operand but not both.
        //    Assume A = 60 and B = 13 in binary format, they will be as follows −
        //
        //    A = 0011 1100
        //    B = 0000 1101
        //
        //    A^B = 0011 0001 = 49
        
    }
    printf("---FIM FUNÇÃO--- \n");
    return ret;
};
