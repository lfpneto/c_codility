//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Kadane
//   maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array, a[1...n], of numbers which has the largest sum.

// LYB
#include <stdio.h>
#include <stdlib.h>


// GLOBAL VARs
struct retKadane {
    int maxGlobal;
    int index;
};
int A[] = {1,-3,2,1,-1};
int N = sizeof(A)/sizeof(int);

// FUNCTIONS DEFINED
struct retKadane solution(int A[], int N) {
    struct retKadane ret;
    int max = A[0];
    ret.maxGlobal = A[0];
    ret.index = 0;
    
    
    
    for (int i = 1; i<N ; i++) {
        if (A[i]+max>A[i]) {
            max=A[i]+max;
        } else {
            max=A[i];
        }
        if (max>ret.maxGlobal) {
            ret.index = i;
            ret.maxGlobal = max;
        }
    };
    
    
    
    return ret;
}


// MAIN
int main(void)
{
    printf("N = %d \n",N);
    struct retKadane outp = solution(A,N);
    printf("outp.index = %d \n",outp.index);
    printf("outp.maxGlobal = %d \n",outp.maxGlobal);
    
    return 0;
}























