//
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/10/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//
//
//  PUSH POP ARRAY
//



// LYB
#include <stdio.h>
#include <stdlib.h>



// GLOBAL VARs


// FUNCTIONS DEFINED


void PUSH(int *p, int var) {
    printf("// PUSH \n");
    //        // a[0] incrementa
    //        //  guarda o indice do próximo elemento (extremo exterior do array)
    //        a[0]++;
    //        printf("a[0]=%d \n",a[0]);
    //
    //        a[a[1]]=var;
    //        printf("a[a[1]]=var=%d \n",a[a[1]]);
    //
    
    printf("*p = %d \n",*p);
    ++*p;
    printf("*p = %d \n",*p);
    // o pretendido agora é que o endereço seguinte guarde o valor de var.
    
    printf("sizeOf(int) = sizeOf(*p) %d \n",sizeof(*p));
    //p = &a = &a[0]
    // logo
    //&a[1] = &a + sizeOf(a(0))
    // var é guardado em &a + sizeOf(a(0))*a(0)
    // var é guardado em  p + sizeOf(*p)*  (*p)
    int *aux = p + sizeof(*p)*(*p);
    printf("p                         = %x \n",p);
    printf("aux = p + sizeof(*p)*(*p) = %x (x) \n", aux);
    printf("p + sizeof(*p)*(*p) = %x \n",p + sizeof(*p)*(*p));
    
    //vemos o que está no endereço de AUX
    printf("*aux = %d \n",*aux);
    
    
    
    
    printf("// FIM PUSH \n");
    return;
}


// FUNCTIONS DEFINED





// MAIN
int main(void)
{
    // para as array deve ser declarado o tamanho no inicio
    // a[0] guarda o indice do próximo elemento (extremo exterior do array)
    int a[] = {1};
    printf("a[0]=%d \n",a[0]);
    
    
    //PUSH:
    //  .a[] aumenta o tamanho por um
    //  .a[0] é incrementado
    int valorPush = 10;
    //á expressão PUSH passa-se um endereço para o inicio de a[]
    PUSH(&a,valorPush);
    
    printf("a[1]=%d \n",a[1]);
    
    
    //    printf("\n ESTUDO \nARRAY E SEQUENCIA DE MORADAS \n");
    //    int A[] = {1,5,2,1,4,0};
    //    for (int i = 0 ; i < 6; i++) {
    //        printf("A[%d] = %d @ %x \n",i,A[i],&A[i]);
    //    }
    //
    //    int aux = &A[0];
    //    printf("aux = %x \n",aux);
    //    aux+=sizeof(A[0]);
    //    printf("aux = %x \n",aux);
    //
    //    int *AUX = &A[0];
    //    printf("AUX = %x \n",AUX);
    //    AUX++;
    //    printf("AUX = %x \n",AUX);
    //
    //    printf(" A[2] = 0 \n");
    //    *AUX = 0;
    //    for (int i = 0 ; i < 6; i++) {
    //        printf("A[%d] = %d @ %x \n",i,A[i],&A[i]);
    //    }
    //
    //    // AGORA SE QUISER ANDAR UM NUMERO N PARA A FRENTE
    //
    //    int *AUXn = &A[0];
    //    printf("AUXn = %x \n",AUXn);
    //    AUXn=AUXn+2;
    //    printf("AUXn = %x \n",AUXn);
    
    
    printf("\n ESTUDO \nSEQUENCIA PUSH E POP \n");
    //    int a[] = {1};
    
    printf("PUSH \n");
    int *auxPUSH = &a[0];
    printf("aux = %x \n",auxPUSH);
    auxPUSH++;
    printf("aux = %x \n",auxPUSH);
    *auxPUSH = 0;
    
    printf("POP \n");
    int *auxPOP = &a[0];
    printf("aux = %x \n",auxPOP);
    auxPOP--;
    printf("aux = %x \n",auxPOP);
    *auxPOP = 0;

    
    
    
    
    
    
    
    
    
    
    return 0;
}
