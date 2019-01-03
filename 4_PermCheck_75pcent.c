//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  PermCheck
//


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
int A[] = {3,2,2};
int N =  3;


outp = solution(A,N);
printf("outp = %d \n", outp);

}



// FUNCTIONS
int solution(int A[], int N) {
int ret = 1;
for (int i=1 ; i<=N ; i++) {
//printf("Á procura do numero %d \n",i);
for (int j=0 ; j <= (N+1) ; j++) {
//printf("j = %d \n",j);
if ( j == (N+1)) {
//printf("Não encontrou %d \n",i);
i=N;
ret = 0; // aqui podia usar return 0; 
break;
} else if (i == A[j]){
//printf("encontrou %d em A[%d] \n",i,j);
break;
}
}
}
return ret;
}

//int solution(int A[], int N) {
//    long s=0;
//    for(int i=0;i<N;i++)
//        s^=(i+1)^A[i];
//    return s==0?1:0;
//
//    //  ? :	Conditional Expression.	If Condition is true ? then value X : otherwise value Y
//
//   // Unfortunately, your solution is wrong. Try [3,4,7].
//}
