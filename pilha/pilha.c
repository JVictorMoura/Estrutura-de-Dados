#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item *criarItem(int Chave)
{
    Item *I = (Item *)malloc(sizeof(Item));
    if (I == NULL)
    {
        printf("erro: Nao foi possivel alocar memoria para o item");
        return NULL;
    }
    I->Chave = Chave;
    I->Anterior = NULL;
    return I;
}
Pilha *criarPilha()
{
    Pilha *P = (Pilha *)malloc(sizeof(Pilha));
    if (P == NULL)
    {
        printf("erro: Nao foi possivel alocar memoria para o pilha");
        return NULL;
    }
    P->Tamanho = 0;
    P->Topo = NULL;

    return P;
}
void empilhar(Pilha *P, Item *I){
    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho++;
}
void desempilhar(Pilha *P){
    if (P->Tamanho == 0)
    {
        printf("erro");
        exit;
    }
    Item * I = P->Topo;
    P->Topo = I->Anterior;
    free(I);
    P->Tamanho--;
}
