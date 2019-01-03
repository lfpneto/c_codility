//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  FrogRiverOne
//


// LYB
#include <stdio.h>
#include <stdlib.h> // para incluir ABS

// GLOBAL VARs

int solution(int X, int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    int A[] = {1,3,1,7,2,3,5,7};
    int N =  7;
    int X = 5;
    
    outp = solution(X,A,N);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    if (N==1) {
        if (A[0] == 1) {
            return 0;
        }
        return -1;
    }
    int tmin = 0;
    for (int p = 1; p<=X ; p++) {
        //printf("Procura do tempo menor para a posição %d \n", p);
        for (int i=0 ; i<=N+1 ; i++) {
            if (A[i] == p ) {
                //printf("A posição %d é preenchida no segundo %d \n", p,i);
                if (tmin < i) {
                    tmin = i;
                    //printf("tmin = %d \n", tmin);
                    break;
                }
                break;
                
            }
            else if ( i==N+1 ){
                return -1;
            }
        }
    }
    return tmin;
}


