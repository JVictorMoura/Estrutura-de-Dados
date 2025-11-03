#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int Chave;
    struct Item * Proximo;

} Item;

int main() {

    Item * I = (Item *)malloc(sizeof(Item));

    // Observação: usa-se -> para acessar campos de ponteiros para struct
    
    I->Chave = 13;
    I->Proximo = NULL;

    // Alguns testes (printf)

    printf("Endereço (em hexadecimal): %X\n", I);
    printf("%d\n", I->Chave); // Mostrará 13 (Chave)
    printf("%d\n", I->Proximo); // Mostrará 0 (NULL)

}