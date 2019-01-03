//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  estudo de Pointer's
//


// LYB
#include <stdio.h>
#include <stdlib.h>


// GLOBAL VARs


// FUNCTIONS DEFINED

int *retPointerToNewArray(int A[], int N){
int K = 1;          /*  numero de rotações  */

if(N) {
K = K % N;
} else K = 0;

int* B = malloc( sizeof(int) * N);          /*  cria um pointer para uma nova zona de memoria com tamanho de N int's    */
memcpy(&B[0],&A[N - K],sizeof(int) * K);
memcpy(&B[K],&A[0],sizeof(int) * ( N - K ));
return B;
}


// MAIN
int main(void)
{

int  var = 20;      /* actual variable declaration */
int  *ip;           /* pointer variable declaration */
ip = &var;          /* store address of var in pointer variable*/

printf("Address of var variable: %x\n", &var );
/* address stored in pointer variable */
printf("Address stored in ip variable: %x\n", ip );
/* access the value using the pointer */
printf("Value of *ip variable: %d\n", *ip );

int A[] = {0,1,2,3,4,5,6,7,8,9};
int N = sizeof(A)/sizeof(int);

int *test = retPointerToNewArray(A, N);
for ( int i = 0 ; i<N ; i++ ) {
printf(" %d,", test[i]);
}


printf(" \n FIM \n");
return 0;
}


/*
    int x;
    int *p;  // * is used in the declaration:
    // p is a pointer to an integer, since (after dereferencing),
    // *p is an integer
    x = 0;
    // now x == 0
    p = &x;  // & takes the address of x
    // now *p == 0, since p == &x and therefore *p == x
    *p = 1;  // equivalent to x = 1, since p == &x
    // now *p == 1 and x == 1
*/
