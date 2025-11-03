#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int Chave;
    struct Item * Proximo;

} Item;

Item * CriarItem(int Chave); // Criar item a partir de uma chave
void ExibirLista(Item * Inicio, int N); // Exibir os N primeiros elementos da lista

int main() {

    system("cls");

    Item * A = CriarItem(17);
    Item * B = CriarItem(29);
    Item * C = CriarItem(41);
    Item * D = CriarItem(97);

    // Construindo a lista A -> B -> C -> D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = A;

    // Lista (encadeada) CIRCULAR: O último elemento deve apontar para o início

    ExibirLista(A, 100);

}

Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc(sizeof(Item));
    I->Chave = Chave;
    I->Proximo = NULL;

    return I;

}

void ExibirLista(Item * Inicio, int N) {

    Item * Temp = Inicio;

    for (int i = 0; i < N; i++) {
        printf("%d\t", Temp->Chave);
        Temp = Temp->Proximo; 
    }

}
