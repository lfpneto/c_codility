//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  CountDiv
//  O(B-A)
//

// LYB
#include <stdio.h>

// GLOBAL VARs

int solution(int A, int B, int K);




// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    
    outp = solution(6,11,2);
    // print solução
    printf("OUTPUT \n");
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS

int solution(int A, int B, int K) {
    // write your code in C99
    
    //    Devolve o numero de Ints entre A e B que sejam divisiveis por K
    int ret = 0;
    
    for (int i = A ; i <= B ; i++ ) {
        if ( i%K == 0) {
            ret++;
        }
    }
    
    
    return ret;
}




