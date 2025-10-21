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
    Item *X = (Item *)malloc(sizeof(Item));

    A->Chave = 17;
    A->Proximo = NULL;//linha será substituida

    B->Chave = 29;
    B->Proximo = NULL;//linha será substituida

    C->Chave = 41;
    C->Proximo = NULL;//linha será substituida

    D->Chave = 97;
    D->Proximo = NULL;//linha será substituida

    X->Chave = 79;
    X->Proximo = NULL;//linha será substituida



    // printf("%X\t%d\n", A, A->Chave);
    // printf("%X\t%d\n", B, B->Chave);
    // printf("%X\t%d\n", C, C->Chave);
    // printf("%X\t%d\n", D, D->Chave);
    // Encadeamento (A, C, B, D)

    X->Proximo = A;
    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = NULL;

    printf("%d\n", A->Chave);// 17
    printf("%d\n", A->Proximo->Chave); // 29
    printf("%d\n", A->Proximo->Proximo->Chave); // 41
    printf("%d\n", A->Proximo->Proximo->Proximo->Chave); // 97
    printf("%d\n", A->Proximo->Proximo->Proximo->Proximo->Chave); // NULL

    return 0;
}//linha será substituida