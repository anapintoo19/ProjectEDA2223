#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "menu.h"


#pragma warning(disable : 4996)



#define MAXNOME 40

// Cria e Guarda Dados num File, ou seja, exporta Dados

void dadosExportados(Cliente* cliente, Gestor* gestor, Mobilidade* mobilidade) {

	remove("ExportaDados.txt");

	FILE* exportaFile = fopen("ExportaDados.txt", "a");

	Cliente* cliAux = cliente;

	fprintf(exportaFile, "****************************************************************************\n");
	fprintf(exportaFile, "*                      LISTA DE CLIENTE E MOBILIDADES                      *\n");
	fprintf(exportaFile, "****************************************************************************\n\n");

	if (cliente != NULL)
	{
		fprintf(exportaFile, "ID cliente: %d   Nome: %s   Morada: %s   NIF: %d   Saldo: %.2f\n", cliAux->idCliente, cliAux->nomeCliente, cliAux->moradaCliente, cliAux->nifCliente, cliAux->saldo);

		ClienteMobilidade* CliMobAux = cliAux->mobilidadeAlugada;

		if (CliMobAux != NULL)
		{
			while (CliMobAux != NULL)
			{
				Mobilidade* mobAux = mobilidade;

				while (mobAux != NULL && mobAux->idMobilidade != CliMobAux->id)
				{
					mobAux = mobAux->seguinte;
				}

				fprintf(exportaFile, "ID: %d    Tipo de Mobilidade: %s    Nível de Bateria: %.2f   Autonomia: %.2f\n", mobAux->idMobilidade, mobAux->tipo, mobAux->nivel_bateria, mobAux->autonomia);

				CliMobAux = CliMobAux->seguinte;
			}
		}
		else
		{
			fprintf(exportaFile, "\tSem Mobilidades Alugadas\n");
		}

		fprintf(exportaFile, "****************************************************************************\n\n");
		fprintf(exportaFile, "****************************************************************************\n\n");

		cliAux = cliAux->seguinte;
	}
	else
	{
		fprintf(exportaFile, "Sem Clientes a apresentar\n");
	}

	// Guardar dados dos gestores

	Gestor* gesAux = gestor;

	fprintf(exportaFile, "****************************************************************************\n");
	fprintf(exportaFile, "*                      LISTA DE GESTORES                                   *\n");
	fprintf(exportaFile, "****************************************************************************\n\n");

	if (gestor != NULL)
	{
		while (gesAux != NULL)
		{
			fprintf(exportaFile, "ID: %d     Nome: %s     Password: %s\n", gesAux->idGestor, gesAux->nomeGestor, gesAux->password);

			fprintf(exportaFile, "****************************************************************************\n\n");

			gesAux = gesAux->seguinte;
		}
	}
	else
	{
		fprintf(exportaFile, "Sem Gestores a apresentar\n");
	}

	fclose(exportaFile);

	printf("****************************************************************************\n");
	printf("*                  OS DADOS FORAM EXPORTADOS COM SUCESSO                   *\n");
	printf("****************************************************************************\n");
}


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

	cli = inserirCliente(cli, 259874123, 1, "Alberta", "Rua das Fontainhas", 20.0);
	cli = inserirCliente(cli, 256963520, 2, "Joel", "Rua dos Joelhos", 50.0);
	cli = inserirCliente(cli, 147456852, 3, "Ulisses", "Rua da Escola", 10.0);


	// Inserção de Gestores Predefinidos
	Gestor* ges = NULL;

	ges = inserirGestor(ges, 1, "Joaquim Pereira", "jqmPereira");
	ges = inserirGestor(ges, 2, "Adelina Pinto", "adelPinto");
	ges = inserirGestor(ges, 3, "Ana Almeida", "anaAlmeida");

	// Inserção de Mobilidade Predefinidas
	Mobilidade* mo = NULL;

	mo = inserirMobilidade(mo, 1, "Bicicleta Elétrica", 50.5, 60.00);
	mo = inserirMobilidade(mo, 2, "Trotinete Elétrica", 80.0, 100.00);
	mo = inserirMobilidade(mo, 3, "Skate Elétrica", 20.7, 40.00);

	// Associação de Mobilidades aos Clientes
	cli = associarMobilidade(cli, 259874123, 1);
	cli = associarMobilidade(cli, 256963520, 3);

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
					listarClientes(cli, mo);
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
					cli = editaCliente(cli);
					system("pause");
					break;
				case 5:
					cli = associaMobilidade(cli, mo);
					system("pause");
					break;
				case 6:
					cli = desassociaMobilidade(cli, mo);
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
					ges = editaGestor(ges);
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
					mo = editaMobilidade(mo);
					system("pause");
					break;

				case 5:
					listarMobilidadesDESC(mo);
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
		case 4:
			dadosExportados(cli, ges, mo);
			system("pause");
			break;

		case 0:
			system("exit");
			break;

		default:
			printf("Opçao Inválida\n\n");
			system("pause");
			break;

		}
		system("cls");
	} while (option != 0);

}