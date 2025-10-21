// Lista (A, B, C, D)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// para lista nao circular

typedef struct Item
{
    int Chave;
    struct Item *Proximo;
    struct Item *Anterior;

} Item;

Item *CriarItem(int Chave);
void ExibirLista(Item *Inicio);
void InserirItem(Item *Inicio, Item *I, int Posicao);
void ExcluirItem(Item *Inicio, int Posicao);

int main()
{
    Item *A = CriarItem(17);
    Item *B = CriarItem(29);
    Item *C = CriarItem(41);
    Item *P = CriarItem(67);
    Item *D = CriarItem(97);

    // A->Chave = 17;
    // A->Proximo = NULL; // linha será substituida

    // B->Chave = 29;
    // B->Proximo = NULL; // linha será substituida

    // C->Chave = 41;
    // C->Proximo = NULL; // linha será substituida

    // D->Chave = 97;
    // D->Proximo = NULL; // linha será substituida

    // printf("%X\t%d\n", A, A->Chave);
    // printf("%X\t%d\n", B, B->Chave);
    // printf("%X\t%d\n", C, C->Chave);
    // printf("%X\t%d\n", D, D->Chave);
    // Encadeamento (A, C, B, D)

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = P;
    P->Proximo = D;

    A->Proximo = C;//duas opcoes
    A->Proximo = B->Proximo; //excluindo elemento B
    free(B);//liberando memoria antes alocada
    // printf("%d\n", A->Chave);// 17
    // printf("%d\n", A->Proximo->Chave); // 29
    // printf("%d\n", A->Proximo->Proximo->Chave); // 41
    // printf("%d\n", A->Proximo->Proximo->Proximo->Chave); // 97
    // printf("%d\n", A->Proximo->Proximo->Proximo->Proximo->Chave); // NULL

    // percorrendo a lista

    // Item *X = A;
    //  printf("%X\t  %d\n", X, X->Chave);

    // Estrutura de repeticao para percorrer a lista
    //  for (int i = 0; X->Proximo != NULL; i++)
    // for (  ; X != NULL; X = X->Proximo)
    // {
    //     if (X == NULL)
    //         printf("cabo\n");
    //     printf("%X\t  %d\n", X, X->Chave);
    // }
    //   for ( int i = 0 ; i < 15; i++, X = X->Proximo)
    //     {
    //         if (X == NULL)
    //             printf("cabo\n");
    //         printf("%X\t  %d\n", X, X->Chave);
    //     }

    ExibirLista(A);

    return 0;
}

void ExibirLista(Item *Inicio)
{
    Item *X = Inicio;
    for (; X != NULL; X = X->Proximo)
    {
        if (X == NULL)
            printf("cabo\n");
        printf("%d\n", X->Chave);
    }
}

Item *CriarItem(int Chave)
{
    Item *X = (Item *)malloc(sizeof(Item));
    X->Chave = Chave;
    X->Proximo = NULL;
}

// free
//excluir um item da lista de uma posicao especifica, (usar X->Proximo(s) para faze-lo)