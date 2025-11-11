#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

typedef struct
{
	int pos;
	char nome[256];
} cidadeInfo;

int comparar(const void *a, const void *b)
{
	const cidadeInfo *c1 = (const cidadeInfo *)a;
	const cidadeInfo *c2 = (const cidadeInfo *)b;
	if (c1->pos < c2->pos)
		return -1;
	if (c1->pos > c2->pos)
		return 1;
	return 0;
}

static void liberarEstrada(Estrada *e)//"encapsulamento" com static
{ 
	if (!e)
		return;
	Cidade *atual = e->Inicio;
	while (atual)
	{
		Cidade *prox = atual->Proximo;
		free(atual);
		atual = prox;
	}
	free(e);
}

Estrada *getEstrada(const char *nomeArquivo)
{
	FILE *f = fopen(nomeArquivo, "r");
	if (!f)
		return NULL;

	Estrada *e = malloc(sizeof(Estrada));
	if (!e)
	{
		fclose(f);
		return NULL;
	}

	if (fscanf(f, "%d", &e->T) != 1 || fscanf(f, "%d", &e->N) != 1)
	{
		fclose(f);
		free(e);
		return NULL;
	}

	if (e->T < 3 || e->T > 1000000 || e->N < 2 || e->N > 10000)
	{
		fclose(f);
		free(e);
		return NULL;
	}

	cidadeInfo *temp = malloc(sizeof(cidadeInfo) * e->N);
	if (!temp)
	{
		fclose(f);
		free(e);
		return NULL;
	}

	for (int i = 0; i < e->N; i++)
	{
		if (fscanf(f, "%d %255[^\n]", &temp[i].pos, temp[i].nome) != 2)
		{
			free(temp);
			fclose(f);
			free(e);
			return NULL;
		}

		if (temp[i].pos <= 0 || temp[i].pos >= e->T)
		{
			free(temp);
			fclose(f);
			free(e);
			return NULL;
		}

		for (int j = 0; j < i; j++)
		{
			if (temp[j].pos == temp[i].pos)
			{
				free(temp);
				fclose(f);
				free(e);
				return NULL;
			}
		}
	}

	fclose(f);
	qsort(temp, e->N, sizeof(cidadeInfo), comparar);

	e->Inicio = NULL;
	Cidade *ultima = NULL;

	for (int i = 0; i < e->N; i++)
	{
		Cidade *nova = malloc(sizeof(Cidade));
		if (!nova)
		{
			liberarEstrada(e);
			free(temp);
			return NULL;
		}

		strcpy(nova->Nome, temp[i].nome);
		nova->Posicao = temp[i].pos;
		nova->Proximo = NULL;

		if (!e->Inicio)
			e->Inicio = nova;
		else
			ultima->Proximo = nova;

		ultima = nova;
	}
	free(temp);
	return e;
}

double calcularMenorVizinhanca(const char *nomeArquivo)
{
	Estrada *e = getEstrada(nomeArquivo);
	if (!e)
		return -1.0;
	int N = e->N;
	int T = e->T;
	int *pos = malloc(sizeof(int) * N);
	double *vizinhas = malloc(sizeof(double) * N);
	if (!pos || !vizinhas)
	{
		liberarEstrada(e);
		free(pos);
		free(vizinhas);
		return -1.0;
	}

	Cidade *atual = e->Inicio;
	for (int i = 0; i < N; i++)
	{
		pos[i] = atual->Posicao;
		atual = atual->Proximo;
	}

	for (int i = 0; i < N; i++)
	{
		double limiteEsq = (i == 0) ? 0 : (pos[i - 1] + pos[i]) / 2.0;
		double limiteDir = (i == N - 1) ? T : (pos[i] + pos[i + 1]) / 2.0;
		vizinhas[i] = limiteDir - limiteEsq;
	}

	double menor = vizinhas[0];
	for (int i = 1; i < N; i++)
	{
		if (vizinhas[i] < menor)
			menor = vizinhas[i];
	}

	free(pos);
	free(vizinhas);
	liberarEstrada(e);
	return menor;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo)
{
	Estrada *e = getEstrada(nomeArquivo);
	if (!e)
		return NULL;

	int N = e->N;
	int T = e->T;

	int *pos = malloc(sizeof(int) * N);
	double *vizinhas = malloc(sizeof(double) * N);
	char **nomes = malloc(sizeof(char *) * N);

	if (!pos || !vizinhas || !nomes)
	{
		liberarEstrada(e);
		free(pos);
		free(vizinhas);
		free(nomes);
		return NULL;
	}

	Cidade *atual = e->Inicio;
	for (int i = 0; i < N; i++)
	{
		pos[i] = atual->Posicao;
		nomes[i] = strdup(atual->Nome);
		atual = atual->Proximo;
	}

	for (int i = 0; i < N; i++)
	{
		double limiteEsq = (i == 0) ? 0 : (pos[i - 1] + pos[i]) / 2.0;
		double limiteDir = (i == N - 1) ? T : (pos[i] + pos[i + 1]) / 2.0;
		vizinhas[i] = limiteDir - limiteEsq;
	}

	int indiceMenor = 0;

	for (int i = 1; i < N; i++)
	{
		if (vizinhas[i] < vizinhas[indiceMenor])
			indiceMenor = i;
	}

	char *resultado = malloc(strlen(nomes[indiceMenor]) + 1);
	strcpy(resultado, nomes[indiceMenor]);

	for (int i = 0; i < N; i++)
		free(nomes[i]);

	free(pos);
	free(vizinhas);
	free(nomes);
	liberarEstrada(e);

	return resultado;
}
