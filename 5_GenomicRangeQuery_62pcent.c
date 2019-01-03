//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  GenomicRangeQuery
//  O(N * M)
//

// LYB
#include <stdio.h>

// GLOBAL VARs

struct Results {
int *A;
int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M);


// MAIN
int main(void){

char S[7] = {'G','G','T'};
int P[3] = {0,0,0};
int Q[3] = {0,1,2};
int M = 3;

struct Results outp = solution(S,P,Q,M);

// print solução
printf("\t OUTPUT \n");
//printf("outp.M = %d \n", outp.M);
for (int i = 0 ; i < outp.M ; i++) {
printf("outp.A[i] = %d \n", outp.A[i]); // *************** &

}


}



// FUNCTIONS

struct Results solution(char *S, int P[], int Q[], int M){
//#define A 1
//#define C 2
//#define G 3
//#define T 4
struct Results ret;
int *B = (int *)calloc(M, sizeof *B);
char sel;
for ( int i = 0 ; i < M ; i++){
printf("\t i = %d \n",i);
B[i] = 4;
for ( int j = P[i] ; j <= Q[i] ; j++){
sel = S[j];
printf("sel = %c \n",S[j]);
switch(sel){
case 'A':
printf("case A \n");
B[i] = 1;
j = Q[i]+1;
break;
case 'C':
printf("case C \n");
B[i] = 2;
break;
case 'G':
printf("case G \n");
if ( B[i] == 4) {
B[i] = 3;
printf("*B[i] = 3 \n");
}
break;
}
}
}
ret.M = M;
ret.A = B;
return ret;
}

// y = 58 + 11.83333*x - 6*x^2 + 1.166667*x^3
// B[i] = 58 + 11.83333*temp - 6*temp^2 + 1.166667*temp^3





