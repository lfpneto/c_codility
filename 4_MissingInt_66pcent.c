//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  MissingInt
//  O(N**2)
//
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
int ret = 1;
for (int i = 1 ; i <= N+1 ; i++){
for (int j = 0; j<= N+1 ; j++) {
if (A[j] == i) {
printf("encontrou %d em A[%d] \n",i,j);
break;
} else if (j == N+1){
ret = i;
i = N + 2;
}
}
}
return ret;
}


// conclui-se que for dentro de for aumenta a "time complexity"

