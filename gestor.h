#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 50

#pragma once

// Estrutura para representar um gestor

typedef struct gestor
{
    // Identificador único do gestor
    int idGestor; 
    // Nome do gestor
    char nomeGestor[MAXNOME];
    // Senha de acesso do gestor
    char password[MAXNOME]; 
    // Ponteiro para o próximo gestor na lista
    struct gestor* seguinte; 

} Gestor;

//Declaração das funções para os gestores

void listarGestores(Gestor* gestor);
Gestor* inserirGestor(Gestor* gestor, int idGestor, char nomeGestor[], char password[]);