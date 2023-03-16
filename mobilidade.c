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
		printf("ID: %d    Tipo de Mobilidade: %s    Nível de Bateria: %.2f   Autonomia:%.2f  Mobilidade Alugada? %d", mobilidade->idMobilidade, mobilidade->tipo, mobilidade->nivel_bateria, mobilidade->autonomia);
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