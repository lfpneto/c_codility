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
    
    int *B; //cria uma variavel do tipo pointer
    if (N == 1) {
        if (A[0] == X) {
            // Se o comprimento do array for 1
            // se no tempo 0 (A[0]) a folha cair na posição para onde o sapo quer saltar
            // Devolve Zero
            // X é a ultima posição que o sapo precisa de atravessar para chegar à outra margem
            return 0;
        } else {
            return -1;
        }
    }
    // B = (int *)calloc(X, sizeof(int)); // cria um ponteiro para uma area de memoria de X elementos de tamanho int, e enche de zeros
    
    B = calloc(X, sizeof(int)); // ALTERAÇÃO "no need to cast the result"
    
    //    void *calloc(size_t nitems, size_t size)
    //
    //    Parameters
    //    nitems − This is the number of elements to be allocated.
    //
    //    size − This is the size of elements.
    //
    //    Return Value
    //    This function returns a pointer to the allocated memory, or NULL if the request fails.
    //    The diferrence malloc and calloc is that
    //    malloc does not set the memory to zero where as calloc sets allocated memory to zero.
    //
    // DEVOLVE UM POINTER
    
    //    qual é a diferença entre (int *)calloc(size_t nitems, size_t size) ou só *calloc(size_t nitems, size_t size)
    
    //    The difference is that, first causes constraint violation while second is not.
    //    Return type of calloc is  void *, therefore no need to cast it.
    
    
    int num = 0;
    for(int i = 0; i < N ; i ++) {
        if(B[A[i] - 1] == 0) {
            num ++;
            B[A[i] - 1] = 1;
        }
        if(i >= X - 1) {
            if (num == X) {
                return i;
            }
        }
    }
    return -1;
}

//int solution(int X, int A[], int N) {
//    // write your code in C99 (gcc 6.2.0)
//    if (N==1) {
//        if (A[0] == 1) {
//            return 0;
//        }
//        return -1;
//    }
//    int tmin = 0;
//    for (int p = 1; p<=X ; p++) {
//        //printf("Procura do tempo menor para a posição %d \n", p);
//        for (int i=0 ; i<=N+1 ; i++) {
//            if (A[i] == p ) {
//                //printf("A posição %d é preenchida no segundo %d \n", p,i);
//                if (tmin < i) {
//                    tmin = i;
//                    //printf("tmin = %d \n", tmin);
//                    break;
//                }
//                break;
//
//            }
//            else if ( i==N+1 ){
//                return -1;
//            }
//        }
//
//
