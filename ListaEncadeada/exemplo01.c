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
    Item *I = (Item *)malloc(sizeof(Item));

    I->Chave = 17;
    I->Proximo = NULL;

    printf("%X\t%d\n", I, I->Chave);
    printf("%X\n", I->Proximo);


    return 0;
}