//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  NumberOfDiscIntersections
//  6%



// LYB
#include <stdio.h>
#include <stdlib.h>



// GLOBAL VARs


// FUNCTIONS DEFINED

int comparator(const void *a, const void *b) {
return *(int*)a - *(int*)b;
}

int solution(int A[], int N) {
// write your code in C99 (gcc 6.2.0)
int ret = 0, retAux = 0;
int *refD = (int *)calloc(N, sizeof(int)), *refE = (int *)calloc(N, sizeof(int));

for (int i = 0 ; i<N ; i++) {
refD[i] = i+A[i];
refE[i] = i-A[i];
}
qsort(refE, N, sizeof(int), comparator);
for (int i = 0 ; i < N-1 ; i++) {
retAux = -(i+1);
printf("* i=%d    refD[i]=%d ------\n",i,refD[i]);

for (int j = 0; refE[j]<refD[i] && j<N ; j++) {
printf("** j=%d    refE[j]=%d \n",j,refE[j]);
if (refD[i]>refE[j]) {
retAux++;
printf("*** retAux++ = %d \n",retAux);
}
}
printf("* retAux = %d \n",retAux);
if (retAux > 0 ) {
ret = ret + retAux;
printf("* ret = %d \n",ret);
}


if (ret > 10000000) {
return -1;
}

}
return ret;
}


// FUNCTIONS DEFINED





// MAIN
int main(void)
{
//int A[] = {10,2,5,1,8,20};
//int A[] = {10,50,5,-1};
int A[] = {1,5,2,1,4,0};

int N = sizeof(A)/sizeof(int);

int outP = solution( A, N);

printf("outP = %d \n",outP);
printf(" \n - - FIM - - \n");

return 0;
}
