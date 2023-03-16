#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


// Função para Listar todos os clientes e mobilidades elétricas que estejam associadas
void listarClientes(Cliente* cliente, Mobilidade* mobilidade)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE CLIENTE                             *\n");
	printf("****************************************************************************\n\n");

	while (cliente != NULL) {
		
		printf("ID cliente: %d   Nome: %s   Morada: %s   NIF: %d   Saldo: %.2f\n", cliente->idCliente, cliente->nomeCliente, cliente->moradaCliente, cliente->nifCliente, cliente->saldo);

		ClienteMobilidade* climobAux = cliente->mobilidadeAlugada
		
			if (climobAux == NULL)
			{
				printf("\tnão existe Mobilidades Associadas\n\n");
			}
			else
			{
				while (climobAux != NULL)
				{
					Mobilidade* mobAux = mobilidadeAlugada;

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
	printf("\n****************************************************************************\n");
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
	Cliente* novo = (Cliente*)malloc(sizeof(Cliente));

	if (novo != NULL) {
		novo->idCliente = idCliente;
		strcpy(novo->nomeCliente, nomeCliente);
		strcpy(novo->moradaCliente, moradaCliente);
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
