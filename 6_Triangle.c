//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Triangle
//
//  faz sort de A com recurso a qsort e função comparator
//  cria 3 variaveis P Q e R do tipo long
//  testa a condição e devolve 1 se se verificar


// LYB
#include <stdio.h>
#include <stdlib.h>



// GLOBAL VARs


// FUNCTIONS DEFINED
int comparator(const void *a, const void *b) {
return *(long*)a - *(long*)b;
// A const void * points to memory that should not be modified.
// A void * (non-const) points to memory that could be modified (but not via the void *; you'd have to cast it first).
}

int solution(int A[], int N) {
qsort(A, N, sizeof(int), comparator);
/*
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))

base − This is the pointer to the first element of the array to be sorted.
nitems − This is the number of elements in the array pointed by base.
size − This is the size in bytes of each element in the array.
compar − This is the function that compares two elements.
*/
int i;
long long P, Q, R;
for(i=2; i<N; i++) {
P = (long long)A[i];            // neste caso long long é um modificador
Q = (long long)A[i-1];
R = (long long)A[i-2];
if((P+Q>R) && (P+R>Q) && (Q+R>P)) {
return 1;
}
}
return 0;
}






// MAIN
int main(void)
{
//int A[] = {10,2,5,1,8,20};
int A[] = {10,50,5,1};
int N = sizeof(A)/sizeof(int);

int outP = solution( A, N);

printf("outP = %d \n",outP);
printf(" \n - - FIM - - \n");

return 0;
}
