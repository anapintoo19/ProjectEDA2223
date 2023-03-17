#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestor.h"

// Função para Listar todas os gestores
void listarGestores(Gestor* gestor)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE GESTOR                              *\n");
	printf("****************************************************************************\n\n");
	while (gestor != NULL)
	{
		printf(" ID: %d     Nome: %s     Password: %s\n", gestor->idGestor, gestor->nomeGestor, gestor->password);
		gestor = gestor->seguinte;
	}
	printf("\n****************************************************************************\n");
}

// Função para Criar um Novo Registo de um novo gestor (inserção de um novo gestor)
Gestor* inserirGestor(Gestor* gestor, int idGestor, char nomeGestor[], char password[]) {

	if (!existeGestor(gestor, idGestor))
	{
		Gestor* novo = (Gestor*)malloc(sizeof(Gestor));

		if (novo != NULL) {
			novo->idGestor = idGestor;
			strcpy(novo->nomeGestor, nomeGestor);
			strcpy(novo->password, password);
			novo->seguinte = gestor;

			return(novo);
		}
		else {
			return(gestor);
		}
	}
}

// Função para verificar se um registo de um gestor já existe pelo ID

int existeGestor(Gestor* gestor, int idGestor) {

	while (gestor != NULL)
	{
		if (gestor->idGestor == idGestor)
		{
			return(1);
			gestor = gestor->seguinte;
		}
		return(0);
	}
}

// Função para remover um registo de um gestor pelo seu ID

Gestor* removerGestor(Gestor* gestor, int idGestor) {

	Gestor* anterior = gestor, * atual = gestor, * aux;

	if (atual == NULL)
	{
		return NULL;
	}
	else
	{
		if (atual->idGestor == idGestor)
		{
			aux = atual->seguinte;
			free(atual);
		}
		else
		{
			while ((atual != NULL) && (atual->idGestor != idGestor))
			{
				anterior = atual;
				atual = atual->seguinte;
			}

			if (atual == NULL)
			{
				return(gestor);
			}
			else
			{
				anterior->seguinte = atual->seguinte;
				free(atual);
				return(gestor);
			}
		}
	}
}

// Função para alterar um registo de um gestor pelo seu ID

Gestor* alterarGestor(Gestor* gestor, int idGestor, char nomeGestorNovo[], char passwordNova[]) {

	Gestor* nodoAtual = gestor;
	Gestor* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->idGestor != idGestor)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		strcpy(nodoAtual->nomeGestor, nomeGestorNovo);
		strcpy(nodoAtual->password, passwordNova);
	}

	return(gestor);
}