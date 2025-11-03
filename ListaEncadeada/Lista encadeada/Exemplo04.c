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

    printf("%d\t", Temp->Chave); // 17 (1° elemento)

    Temp = Temp->Proximo; // Avança do 1° para 2° elemento

    printf("%d\t", Temp->Chave); // 29 (2° elemento)

    Temp = Temp->Proximo; // Avança do 2° para 3° elemento

    printf("%d\t", Temp->Chave); // 41 (3° elemento)

    Temp = Temp->Proximo; // Avança para o último elemento

    printf("%d\t", Temp->Chave); // 97

}