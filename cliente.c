#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


// Função para Listar todas os clientes
void listarClientes(Cliente* cliente)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE CLIENTE                             *\n");
	printf("****************************************************************************\n\n");
	while (cliente != NULL)
	{
		printf(" ID: %d     Nome: %s     Morada: %s      NIF: %d      Saldo:%.2f\n", cliente->idCliente, cliente->nomeCliente, cliente->moradaCliente, cliente->nifCliente, cliente->saldo);
		cliente = cliente->seguinte;
	}
	printf("\n****************************************************************************\n");
}

// Função para Criar um Novo Registo de um novo cliente (inserção de um novo cliente)
Cliente* inserirCliente(Cliente* cliente, int idCliente, char nomeCliente[], char moradaCliente[], int nifCliente, float saldo) {
	Cliente* novo = (Cliente*)malloc(sizeof(Cliente));

	if (novo != NULL) {
		novo->idCliente = idCliente;
		strcpy(novo->nomeCliente, nomeCliente);
		strcpy(novo->moradaCliente, moradaCliente);
		novo->nifCliente = nifCliente;
		novo->saldo = saldo;
		novo->seguinte = cliente;
		return(novo);
	}
	else {
		return(cliente);
	}
}
