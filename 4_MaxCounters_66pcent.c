//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  MaxCounters
//
// all max_counter operations TIMEOUT ERROR


// LYB
#include <stdio.h>
#include <stdlib.h> // para incluir ABS

// GLOBAL VARs

struct Results {
int * C;
int L; // Length of the array
};
struct Results solution(int N, int A[], int M);

// MAIN
int main(void){
//LOCAL VARs
struct Results outp;
//BODY MAIN
int N =  5; // Numero de counters
int A[] = {3,4,4,6,1,4,4};
int X = 5;

outp = solution(N,A,X);
// print solução
printf("OUTPUT \n");
for(int i = 0; i < N; i++) {printf("%d ", outp.C[i]);} printf("\n");

}



// FUNCTIONS

struct Results solution(int N, int A[], int M) {
struct Results result;
// write your code in C99 (gcc 6.2.0)

int *B;
B = calloc(N, sizeof *B);
// cria um pointer para B, com N int's
int maxCounter = 0;

for ( int i=0 ; i <= M ; i++){
//vai buscar A[i]
printf("------ A[%d] = %d ------ \n",i,A[i]);

if ( A[i] <= N ){

//  if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X)
printf("faz increase(X), pois %d <= %d \n", A[i],N);
printf("== B[A[i]-1] = B[%d] = %d \n ",A[i]-1,B[A[i]-1]);

B[A[i]-1]++;

printf("++ B[A[i]-1] = B[%d] = %d \n ",A[i]-1,B[A[i]-1]);

if (B[A[i]-1] > maxCounter){
maxCounter = B[A[i]-1];
printf("maxCounter = %d \n", B[A[i]-1] );
}

}else{
//  if A[K] = N + 1 then operation K is max counter
printf("Max counter %d > %d \n", A[i],N);
for (int j = 0; j < N ; j++){
B[j] = maxCounter;
}

// ******
// memset(B,maxCounter,sizeof *B);
// memset é para string's, só funciona desta forma se int c = maxCounter ≈ 0 '/0'

// ******
// memcpy(void *str1, const void *str2, size_t n)
//            Parameters
//            str1 − This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
//
//            str2 − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
//
//            n − This is the number of bytes to be copied.

// memcpy(&B[0],&maxCounter,sizeof *B);
// NÃO FUNCIONA



for(int j = 0; j < N; j++) {printf("B[%d]=%d, ", j,B[i]);} printf("\n");
}

}


result.C = B;
result.L = N;
return result;
}
