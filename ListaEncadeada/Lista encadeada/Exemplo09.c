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

void ExcluirItem(Item * Inicio, int Posicao);
void InserirItem(Item * Inicio, Item * I, int Posicao);


int main() {

    system("cls");

    Lista * MinhaLista = (Lista *)malloc(sizeof(Lista));
    MinhaLista->Tamanho = 0;

    Item * A = CriarItem(17);
    Item * B = CriarItem(29);
    Item * C = CriarItem(41);
    Item * D = CriarItem(97);

    MinhaLista->Inicio = A;

    // Construindo a lista A -> B -> C -> D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = A;

    MinhaLista->Tamanho = 4;

    // Lista (encadeada) CIRCULAR: O último elemento deve apontar para o início

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

}
