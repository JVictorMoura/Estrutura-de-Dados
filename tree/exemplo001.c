#include <stdio.h>
#include <stdlib.h>

typedef struct No{

char Chave;
struct No* Esquerda;
struct No* Direita;
// struct No* F3;

}No;

No* criarNo (char Chave){//declarando o primeiro nó
    No * N = (No*) malloc(sizeof(No));
    if (N == NULL)
    {
        printf("nao foi possivel criar o no");
        return NULL;
    }
    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;
    // N->F3 = NULL;
}