#include <stdio.h>
#include <stdlib.h>
#include "mobilidade.h"
#pragma warning(disable : 4996)


#define MAXNOME 50

#pragma once

// Estrutura para representar um cliente

typedef struct cliente
{
    // Identificador �nico do cliente
    int idCliente; 
    // Nome do cliente
    char nomeCliente[MAXNOME];
    //Morada do cliente
    char moradaCliente[MAXNOME];
    //NIF do Cliente
    int nifCliente;
    // Saldo dispon�vel do cliente
    float saldo; 
    // Ponteiro para a estrutura do meio de mobilidade el�trica alugado pelo cliente que pode ser usada para armazenar informa��es cobre a mobilidade do cliente
    struct clientemobilidade* mobilidadeAlugada; 
    // Ponteiro para o pr�ximo cliente na lista
    struct cliente* seguinte;

} Cliente;

// Estrutura para representar uma mobilidade e um cliente

typedef struct clientemobilidade {

    // Nif do cliente
    int nifCliente;
    // ID da Mobilidade
    int id;
    // Apontador para o proximo clientemobilidade da lista
    struct clientemobilidade* seguinte;

}ClienteMobilidade;

//Declara��o das fun��es para os clientes

void listarClientes(Cliente* cliente, Mobilidade* mobilidade);
void listarsomenteClientes(Cliente* cliente);
int existeCliente(Cliente* cliente, int nifCliente);
Cliente* inserirCliente(Cliente* cliente, int nifCliente, int idCliente, char nomeCliente[], char moradaCliente[], float saldo);
Cliente* removerCliente(Cliente* cliente, int nifCliente);
Cliente* alterarCliente(Cliente* cliente, int nifCliente, char nomeNovo[], char moradaNovo[], float saldo);
Cliente* associarMobilidade(Cliente* cliente, int idCliente, int idMob);
Cliente* desassociarMobilidade(Cliente* cliente, int idCliente, int idMobilidade);