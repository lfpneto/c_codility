//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  printInt2Bin
//
//    FALHAS:
//     .controlo de overflow, ex:
//     // 4bytes * 8 = 32
//     // para n >= 4294967296
//
//



// LYB
#include <stdio.h>


void printInt2Bin(int n) {
    /*
     2147483647 = (2 pow 32)/2 ;
     2147483647 + 1 = -2147483648
     */
    
    
    /************************
     ((c << i) & 0x80000000));
     binary shift << i vezes
     faz um AND com mascara binaria 0x80000000 (valor HEXADECIMAL)
     !! , duplo NOT força o resultado lógico
     
     sem !!, quando:
     1000 0000 : mascara
     0xxx xxxx : numero
     = 0
     1000 0000 : mascara
     1xxx xxxx : numero
     = NUMERO
     ************************/
    
    if ( sizeof(int) == 2) {
        // 2bytes * 8 = 16
        for (int i = 0; i < 16; i++) {
            printf("%d", !!((n << i) & 0x8000));
        }
        printf("\n");
    }
    if ( sizeof(int) == 4) {
        // 4bytes * 8 = 32
        for (int i = 0; i < 32; i++) {
            printf("%d", !!((n << i) & 0x80000000));
        }
        printf("\n");
    }
    return;
}

int main()
{
    
    /*          teste simples           */
    printf(" /*          teste simples         */ \n");
    for (int i = 0; i < 20 ; i++) {
        printInt2Bin(i);
        
    }
    
    
    /*          teste numeros negativos         */
    printf(" /*          teste numeros negativos         */ \n");
    int j = 2147483640; // = (2 pow 32)/2 ;
    for (int i = 0; i < 20 ; i++) {
        printf(" i+j = %d ->", i+j);
        printInt2Bin(i+j);
    }
    
    /*          teste overflow         */
    printf(" /*          teste overflow         */ \n");
    j = 4294967290; // = 2 pow 32 ;
    for (int i = 0; i < 20 ; i++) {
        printf(" i+j = %d ->", i+j);
        printInt2Bin(i+j);
    }
    
    
    
    /*          teste unsigned         */
    printf(" /*          teste unsigned         */ \n");
    for (unsigned int i = 0; i < 20 ; i++) {
        printInt2Bin(i);
    }
    
    
    //    //NÃO ESTÁ A FUNCIONAR PARA:
    //
    //    unsigned short int onesInByte[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2,
    //        2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
    //        4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    //        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2,
    //        3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
    //        4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3,
    //        4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6,
    //        5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4,
    //        5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3,
    //        3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4,
    //        5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
    //        3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5,
    //        6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6,
    //        6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
    //
    //    for (int i = 0; i < sizeof(onesInByte)/sizeof(int) ; i++) {
    //        printf("onesInByte[%d] = %d = ",i,onesInByte[i]);
    //        printBinario(onesInByte[i]);
    //    }
    
    
    
    
    return 0;
}


/************************COPY*****************************
 
void printInt2Bin(int n) {
    if ( sizeof(int) == 2) {
        for (int i = 0; i < 16; i++) {
            printf("%d", !!((n << i) & 0x8000));}
        printf("\n");
    }
    if ( sizeof(int) == 4) {
        for (int i = 0; i < 32; i++) {
            printf("%d", !!((n << i) & 0x80000000));}
        printf("\n");
    }
    return;
}

*/

