//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 05/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  FrogJmp
//

// LYB
#include <stdio.h>

// GLOBAL VARs

int X,Y,D;
int solution(int X, int Y, int D);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    X = 10; Y = 85; D = 30;
    
    outp = solution(X,Y,D);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS
int solution(int X, int Y, int D) {
    // write your code in C99 (gcc 6.2.0)
    int ret,A;
    A = Y-X;
    ret = (A/D);
    if ( A%D != 0 ){
        ret++;
    }
    return ret;
}

