//
//  BinaryGap.c
//  C_Pratica_Aug2018
//
//  Created by Luís Neto on 02/08/18.
//  Copyright © 2018 Luís Neto. All rights reserved.
//

#include <stdio.h>


int solution(int N);


int main(void){
    
    int op;
    int numTest = 0x00010010;
    printf("numTest= %d \n \n", numTest);
    
    op = solution(numTest);
    
    printf("resposta= %d \n", op);
    
}

int solution(int N) {
    
    //Usar uma mascara, verificar bit a bit se é um 1 ou um 0
    //se for um zero consecutivo incrementa o contador
    
    int mask = 0x00000001;
    int resultado = 0;
    int loop = 0;
    
    int estado = 3;
    // estado 0: na ultima it. encontrou '0'
    // estado 1: na ultima it. encontrou '1'
    // estado 3: primeira it.
    
    while (mask > 0){
        
        if((mask & N) != 0)
        {
            //printf("Encontrou um 1");
            // int test = mask & N;
            //printf("test = %d \n", test);
            if(estado != 1){
                estado = 1;
                if(loop > resultado){
                    resultado = loop;
                }
            }
            loop = 0;
        }
        else { // '0'
            if(estado == 3); // nothing
            else {
                estado = 0;
                loop++;
            }
        }
        mask = mask << 1;
    }
    return resultado;
}

