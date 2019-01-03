//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  passingCars
//  O(N)
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
    
    // começa na ponta Este e ve o primeiro carro
    // se esse carro estiver a andar para Oeste, acrescenta aos carros que vão para oeste
    // se vai para Este significa que vai passar por todos os carros que vão para Oeste
    // que foram contabilizados até aquele momento
    
    int ret = 0;
    int passamParaOeste = 0;
    int passaEste = 0;
    for (int i = N - 1; i >=0 ; i -- ) {
        printf(" *** i = %d *** \n",i);
        if (A[i] == 0) {
            passaEste ++;
            ret += passamParaOeste;
            printf("ret = %d \n",ret);
            
            if (ret > 1000000000) {
                return -1;
            }
        } else {
            passamParaOeste ++;
            printf("westCars = %d \n", passamParaOeste);
        }
    }
    
    return ret;
}
