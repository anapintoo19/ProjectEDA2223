#include <stdio.h>
#include <stdlib.h>
#include "mobilidade.h"

// Função para listar as mobilidades

void listarMobilidade(Mobilidade* mobilidade) {
	printf("****************************************************************************\n");
	printf("*                             LISTA DE MOBILIDADE                          *\n");
	printf("****************************************************************************\n\n");

	while (mobilidade != NULL)
	{
		printf("ID: %d    Tipo de Mobilidade: %s    Nível de Bateria: %.2f   Autonomia:%.2f  Mobilidade Alugada? %d", mobilidade->idMobilidade, mobilidade->tipo, mobilidade->nivel_bateria, mobilidade->autonomia, mobilidade->mobilidadeAlugada);
	}
	printf("\n****************************************************************************\n");
}

// Função para criar um novo registo de uma nova Mobilidade

Mobilidade* inserirMobilidade(Mobilidade* mobilidade, int idMobilidade, char tipo[], float nivel_bateria, float autonomia, int mobilidadeAlugada) {
	Mobilidade* novo = (Mobilidade*)malloc(sizeof(Mobilidade));

	if (novo != NULL)
	{
		novo->idMobilidade = idMobilidade;
		strcpy(novo->tipo, tipo);
		novo->nivel_bateria = nivel_bateria;
		novo->autonomia = autonomia;
		novo->mobilidadeAlugada = mobilidadeAlugada;
		novo->seguinte = mobilidade;
		return(novo);
	}
	else
	{
		return(mobilidade);
	}
}