#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int Chave;
    struct Item * Proximo;

} Item;

typedef struct {

    int Tamanho;
    Item * Inicio;

} Lista;

Item * CriarItem(int Chave); // Criar item a partir de uma chave
void ExibirLista(Lista * L); // Exibir os N primeiros elementos da lista

void InserirItem(Lista * L, Item * I, int Posicao);
void ExcluirItem(Lista * L, int Posicao);


int main() {

    system("cls");

    Lista * MinhaLista = (Lista *)malloc(sizeof(Lista));
    MinhaLista->Tamanho = 0;

    InserirItem(MinhaLista, CriarItem(17), 0);
    InserirItem(MinhaLista, CriarItem(29), 1);
    InserirItem(MinhaLista, CriarItem(41), 2);
    InserirItem(MinhaLista, CriarItem(97), 3);
    InserirItem(MinhaLista, CriarItem(60), 0);
    InserirItem(MinhaLista, CriarItem(99), 3);
    InserirItem(MinhaLista, CriarItem(33), 6);

    ExibirLista(MinhaLista);

    ExcluirItem(MinhaLista, 1);

    ExibirLista(MinhaLista);

}

Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc(sizeof(Item));
    I->Chave = Chave;
    I->Proximo = NULL;

    return I;

}

void ExibirLista(Lista * L) {

    Item * Temp = L->Inicio;

    for (int i = 0; i < L->Tamanho; i++) {
        printf("%d\t", Temp->Chave);
        Temp = Temp->Proximo; 
    }

    printf("\n");

}


void InserirItem(Lista * L, Item * I, int Posicao) {

    if (Posicao < 0 || Posicao > L->Tamanho) {
        printf("ERRO: não é possível inserir elemento na posição %d.\n", Posicao);
        return;
    }

    if (Posicao == 0) {
        I->Proximo = L->Inicio;
        L->Inicio = I;
    }
    else {

        Item * Temp = L->Inicio;
        
        for(int i = 0; i < Posicao - 1; i++) {
            Temp = Temp->Proximo;
        }

        I->Proximo = Temp->Proximo;
        Temp->Proximo = I;

    }

    L->Tamanho++;


}

// Melhorar esta função !!!!!

void ExcluirItem(Lista * L, int Posicao) {

    if (Posicao < 0 || Posicao >= L->Tamanho) {
        printf("ERRO: não é possível inserir elemento na posição %d.\n", Posicao);
        return;
    }

    if (Posicao == 0) {
        Item * Aux = L->Inicio;
        L->Inicio = L->Inicio->Proximo;
        free(Aux);
    }
    else {

        Item * Temp = L->Inicio;

        for(int i = 0; i < Posicao - 1; i++) Temp = Temp->Proximo;
            
        Item * Aux = Temp->Proximo;
        Temp->Proximo = Temp->Proximo->Proximo;
        free(Aux);

    }

    L->Tamanho--;

}