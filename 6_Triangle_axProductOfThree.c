//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  MaxProductOfThree
//



// LYB
#include <stdio.h>
#include <stdlib.h>



// GLOBAL VARs


// FUNCTIONS DEFINED
int comparator(const void *a, const void *b) {
return *(int*)a - *(int*)b;
}

int solution(int A[], int N) {
qsort(A, N, sizeof(int), comparator);
long left = A[0]*A[1]*A[N-1];
long right = A[N-1]*A[N-2]*A[N-3];
return left > right ? left : right;
}






// MAIN
int main(void)
{
//int A[] = {10,2,5,1,8,20};
//int A[] = {10,50,5,1};
int A[] = {-10,-2,-5,-1,-8,-20,-6};

int N = sizeof(A)/sizeof(int);

int outP = solution( A, N);

printf("outP = %d \n",outP);
printf(" \n - - FIM - - \n");

return 0;
}
