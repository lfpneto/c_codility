//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  PermCheck
//
// ***** forma de inicializar array de null's
// ***** forma de preencher array auxiliar caso exista esse determinado numero no array principal


// LYB
#include <stdio.h>
#include <stdlib.h> // para incluir ABS

// GLOBAL VARs

int solution(int A[], int N);

// MAIN
int main(void){
    //LOCAL VARs
    int outp;
    //BODY MAIN
    int A[] = {3,4,7};
    int N =  3;
    
    
    outp = solution(A,N);
    printf("outp = %d \n", outp);
    
}



// FUNCTIONS

int solution(int A[], int N) {
    int T[N];
    //when the compiler sees N variable declaration it cannot know how many
    //elements there are in the array.
    //must manually initialize that array.
    
    memset(          T,     0, N*sizeof(int) );
    //  void *memset(void *str, int c, size_t n)
    //
    //    copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.
    //    str − This is a pointer to the block of memory to fill.
    //
    //    c − This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
    //
    //    n − This is the number of bytes to be set to the value.
    //
    //    This function returns a pointer to the memory area str.
    
    // CRIA UM ARRAY T DE TAMANHO N E ENCHE DE ZEROS
    
    //    Are you looking for zero the character, or zero the number? When initializing an array as so:
    //
    //    memset(arr, 0, count);  It is equivalent to
    //    memset(arr, '\0', count);
    //    Because 0 =='\0'.
    //      The length of a string is the position of the first null terminator, so your string is zero-length, because the array backing it is filled with zeros.
    //    The reason people do this is so that as they add things to the string, they don't need to re-null-terminate it.
    
    for (int i=0;i<N;i++)
    {
        if (A[i]>N)
        {
            return 0;
        }
        T[A[i]-1]++;
        // os valores que existirem no array deixam de ter o valor null
        // passam a ter o valor um
        // no indice respectivo ao valor
    }
    int sum = 0;
    for (int i=0;i<N;i++)
    {
        sum =sum+T[A[i]-1];
    }
    return (sum==N)?1:0;
}


