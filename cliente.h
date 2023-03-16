#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 50

#pragma once

// Estrutura para representar um cliente

typedef struct cliente
{
    // Identificador único do cliente
    int idCliente; 
    // Nome do cliente
    char nomeCliente[MAXNOME];
    //Morada do cliente
    char moradaCliente[MAXNOME];
    //NIF do Cliente
    int nifCliente;
    // Saldo disponível do cliente
    float saldo; 
    // Ponteiro para a estrutura do meio de mobilidade elétrica alugado pelo cliente que pode ser usada para armazenar informações cobre a mobilidade do cliente
    struct ClienteMobilidade* mobilidadeAlugada; 
    // Ponteiro para o próximo cliente na lista
    struct cliente* seguinte;

} Cliente;

typedef struct clientemobilidade {

    // Nif do cliente
    int nifCliente;
    // ID da Mobilidade
    int id;
    // Apontador para o proximo clientemobilidade da lista
    struct clientemobilidade* seguinte;

}ClienteMobilidade;

//Declaração das funções para os clientes

void listarClientes(Cliente* cliente);
Cliente* inserirCliente(Cliente* cliente, int idCliente, char nomeCliente[], char moradaCliente[], int nifCliente, float saldo);