#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "menu.h"

// mobilidadeEletrica *lista_mobilidade = NULL;
// cliente *lista_cliente = NULL;
// gestor *lista_gestor = NULL;

// int main(){

//     cliente *new_cliente = (cliente *) malloc(sizeof(cliente));
//     new_cliente->id = 1;
//     strcpy(new_cliente->nome, "Ana");
//     new_cliente->saldo = 100.00;
//     new_cliente->mobilidade_alugada = NULL;
//     new_cliente->next = lista_cliente; // Inserir no início da lista
//     lista_cliente = new_cliente; // Atualizar o início da lista

//     cliente *new_cliente = (cliente *) malloc(sizeof(cliente));
//     new_cliente->id = 2;
//     strcpy(new_cliente->nome, "Ana");
//     new_cliente->saldo = 100.00;
//     new_cliente->mobilidade_alugada = NULL;
//     new_cliente->next = lista_cliente; // Inserir no início da lista
//     lista_cliente = new_cliente; // Atualizar o início da lista

//     // Criar um novo gestor
//     gestor *new_gestor = (gestor *) malloc(sizeof(gestor));
//     new_gestor->id = 1;
//     strcpy(new_gestor->nome, "Ana");
//     strcpy(new_gestor->password, "1234");
//     new_gestor->next = lista_gestor;
//     lista_gestor = new_gestor;

//     // Criar um novo meio de mobilidade elétrica
//     mobilidadeEletrica *new_mobilidade = (mobilidadeEletrica *) malloc(sizeof(mobilidadeEletrica));
//     new_mobilidade->id = 1;
//     strcpy(new_mobilidade->tipo, "bicicleta elétrica");
//     new_mobilidade->nivel_bateria = 100.0;
//     new_mobilidade->alugada = 0;
//     new_mobilidade->next = lista_mobilidade;
//     lista_mobilidade = new_mobilidade;


// }

#define MAXNOME 40

// Cria e Guarda Dados num File
// Funções para AutoIncrementar os ID's por uma File
// int autoIdJob() {
// 	int idJob;
// 	FILE* idFile = fopen("idJob.txt", "r");
// 	if (!idFile) {
// 		idFile = fopen("idJob.txt", "w");
// 		if (!idFile) return -1; // Erro
// 		fprintf(idFile, "%d", 1);
// 		fclose(idFile);
// 		return 1;
// 	}
// 	fscanf(idFile, "%d", &idJob); // Lê o ID e Incrementa 1 Valor
// 	idJob++;

// 	fclose(idFile); // Fecha a File
// 	idFile = fopen("idJob.txt", "w"); // Reabre a File
// 	fprintf(idFile, "%d", idJob);
// 	fclose(idFile);
// 	return idJob;
// }

// int autoIdOp() {
// 	int idOp;
// 	FILE* idFile = fopen("idOp.txt", "r");
// 	if (!idFile) {
// 		idFile = fopen("idOp.txt", "w");
// 		if (!idFile) return -1; // Erro
// 		fprintf(idFile, "%d", 1);
// 		fclose(idFile);
// 		return 1;
// 	}
// 	fscanf(idFile, "%d", &idOp); // Lê o ID e Incrementa 1 Valor
// 	idOp++;

// 	fclose(idFile); // Fecha a File
// 	idFile = fopen("idOp.txt", "w"); // Reabre a File
// 	fprintf(idFile, "%d", idOp);
// 	fclose(idFile);
// 	return idOp;
// }

// int autoIdMaq() {
// 	int idMaq;
// 	FILE* idFile = fopen("idMaq.txt", "r");
// 	if (!idFile) {
// 		idFile = fopen("idMaq.txt", "w");
// 		if (!idFile) return -1; // Erro
// 		fprintf(idFile, "%d", 1);
// 		fclose(idFile);
// 		return 1;
// 	}
// 	fscanf(idFile, "%d", &idMaq); // Lê o ID e Incrementa 1 Valor
// 	idMaq++;

// 	fclose(idFile); // Fecha a File
// 	idFile = fopen("idMaq.txt", "w"); // Reabre a File
// 	fprintf(idFile, "%d", idMaq);
// 	fclose(idFile);
// 	return idMaq;
// }


int main() {

	// Variáveis para Escolha da Opção dos Menus e SubMenus
	int option;
	int subOption;

	// Definição de Locale como LC_ALL para UTF-8 
	// Permite assim caracteres especiais na Consola de Debug
	char* locale;
	locale = setlocale(LC_ALL, "");

	// Inserção de Clientes Predefinidos
	Cliente* cli = NULL;

	cli = inserirCliente(cli, 1, "Maria Paula", "Rua das Agras", 254897451, 5.00);
	cli = inserirCliente(cli, 2, "Hélder João", "Rua das Andorinhas", 258789104, 1.50);
	cli = inserirCliente(cli, 3, "Joaquina", "Rua Alberto Pais", 256986321, 2.30);

	// Inserção de Gestores Predefinidos
	Gestor* ges = NULL;

	ges = inserirGestor(ges, 1, "Joaquim Pereira", "jqmPereira");
	ges = inserirGestor(ges, 2, "Adelina Pinto", "adelPinto");
	ges = inserirGestor(ges, 3, "Tatiana Almeida", "tatiAlmeida");

	// Inserção de Mobilidade Predefinidas
	Mobilidade* mo = NULL;

	mo = inserirMobilidade(mo, 1, "Bicicleta Elétrica", 50.5, 1);
	mo = inserirMobilidade(mo, 2, "Trotinete Elétrica", 80.0, 5);
	mo = inserirMobilidade(mo, 2, "Skate Elétrica", 20.7, 10);

	do
	{
		mostrarMenu();
		scanf_s("%d", &option);
		system("cls");

		switch (option)
		{

			// MENU CLIENTE
		case 1:
			do
			{
				mostrarCliente();

				scanf_s("%d", &subOption);
				system("cls");

				switch (subOption)
				{

				case 1:
					listarClientes(cli);
					system("pause");
					break;

				case 2:
					cli = criaCliente(cli);
					system("pause");
					break;

				case 3:
					cli = removeCliente(cli);
					system("pause");
					break;

				case 4:
					cli = alterarCliente(cli);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opçao Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

			// MENU GESTOR
		case 2:
			do
			{
				mostrarGestor();

				scanf_s("%d", &subOption);
				system("cls");

				switch (subOption)
				{
				case 1:
					listarGestores(ges);
					system("pause");
					break;

				case 2:
					ges = criaGestor(ges);
					system("pause");
					break;

				case 3:
					ges = removeGestor(ges);
					system("pause");
					break;

				case 4:
					ges = alterarGestor(ges);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opçao Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

			// MENU MOBILIDADE
		case 3:
			do
			{
				mostrarMobilidade();

				scanf_s("%d", &subOption);
				system("cls");

				switch (subOption)
				{
				case 1:
					listarMobilidade(mo);
					system("pause");
					break;

				case 2:
					mo = criaMobilidade(mo);
					system("pause");
					break;

				case 3:
					mo = removeMobilidade(mo);
					system("pause");
					break;

				case 4:
					mo = alterarMobilidade(mo);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opçao Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

		case 0:
			system("exit");
			break;

		default:
			printf("Opçao Inválida\n\n");
			system("pause");
			break;

		}
	} while (option != 0);

}