//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  Distinct
//  expected worst-case time complexity is O(N*log(N))
//  Thus the designed solution would be sort the input and travel them.
//
//  Fiquei com dúvidas
//


// LYB
#include <stdio.h>
#include <stdlib.h>


#define CHAR_BIT 8 // Number of bits in a type char. Minimum Acceptable Value: 8


// GLOBAL VARs


// FUNCTIONS DEFINED

int solution(int A[], int N){
    int index = 0;
    int result = 0;
    
    /**************************************************************
     “each element of array A is an integer within the range [−1,000,000..1,000,000].”
     */
    unsigned char appeared[2000001/CHAR_BIT+1];
    printf("[−1,000,000..1,000,000] = 2000001/%d = %d \n",CHAR_BIT+1, 2000001/CHAR_BIT+1 );
    
    
    /**************************************************************
     onesInByte is a pre-compute array.
     onesInByte[i] = j
     means there are j 1s in the binary formation of integer i.
     */
    unsigned short int onesInByte[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2,
        2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
        4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2,
        3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
        4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3,
        4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6,
        5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4,
        5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3,
        3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4,
        5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
        3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5,
        6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6,
        6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
    };
    
    /**************************************************************
     // teste
     
     for (int i = 0; i <= sizeof(onesInByte)/sizeof(int); i++) {
     for (int j = 0; j < 32; j++) {
     printf("%d", !!((i << j) & 0x80000000));}
     printf(" = %d \n", onesInByte[i]);
     }
     */
    
    
    
    
    /*
     Q:
     So I know that the difference between a signed and unsigned int is that a bit is used to signify if the number if positive or negative, but how does this apply to a char? How can a character be positive or negative?
     
     R:
     There's no dedicated "character type" in C language. char is an integer type, same (in that regard) as int, short and other integer types. char just happens to be the smallest integer type. So, just like any other integer type, it can be signed or unsigned.
     
     It is true that (as the name suggests) char is mostly intended to be used to represent characters. But characters in C are represented by their integer "codes", so there's nothing unusual in the fact that an integer type char is used to serve that purpose.
     
     The only general difference between char and other integer types is that plain char is generally not synonymous with signed char, while with other integer types the signed modifier is optional/implied.
     
     R2:
     
     I slightly disagree with the above. The unsigned char simply means: Use the most significant bit instead of treating it as a bit flag for +/- sign when performing arithmetic operations.
     
     It makes significance if you use char as a number for instance:
     
     typedef char BYTE1;
     typedef unsigned char BYTE2;
     
     BYTE1 a;
     BYTE2 b;
     
     For variable a, only 7 bits are available and its range is (-127 to 127) = (+/-)2^7 -1. For variable b all 8 bits are available and the range is 0 to 255 (2^8 -1).
     
     If you use char as character, "unsigned" is completely ignored by the compiler just as comments are removed from your program.
     */
    
    
    
    
    memset(appeared, 0, 2000001/CHAR_BIT+1);
    
    // Record the appeared values
    for(index = 0; index < N; ++index) {
        //          The '|=' symbol is the bitwise OR assignment operator.
        appeared[ (A[index]+1000000) / CHAR_BIT] |= (1<<(int)((A[index]+1000000)%CHAR_BIT));
    }
    
    // Compute the number of distinct values
    for(index = 0; index < 2000001/CHAR_BIT+1; ++index){
        result += onesInByte[appeared[index]];
    }
    return result;
}




// MAIN
int main(void)
{
    int A[] = {2,0,1,-2,3,1};
    // the function should return 5, because there are 5 distinct values appearing in array A, namely 1, 2 and 3.
    int N = sizeof(A)/sizeof(int);
    
    int outP = solution( A, N);
    
    printf("outP = %d \n",outP);
    
    printf(" \n FIM \n");
    return 0;
}
