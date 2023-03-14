#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "menu.h"

#define MAXNOME 40

// Cria e Guarda Dados num File
// Guardar Dados dos Clientes
int guardarClientes(Cliente* cliente)
{
	FILE* fp;
	fp = fopen("clientes.txt", "w");
	if (fp != NULL)
	{
		Cliente* aux = cliente;
		while (aux != NULL)
		{
			printf("teste");
			fprintf(fp, "%d;%s;%s;%d;%.2f\n", aux->idCliente, aux->nomeCliente,
				aux->moradaCliente, aux->nifCliente, aux->saldo);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

Cliente* lerClientes()
{
	FILE* fp;
	int idCliente;
	char nomeCliente, moradaCliente;
	int nifCliente;
	float saldo;
	Cliente* aux = NULL;
	fp = fopen("clientes.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%s;%s;%d;%.2f\n", &idCliente, &nomeCliente, &moradaCliente, &nifCliente, &saldo);
			aux = inserirCliente(aux, idCliente, nomeCliente, moradaCliente, nifCliente, saldo);
		}
		fclose(fp);
	}
	return(aux);
}

//Guardar Dados dos Gestores

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


	// Inserção de Gestores Predefinidos
	Gestor* ges = NULL;

	ges = inserirGestor(ges, 1, "Joaquim Pereira", "jqmPereira");
	ges = inserirGestor(ges, 2, "Adelina Pinto", "adelPinto");
	ges = inserirGestor(ges, 3, "Tatiana Almeida", "tatiAlmeida");

	// Inserção de Mobilidade Predefinidas
	Mobilidade* mo = NULL;

	mo = inserirMobilidade(mo, 1, "Bicicleta Elétrica", 50.5, 60.00, 1);
	mo = inserirMobilidade(mo, 2, "Trotinete Elétrica", 80.0, 100.00, 5);
	mo = inserirMobilidade(mo, 2, "Skate Elétrica", 20.7, 40.00, 10);

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
			guardarClientes(cli);
			system("exit");
			break;

		default:
			printf("Opçao Inválida\n\n");
			system("pause");
			break;

		}
	} while (option != 0);

}