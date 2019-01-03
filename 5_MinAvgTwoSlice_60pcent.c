//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  MinAvgTwoSlice
//
// 60 %
//
// RESULTADO ESPARADO É 1 MAS DEVOLVE ZERO, contudo eu acho que está certo porque vai ao encontro do enunciado.
// given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

// LYB
#include <stdio.h>
#include <stdlib.h>


// GLOBAL VARs

int A[] = {4, 2, 2, 5, 1, 5, 8};
int N = sizeof(A)/sizeof(int);

// FUNCTIONS DEFINED
int solution(int A[], int N) {
// write your code in C99 (gcc 6.2.0)
if (N == 1 ) { return 0; }

int avg = 0;
int minAvg = 0;
int minAvgIndex = 0;
int P = 0;
int Q = 1;

do {
if ( P==0 ) {
avg = (A[P] + A[Q] )/(Q-P+1);
minAvg = avg;
printf("P == 0  --  avg = %d  \n",avg);
} else {
avg = (A[P] + A[Q] )/(Q-P+1);
printf("Slice (%d, %d)  --  avg = %d  \n",P,Q,avg);


if (avg < minAvg) {
minAvg = avg;
minAvgIndex = P;
printf("!!! avg < minAvg = %d \n",minAvg);
printf("!!! minAvgIndex = %d \n",minAvgIndex);
}

}

Q++;

avg = (A[P] + A[P+1] + A[Q] )/(Q-P+1);
printf("Slice (%d, %d)  --  avg = %d  \n",P,Q,avg);


if (avg < minAvg) {
minAvg = avg;
minAvgIndex = P;
printf("!!! avg < minAvg = %d \n",minAvg);
printf("!!! minAvgIndex = %d \n",minAvgIndex);
}
P++;

if (P == N-2) {
avg = (A[P] + A[Q] )/(Q-P+1);
printf("Slice (%d, %d)  --  avg = %d  \n",P,Q,avg);

if (avg < minAvg) {
minAvg = avg;
minAvgIndex = P;
printf("!!! avg < minAvg = %d \n",minAvg);
printf("!!! minAvgIndex = %d \n",minAvgIndex);
}
}

} while (P<N-2);


return minAvgIndex;
}


// MAIN
int main(void)
{
//printf("N = %d \n",N);
int outp = solution(A,N);
printf("outp = %d \n",outp);

return 0;
}

