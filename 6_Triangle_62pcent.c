//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Triangle
//  62%
//  Detected time complexity:
//  O(N**3)


// LYB
#include <stdio.h>
#include <stdlib.h>



// GLOBAL VARs


// FUNCTIONS DEFINED

int solution(int A[], int N){
// B = A sorted
int *B = calloc(N+2, sizeof(int));
int temp;
for (int i = 0 ; i < N ; i++) {
B[i] = A[i];
if ( i != 0) {
for (int j = i; j > 0 ; j-- ) {
if (B[j] < B[j-1]) {
temp = B[j];
B[j] = B[j-1];
B[j-1] = temp;
}
}
}
}

printf("Verifica sortA = B \n");
for (int i = 0 ; i < N ; i++) {
printf("%d ",B[i]);
}
printf("\n");

// Verifica Condição
for (int i = 0 ; i<N-2 ; i++) {
printf("B[i]+B[i+1] > B[i+2] && B[i+1]+B[i+2] > B[i] \n");
printf(" %d +   %d  >    %d  &&    %d +   %d  >   %d \n",B[i],B[i+1],B[i+2],B[i+1],B[i+2],B[i]);
printf("        %d  >    %d  &&           %d  >   %d \n",B[i]+B[i+1],B[i+2],B[i+1]+B[i+2],B[i]);
printf("                 %d  &&                   %d \n",(B[i]+B[i+1] > B[i+2]),(B[i+1]+B[i+2]) > B[i]);
printf("\n");
if ( (B[i]+B[i+1] > B[i+2]) && (B[i+1]+B[i+2] > B[i]) ) {
printf("!!! ENTROU NO IF \n");
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
