//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Sorting
// inspirado no bubbleSort
//


// LYB
#include <stdio.h>
#include <stdlib.h>


// GLOBAL VARs

int A[] = {4, 2, 2, 5, 8, 5, 1};
int N = sizeof(A)/sizeof(int);

// FUNCTIONS DEFINED
int sort(int A[], int N) {
int *B = malloc(sizeof *B);

for (int i = 0 ; i < N ; i++ ) {
B[i] = A[i];
}


// PRINT DO SORT
printf("(");
for (int i = 0 ; i < N ; i++) {
;printf(" %d,",B[i]);
}
printf(") \n");



for (int j = 0 ; j < N-1; j++) {
for (int i = 0 ; i < N-1 ; i++ ) {
if (B[i+1] < B[i]) {
int temp = B[i];
B[i] = B[i+1];
B[i+1] = temp;
}
}
}




return B;
}


// MAIN
int main(void)
{
//printf("N = %d \n",N);
int *outp;
outp = sort(A,N);

// PRINT DO SORT
printf("(");
for (int i = 0 ; i < N ; i++) {
;printf(" %d,", *(outp + i));
}
printf(") \n");

return 0;
}

