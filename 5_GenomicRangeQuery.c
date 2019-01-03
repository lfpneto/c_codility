//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 12/09/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//  GenomicRangeQuery
//  O(N + M)
// To compute you need to go through all elements in nArr (size n) and all elements in mArr (size m)


// LYB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// INCLUI strlen()

// GLOBAL VARs

struct Results {
int *A;
int M;
};

// FUNCTIONS DEFINED
struct Results solution(char *S, int P[], int Q[], int M)
{
unsigned length = strlen(S); // Returns the length of string.

int A[length], C[length], G[length], T[length];
// não consegui fazer isto antes, em outros programas
// para o fazer, tem de ser unsigned?
// cria arrays de 7 elementos, de indice 0 até 6

for (int i = 0; i < length; ++i) {

// 1 - coloca os arrays A,C,G,T a Zero á medida que vão sendo percorridos
if (i == 0)
A[i] = C[i] = G[i] = T[i] = 0;
else {
A[i] = A[i - 1];
C[i] = C[i - 1];
G[i] = G[i - 1];
T[i] = T[i - 1];
}


switch (S[i]) {
case 'A':
++A[i];
break;
case 'C':
++C[i];
break;
case 'G':
++G[i];
break;
case 'T':
++T[i];
break;
}
} // FIM FOR
/* Neste ponto estão prencidos os arrays A,C,G,T
os arrays contem informação de, para determinado index
até lá chegar quantas occorencias da sua letra correspodente aconteceram
ex : Q[] = {C,A,G,C,C,T,A}
A[] = {0,1,1,1,1,1,2}
C[] = {1,1,1,2,3,3,3}
G[] = {0,0,1,1,1,1,1}
T[] = {0,0,0,0,0,1,1}
*/



struct Results result = {
calloc(M, sizeof(int)),
M
};

/* Para os interlavos dados por P[i] e Q[i]
para determinada letra
vemos o numero de ocorrencia dessa mesma letra que existiram até ao indice Q[i]
vemos o numero de ocorrencia que existem no fim do intervalo
e subtraimos o numero de ocorrencia dessa mesma letra que existiram até ao indice P[i]-1
e subtraimos o numero de ocorrencia existem antes de o intervalo começar
Se o resultado for zero
significa que dentro do intervalo não aparece a letra do array correspondente

*/
for (int i = 0; i < M; ++i) {
if (A[Q[i]] - (P[i] > 0 ? A[P[i] - 1] : 0) > 0)
result.A[i] = 1;
else if (C[Q[i]] - (P[i] > 0 ? C[P[i] - 1] : 0) > 0)
result.A[i] = 2;
else if (G[Q[i]] - (P[i] > 0 ? G[P[i] - 1] : 0) > 0)
result.A[i] = 3;
else
result.A[i] = 4;
}
return result;
}


// MAIN
int main(void)
{
char S[] = "CAGCCTT";
int P[] = {2, 5, 0}, Q[] = {4, 5, 6};
struct Results result = solution(S, P, Q, 3);
for (int i = 0; i < 3; ++i)
printf("%d ", result.A[i]);
puts("");
return 0;
}












