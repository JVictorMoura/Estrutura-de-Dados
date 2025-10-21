// Lista (A, B, C, D)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
    int Chave;
    struct Item *Proximo;

} Item;

int main()
{
    Item *A = (Item *)malloc(sizeof(Item));
    Item *B = (Item *)malloc(sizeof(Item));
    Item *C = (Item *)malloc(sizeof(Item));
    Item *D = (Item *)malloc(sizeof(Item));

    A->Chave = 17;
    A->Proximo = NULL; // linha será substituida

    B->Chave = 29;
    B->Proximo = NULL; // linha será substituida

    C->Chave = 41;
    C->Proximo = NULL; // linha será substituida

    D->Chave = 97;
    D->Proximo = NULL; // linha será substituida

    // printf("%X\t%d\n", A, A->Chave);
    // printf("%X\t%d\n", B, B->Chave);
    // printf("%X\t%d\n", C, C->Chave);
    // printf("%X\t%d\n", D, D->Chave);
    // Encadeamento (A, C, B, D)

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = NULL;

    // printf("%d\n", A->Chave);// 17
    // printf("%d\n", A->Proximo->Chave); // 29
    // printf("%d\n", A->Proximo->Proximo->Chave); // 41
    // printf("%d\n", A->Proximo->Proximo->Proximo->Chave); // 97
    // printf("%d\n", A->Proximo->Proximo->Proximo->Proximo->Chave); // NULL

    // percorrendo a lista

    Item *X = A;
    // printf("%X\t  %d\n", X, X->Chave);

    // Estrutura de repeticao para percorrer a lista
    //  for (int i = 0; X->Proximo != NULL; i++)
    for (  ; X != NULL; X = X->Proximo)
    {
        if (X == NULL)
            printf("cabo\n");
        printf("%X\t  %d\n", X, X->Chave);
    }

    return 0;
} // linha será substituida
