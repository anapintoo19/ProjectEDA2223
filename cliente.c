#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


// Função para Listar todas os clientes
void listarClientes(Cliente* cliente)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE CLIENTE                             *\n");
	printf("****************************************************************************\n\n");

	while (cliente != NULL) {
		
		printf("tetetete");

		cliente->seguinte;
	}


//	while (aux != NULL)
//	{
		

		/*Cliente* cliMob = cliente->mobilidadeAlugada;

		*/
	/*	if (cliMob == NULL)
		{
			printf("\tNao tem Mobiliddes Associadas\n\n");
		}
		else
		{
			while (cliMobAux != NULL)
			{
				Mobilidade* mobAux = mobilidade;

				while (mobAux != NULL && mobAux->id != cliMobAux->idMob)
				{
					mobAux = mobAux->next;
				}
				if (mobAux != NULL)
				{
					printf("\tID: %d   Tipo Mobilidade: %s     Bateria: %.2f     Autonomia: %.2f\n\n", mobAux->id, mobAux->tipo, mobAux->nivel_bateria, mobAux->autonomia);
				}
				cliMobAux = cliMobAux->next;
			}
		}*/
		//printf("%s ", cliente->nomeCliente);
//		aux = aux->seguinte;
	//}
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
		novo->mobilidadeAlugada = NULL;
		novo->seguinte = cliente;
		return(novo);
	}
	else {
		return(cliente);
	}
}
