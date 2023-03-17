#include <stdio.h>
#include <stdlib.h>
#include "mobilidade.h"

// Função para listar as mobilidades

void listarMobilidade(Mobilidade* mobilidade) {
	printf("****************************************************************************\n");
	printf("*                             LISTA DE MOBILIDADE                          *\n");
	printf("****************************************************************************\n\n");

	while (mobilidade != NULL)
	{
		printf("ID: %d    Tipo de Mobilidade: %s    Nível de Bateria: %.2f   Autonomia: %.2f\n", mobilidade->idMobilidade, mobilidade->tipo, mobilidade->nivel_bateria, mobilidade->autonomia);
		mobilidade = mobilidade->seguinte;
	}
	printf("\n****************************************************************************\n");
}

// Função para criar um novo registo de uma nova Mobilidade

Mobilidade* inserirMobilidade(Mobilidade* mobilidade, int idMobilidade, char tipo[], float nivel_bateria, float autonomia) {

	if (!existeMobilidade(mobilidade, idMobilidade))
	{
		Mobilidade* novo = malloc(sizeof(struct mobilidade));

		if (novo != NULL)
		{
			novo->idMobilidade = idMobilidade;
			strcpy(novo->tipo, tipo);
			novo->nivel_bateria = nivel_bateria;
			novo->autonomia = autonomia;
			novo->seguinte = mobilidade;
			return(novo);
		}
		else
		{
			return(mobilidade);
		}
	}

	
}

// Função para verificar se um registo de uma mobilidade já existe pelo seu ID

int existeMobilidade(Mobilidade* mobilidade, int idMobilidade) {

	Mobilidade* novo = (Mobilidade*)malloc(sizeof(Mobilidade));

	if (novo != NULL)
	{
		novo->idMobilidade = idMobilidade;
		strcpy(novo->tipo, tipo);
		novo->nivel_bateria = nivel_bateria;
		novo->autonomia = autonomia;
		novo->seguinte = mobilidade;
		return(novo);
	}
	else
	{
		return(mobilidade);
	}
}

// Função para remover um registo de uma mobilidade pelo ID

Mobilidade* removerMobilidade(Mobilidade* mobilidade, int idMobilidade) {

	Mobilidade* anterior = mobilidade, * atual = mobilidade, * aux;

	if (atual == NULL)
	{
		return NULL;
	}
	else
	{
		if (atual->idMobilidade == idMobilidade)
		{
			aux = atual->seguinte;
			free(atual);
		}
		else
		{
			while ((atual != NULL) && (atual->idMobilidade != idMobilidade))
			{
				anterior = atual;
				atual = atual->seguinte;
			}
			if (atual == NULL)
			{
				return(mobilidade);
			}
			else
			{
				anterior->seguinte;
				free(atual);
				return(mobilidade);
			}
		}
	}
}

// Função para alterar um registo de uma mobilidade 

Mobilidade* alterarMobilidade(Mobilidade* mobilidade, int idMobilidade, char tipo[], float nivel_bateria, float autonomia) {

	Mobilidade* nodoAtual = mobilidade;
	Mobilidade* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->idMobilidade != idMobilidade)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		nodoAtual->idMobilidade = idMobilidade;
		strcpy(nodoAtual->tipo, tipo);
		nodoAtual->nivel_bateria = nivel_bateria;
		nodoAtual->autonomia = autonomia;
	}

	return(mobilidade);
}

// Função para apresentar uma lista com mobilidades por ordem decrescente de autonomia

void listarMobilidadesDESC(Mobilidade* mobilidade) {

	// Obter número de meios de mobilidades na lista
	int numMobilidade = 0;
	Mobilidade* nodoAtual = mobilidade;

	while (nodoAtual != NULL)
	{
		numMobilidade++;
		nodoAtual = nodoAtual->seguinte;
	}

	// Armazenar os dados dos meios de mobilidades em um vetor de estruturas
	Mobilidade* mobArray = malloc(numMobilidade * sizeof(Mobilidade));
	nodoAtual = mobilidade;

	for (int i = 0; i < numMobilidade; i++)
	{
		mobArray[i].idMobilidade = nodoAtual->idMobilidade;
		strcpy(mobArray[i].tipo, nodoAtual->tipo);
		mobArray[i].nivel_bateria = nodoAtual->nivel_bateria;
		mobArray[i].autonomia = nodoAtual->autonomia;
		nodoAtual = nodoAtual->seguinte;
	}

	// Ordenar o vetor de meios de mobilidades em ordem decrescente de autonomia

	for (int i = 0; i < numMobilidade; i++)
	{
		int max = i;
		for (int j = i + 1; j < numMobilidade; j++)
		{
			if (mobArray[j].autonomia > mobArray[max].autonomia)
			{
				max = j;
			}
		}

		Mobilidade temp = mobArray[i];
		mobArray[i] = mobArray[max];
		mobArray[max] = temp;
	}

	// Imprimir os dados dos meios de mobilidade na ordem do vetor ordenado
	for (int i = 0; i < numMobilidade; i++)
	{
		printf("ID: %d    Tipo de Mobilidade: %s    Nível de Bateria: %.2f   Autonomia: %.2f\n", mobArray[i].idMobilidade, mobArray[i].tipo, mobArray[i].nivel_bateria, mobArray[i].autonomia);
		printf("\n****************************************************************************\n");
	}
	free(mobArray);
}