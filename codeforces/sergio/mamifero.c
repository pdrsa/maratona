#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char *nome;
    char *ordem;
    float peso;

} mamifero;

void animal_m(mamifero *mam)
{
    char *aux;
    float aux2;
    
	printf("nome do mamifero:");
    fgets(aux, 1000 ,stdin);
    strcpy(mam->nome, aux);
    
	printf("\nordem do mamifero:");
    fflush(stdin);
    fgets(aux, 1000 ,stdin);
    strcpy(mam->ordem, aux);

    printf("peso mamifero:");
    scanf("%f", &aux2);
    mam->peso = aux2;

	return;
}

void main()
{

    mamifero mami = malloc(sizeof mami);
    animal_m(&mami);

	// char *aux = mami.nome;
    // printf("\n %s",   mami.nome);
    // printf("\n %s",   mami.ordem);
    // printf("\n %.2f", mami.peso);

    system("pause");
}