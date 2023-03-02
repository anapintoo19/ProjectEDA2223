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
    // Ponteiro para o meio de mobilidade elétrica alugado pelo cliente (ou NULL se não estiver alugado nenhum)
    struct Mobilidade* mobilidadeAlugada; 
    // Ponteiro para o próximo cliente na lista
    struct cliente* seguinte;

} Cliente;

//Declaração das funções para os clientes

void listarClientes(Cliente* cliente);
Cliente* inserirCliente(Cliente* cliente, int idCliente, char nomeCliente[], char moradaCliente[], int nifCliente, float saldo);