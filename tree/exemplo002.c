#include <stdio.h>
#include <stdlib.h>
//arvore binaria
typedef struct No{

// char Chave;
int valor;
struct No* Esquerda;
struct No* Direita;
// struct No* F3;

}No;

No* criarNo (int a){//declarando o primeiro nó
    No * N = (No*) malloc(sizeof(No));//(No*) faz o malloc retornar um tipo No, nao necessario em C, so C++
    if (N == NULL)
    {
        printf("nao foi possivel criar o no");
        return NULL;
    }
    // N->Chave = Chave;
    N->valor = a;
    N->Esquerda = NULL;
    N->Direita = NULL;
    // N->F3 = NULL;

}





int main(){

// No* A = criarNo(10);
// No* B = criarNo(12);
// No* C = criarNo(15);
// No* D = criarNo(16);
// No* E = criarNo(18);
// No* F = criarNo(20);
// //nivel 1
// A->Direita=C;
// A->Esquerda=B;
// //nivel 2
// B->Esquerda=D;
// B->Direita=E;
// //nivel 3
// C->Direita=F;
// //nivel 1


No*Raiz = criarNo(10);
//nivel 2
Raiz->Esquerda=criarNo(12);
Raiz->Direita=criarNo(15);
//nivel 3
Raiz->Esquerda->Esquerda= criarNo(16);
Raiz->Esquerda->Direita= criarNo(18);


Raiz->Direita->Direita->Direita= criarNo(20);
}