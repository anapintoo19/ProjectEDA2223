#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


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
				printf("\tnão existe Mobilidades Associadas\n\n");
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
						printf("\tID: %d   Tipo de Mobilidade: %s   Bateria: %.2f   Autonomia: %.2f\n", mobAux->idMobilidade, mobAux->tipo, mobAux->nivel_bateria, mobAux->autonomia);
					}
					climobAux = climobAux->seguinte;
				}
			}
			
		cliente = climobAux->seguinte;
		
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

Cliente* inserirCliente(Cliente* cliente, int idCliente, char nomeCliente[], char moradaCliente[], int nifCliente, float saldo) {

	if (!existeCliente(cliente, nifCliente))
	{
		Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
		if (novo != NULL) 
		{
			novo->idCliente = idCliente;
			strcpy_s(novo->nomeCliente, nomeCliente);
			strcpy_s(novo->moradaCliente, moradaCliente);
			novo->nifCliente = nifCliente;
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

	Cliente* anterior = cliente, * atual = cliente, * aux;

	if (atual == NULL)
	{
		return NULL;
	}
	else
	{
		if (atual->nifCliente == nifCliente)
		{
			aux = atual->seguinte;
			free(atual);
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
		strcpy_s(nodoAtual->nomeCliente, nomeNovo);
		strcpy_s(nodoAtual->moradaCliente, moradaNovo);
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

Cliente* desassociarMobilidade(Cliente* cliente, int idCliente, int idMob) {

}
