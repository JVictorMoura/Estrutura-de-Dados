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
    A->Proximo = NULL;

    B->Chave = 29;
    B->Proximo = NULL;

    C->Chave = 41;
    C->Proximo = NULL;

    D->Chave = 97;
    D->Proximo = NULL;

    printf("%X\t%d\n", A, A->Chave);
    printf("%X\t%d\n", B, B->Chave);
    printf("%X\t%d\n", C, C->Chave);
    printf("%X\t%d\n", D, D->Chave);

    // Encadeamento (A, C, B, D)

    A->Proximo = C;
    B->Proximo = D;
    C->Proximo = B;
    D->Proximo = NULL;

    printf("%d\n", A->Chave);// 17
    printf("%d\n", A->Proximo->Chave); // 41
    printf("%d\n", A->Proximo->Proximo->Chave); // 29
    printf("%d\n", A->Proximo->Proximo->Proximo->Chave); // 97
    printf("%d\n", A->Proximo->Proximo->Proximo->Proximo->Chave); // NULL

    return 0;
}