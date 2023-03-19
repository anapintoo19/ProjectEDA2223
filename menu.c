#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "menu.h"


#pragma warning(disable : 4996)

#define MAXNAME 50

void flushstdin(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

#pragma region MENUS

void mostrarMenu() {
	printf("***********************************\n");
	printf("*             MENU                *\n");
	printf("***********************************\n");
	printf("* 1. Cliente                      *\n");
	printf("* 2. Gestor                       *\n");
	printf("* 3. Mobilidade                   *\n");
	printf("* 4. Exportar Dados               *\n");
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
	printf("* 5. Associar Mobilidade          *\n");
	printf("* 6. Desassociar Mobilidade       *\n");
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
	printf("* 5. Listar Mobilidade Ordem DESC *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opcao: ");
}

#pragma endregion

#pragma region CLIENTE

// Função para criar um cliente

Cliente* criaCliente(Cliente* cliente) {

	int nifCliente;
	int idCliente = 0;
	char nomeCliente[MAXNAME];
	char moradaCliente[MAXNAME];
	float saldo = 0.0;
	

	printf("NIF do Cliente: \n");
	scanf("%d", &nifCliente);

	Cliente* cliAux = cliente;

	while (cliAux != NULL && (cliAux->nifCliente != nifCliente))
	{
		cliAux = cliAux->seguinte;
	}

	if (cliAux != NULL)
	{
		printf("\nJá existe um cliente com o ID '%d'\n", nifCliente);

	}
	else
	{
		printf("\nID do cliente: \n");
		scanf("%d", &idCliente);

		printf("\nNome do cliente: \n");
		flushstdin();
		scanf("%s", &nomeCliente);

		printf("\nMorada: \n");
		flushstdin();
		scanf("%s", &moradaCliente);

		printf("\nSaldo: \n");
		flushstdin();
		scanf("%f", &saldo);

	}

	return inserirCliente(cliente, nifCliente, idCliente, nomeCliente, moradaCliente, saldo);


}

// Função remover cliente

Cliente* removeCliente(Cliente* cliente) {

	int nifCliente;

	listarsomenteClientes(cliente);

	printf("NIF do Cliente que pretende remover: ");
	scanf("%d", &nifCliente);

	return removerCliente(cliente, nifCliente);
}

// Função para edita um cliente

Cliente* editaCliente(Cliente* cliente) {
	
	int idCliente;
	char newName[50];
	char newHousehold[50];
	int newNIF;
	float newSaldo;

	listarsomenteClientes(cliente);

	printf("ID do Cliente que pretende editar: ");
	scanf("%d", &idCliente);

	printf("Novo Nome do Cliente: ");
	scanf("%s", &newName);

	printf("Nova Morada do Cliente: ");
	scanf("%s", &newHousehold);

	printf("Novo NIF do Cliente: ");
	scanf("%d", &newNIF);

	printf("Novo Saldo do Cliente: ");
	scanf("%.2f", &newSaldo);

	return alterarCliente(cliente, idCliente, newName, newHousehold, newNIF, newSaldo);
}

// Associar uma determinada mobilidade a um cliente

Cliente* associaMobilidade(Cliente* cliente, Mobilidade* mobilidade) {
	int idCliente = 0, idMobilidade = 0, found = 0;

	do
	{
		listarClientes(cliente, mobilidade);

		printf("NIF do Cliente: ");
		scanf("%d", &idCliente);

		Cliente* cliAux = cliente;
		
		while (cliAux != NULL && cliAux->nifCliente != idCliente)
		{
			cliAux = cliAux->seguinte;
		}

		if (cliAux == NULL)
		{
			idCliente = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idCliente == 0);

	system("cls");

	do
	{
		printf("ID do Cliente: %d\n", idCliente);

		listarMobilidade(mobilidade);

		printf("ID da Mobilidade Para Associar: ");
		scanf("%d", &idMobilidade);

		Mobilidade* mobAux = mobilidade;

		while (mobAux != NULL && mobAux->idMobilidade != idMobilidade)
		{
			mobAux = mobAux->seguinte;
		}
		if (mobAux == NULL)
		{
			idMobilidade = 0;
			system("cls");
			printf("Escolha invalida\n");
			system("pause");
			system("cls");
		}
	} while (idMobilidade == 0);

	// Verificar se existe mobilidade já associadas

	Cliente* cliAux = cliente;

	while (cliAux != NULL)
	{
		ClienteMobilidade* CliMobAux = cliAux->mobilidadeAlugada;

		while (CliMobAux != NULL)
		{
			if (CliMobAux->nifCliente == idCliente && CliMobAux->id == idMobilidade)
			{
				found = 1;
			}
			CliMobAux = CliMobAux->seguinte;
		}
		cliAux = cliAux->seguinte;
	}

	if (found == 1)
	{
		printf("\n\n A Mobilidade '%d' já está associada a um Cliente '%d'\n", idMobilidade, idCliente);
		return cliente;
	}

	return associarMobilidade(cliente, idCliente, idMobilidade);
	
}

// Desassociar Mobilidades

Cliente* desassociaMobilidade(Cliente* cliente, Mobilidade* mobilidade) {
	int idCliente = 0, idMobilidade = 0, found = 0;

	do
	{
		listarClientes(cliente, mobilidade);

		printf("NIF do Cliente: ");
		scanf("%d", &idCliente);

		Cliente* cliAux = cliente;

		while (cliAux != NULL && cliAux->nifCliente != idCliente)
		{
			cliAux = cliAux->seguinte;
		}

		if (cliAux == NULL) {
			idCliente = 0;
			system("cls");
			printf("Escolha invalida\n");
			system("pause");
			system("cls");
		}
	} while (idCliente == 0);

	system("cls");

	do
	{
		printf("ID do Cliente: %d\n", idCliente);

		listarMobilidade(mobilidade);

		printf("ID da Mobilidade Para Desassociar: ");
		scanf("%d", &idMobilidade);

		Mobilidade* mobAux = mobilidade;

		while (mobAux != NULL && mobAux->idMobilidade != idMobilidade)
		{
			mobAux = mobAux->seguinte;
		}

		if (mobAux == NULL) {
			idMobilidade = 0;
			system("cls");
			printf("Escolha invalida\n");
			system("pause");
			system("cls");
		}

	} while (idMobilidade == 0);

	// Verificar se existe mobilidades já não associadas

	Cliente* cliAux = cliente;

	while (cliAux != NULL)
	{
		ClienteMobilidade* CliMobAux = cliAux->mobilidadeAlugada;

		while (CliMobAux != NULL)
		{
			if (CliMobAux->nifCliente == idCliente && CliMobAux->id == idMobilidade)
			{
				found = 1;
			}
			CliMobAux = CliMobAux->seguinte;
		}
		cliAux = cliAux->seguinte;
	}

	if (found == 1)
	{
		return desassociarMobilidade(cliente, idCliente, idMobilidade);
	}
	else
	{
		printf("\n\nA Mobilidade '%d' não está associada a Cliente '%d'\n", idMobilidade, idCliente);
		return cliente;
	}
}

#pragma endregion

#pragma region GESTOR

// Função para cria um gestor

Gestor* criaGestor(Gestor* gestor) {
	int idGestor;
	char nomeGestor[MAXNAME];
	char password[MAXNAME];
	
	printf("ID do gestor: ");
	scanf("%d", &idGestor);

	Gestor* gesAux = gestor;

	while (gesAux != NULL && (gesAux->idGestor != idGestor))
	{
		gesAux = gesAux->seguinte;
	}

	if (gesAux != NULL)
	{
		printf("\nJá existe um Gestor com o ID '%d'\n", idGestor);
	}
	else
	{
		printf("Nome do gestor: ");
		scanf("%s", &nomeGestor);

		printf("Insira a password: ");
		flushstdin();
		scanf("%s", &password);
	}

	return inserirGestor(gestor, idGestor, nomeGestor, password);

}

// Função de remover um gestor

Gestor* removeGestor(Gestor* gestor) {
	int idGestor;

	listarGestores(gestor);

	printf("ID do gestor que pretende remover: ");
	scanf("%d", &idGestor);

	return removerGestor(gestor, idGestor);
}

// Função para edita um gestor

Gestor* editaGestor(Gestor* gestor) {
	
	char novoNomeGestor[MAXNAME];
	char novaPassword[MAXNAME];
	int idGestor;

	listarGestores(gestor);

	printf("ID do Gestor que prentende editar: ");
	scanf("%d", &idGestor);

	printf("Novo Nome do Gestor: ");
	scanf("%s", &novoNomeGestor);

	printf("Nova Password do Gestor: ");
	flushstdin();
	scanf("%s", &novaPassword);

	return alterarGestor(gestor, idGestor, novoNomeGestor, novaPassword);
}

#pragma endregion

#pragma region MOBILIDADE

// Função para inserir uma mobilidade

Mobilidade* criaMobilidade(Mobilidade* mobilidade) {
	int idMobilidade;
	char tipo[40];
	float nivel_bateria;
	float autonomia; 

	printf("ID da Mobilidade: ");
	scanf("%d", &idMobilidade);

	Mobilidade* mobAux = mobilidade;

	while (mobAux != NULL && (mobAux->idMobilidade != idMobilidade))
	{
		mobAux = mobAux->seguinte;
	}

	if (mobAux != NULL)
	{
		printf("\nJá existe uma Mobilidade com o id '%d'\n", idMobilidade);
		return mobilidade;
	}
	else
	{
		printf("Tipo de Mobilidade: ");
		scanf("%s", tipo);

		printf("Nível da Bateria: ");
		flushstdin();
		scanf("%.2f", &nivel_bateria);

		printf("Autonomia: ");
		flushstdin();
		scanf("%.2f", &autonomia);
	}

	return inserirMobilidade(mobilidade, idMobilidade, tipo, nivel_bateria, autonomia);
}

// Função para remover uma mobilidade

Mobilidade* removeMobilidade(Mobilidade* mobilidade) {
	int idMobilidade;

	listarMobilidade(mobilidade);

	printf("ID da mobilidade que pretende remover: ");
	scanf("%d", &idMobilidade);

	return removerMobilidade(mobilidade, idMobilidade);
}

// Função para edita uma mobilidade

Mobilidade* editaMobilidade(Mobilidade* mobilidade) {
	
	char novoTipo[MAXNAME];
	int novaBateria;
	int novaAutonomia;
	int idMobilidade;

	listarMobilidade(mobilidade);

	printf("ID da Mobilidade que pretende Editar: ");
	scanf("%d", &idMobilidade);

	printf("Novo Tipo de Mobilidade: ");
	scanf("%s", &novoTipo);

	printf("Percentagem da Bateria da nova Mobilidade: ");
	flushstdin();
	scanf("%d", &novaBateria);

	printf("Percentagem da Autonomia da nova Mobilidade:");
	flushstdin();
	scanf("%d", &novaAutonomia);

	return alterarMobilidade(mobilidade, idMobilidade, novoTipo, novaBateria, novaAutonomia);
}

#pragma endregion