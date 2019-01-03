//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Distinct
//  O(N**2)
//
/* falhou testes:

large_random1
chaotic sequence of values from [-1M..1M], length=100K ✘TIMEOUT ERROR
running time: 4.70 sec., time limit: 0.10 sec.

large_random2
another chaotic sequence of values from [-1M..1M], length=100K ✘TIMEOUT ERROR
running time: 4.74 sec., time limit: 0.10 sec.
*/

// LYB
#include <stdio.h>
#include <stdlib.h>


// GLOBAL VARs


// FUNCTIONS DEFINED

int solution(int A[], int N){
//returns the number of distinct values in array A

int ret = 0;
int flagZero = 0;
int *B = calloc(N, sizeof(int));


for (int i = 0 ; i < N; i++ ) {
// Pega em A[0] = 2
for (int j = 0 ; j < N ; j++) {
if (A[i] == 0 && flagZero == 0) {
ret ++;
flagZero = 1;
break;
}
if (B[j] == A[i]) {
break;
}
if (B[j] == 0) {
B[j] = A[i];
ret ++;
break;
}
}

}
printf("\n");
for (int i = 0 ; i < N ; i++) {
printf("%d ", B[i]);
}
printf("\n");

return ret;
}


// MAIN
int main(void)
{
int A[] = {2,0,1,-2,3,1};
// the function should return 5, because there are 5 distinct values appearing in array A, namely 1, 2 and 3.
int N = sizeof(A)/sizeof(int);

int outP = solution( A, N);

printf("outP = %d \n",outP);

printf(" \n FIM \n");
return 0;
}
