#include <stdio.h>
#include "mobilidade.h"
#include "gestor.h"
#include "cliente.h"
#pragma warning(disable : 4996)

#pragma region MENUS

void mostrarMenu();
void mostrarCliente();
void mostrarGestor();
void mostrarMobilidade();

#pragma endregion


#pragma region CLIENTE

Cliente* criaCliente(Cliente* cliente);
Cliente* removeCliente(Cliente* cliente);
Cliente* editaCliente(Cliente* cliente);
Cliente* associaMobilidade(Cliente* cliente, Mobilidade* mobilidade);
Cliente* desassociaMobilidade(Cliente* cliente, Mobilidade* mobilidade);

#pragma endregion


#pragma region GESTOR

Gestor* criaGestor(Gestor* gestor);
Gestor* removeGestor(Gestor* gestor);
Gestor* editaGestor(Gestor* gestor);

#pragma endregion


#pragma region MOBILIDADE

Mobilidade* criaMobilidade(Mobilidade* mobilidade);
Mobilidade* removeMobilidade(Mobilidade* mobilidade);
Mobilidade* editaMobilidade(Mobilidade* mobilidade);
void listarMobilidadesDESC(Mobilidade* mobilidade);

#pragma endregion