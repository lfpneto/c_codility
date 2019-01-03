//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 03/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  CyclicRotation
//

// LYB
#include <stdio.h>

// GLOBAL VAR
struct Results {
    int *A; // Pointer para o Array
    int N; // Comprimento do Array
};

int k, n;
struct Results solution(int A[], int N, int K);

// MAIN
int main(void){
    
    // LOCAL VAR
    int a[] = {3,8,9,7,6};
    struct Results outp;
    
    // dados  para teste da função #Results
    k = 3;
    n = sizeof(a)/sizeof(a[0]);
    printf("n = %d \n", n);
    printf("k = %d \n", k);
    
    //print array
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    // teste da função Results
    outp = solution( a,  n,  k);
    
    // print solução
    printf("OUTPUT \n");
    for(int i = 0; i < n; i++) {printf("%d ", a[i]);} printf("\n");
    
}


// FUNCTIONS

// solução copiada
struct Results solution(int A[], int N, int K) {
    
    // é criada uma variavél local do tipo struct a qual é devolvida no finaç da função
    // SE  N 'numero de elementos' for > 0
    //      K é igual ao resto da divisão de K por N
    //      Faz com que o numero de iterações seja o menor possivél
    //          EX:
    //          N = 5 e K = 1 :: uma deslocação
    //          N = 5 e K = 6 :: uma deslocação
    //          N = 5 e K = 5 :: não há deslocação
    // SEÑ K 'deslocações' é igual a zero
    //
    // criado um ponteiro de tamanho igual ao de um int vezes o numero de ints que existem no array
    //
    //  copia-se (bytes) para o inicio do novo ponteiro
    //  dados do antigo ponteiro a começar pelo indice que irá ser 0 no ponteiro final (N-K)
    //          EX:
    //          N = 5 e K = 1 :: (N-K) = 4
    //          a[] = {3,8,9,7,6} >> copia de a[4] para a frente
    //          B[] = {6}
    //          N = 5 e K = 3 :: (N-K) = 2
    //          a[] = {3,8,9,7,6} >> copia de a[2] para a frente
    //          B[] = {9,7,6}
    //
    //  copia-se (bytes) do inicio do antigo array
    //  para a posição indice K no novo ponteiro
    //          EX:
    //          N = 5 e K = 1
    //          a[] = {3,8,9,7,6} >> copia de a[0] para a frente e coloca em indice K
    //          como são defenidos os bytes a copiar sizeof(int) * ( N - K ) = 4
    //          copia 4 int's , logo:
    //          B[] = {6} + {3,8,9,7}
    //          N = 5 e K = 3
    //          a[] = {3,8,9,7,6} >> copia de a[0] para a frente e coloca em indice K
    //          como são defenidos os bytes a copiar sizeof(int) * ( N - K ) = 2
    //          copia 4 int's , logo:
    //          B[] = {9,7,6} + {3,8}
    
    struct Results result;
    
    if(N) {
        K = K % N;
    } else K = 0;
        
        int* B = malloc( sizeof(int) * N);
        
        
        memcpy(     &B[0],         &A[N - K], sizeof(int) * K);
        //      memcpy(void *str1,  const void *str2,        size_t n);
        //      copies n characters from memory area str2 to memory area str1.
        //
        //            str1  − This is pointer to the destination array where the content is to be copied,
        //                    type-casted to a pointer of type void*.
        //            str2  − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
        //            n     − This is the number of bytes to be copied.
        //
        //            Return Value
        //            This function returns a pointer to destination, which is str1.
        
        memcpy( &B[K], &A[0], sizeof(int) * ( N - K ) );
        result.A = B;
        result.N = N;
        return result;
}

//// solução original  ---------------------------------------
//struct Results solution(int A[], int N, int K) {
//    struct Results result;
//    int i = K-1;
//    if ( N != K ) {
//        do {
//            int aux = A[0];
//            for (int j = 0; j < N-1 ; j++){
//                A[j] = A[j+1];
//            }
//            A[N-1] = aux;
//            i--;
//        }while ( i > 0 );
//
//    }
//
//    result.A = A;
//    result.N = K;
//    return result;
//};
//
////  !! Erro, no codility o outp éra:
//// WRONG ANSWER  (got [9, 7, 6] expected [9, 7, 6, 3, 8])
