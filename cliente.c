#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#pragma warning(disable : 4996)


// Função para Listar todos os clientes e mobilidades elétricas que estejam associadas
void listarClientes(Cliente* cliente, Mobilidade* mobilidade)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE CLIENTE                             *\n");
	printf("****************************************************************************\n\n");

	while (cliente != NULL) {
		
		printf("ID cliente: %d   Nome: %s   Morada: %s   NIF: %d   Saldo: %.2f\n", cliente->idCliente, cliente->nomeCliente, cliente->moradaCliente, cliente->nifCliente, cliente->saldo);

		ClienteMobilidade* climobAux = cliente->mobilidadeAlugada;
		
			if (climobAux == NULL)
			{
				printf("\tNão existe Mobilidades Associadas\n\n");
			}
			else
			{
				while (climobAux != NULL)
				{
					Mobilidade* mobAux = mobilidade;

					while (mobAux != NULL && mobAux->idMobilidade != climobAux->id)
					{
						mobAux = mobAux->seguinte;
					}
					if (mobAux != NULL)
					{
						printf("\tID: %d   Tipo de Mobilidade: %s   Bateria: %.2f   Autonomia: %.2f km\n", mobAux->idMobilidade, mobAux->tipo, mobAux->nivel_bateria, mobAux->autonomia);
					}
					climobAux = climobAux->seguinte;
				}
			}
			
		    cliente = cliente->seguinte;
		
	}
	printf("****************************************************************************\n\n");


}


// Função para listar somente os clientes

void listarsomenteClientes(Cliente* cliente) {

	printf("****************************************************************************\n");
	printf("*                             LISTA DE CLIENTE                             *\n");
	printf("****************************************************************************\n\n");

	while (cliente != NULL)
	{
		printf("ID cliente: %d   Nome: %s   Morada: %s   NIF: %d   Saldo: %.2f\n", cliente->idCliente, cliente->nomeCliente, cliente->moradaCliente, cliente->nifCliente, cliente->saldo);
	}

	printf("****************************************************************************\n\n");

}


// Função para Criar um Novo Registo de um novo cliente (inserção de um novo cliente)

Cliente* inserirCliente(Cliente* cliente, int nifCliente, int idCliente, char nomeCliente[], char moradaCliente[], float saldo) {

	if (!existeCliente(cliente, nifCliente))
	{
		Cliente* novo = (Cliente*)malloc(sizeof (Cliente));
		if (novo != NULL) 
		{
			novo->nifCliente = nifCliente;
			novo->idCliente = idCliente;
			strcpy(novo->nomeCliente, nomeCliente);
			strcpy(novo->moradaCliente, moradaCliente);
			novo->saldo = saldo;
			novo->mobilidadeAlugada = NULL;
			novo->seguinte = cliente;
			return(novo);
		}
		else {
			return(cliente);
		}
	}
}

// Função para Verificar se um registo de um cliente já existe pelo NIF

int existeCliente(Cliente* cliente, int nifCliente) {

	while (cliente != NULL)
	{
		if (cliente->nifCliente == nifCliente)
		{
			return(1);
			
		}
		cliente = cliente->seguinte;
		
	}
	return(0);
}

// Função para remover um registo de cliente pelo seu NIF
Cliente* removerCliente(Cliente* cliente, int nifCliente) {

	Cliente* anterior = cliente, *atual = cliente, *aux;

	if (atual == NULL)
	{
		return NULL;
	}
	else if (atual->nifCliente == nifCliente)
	{
		aux = atual->seguinte;
		free(atual);
		return aux;
	}
	else
	{
		while ((atual != NULL) && (atual->nifCliente != nifCliente))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL)
		{
			return(cliente);
		}
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(cliente);
		}
	}
}


// Função para alterar os dados de um determinado cliente através do seu NIF

Cliente* alterarCliente(Cliente* cliente, int idNovo, char nomeNovo[], char moradaNovo[], int nifCliente, float saldo) {

	Cliente* nodoAtual = cliente;
	Cliente* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->nifCliente != nifCliente)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		nodoAtual->idCliente = idNovo;
		strcpy(nodoAtual->nomeCliente, nomeNovo);
		strcpy(nodoAtual->moradaCliente, moradaNovo);
		nodoAtual->nifCliente = nifCliente;
		nodoAtual->saldo = saldo;
	}

	return(cliente);
}

// Função para associar uma mobilidade a um cliente

Cliente* associarMobilidade(Cliente* cliente, int idCliente, int idMob) { 

	Cliente* nodoAtual = cliente;
	Cliente* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual-> nifCliente != idCliente)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		ClienteMobilidade* nova = malloc(sizeof(struct clientemobilidade));
		nova->nifCliente = idCliente;
		nova->id = idMob;
		nova->seguinte = nodoAtual->mobilidadeAlugada;

		nodoAtual->mobilidadeAlugada = nova;
	}

	return cliente;
}

// Função para desassociar uma mobilidade a um cliente

Cliente* desassociarMobilidade(Cliente* cliente, int idCliente, int idMobilidade) {

	Cliente* nodoAtual = cliente;
	Cliente* nodoAnterior = NULL;
	ClienteMobilidade* mobilidadeAtual = NULL;
	ClienteMobilidade* mobilidadeAnterior = NULL;

	while (nodoAtual != NULL && nodoAtual->nifCliente != idCliente)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual == NULL) {
		return cliente;
	}

	mobilidadeAtual = nodoAtual->mobilidadeAlugada;

	while (mobilidadeAtual != NULL && mobilidadeAtual->id != idMobilidade) {
		mobilidadeAnterior = mobilidadeAtual;
		mobilidadeAtual = mobilidadeAtual->seguinte;
	}

	if (mobilidadeAtual == NULL) {
		return cliente;
	}

	if (mobilidadeAnterior == NULL) {
		nodoAtual->mobilidadeAlugada = mobilidadeAtual->seguinte;
	}
	else {
		mobilidadeAnterior->seguinte = mobilidadeAtual->seguinte;
	}

	free(mobilidadeAtual);

	return cliente;
}
