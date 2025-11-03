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

    printf("%d\t", A->Chave);
    printf("%d\t", B->Chave);
    printf("%d\t", C->Chave);
    printf("%d\t", D->Chave);

    // Construindo a lista A -> C -> D -> B

    A->Proximo = C; // C está depois do A
    C->Proximo = D; // D está depois do C
    D->Proximo = B; // B está depois de D

    // O que será mostrado, na tela, a seguir?

    printf("\nTeste: ");
    printf("%d", A->Proximo->Proximo->Chave);

    


}