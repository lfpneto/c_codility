//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  MissingInt
//  O(N) or O(N * log(N))
//  Pigeon Hole principle
//

// LYB
#include <stdio.h>

// GLOBAL VARs

int solution(int A[], int N);

// MAIN
int main(void){
//LOCAL VARs
int outp;
//BODY MAIN
int N = 5;
int A[] = {1,2,3,5,4};

outp = solution(A,N);
// print solução

printf("OUTPUT \n");
printf("outp = %d \n", outp);
}



// FUNCTIONS

int solution(int A[], int N) {
// write your code in C99 (gcc 6.2.0)
int *B;
B = (int *)calloc( N, sizeof *B);

for (int i = 0 ; i <= N; i++) {
if (A[i] > 0 && A[i] <= N ) {
B[A[i] - 1] = 1;
}

}
for (int i = 0 ; i < N; i++) {
if (B[i] == 0 ) {
return i + 1;
}
}

return N + 1;
//  não é preciso fazer iterações <= N
// se chegar ao fim das iterações e nao encontrar o resultado é N+1
}

