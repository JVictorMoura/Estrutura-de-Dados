#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int Chave;
    struct Item * Proximo;

} Item;

int main() {

    system("cls");

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

    A->Chave = 17; 
    A->Proximo = NULL;
    
    B->Chave = 29; 
    B->Proximo = NULL;
    
    C->Chave = 41; 
    C->Proximo = NULL;
    
    D->Chave = 97; 
    D->Proximo = NULL;

    // Construindo a lista A -> B -> C -> D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;

    // Percorrento a lista encadeada

    Item * Temp = A;

    printf("\nOpção 01: for com variável inteira: ");

    for (int i = 0; i < 4; i++) {
        printf("%d\t", Temp->Chave);
        Temp = Temp->Proximo; 
    }

    Temp = A;

    printf("\nOpção 02: for controlado pelo ponteiro Temp: ");

    for ( ; Temp != NULL; Temp = Temp->Proximo) {
        printf("%d\t", Temp->Chave);
    }

    Temp = A;

    printf("\nOpção 03: usando while ");

    while(Temp != NULL) {
        printf("%d\t", Temp->Chave);
        Temp = Temp->Proximo;
    }



}