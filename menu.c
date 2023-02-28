#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#pragma region MENUS

void mostrarMenu() {
	printf("***********************************\n");
	printf("*             MENU                *\n");
	printf("***********************************\n");
	printf("* 1. Cliente                      *\n");
	printf("* 2. Gestor                       *\n");
	printf("* 3. Mobilidade                   *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opção: ");
}

void mostrarCliente() {
	printf("***********************************\n");
	printf("*             CLIENTE             *\n");
	printf("***********************************\n");
	printf("* 1. Listar Clientes              *\n");
	printf("* 2. Inserir Novo Cliente         *\n");
	printf("* 3. Remover Cliente              *\n");
	printf("* 4. Alterar Cliente              *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opção: ");
}

void mostrarGestor() {
	printf("***********************************\n");
	printf("*             GESTOR              *\n");
	printf("***********************************\n");
	printf("* 1. Listar Gestores              *\n");
	printf("* 2. Inserir Novo Gestor          *\n");
	printf("* 3. Remover Gestor               *\n");
	printf("* 4. Alterar Gestor               *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opção: ");
}

void mostrarMobilidade() {
	printf("***********************************\n");
	printf("*             MOBILIDADE          *\n");
	printf("***********************************\n");
	printf("* 1. Listar Mobilidades           *\n");
	printf("* 2. Inserir Nova Mobilidade      *\n");
	printf("* 3. Remover Mobilidade           *\n");
	printf("* 4. Alterar Mobilidade           *\n");
	printf("* 0. Sair                         *\n");
	printf("***********************************\n");
	printf("Opção: ");
}