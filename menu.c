#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"


#define MAXNAME 50

#pragma region MENUS

void mostrarMenu() {
	printf("***********************************\n");
	printf("*             MENU                *\n");
	printf("***********************************\n");
	printf("* 1. Cliente                      *\n");
	printf("* 2. Gestor                       *\n");
	printf("* 3. Mobilidade                   *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opcao: ");
}

void mostrarCliente() {
	printf("***********************************\n");
	printf("*             CLIENTE             *\n");
	printf("***********************************\n");
	printf("* 1. Listar Clientes              *\n");
	printf("* 2. Inserir Novo Cliente         *\n");
	printf("* 3. Remover Cliente              *\n");
	printf("* 4. Alterar Cliente              *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opcao: ");
}

void mostrarGestor() {
	printf("***********************************\n");
	printf("*             GESTOR              *\n");
	printf("***********************************\n");
	printf("* 1. Listar Gestores              *\n");
	printf("* 2. Inserir Novo Gestor          *\n");
	printf("* 3. Remover Gestor               *\n");
	printf("* 4. Alterar Gestor               *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opcao: ");
}

void mostrarMobilidade() {
	printf("***********************************\n");
	printf("*             MOBILIDADE          *\n");
	printf("***********************************\n");
	printf("* 1. Listar Mobilidades           *\n");
	printf("* 2. Inserir Nova Mobilidade      *\n");
	printf("* 3. Remover Mobilidade           *\n");
	printf("* 4. Alterar Mobilidade           *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opcao: ");
}

#pragma endregion

#pragma region CLIENTE

// Função para inserir um cliente

Cliente* criaCliente(Cliente* cliente) {
	int idCliente;
	char nomeCliente[MAXNAME];
	char moradaCliente[MAXNAME];
	int nifCliente;
	float saldo;
	Cliente* clientes = NULL;

	printf("ID do cliente: \n");
	scanf("%d", &idCliente);
	printf("Nome do cliente: \n");
	scanf("%s", &nomeCliente);
	printf("Morada:\n ");
	scanf("%s", &moradaCliente);
	printf("NIF: \n");
	scanf("%d", &nifCliente);
	printf("Saldo: \n");
	scanf("%.2f", &saldo);

	/*if (idCliente != NULL) {
		printf("\n\Já exite um cliente com o id '%d'\n", idCliente);
		return cliente;
	}*/

	return inserirCliente(cliente, idCliente, nomeCliente,  moradaCliente, nifCliente, saldo);

}

// Função remover cliente
Cliente* removeCliente(Cliente* cliente) {
	int idCliente = 0;

	listarClientes(cliente);

	printf("ID do Cliente que pretende remover: ");
	scanf("%d", &idCliente);

	return removeCliente(cliente, idCliente);
}

// Função para alterar um cliente
Cliente* alterarCliente(Cliente* cliente, int nifCliente, char nomeNovo[]) {
	Cliente* nodoAtual = cliente;
	Cliente* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->nifCliente != nifCliente) {
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL) {
		strcpy(nodoAtual->nomeCliente ,nomeNovo);
	}

	return(cliente);
}

#pragma endregion

#pragma region GESTOR

// Função para inserir um gestor

Gestor* criaGestor(Gestor* gestor) {
	int idGestor;
	char nomeGestor[MAXNAME];
	char password[MAXNAME];
	Gestor* gestores = NULL;

	printf("ID do gestor: ");
	scanf("%d", &idGestor);
	printf("Nome do gestor: ");
	scanf("%s", &nomeGestor);
	printf("Insira a password: ");
	scanf("%s", &password);

	if (idGestor != NULL) {
		printf("\n\Já existe um gestor com o nome '%s'\n", nomeGestor);
		return(gestor);
	}

	return inserirGestor(gestor, idGestor, nomeGestor, password);

}

// Função de remover um gestor

Gestor* removeGestor(Gestor* gestor) {
	int idGestor = 0;

	listarGestores(gestor);

	printf("ID do gestor que pretende remover: ");
	scanf("%d", &idGestor);

	return removeGestor(gestor, idGestor);
}

// Função para alterar um gestor

Gestor* alterarGestor(Gestor* gestor, int idGestor, char nomeNovo[]) {
	Gestor* nodoAtual = gestor;
	Gestor* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->idGestor != idGestor)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL) {
		strcpy(nodoAtual->nomeGestor, nomeNovo);
	}

	return(gestor);
}

#pragma endregion

#pragma region MOBILIDADE

// Função para inserir uma mobilidade

Mobilidade* criaMobilidade(Mobilidade* mobilidade) {
	int idMobilidade;
	char tipo[20];
	float nivel_bateria;
	float autonomia;
	int mobilidadeAlugada;
	Mobilidade* mobilidades = NULL;

	printf("ID da Mobilidade: ");
	scanf("%d", &idMobilidade);
	printf("Tipo de Mobilidade: ");
	scanf("%s", &tipo);
	printf("Nível da Bateria: ");
	scanf("%.2f", &nivel_bateria);
	printf("Autonomia: ");
	scanf("%.2f", &autonomia);
	printf("A Mobilidade é alugada? ");
	scanf("%d", &mobilidadeAlugada);

	if (idMobilidade != NULL)
	{
		printf("\n\Já existe uma mobilidade com o ID '%d'\n", idMobilidade);
		return(mobilidade);
	}

	return inserirMobilidade(mobilidade, idMobilidade, tipo, nivel_bateria, autonomia, mobilidadeAlugada);
}

// Função para remover uma mobilidade

Mobilidade* removeMobilidade(Mobilidade* mobilidade) {
	int idMobilidade = 0;

	listarMobilidade(mobilidade);

	printf("ID da mobilidade que pretende remover: ");
	scanf("%d", &idMobilidade);

	return removeMobilidade(mobilidade, idMobilidade);
}

// Função para alterar uma mobilidade

Mobilidade* alterarMobilidade(Mobilidade* mobilidade, char tipo[], int novoID) {
	Mobilidade* nodoAtual = mobilidade;
	Mobilidade* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->tipo != tipo) {
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		strcpy(nodoAtual->idMobilidade, novoID);
	}

	return(mobilidade);
}

#pragma endregion