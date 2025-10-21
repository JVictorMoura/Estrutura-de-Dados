#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Item{
int Chave; 
struct Item * Proximo;

}Item;

int main ()
{
Item * I = (Item*) malloc (sizeof(Item));

I->Chave = 23;
I->Proximo = NULL;
printf("Endereco (hexadecimal): %X\n", I);
printf("%d\n", I->Chave);
printf("%d\n", I->Proximo);




    return 0;
}