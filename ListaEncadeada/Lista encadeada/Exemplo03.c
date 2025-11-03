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
    
    // 1) A partir de A, como acessar o 2° elemento da lista?

    printf("Chave do 2° elemento: %d\n", A->Proximo->Chave);

    // 2) Qual o valor do "Proximo" do último elemento da lista?

    printf("Proximo do último elemento: %d\n", D->Proximo);

  


}