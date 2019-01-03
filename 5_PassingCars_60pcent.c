//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  passingCars
//  O(N ** 2)
//

// LYB
#include <stdio.h>

// GLOBAL VARs

int solution(int A[], int N);
// array A, numero de elementos N, até onde é que conta X (a começar no inicio)




// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    
    int A[] = {0,1,0,1,1};
    int N = 5;
    
    outp = solution(A,N);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS

int solution(int A[], int N) {
    // write your code in C99
    int passing = 0;
    int westCars = 0;
    int hasEast = 0;
    for (int i = N - 1; i >=0 ; i -- ) {
        if (A[i] == 0) {
            hasEast ++;
            passing += westCars;
            if (passing > 1000000000) {
                return -1;
            }
        } else {
            westCars ++;
        }
    }
    
    return passing;
}




