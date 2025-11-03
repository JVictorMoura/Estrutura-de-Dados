#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int Chave;
    struct Item * Anterior;
    struct Item * Proximo;
    
} Item;

typedef struct {

    int Tamanho;
    Item * Inicio;

} Lista;

Item * CriarItem(int Chave); 
void ExibirLista(Lista * L); 

// Outras funções (...)


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

